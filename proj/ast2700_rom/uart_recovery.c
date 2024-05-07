#include <boot.h>
#include <bootstage.h>
#include <drivers/lpc.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <drivers/uart.h>
#include <drivers/usb.h>
#include <fmc_verify.h>
#include <io.h>
#include <lib/printf.h>
#include <otp_mem.h>
#include <platform.h>
#include <recovery.h>
#include <types.h>

struct uart rc_uart[1];
static uint32_t rc_uart_cptr_fw_load;
static uint8_t *iosram_ptr;

struct rc_uart_route {
	uint32_t rx_route_reg;
	uint32_t rx_route_val;
	uint32_t tx_route_reg;
	uint32_t tx_route_val;
};

/*
 * UART IO route configuration.
 *
 * SCUIO_0C0[21:20] (RX: IOx -> UART12)
 *   00: NA    (loopback)
 *   01: IO_12 (default)
 *   10: IO_0
 *   11: IO_5
 *
 * LPC0_098[24] (TX: UART12 -> IO0)
 * LPC1_098[24] (TX: UART12 -> IO5)
 */
static struct rc_uart_route routing_tb[3] = {
	[0] = { },
	[1] = {
		/* route UART12 to IO0 */
		.rx_route_reg = SCU1_MISC1,
		.rx_route_val = FIELD_PREP(SCU1_MISC1_UART12_ROUTE, 0x2),
		.tx_route_reg = LPC0_HICR9,
		.tx_route_val = LPC_UART12_TX_ROUTE,
	},
	[2] = {
		/* route UART12 to IO5 */
		.rx_route_reg = SCU1_MISC1,
		.rx_route_val = FIELD_PREP(SCU1_MISC1_UART12_ROUTE, 0x3),
		.tx_route_reg = LPC1_HICR9,
		.tx_route_val = LPC_UART12_TX_ROUTE,
	}
};

/*
 * Recovery UART port selection
 *
 *  SCUIO_884[7:6] (RX: IOx -> UART12)
 *   00: IO_12 (BMC UART by default)
 *   01: IO_0 (Node 0 UART)
 *   10: IO_5 (Node 1 UART)
 */
static int uart_route_conf(void)
{
	uint32_t uart_port;
	uint32_t reg_val;

	uart_port = readl(SCU1_OTPCFG_03_02) & OTPCFG2_RC_UART_PORT_SEL;
	uart_port >>= 6;

	/* IO_12 by default */
	if (uart_port == 0)
		return 0;

	if (uart_port > 2)
		return REC_ERR_UART_PORT;

	mdelay(1);

	/* config RX route */
	reg_val = readl(routing_tb[uart_port].rx_route_reg);
	reg_val &= ~(SCU1_MISC1_UART12_ROUTE);
	reg_val |= routing_tb[uart_port].rx_route_val;
	writel(reg_val, routing_tb[uart_port].rx_route_reg);

	/* config TX route */
	reg_val = readl(routing_tb[uart_port].tx_route_reg);
	reg_val &= ~(LPC_UART12_TX_ROUTE);
	reg_val |= routing_tb[uart_port].tx_route_val;
	writel(reg_val, routing_tb[uart_port].tx_route_reg);

	mdelay(1);

	return 0;
}

static void uart_route_restore(void)
{
	uint32_t uart_port;
	uint32_t i;
	uint32_t reg_val;

	uart_port = readl(SCU1_OTPCFG_03_02) & OTPCFG2_RC_UART_PORT_SEL;
	uart_port >>= 6;

	/* no need to restore */
	if (uart_port == 0)
		return;

	mdelay(1);

	/* force to restore */
	for (i = 1; i < 3; i++) {
		reg_val = readl(routing_tb[uart_port].rx_route_reg);
		reg_val &= ~(SCU1_MISC1_UART12_ROUTE);
		reg_val |= FIELD_PREP(SCU1_MISC1_UART12_ROUTE, 0x1);
		writel(reg_val, routing_tb[uart_port].rx_route_reg);

		reg_val = readl(routing_tb[uart_port].tx_route_reg);
		reg_val &= ~(LPC_UART12_TX_ROUTE);
		writel(reg_val, routing_tb[uart_port].tx_route_reg);
	}

	mdelay(1);
}

static int uart_get_img_sz(struct uart *rc_uart,
			   uint32_t *img_sz,
			   uint32_t *received_sz)
{
	int ret = 0;
	uint32_t i;
	uint8_t data_byte;
	uint32_t data_dword;
	struct ast_fmc_header *fmc_hdr = (struct ast_fmc_header *)iosram_ptr;

	*img_sz = 0;

	if (rc_uart_cptr_fw_load == 0) {
		for (i = 0; i < 4; i++) {
			ret = uart_poll_in_forever(rc_uart, &data_byte);
			if (ret != 0) {
				ret = REC_ERR_RECEIVE_IMG_SZ;
				goto end;
			}

			data_dword = (uint32_t)data_byte;
			*img_sz |= data_dword << (i * 8);
		}

		rc_uart_cptr_fw_load = 1;
	} else {
		for (i = 0; i < sizeof(*fmc_hdr); i++) {
			ret = uart_poll_in_forever(rc_uart, &data_byte);
			if (ret != 0) {
				ret = REC_ERR_RECEIVE_IMG_SZ;
				goto end;
			}

			writeb(data_byte, iosram_ptr);
			iosram_ptr++;
		}

		*received_sz = sizeof(*fmc_hdr);
		*img_sz = fmc_hdr->body.size;
	}

end:
	return ret;
}

static void uart_load_deinit(void)
{
	uart_route_restore();
}

static int uart_load_init(void)
{
	rc_uart_cptr_fw_load = 0;

	/* skip loading calipta fw image */
	if ((readl(SCU1_HWSTRAP1) & SCU1_HWSTRAP1_DIS_CPTRA) ||
	    (readl(SCU1_EFUSE) & SCU1_EFUSE_DIS_CPTRA))
		rc_uart_cptr_fw_load = 1;

	/* 0x80 is return here in order to distinguish
	 * boot from UART mode from other error code.
	 */
	return 0x80;
}

static int uart_ctrl_conf(void)
{
	int ret = 0;
	struct uart_cfg rc_uartcfg;

	rc_uartcfg.divisor = 1,
	rc_uartcfg.parity = UART_CFG_PARITY_NONE,
	rc_uartcfg.stop_bits = UART_CFG_STOP_BITS_1,
	rc_uartcfg.data_bits = UART_CFG_DATA_BITS_8,

	/* init UART, including reset UART FIFO. */
	ret = uart_init(CONFIG_SYS_CONSOLE_BASE, rc_uart);
	if (ret != 0) {
		ret = REC_ERR_UART_INIT;
		goto end;
	}

	ret = uart_configure(rc_uart, &rc_uartcfg);
	if (ret != 0) {
		ret = REC_ERR_UART_CONF;
		goto end;
	}

end:
	mdelay(1);

	return ret;
}

/*
 * from: don't care.
 * *dst: destination address to move to
 * len: required length, if not equal, return failre
 */
static int uart_load(u32 from, u32 *dst, u32 len)
{
	int ret = 0;
	uint32_t img_sz = 0;
	uint32_t received_sz = 0;
	uint8_t data_byte;

	/* wait for all UART characters are printed */
	mdelay(2);

	ret = uart_route_conf();
	if (ret != 0)
		goto end;

	ret = uart_ctrl_conf();
	if (ret != 0)
		goto end;

	if (rc_uart_cptr_fw_load == 0)
		printf(" U1");
	else
		printf(" U2");

	udelay(400);

	/* always load received image to IO SRAM. */
	iosram_ptr = (uint8_t *)SRAM_MEM;

	ret = uart_get_img_sz(rc_uart, &img_sz, &received_sz);
	if (ret != 0)
		goto end;

	/* image size sanity. */
	if (img_sz == 0) {
		ret = REC_ERR_ZERO_IMG_SZ;
		goto end;
	}

	if (img_sz > CONFIG_FMC_LOAD_SIZE - received_sz) {
		ret = REC_ERR_LARGE_IMG_SZ;
		goto end;
	}

	while (img_sz != 0) {
		ret = uart_poll_in_forever(rc_uart, &data_byte);
		if (ret != 0) {
			ret = REC_ERR_RECEIVE_DATA;
			goto end;
		}

		writeb(data_byte, iosram_ptr);
		iosram_ptr++;
		img_sz--;
	}

end:
	uart_route_restore();

	/* the mask 0xff is used here in order to
	 * satisfy the type of syndrome variable.
	 */
	return (ret & 0xff);
}

static struct bootdev_ops uart_ops = {
	.init = uart_load_init,
	.read = uart_load,
	.deinit = uart_load_deinit,
};

void uart_register(struct bootdev *bd)
{
	bd->id = BOOT_UART;
	bd->ops = &uart_ops;
}
