#include <debug.h>
#include <drivers/i3c.h>
#include <drivers/scu.h>
#include <io.h>
#include <platform.h>
#include <errno.h>
#include <utils.h>
#include <lib/printf.h>
#include <recovery.h>
#include <lib/string.h>

#define MIPI_VENDOR_ASPEED 0x3f6
/* Aspeed part id: G6 A1 */
#define PART_ID_ASPEED 0x0601
/* Extended Capability Header */
#define CAP_HEADER_LENGTH GENMASK(23, 8)
#define CAP_HEADER_ID GENMASK(7, 0)

#define DBG(...)

#define I3C_PID(manuf_id, pid_type, part_id, instance_id, extra_info) \
	((((u64)(manuf_id) & GENMASK(14, 0)) << 33) |                   \
	 ((u64)!!(pid_type) << 32) |                                 \
	 (((u64)(part_id) & GENMASK(14, 0)) << 16) |                    \
	 (((u64)(instance_id) & GENMASK(3, 0)) << 12) |                 \
	 ((u64)(extra_info) & GENMASK(11, 0)))

struct i3c_hci g_hci;

static int hci_extcap_vendor_ASPEED(struct i3c_hci *hci, void *base)
{
	u32 regs_offset;

	regs_offset = readl(base + 1 * 4);
	hci->INHOUSE_regs = hci->base_regs + regs_offset;
	DBG("INHOUSE control at offset %#x\n", regs_offset);
	regs_offset = readl(base + 2 * 4);
	hci->PHY_regs = hci->base_regs + regs_offset;
	DBG("PHY_regs control at offset %#x\n", regs_offset);
	return 0;
}

static int i3c_hci_parse_ext_caps(struct i3c_hci *hci)
{
	void *curr_cap = hci->EXTCAPS_regs;
	void *end = curr_cap + 0x1000; /* some arbitrary limit */
	u32 cap_header, cap_id, cap_length;
	int err = 0;

	if (!curr_cap)
		return 0;

	for (; !err && curr_cap < end; curr_cap += cap_length * 4) {
		cap_header = readl(curr_cap);
		cap_id = FIELD_GET(CAP_HEADER_ID, cap_header);
		cap_length = FIELD_GET(CAP_HEADER_LENGTH, cap_header);
		DBG("id=0x%02x length=%d\n", cap_id, cap_length);
		if (!cap_length)
			break;
		if (curr_cap + cap_length * 4 >= end)
			break;

		if (cap_id >= 0xc0 && cap_id <= 0xcf) {
			err = hci_extcap_vendor_ASPEED(hci, curr_cap);
			continue;
		}
	}
	return 0;
}

static void i3c_pio_init(struct i3c_hci *hci)
{
	u32 val;

	val = FIELD_PREP(QUEUE_RESP_BUF_THLD, 1) |
	      FIELD_PREP(QUEUE_CMD_EMPTY_BUF_THLD, 1);
	pio_reg_write(QUEUE_THLD_CTRL, val);

	/* Disable all IRQs but allow all status bits */
	pio_reg_write(INTR_SIGNAL_ENABLE, 0x0);
	pio_reg_write(INTR_STATUS_ENABLE, 0xffffffff);
}

static void i3c_target_read_rx_fifo(struct i3c_hci *hci, unsigned int count,
				    void *buf)
{
	u32 *p = buf;

	if (count >= 4) {
		unsigned int nr_words = count / 4;

		while (nr_words--)
			*p++ = pio_reg_read(XFER_DATA_PORT);
	}
	count &= 3;
	if (count) {
		u8 *p_byte = (u8 *)p;
		u32 data = pio_reg_read(XFER_DATA_PORT);

		data = (u32)cpu_to_le32(data);
		while (count--) {
			*p_byte++ = data;
			data >>= 8;
		}
	}
}

static int i3c_pio_process_resp(struct i3c_hci *hci, u8 *data)
{
	u32 resp = pio_reg_read(RESPONSE_QUEUE_PORT);
	size_t nbytes = TARGET_RESP_DATA_LENGTH(resp);

	DBG("resp status:%lx, xfer type:%lx, CCC_INDI:%lx tid:%lx, CCC_HDR: %lx, data legth: %lx\n",
	    TARGET_RESP_STATUS(resp), TARGET_RESP_XFER_TYPE(resp),
	    TARGET_RESP_CCC_INDICATE(resp), TARGET_RESP_TID(resp),
	    TARGET_RESP_CCC_HDR(resp), TARGET_RESP_DATA_LENGTH(resp));

	if (TARGET_RESP_CCC_INDICATE(resp)) {
		if (TARGET_RESP_XFER_TYPE(resp)) {
			i3c_target_read_rx_fifo(hci, nbytes, data);
			/* TODO: Handle the SET CCC */
			return -EINVAL;
		}
	} else if (TARGET_RESP_XFER_TYPE(resp)) {
		i3c_target_read_rx_fifo(hci, nbytes, data);
		return nbytes;
	}
	return 0;
}

/*
 * HV I3C: index 0~3(GRP_L), 12~15(GRP_I)
 * LV I3C: index 4~11(GRP_J and GRP_K)
 */

static void i3c_pinctrl_setting(u8 index)
{
	u32 mask, value, bit_shift, gpio_group;

	bit_shift = (index & 0x3) << 2;
	mask = GENMASK(7, 0) << bit_shift;
	value = FIELD_PREP(mask, 0x11 << bit_shift);
	gpio_group = index >> 2;

	switch (gpio_group) {
	case 0:
		clrsetbits(SCU1_PINMUX_GRP_L, mask, value);
		break;
	case 1:
		clrsetbits(SCU1_PINMUX_GRP_J, mask, value);
		break;
	case 2:
		clrsetbits(SCU1_PINMUX_GRP_K, mask, value);
		break;
	case 3:
		clrsetbits(SCU1_PINMUX_GRP_I, mask, value);
		break;
	default:
		break;
	}
}

static int i3c_target_bus_init(struct i3c_hci *hci)
{
	u64 pid;
	u8 bcr;
	u8 dcr;
	u8 hdr_cap = 0;
	u32 reg;

	pid = I3C_PID(MIPI_VENDOR_ASPEED, 0, PART_ID_ASPEED, hci->index, 0);
	ast_inhouse_write(ASPEED_I3C_SLV_PID_LO, SLV_PID_LO(pid));
	ast_inhouse_write(ASPEED_I3C_SLV_PID_HI, SLV_PID_HI(pid));
	bcr = I3C_BCR_DEVICE_ROLE(I3C_BCR_I3C_SLAVE) | I3C_BCR_HDR_CAP |
	      I3C_BCR_IBI_PAYLOAD | I3C_BCR_IBI_REQ_CAP;
	/* Generic device */
	dcr = FIELD_GET(SCU1_OTPCFG15_I3C_DCR, readl(SCU1_OTPCFG_15_14));
	DBG("dcr = %x\n", dcr);
	ast_inhouse_write(ASPEED_I3C_SLV_CHAR_CTRL,
			  FIELD_PREP(ASPEED_I3C_SLV_CHAR_CTRL_DCR, dcr) |
				  FIELD_PREP(ASPEED_I3C_SLV_CHAR_CTRL_BCR,
					     bcr));
	/* Make slave will send the ibi when bus idle */
	reg = ast_inhouse_read(ASPEED_I3C_SLV_CAP_CTRL);
	ast_inhouse_write(ASPEED_I3C_SLV_CAP_CTRL,
			  reg | ASPEED_I3C_SLV_CAP_CTRL_IBI_WAIT |
				  ASPEED_I3C_SLV_CAP_CTRL_HJ_WAIT);
	if (hci->caps & HC_CAP_HDR_DDR_EN)
		hdr_cap |= BIT(I3C_HDR_DDR);
	if (hci->caps & HC_CAP_HDR_TS_EN) {
		if (reg_read(HC_CONTROL) & HC_CONTROL_I2C_TARGET_PRESENT)
			hdr_cap |= BIT(I3C_HDR_TSL);
		else
			hdr_cap |= BIT(I3C_HDR_TSP);
	}
	if (hci->caps & HC_CAP_HDR_BT_EN)
		hdr_cap |= BIT(I3C_HDR_BT);

	ast_inhouse_write(ASPEED_I3C_SLV_STS8_GETCAPS_TGT, hdr_cap);

	ast_inhouse_write(ASPEED_I3C_CTRL,
			  ASPEED_I3C_CTRL_INIT | ASPEED_I3C_SLV_CCC_NOTIFY_DIS |
				  FIELD_PREP(ASPEED_I3C_CTRL_INIT_MODE,
					     INIT_SEC_MST_MODE));

	i3c_pio_init(hci);

	reg_set(HC_CONTROL, HC_CONTROL_BUS_ENABLE);

	return 0;
}

static void i3c_wait_address_assign(struct i3c_hci *hci)
{
	u32 reg;
	bool hj_req_en;

	reg = readl(SCU1_OTPCFG_15_14);
	hj_req_en = FIELD_GET(SCU1_OTPCFG15_I3C_HJ_REQ, reg);
	while (!(ast_inhouse_read(ASPEED_I3C_STS) &
		 ASPEED_I3C_STS_SLV_DYNAMIC_ADDRESS_VALID)) {
		if (hj_req_en) {
			if (ast_inhouse_read(ASPEED_I3C_SLV_STS1) &
			    ASPEED_I3C_SLV_STS1_HJ_EN) {
				reg = ast_inhouse_read(ASPEED_I3C_SLV_CAP_CTRL);
				ast_inhouse_write(ASPEED_I3C_SLV_CAP_CTRL,
						  reg | ASPEED_I3C_SLV_CAP_CTRL_HJ_REQ);
				udelay(10);
			}
		}
	}
	DBG("Dynamic address assigned 0x%x\n",
	    FIELD_GET(ASPEED_I3C_STS_SLV_DYNAMIC_ADDRESS,
		      ast_inhouse_read(ASPEED_I3C_STS)));
}

int i3c_init(void)
{
	struct i3c_hci *hci = &g_hci;
	u32 regval, offset;
	int ret;

	regval = readl(SCU1_OTPCFG_15_14);
	hci->index = FIELD_GET(SCU1_OTPCFG15_I3C_I2C_CH, regval);
	hci->base_regs = (void *)I3C_REG(hci->index);

	DBG("Choice I3C%d for recovery\n", hci->index);

	i3c_pinctrl_setting(hci->index);

	/* assert reset */
	writel(SCU1_RSTCTL1_I3C(hci->index), SCU1_RSTCTL1);
	/* clk gate */
	writel(SCU1_CLKGATE1_I3C(hci->index), SCU1_CLKGATE1);
	udelay(1);
	/* de-assert reset and delay */
	/* clk ungate */
	writel(SCU1_CLKGATE1_CLR_I3C(hci->index), SCU1_CLKGATE1_CLR);
	writel(SCU1_RSTCTL1_CLR_I3C(hci->index), SCU1_RSTCTL1_CLR);
	mdelay(1);

	hci->caps = reg_read(HC_CAPABILITIES);
	DBG("caps = %#x\n", hci->caps);

	regval = reg_read(PIO_SECTION);
	offset = FIELD_GET(PIO_REGS_OFFSET, regval);
	hci->PIO_regs = offset ? hci->base_regs + offset : NULL;
	DBG("PIO section at offset %#x\n", offset);

	regval = reg_read(EXT_CAPS_SECTION);
	offset = FIELD_GET(EXT_CAPS_OFFSET, regval);
	hci->EXTCAPS_regs = offset ? hci->base_regs + offset : NULL;
	DBG("Extended Caps at offset %#x\n", offset);

	i3c_hci_parse_ext_caps(hci);

	ret = readx_poll_timeout(reg_read, RESET_CONTROL, regval,
				 !(regval & SOFT_RST), 1, 10000);
	if (ret)
		return REC_ERR_I3C_INIT;
	reg_write(RESET_CONTROL, SOFT_RST);
	ret = readx_poll_timeout(reg_read, RESET_CONTROL, regval,
				 !(regval & SOFT_RST), 1, 10000);
	if (ret)
		return REC_ERR_I3C_INIT;

	/* Disable all interrupts and allow all signal updates */
	reg_write(INTR_SIGNAL_ENABLE, 0x0);
	reg_write(INTR_STATUS_ENABLE, 0xffffffff);
	ast_inhouse_write(ASPEED_I3C_INTR_SIGNAL_ENABLE, 0);
	ast_inhouse_write(ASPEED_I3C_INTR_STATUS_ENABLE, 0xffffffff);

	/* Make sure our data ordering fits the host's (little endian) */
	regval = reg_read(HC_CONTROL);
	if (regval & HC_CONTROL_DATA_BIG_ENDIAN) {
		regval &= ~HC_CONTROL_DATA_BIG_ENDIAN;
		reg_write(HC_CONTROL, regval);
		regval = reg_read(HC_CONTROL);
		if (regval & HC_CONTROL_DATA_BIG_ENDIAN) {
			DBG("cannot clear BE mode\n");
			return REC_ERR_I3C_INIT;
		}
	}

	/* Activating PIO mode */
	reg_set(HC_CONTROL, HC_CONTROL_PIO_MODE);
	if (!(reg_read(HC_CONTROL) & HC_CONTROL_PIO_MODE)) {
		DBG("DMA mode is stuck\n");
		return REC_ERR_I3C_INIT;
	}

	i3c_target_bus_init(hci);
	i3c_wait_address_assign(hci);
	return 0;
}

void i3c_deinit(void)
{
	struct i3c_hci *hci = &g_hci;

	/* assert reset */
	writel(SCU1_RSTCTL1_I3C(hci->index), SCU1_RSTCTL1);
	/* clk gate */
	writel(SCU1_CLKGATE1_I3C(hci->index), SCU1_CLKGATE1);
}

void mipi_i3c_hci_resume(struct i3c_hci *hci)
{
	reg_set(HC_CONTROL, HC_CONTROL_RESUME);
}

void i3c_poll_in_forever(struct i3c_hci *hci, u8 *data, u32 *size)
{
	u32 status;
	int ret;

	while (true) {
		status = pio_reg_read(INTR_STATUS);
		if (status & STAT_RESP_READY) {
			ret = i3c_pio_process_resp(hci, data);
			if (ret <= 0)
				continue;
			*size = ret;
			break;
		}
		if (FIELD_GET(ASPEED_I3C_SLV_FSM_MASK,
			      ast_inhouse_read(ASPEED_I3C_SLV_FSM)) ==
		    ASPEED_I3C_SLV_FSM_HALT) {
			DBG("Detect i3c enter halt, resum it\n");
			mipi_i3c_hci_resume(hci);
		}
	}
}

/*
 * from: don't care.
 * *dst: destination address to move to
 * len: required length, if not equal, return failre
 */
static int i3c_recovery(u32 from, u32 *dst, u32 len)
{
	struct i3c_hci *hci = &g_hci;
	u32 size, packet_size, received_size = 0;
	u8 *io_sram_ptr;
	struct i3c_recovey_packet const *hdr;

	io_sram_ptr = (u8 *)dst;
	while (1) {
		i3c_poll_in_forever(hci, hci->data, &size);
		hdr = (struct i3c_recovey_packet *)hci->data;
		packet_size = (hdr->len_hi << 8) | hdr->len_lo;
		DBG("command: 0x%x, length: %x, hw received size: %x\n",
		    hdr->command, packet_size, size);
		/*
		 * Packet size should same as hardware received size.
		 * Header size = 3 bytes, PEC size = 1 byte, DDR padding data = 1bytes
		 * Without PEC, the packet size should equal to hw received size - Header size
		 * With PEC, it should be minus an additional 1 byte.
		 * With DDR mode, the packet size is even with PEC then need to minus padding data
		 */
		if (packet_size != size - 3 && packet_size != size - 4 && packet_size != size - 5)
			return REC_ERR_RECEIVE_DATA;
		if (hdr->command == OCP_REC_CTRL) {
			if (packet_size != OCP_REC_CTRL_BYTES)
				continue;
			if (hdr->payload[OCP_REC_CTRL_CMS_BYTE] == 0 &&
			    hdr->payload[OCP_REC_CTRL_IMG_SEL_BYTE] ==
				    OCP_REC_CTRL_IMG_SEL_CMS &&
			    hdr->payload[OCP_REC_CTRL_ACTIVATE_BYTE] ==
				    OCP_REC_CTRL_ACTIVATE_REC_IMG)
				break;
		} else if (hdr->command == OCP_INDIRECT_DATA) {
			received_size += packet_size;
			if (received_size > len)
				return REC_ERR_LARGE_IMG_SZ;
			memcpy(io_sram_ptr, hdr->payload, packet_size);
			io_sram_ptr += packet_size;
		}
	}
	return 0;
}

static struct bootdev_ops i3c_ops = {
	.init = i3c_init,
	.read = i3c_recovery,
	.deinit = i3c_deinit,
};

void i3c_register(struct bootdev *bd)
{
	bd->id = BOOT_I3C;
	bd->ops = &i3c_ops;
}
