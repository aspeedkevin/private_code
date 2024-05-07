#include <debug.h>
#include <drivers/i2c.h>
#include <drivers/scu.h>
#include <io.h>
#include <platform.h>
#include <errno.h>
#include <utils.h>
#include <lib/printf.h>
#include <recovery.h>
#include <lib/string.h>

#define DBG(...)

struct i2c_hci i2c_g_hci;
u8 i2c_buff[I2C_BUFFER_SIZE];

static void i2c_pinctrl_setting(u8 index)
{
	u32 mask, value, bit_shift, gpio_group;

	bit_shift = (index & 0x3) << 3;
	mask = GENMASK(7 + bit_shift, 0 + bit_shift);
	gpio_group = index >> 2;

	/* i2c0 - i2c11 are F1, i2c12 - i2c15 are F2 */
	if (gpio_group < 3) {
		value = FIELD_PREP(mask, I2C_MULTI_FUN1);
	} else {
		value = FIELD_PREP(mask, I2C_MULTI_FUN2);
	}

	switch (gpio_group) {
	case 0:
		clrsetbits(SCU1_PINMUX_GRP_V, mask, value);
		break;
	case 1:
		clrsetbits(SCU1_PINMUX_GRP_W, mask, value);
		break;
	case 2:
		clrsetbits(SCU1_PINMUX_GRP_X, mask, value);
		break;
	case 3:
		clrsetbits(SCU1_PINMUX_GRP_I, mask, value);
	default:
		break;
	}
}

int i2c_global_init(struct i2c_hci *hci)
{
	/* clear master slave irq registers */
	i2c_g_reg_write(I2CG_MIRQ, 0);
	i2c_g_reg_write(I2CG_SIRQ, 0);

	/* set control register */
	i2c_g_reg_write(I2CG_CTRL, (I2CG_CTRL_NEW_REG | I2CG_CTRL_NEW_CLK_DIV));

	/* clear ac timing */
	i2c_g_reg_write(I2CG_AC_CTRL, 0);

	/* sram fifo setting */
	i2c_g_reg_write(I2CG_FIFO_CFG0, I2C_FIFO_DEFAULT);
	i2c_g_reg_write(I2CG_FIFO_CFG1, I2C_FIFO_DEFAULT);

	return 0;
}

int i2c_device_init(struct i2c_hci *hci)
{
	/* disable slave address */
	i2c_reg_write(I2CS_ADDR_1, 0x0);
	i2c_reg_write(I2CS_ADDR_2, 0x0);

	/* enable slave control register */
	i2c_reg_write(I2CC_FUN_CTRL, I2CC_SLAVE_EN);

	/* set ac timing register */
	i2c_reg_write(I2CC_AC_TIMING, I2CC_AC_VAL);

	/* close slave interrupt and clear interrupt status */
	i2c_reg_write(I2CS_IER, 0x0);
	i2c_reg_write(I2CS_ISR, 0xFFFFFFFF);

	/* set slave dma rx base */
	i2c_reg_write(I2CS_RX_DMA, (u32)(&i2c_buff));
	i2c_reg_write(I2CS_RX_DMA_H, 0x0);

	/* set slave dma rx length */
	i2c_reg_write(I2CS_DMA_LEN, I2CS_DMA_RX_LEN_SET);

	/* set slave address disable */
	i2c_reg_write(I2CS_ADDR_1, hci->slave_addr_disable);

	/* set slave cmd */
	i2c_reg_write(I2CS_CMD_STS, I2CS_FIRE_CMD);

	return 0;
}

int i2c_init(void)
{
	struct i2c_hci *hci = &i2c_g_hci;
	u32 regval;

	/* get the otp setting for i2c recovery */
	regval = readl(SCU1_OTPCFG_15_14);
	hci->index = FIELD_GET(SCU1_OTPCFG15_I3C_I2C_CH, regval);
	hci->slave_addr_disable = FIELD_GET(SCU1_OTPCFG15_I2C_SLAVE_ADDR, regval);

	/* fill the salve address */
	if (hci->slave_addr_disable < 0x8 || hci->slave_addr_disable > 0x77) {
		hci->slave_addr_disable = I2CS_DIS_ADDR;
		hci->slave_addr_enable = I2CS_EN_ADDR;
	} else {
		hci->slave_addr_enable = (hci->slave_addr_disable | I2CS_ENABLE_ADDR0);
	}

	/* initial register base */
	hci->global_regs = (void *)I2C_REG(0);
	hci->base_regs = (void *)I2C_REG(hci->index + 1);

	DBG("Choice I2C%d for recovery\n", hci->index);

	i2c_pinctrl_setting(hci->index);

	/* assert reset */
	writel(SCU1_RSTCTL2_I2C, SCU1_RSTCTL2);
	/* clk gate */
	writel(SCU1_CLKGATE1_I2C, SCU1_CLKGATE1);
	udelay(1);
	/* de-assert reset and delay */
	/* clk ungate */
	writel(SCU1_CLKGATE1_CLR_I2C, SCU1_CLKGATE1_CLR);
	writel(SCU1_RSTCTL2_CLR_I2C, SCU1_RSTCTL2_CLR);
	mdelay(1);

	/* set global register setting */
	i2c_global_init(hci);

	/* set device register setting */
	i2c_device_init(hci);

	return 0;
}

void trigger_i2c_slave(struct i2c_hci *hci)
{
	/* set slave cmd */
	i2c_reg_write(I2CS_CMD_STS, I2CS_FIRE_CMD);
	/* clear interrupt status */
	i2c_reg_write(I2CS_ISR, hci->irq_status);
	i2c_reg_read(I2CS_ISR);
}

void clear_i2c_cmd_info(void)
{
	/* clear i2c command and length informaion */
	i2c_buff[0] = 0x0;
	i2c_buff[1] = 0x0;
}

int i2c_poll_in_forever(struct i2c_hci *hci, u32 *size)
{
	u32 status = 0, length = 0;

	if (!hci)
		return -EINVAL;
	while (true) {
		status = i2c_reg_read(I2CS_ISR);
		if (status & (I2CS_RX_DONE | I2CS_RX_STOP)) {
			length = i2c_reg_read(I2CS_LENGTH);
			*size = (length >> 16) & 0xFFFF;
			hci->irq_status = status;

			/* keep old behavior for eco */
			/* set slave address 0 / 1 auto nak */
			/* reg = (i2c_reg_read(I2CS_CMD_STS) | I2CS_AUTO_NAK); */
			/* i2c_reg_write(I2CS_CMD_STS, reg); */
			break;
		}

		/* keep old behavior for eco */
		/* i2c would not support read in this stage */
		/* if (status & I2CS_WAIT_TX) */
		/*	return REC_ERR_RECEIVE_DATA; */
	}
	return 0;
}

static int i2c_recovery(u32 from, u32 *dst, u32 len)
{
	struct i2c_hci *hci = &i2c_g_hci;
	u32 size, received_size = 0;
	u8 *io_sram_ptr;
	int ret = 0;
	struct i2c_recovey_packet const *hdr;

	DBG("dst: 0x%x, length: %x\n", (u32)dst, len);
	DBG("i2c buf: 0x%x\n", (u32)i2c_buff);

	/* set slave address enable */
	i2c_reg_write(I2CS_ADDR_1, hci->slave_addr_enable);

	/* clear buffer info */
	clear_i2c_cmd_info();

	io_sram_ptr = (u8 *)dst;
	while (1) {
		ret = i2c_poll_in_forever(hci, &size);
		if (!ret) {
			hdr = (struct i2c_recovey_packet *)i2c_buff;
			DBG("command: 0x%x, length: %x\n", hdr->command, hdr->len);
			DBG("got: 0x%x bytes\n", (u32)size);
			for (u32 i = 0; i < hdr->len; i++)
				DBG("%x ", hdr->payload[i]);
			DBG("\n");

			if (hdr->command == OCP_REC_CTRL) {
				if (hdr->len != OCP_REC_CTRL_BYTES)
					continue;

				if (hdr->payload[OCP_REC_CTRL_CMS_BYTE] == 0 &&
				    hdr->payload[OCP_REC_CTRL_IMG_SEL_BYTE] == OCP_REC_CTRL_IMG_SEL_CMS &&
				    hdr->payload[OCP_REC_CTRL_ACTIVATE_BYTE] == OCP_REC_CTRL_ACTIVATE_REC_IMG) {
					/* set slave address disable */
					i2c_reg_write(I2CS_ADDR_1, hci->slave_addr_disable);

					/* Need clear status and trigger */
					trigger_i2c_slave(hci);
					break;
				}
			} else if (hdr->command == OCP_INDIRECT_DATA) {
				/* if received data bytes would not fit with package length */
				if (size >= hdr->len) {
					received_size += hdr->len;
					if (received_size > len)
						return REC_ERR_LARGE_IMG_SZ;
					memcpy(io_sram_ptr, hdr->payload, hdr->len);
					io_sram_ptr += hdr->len;
				}

				/* clear buffer info */
				clear_i2c_cmd_info();
			}

			/* trigger next i2c command */
			trigger_i2c_slave(hci);
		} else {
			break;
		}
	}
	return ret;
}

static struct bootdev_ops i2c_ops = {
	.init = i2c_init,
	.read = i2c_recovery,
	.deinit = NULL,
};

void i2c_register(struct bootdev *bd)
{
	DBG(" i2c register\n");
	bd->id = BOOT_I2C;
	bd->ops = &i2c_ops;
}
