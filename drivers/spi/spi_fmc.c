// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <drivers/abr.h>
#include <boot.h>
#include <drivers/spi.h>
#include <flash.h>
#include <io.h>
#include <platform.h>

/*
 * The rule of FMC30 is,
 * start_addr <= decoding_range < end_addr.
 */
uint32_t spi_fmc_segment_addr_start(uint32_t reg_val)
{
	return (((reg_val) & 0x0000ffff) << 16);
}

uint32_t spi_fmc_segment_addr_end(uint32_t reg_val)
{
	return (reg_val & 0xffff0000) - 1;
}

uint32_t spi_fmc_segment_addr_val(uint32_t start, uint32_t end)
{
	return ((((start) >> 16) & 0xffff) | ((end + 1) & 0xffff0000));
}

uint8_t spi_fmc_read_status_cmd(uint32_t cs)
{
	uint8_t status;
	uint32_t ce_ctrl_val;
	uint32_t addr_decoding_val;
	uint32_t addr;

	addr_decoding_val = readl(FMC_REG + CE0_ADDR_DECODING + cs * 4);
	addr = spi_fmc_segment_addr_start(addr_decoding_val);

	if (addr < SNOR_SZ_256MB)
		addr = FMC_MEM_L;
	else
		addr = FMC_MEM_H;

	/* Configure to command read mode. */
	ce_ctrl_val = readl(FMC_REG + CE0_CTRL + cs * 4);
	ce_ctrl_val &= FMC_CLK_FREQ_MASK;
	ce_ctrl_val |= (((0x05) << 16) | 0x01);
	writel(ce_ctrl_val, FMC_REG + CE0_CTRL + cs * 4);

	/* Only enable data byte 0. */
	writel(0xfe, FMC_REG + ADDR_DATA_CTRL);

	status = readb(addr);

	/* Restore to normal mode */
	ce_ctrl_val &= FMC_CLK_FREQ_MASK;
	writel(ce_ctrl_val, FMC_REG + CE0_CTRL + cs * 4);

	/* Restore FMC0C to default value. */
	writel(0x0, FMC_REG + ADDR_DATA_CTRL);

	return status;
}

/*
 * If SCU010[24], OTPSTRAP[25], is set, FMC will check
 * SPI flash ready bit before it accesses SPI flash.
 */
void spi_fmc_wait_for_ready(uint32_t cs)
{
	uint8_t status;
	/* timeout after about 512ms with 12.5MHz SPI clock */
	int count = 400000;
	uint32_t scu_wait_for_ready;

	scu_wait_for_ready = readl(SCU1_REG + 0x010) & BIT(24);
	if (scu_wait_for_ready == 0)
		return;

	while (count > 0) {
		status = spi_fmc_read_status_cmd(cs);
		if ((status & BIT(0)) != 0)
			count--;
		else
			break;
	}
}

/*
 * If SCU010[25], OTPSTRAP[26], is set, FMC CS0
 * is set to 4-byte address mode.
 */
static void spi_fmc_addr_mode_init(uint32_t cs, uint32_t flash_sz)
{
	uint32_t scu_addr_mode_val;
	uint32_t fmc_addr_mode_reg;

	scu_addr_mode_val = readl(SCU1_REG + 0x010) & BIT(25);

	if (scu_addr_mode_val != 0 || flash_sz >= SNOR_SZ_32MB) {
		fmc_addr_mode_reg = readl(FMC_REG + ADDR_CTRL);
		fmc_addr_mode_reg |= (0x11 << cs);
		writel(fmc_addr_mode_reg, FMC_REG + ADDR_CTRL);
	}
}

/*
 * Set SPI clock frequency to 12.5MHz.
 * FMC10[27:24] = 4b'0000
 * FMC10[11:8] = 4b'0000
 */
static void spi_fmc_clk_init(uint32_t cs)
{
	uint32_t fmc_clk_ctrl_reg;

	fmc_clk_ctrl_reg = readl(FMC_REG + CE0_CTRL + cs * 4);
	fmc_clk_ctrl_reg &= ~(FMC_CLK_FREQ_MASK);

	writel(fmc_clk_ctrl_reg, FMC_REG + CE0_CTRL + cs * 4);
}

/*
 * SCU030[24:23]
 * 2b'00: 12.5MHz (HCLK / 16)
 * 2b'01: 25MHz (HCLK / 8)
 * 2b'10: 40MHz (HCLK / 5)
 * 2b'11: 50MHz (HCLK / 4)
 */
void spi_fmc_clk_freq_adjust(uint32_t cs)
{
	uint32_t scu_fmc_clk_val;
	uint32_t fmc_clk_ctrl_reg;

	scu_fmc_clk_val = (readl(SCU1_REG + 0x030) & GENMASK(24, 23)) >> 23;
	fmc_clk_ctrl_reg = readl(FMC_REG + CE0_CTRL + cs * 4);
	fmc_clk_ctrl_reg &= ~(FMC_CLK_FREQ_MASK);

	switch (scu_fmc_clk_val) {
	case 0x0:
		fmc_clk_ctrl_reg |= 0x00000000;
		break;
	case 0x1:
		fmc_clk_ctrl_reg |= 0x00000400;
		break;
	case 0x2:
		fmc_clk_ctrl_reg |= 0x00000d00;
		break;
	case 0x3:
		fmc_clk_ctrl_reg |= 0x00000600;
		break;
	default:
		fmc_clk_ctrl_reg |= 0x00000000;
		break;
	}

	writel(fmc_clk_ctrl_reg, FMC_REG + CE0_CTRL + cs * 4);
}

/*
 * SCU flash size: SCU030[15:13]
 * 7: 512MB
 * 6: 256MB
 * 5: 128MB
 * 4: 64MB
 * 3: 32MB
 * 2: 16MB
 * 1: 8MB
 * 0: disabled
 */
uint32_t spi_fmc_get_flash_sz_strap(void)
{
	uint32_t scu_flash_sz;
	uint32_t flash_sz_phy;

	scu_flash_sz = (readl(SCU1_REG + 0x030) >> 13) & 0x7;
	switch (scu_flash_sz) {
	case 0x7:
		flash_sz_phy = SNOR_SZ_512MB;
		break;
	case 0x6:
		flash_sz_phy = SNOR_SZ_256MB;
		break;
	case 0x5:
		flash_sz_phy = SNOR_SZ_128MB;
		break;
	case 0x4:
		flash_sz_phy = SNOR_SZ_64MB;
		break;
	case 0x3:
		flash_sz_phy = SNOR_SZ_32MB;
		break;
	case 0x2:
		flash_sz_phy = SNOR_SZ_16MB;
		break;
	case 0x1:
		flash_sz_phy = SNOR_SZ_8MB;
		break;
	case 0x0:
		flash_sz_phy = SNOR_SZ_UNSET;
		break;
	default:
		flash_sz_phy = SNOR_SZ_UNSET;
		break;
	}

	return flash_sz_phy;
}

void spi_fmc_decoding_range_config(uint32_t cs,
				   uint32_t start_addr,
				   uint32_t end_addr)
{
	uint32_t decoding_reg_val;

	decoding_reg_val = spi_fmc_segment_addr_val(start_addr, end_addr);

	writel(decoding_reg_val, FMC_REG + CE0_ADDR_DECODING + cs * 4);
}

void spi_fmc_decoding_range_early_init(void)
{
	spi_fmc_decoding_range_config(0, 0, SNOR_SZ_256MB);
	spi_fmc_decoding_range_config(1, SNOR_SZ_256MB, SNOR_SZ_256MB * 2);
	spi_fmc_decoding_range_config(2, 0, 0);
}

void spi_fmc_init_f(uint32_t cs)
{
	uint32_t flash_sz;

	flash_sz = spi_fmc_get_flash_sz_strap();

	spi_fmc_decoding_range_early_init();
	spi_fmc_addr_mode_init(cs, flash_sz);
	spi_fmc_clk_init(cs);
	spi_fmc_wait_for_ready(cs);
}

int spi_fmc_init_r(uint32_t cs, uint32_t abr_enabled, uint32_t auxpin_abr_enabled, uint32_t abr_single)
{
	int ret = 0;
	uint32_t flash_sz;
	struct decoding_range ce_decoding_range[2];

	flash_sz = spi_fmc_get_flash_sz_strap();

	/* Config address mode according to flash size. */
	spi_fmc_addr_mode_init(cs, flash_sz);

	/* Config address decoding ranges. */
	if (abr_enabled || auxpin_abr_enabled) {
		/*
		 * Don't get abr_mode from the argument abr_info directly
		 * since abr_info is assigned in abr_early_init(), but its
		 * value may be modified in the flash strap.
		 */
		if (abr_single) {
			/* Single flash ABR */
			if (flash_sz == SNOR_SZ_UNSET) {
				ret = (uint8_t)ERROR_INVALID_FLASH_SZ;

				/*
				 * Force to assign an acceptable
				 * address decoding range.
				 */
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = SNOR_SZ_64MB;
				ce_decoding_range[1].start_addr = 0x0;
				ce_decoding_range[1].end_addr = 0x0;
			} else {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = flash_sz;
				ce_decoding_range[1].start_addr = 0x0;
				ce_decoding_range[1].end_addr = 0x0;
			}
		} else {
			/* Dual flash ABR */
			if (flash_sz == SNOR_SZ_UNSET) {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = SNOR_SZ_256MB;
				ce_decoding_range[1].start_addr = SNOR_SZ_256MB;
				ce_decoding_range[1].end_addr = SNOR_SZ_256MB * 2;

			} else {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = flash_sz;
				ce_decoding_range[1].start_addr = flash_sz;
				ce_decoding_range[1].end_addr = flash_sz * 2;
			}
		}
	} else {
		if (flash_sz == SNOR_SZ_UNSET) {
			ce_decoding_range[0].start_addr = 0x0;
			ce_decoding_range[0].end_addr = SNOR_SZ_512MB;
		} else {
			ce_decoding_range[0].start_addr = 0x0;
			ce_decoding_range[0].end_addr = flash_sz;
		}

		ce_decoding_range[1].start_addr = 0x0;
		ce_decoding_range[1].end_addr = 0x0;
	}

	spi_fmc_decoding_range_config(0,
				      ce_decoding_range[0].start_addr,
				      ce_decoding_range[0].end_addr);
	spi_fmc_decoding_range_config(1,
				      ce_decoding_range[1].start_addr,
				      ce_decoding_range[1].end_addr);
	/* Always close CS2 window */
	spi_fmc_decoding_range_config(2, 0x0, 0x0);

	spi_fmc_clk_freq_adjust(cs);

	return ret;
}

void fmc_reg_reset_config(void)
{
	uint32_t soc_id;
	uint32_t reg_val;

	soc_id = readl(SCU1_REG) & GENMASK(23, 16);

	/* Unnecessary for AST2700-A0 */
	if (soc_id != 0) {
		reg_val = readl(FMC_REG + FMC_RST_LOCK);
		writel(reg_val | BIT(1), FMC_REG + FMC_RST_LOCK);
	}
}
