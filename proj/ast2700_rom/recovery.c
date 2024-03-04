// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <boot.h>
#include <bootstage.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <drivers/uart.h>
#include <drivers/usb.h>
#include <io.h>
#include <lib/printf.h>
#include <otp_mem.h>
#include <platform.h>
#include <recovery.h>
#include <types.h>

static int recovery_download_usb(void)
{
	int ret;

	if (!sli_get_availability())
		return STS_SLI_UNAVAIL;

	usb_enable();
	while (1) {
		ret = usb_poll();
		if (ret)
			return ret;

		if (usb_is_dnload_done())
			break;
	}

	return ret;
}

static int recovery_download_uart(void)
{
	uint32_t img_sz = 0;
	uint32_t i;
	uint32_t data_dword;
	uint16_t cfg = 0;
	uint8_t data_byte;
	uint8_t sts = 0;
	int ret;
	uint8_t *io_sram_ptr;
	uint32_t io_routing_rx_val;
	uint32_t io_routing_rx_val_ori;
	uint32_t io_routing_tx_val;
	uint32_t io_routing_tx_val_ori;
	bool is_uart12_to_io0;
	struct uart cnsl_uart[1];
	struct uart_cfg cnsl_uartcfg;

	otp_read_data(OTPCFG2, &cfg);
	is_uart12_to_io0 = cfg & OTPCFG2_BOOT_FROM_UART_PORT_SEL;

	/* route IO0 <-> UART12 if selected */
	if (is_uart12_to_io0) {
		io_routing_rx_val_ori = readl(SCU1_MISC1);
		io_routing_rx_val = io_routing_rx_val_ori & (~(SCU1_MISC1_UART12_ROUTE));
		io_routing_rx_val |= FIELD_PREP(SCU1_MISC1_UART12_ROUTE, 0x2);
		writel(io_routing_rx_val, SCU1_MISC1);

		io_routing_tx_val_ori = readl(LPC0_REG + 0x098);
		io_routing_tx_val = io_routing_tx_val_ori | BIT(24);
		writel(io_routing_tx_val, LPC0_REG + 0x098);
		udelay(10);
	}

	cnsl_uartcfg.divisor = 1,
	cnsl_uartcfg.parity = UART_CFG_PARITY_NONE,
	cnsl_uartcfg.stop_bits = UART_CFG_STOP_BITS_1,
	cnsl_uartcfg.data_bits = UART_CFG_DATA_BITS_8,

	/* init UART, including reset UART FIFO. */
	ret = uart_init(CONFIG_SYS_CONSOLE_BASE, cnsl_uart);
	if (ret != 0) {
		sts |= (uint8_t)REC_ERR_UART_INIT;
		goto end;
	}

	ret = uart_configure(cnsl_uart, &cnsl_uartcfg);
	if (ret != 0) {
		sts |= (uint8_t)REC_ERR_UART_CONF;
		goto end;
	}

	/* Start to recovery from UART. */
	for (i = 0; i < 4; i++) {
		ret = uart_poll_in_forever(cnsl_uart, &data_byte);
		if (ret != 0) {
			sts |= (uint8_t)REC_ERR_RECEIVE_IMG_SZ;
			goto end;
		}

		data_dword = (uint32_t)data_byte;
		img_sz |= data_dword << (i * 8);
	}

	/* Image size sanity. */
	if (img_sz == 0) {
		sts |= (uint8_t)REC_ERR_ZERO_IMG_SZ;
		goto end;
	}

	if (img_sz > SRAM_SZ) {
		sts |= (uint8_t)REC_ERR_LARGE_IMG_SZ;
		goto end;
	}

	/* Always load received image to IO SRAM. */
	io_sram_ptr = (uint8_t *)SRAM_MEM;

	while (img_sz != 0) {
		ret = uart_poll_in_forever(cnsl_uart, &data_byte);
		if (ret != 0) {
			sts |= (uint8_t)REC_ERR_RECEIVE_DATA;
			goto end;
		}

		writeb(data_byte, io_sram_ptr);
		io_sram_ptr++;
		img_sz--;
	}

end:
	/* Restore the original UART routing for RAM code use. */
	if (is_uart12_to_io0) {
		udelay(20);
		writel(io_routing_rx_val_ori, SCU1_MISC1);
		writel(io_routing_tx_val_ori, LPC0_REG + 0x098);
		udelay(20);
	}

	return sts;
}

bootstage_t recovery_boot(void)
{
	bootstage_t sts = { REC_ERR_SUCCESS, 0 };

	uint16_t cfg;
	uint32_t reg;
	int rc;

	rc = otp_read_data(OTPCFG2, &cfg);
	if (rc || (cfg & OTPCFG2_DIS_RECOVERY_MODE)) {
		sts.syndrome = REC_SYN_SKIP;
		return sts;
	}

	reg = readl(SCU1_HWSTRAP1);
	if (!(reg & SCU1_HWSTRAP1_EN_RECOVERY_BOOT)) {
		sts.syndrome = REC_SYN_SKIP;
		return sts;
	}

	/* recovery mode selection: 0 -> UART, 1 -> USB */
	if (reg & SCU1_HWSTRAP1_RECOVERY_USB) {
		sts.errno = recovery_download_usb();
		sts.syndrome = 1;
	} else {
		sts.errno = recovery_download_uart();
		sts.syndrome = 0;
	}

	if (sts.errno)
		return sts;

	sts.boot2img = BOOTSTAGE_JMP_BOOT2IMG;

	return sts;
}
