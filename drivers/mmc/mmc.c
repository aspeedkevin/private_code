// SPDX-License-Identifier: GPL-2.0+
#include <drivers/mmc.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <io.h>
#include <lib/delay.h>
#include <lib/printf.h>
#include <lib/string.h>
#include <otp_mem.h>
#include <platform.h>
#include <utils.h>

#define MMC_BLOCK_LENGTH			(0x200)
#define MMC_BOOT_DMA_TMO			(1000 * 1000) // max 1 second

#define EB_DMA_ADDR_REG				(EMMC_BOOT_REG + 0x0)
#define EB_DMA_LEN_REG				(EMMC_BOOT_REG + 0x4)
#define EB_INTR_REG				(EMMC_BOOT_REG + 0x8)
#define EB_CONTROL_REG				(EMMC_BOOT_REG + 0xc)

#define SCU_RESET2_CONTROL_REG			(0x12c02200)
#define SCU_RESET2_CLR_REG			(0x12c02204)
#define SCU_RESET2_EMMC_BIT			BIT(17)
#define SCU_STOP_SET_REG			(0x12c02240)
#define SCU_STOP_CLR_REG			(0x12c02244)
#define SCU_STOP_EMMC_BIT			BIT(27)

#define EMMC_BLKCNT_SZ_REG			(EMMC_REG + 0x04)
#define EMMC_ARGUMENT_REG			(EMMC_REG + 0x08)
#define EMMC_COMMAND_REG			(EMMC_REG + 0x0c)
#define EMMC_RESPONSE_REG			(EMMC_REG + 0x10)
#define EMMC_PRESENT_REG			(EMMC_REG + 0x24)
#define EMMC_HOST_CONTROL_0_REG			(EMMC_REG + 0x28)
#define EMMC_HOST_CONTROL_1_REG			(EMMC_REG + 0x2c)
#define EMMC_INT_STATUS_REG			(EMMC_REG + 0x30)
#define EMMC_INT_STATUS_EN_REG			(EMMC_REG + 0x34)
#define EMMC_INT_SIGNAL_EN_REG			(EMMC_REG + 0x38)

#define SDHCI_DATA_0_LVL_MASK			0x00100000

#define EMMC_INT_CMD_DONE			(BIT(0))
#define EMMC_INT_DATA_DONE			(BIT(1))

#define MMC_CMD_TIMEOUT				(3000) // 3ms
#define MMC_DATA_TIMEOUT			(30000) // 30ms

#define EMMC_GPIO_REG				(0x12c02400)
#define AST_GPIOG3_BASE				(0x14c0b24c)
#define EMMC_HW_RST_PIN				AST_GPIOG3_BASE

#define EMMC_INIT_FREQUENCY			(0xefa07)

int mmc_boot_read(uint64_t dma_addr, uint32_t dma_len)
{
	uint32_t val, upper, lower, length;
	int ret = 0;

	lower = dma_addr & 0xffffffff;
	upper = dma_addr >> 32;
	length = (upper << MMC_BOOT_DMA_UPPER_ADDR_OFFSET) | dma_len;

	writel(lower, EB_DMA_ADDR_REG);
	writel(length, EB_DMA_LEN_REG);

	val = MMC_BOOT_ENABLE | MMC_BOOT_MODE | MMC_BOOT_DMA_START;
	writel(val, EB_CONTROL_REG);

	ret = readl_poll_timeout(EB_INTR_REG, val,
				 (val & (MMC_BOOT_ERROR | MMC_BOOT_DMA_DONE)), 30, MMC_BOOT_DMA_TMO);
	if (ret)
		return ret;

	writel(MMC_BOOT_ERROR | MMC_BOOT_DMA_DONE, EB_INTR_REG);

	if (val & MMC_BOOT_ERROR)
		return MMC_BOOT_ERROR;

	return ret;
}

int mmc_switch_part(int part)
{
	uint32_t val;
	int i;

	/* cmd 0 */
	writel(0, EMMC_ARGUMENT_REG);
	writel(0, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
		return 1;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

	for (i = 0; i < 50; i++) {
		/* cmd 1 */
		writel(0x407f8080, EMMC_ARGUMENT_REG);
		writel(0x01020000, EMMC_COMMAND_REG);
		if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
				       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
			return 1;

		writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

		if (readl(EMMC_RESPONSE_REG) & 0x80000000)
			break;
	}

	if (i >= 50)
		return 0xf;

	/* cmd 2 */
	writel(0x00000000, EMMC_ARGUMENT_REG);
	writel(0x02090000, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
		return 2;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

	/* cmd 3 */
	writel(0x00010000, EMMC_ARGUMENT_REG);
	writel(0x031a0000, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
		return 3;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

	/* cmd 9 */
	writel(0x00010000, EMMC_ARGUMENT_REG);
	writel(0x09090000, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
		return 9;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

	/* cmd 7 */
	writel(0x00010000, EMMC_ARGUMENT_REG);
	writel(0x071a0000, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT))
		return 7;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);

	if (part == 0)
		/* cmd 6 switch part1*/
		writel(0x03b34900, EMMC_ARGUMENT_REG);
	else if (part == 1)
		/* cmd 6 switch part1*/
		writel(0x03b35200, EMMC_ARGUMENT_REG);
	else
		return 0xe;

	writel(0x061b0012, EMMC_COMMAND_REG);
	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & (EMMC_INT_CMD_DONE | EMMC_INT_DATA_DONE)), 10, MMC_DATA_TIMEOUT))
		return 6;

	writel(EMMC_INT_CMD_DONE | EMMC_INT_DATA_DONE, EMMC_INT_STATUS_REG);

	if (readl_poll_timeout(EMMC_PRESENT_REG, val,
			       (val & SDHCI_DATA_0_LVL_MASK), 10, MMC_DATA_TIMEOUT))
		return 0xa;

	return 0;
}

void mmc_rst_n_assert(void)
{
	/*
	 * GPIOG5 as the emmc hw rst_n
	 * bit1: direction. (0:input, 1:output)
	 * bit0: val
	 */
	writel(2, EMMC_HW_RST_PIN);
	udelay(5);
}

void mmc_rst_n_deassert(void)
{
	writel(3, EMMC_HW_RST_PIN);
	mdelay(1);
}

void mmc_hw_reset(void)
{
	mmc_rst_n_assert();
	mmc_rst_n_deassert();
}

void mmc_sw_reset(void)
{
	uint32_t val;

	/* send cmd0(0xf0f0f0f0) */
	writel(0xf0f0f0f0, EMMC_ARGUMENT_REG);
	writel(0, EMMC_COMMAND_REG);
	readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			   (val & EMMC_INT_CMD_DONE), 10, MMC_CMD_TIMEOUT);

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);
	mdelay(1);
}

void sdhci_init(void)
{
	/* quit emmc boot mode */
	writel(0, EB_CONTROL_REG);
	writel(0, EB_DMA_ADDR_REG);
	writel(0, EB_DMA_LEN_REG);
	writel(0xffff, EB_INTR_REG);

	/* configure emmc gpio */
	writel(0xfff, EMMC_GPIO_REG);

	/* disable scu stop emmc */
	writel(SCU0_CLKGATE1_CLR_EMMC, SCU0_CLKGATE1_CLR);

	/* emmc top reset assert */
	writel(SCU0_RSTCTL1_EMMC, SCU0_RSTCTL1);
	udelay(5);

	/* emmc top reset deassert*/
	writel(SCU0_RSTCTL1_CLR_EMMC, SCU0_RSTCTL1_CLR);
	udelay(5);

	/* enable emmc power */
	writel(0xf00, EMMC_HOST_CONTROL_0_REG);

	/* enable clock lower than 400Khz */
	writel(EMMC_INIT_FREQUENCY, EMMC_HOST_CONTROL_1_REG);

	/* enable status */
	writel(0x27f003b, EMMC_INT_STATUS_EN_REG);

	mmc_rst_n_deassert();
}

void mmc_bring_to_default(void)
{
	/* quit emmc boot mode */
	writel(0, EB_CONTROL_REG);
	writel(0, EB_DMA_ADDR_REG);
	writel(0, EB_DMA_LEN_REG);
	writel(0xffff, EB_INTR_REG);

	/* assert emmc top reset as default */
	writel(SCU_RESET2_EMMC_BIT, SCU_RESET2_CONTROL_REG);
	udelay(5);

	/* scu stop emmc */
	writel(SCU_STOP_EMMC_BIT, SCU_STOP_SET_REG);
}

int mmc_boot_start(uint32_t wdta_triggered, uint32_t boot_indicator)
{
	int err = 0, sw_rst_en = 0, switch_part_en = 0;
	uint32_t i, blks;
	uint16_t cfg = 0;

	otp_read_data(OTPCFG2, &cfg);
	if (cfg & OTPCFG2_EN_EMMC_SW_RST)
		sw_rst_en = 1;

	if (wdta_triggered)
		switch_part_en = 1;

	if (sw_rst_en || switch_part_en) {
		/*
		 * Init SDHCI accordingly for switch part or sw reset
		 */
		sdhci_init();

		if (switch_part_en) {
			err = mmc_switch_part(boot_indicator);
			if (err)
				goto Err;
		}

		/*
		 * In case there is no GPIO for emmc hw rst_n,
		 * perform a sw reset according to otp conf.
		 */
		if (sw_rst_en)
			mmc_sw_reset();

		mmc_bring_to_default();
	}

	/*
	 * start emmc boot from hw_rst_n toggling
	 */
	mmc_hw_reset();

	/*
	 * emmc boot enter to boot mode to pull low cmd line.
	 */
	blks = ECC_SRAM_SZ / MMC_BLOCK_LENGTH;
	for (i = 0; i < blks; i++) {
		err = mmc_boot_read(ECC_SRAM_MEM + i * MMC_BLOCK_LENGTH, MMC_BLOCK_LENGTH);
		if (err)
			goto Err;
	}

	return 0;

Err:
	mmc_bring_to_default();
	return err;
}

void mmc_boot_copy(void)
{
	/*
	 * All the boot code(RAM code) and flash strap are located at CPU SRAM(128K).
	 * Only copy 88K boot code to IO SRAM
	 */
	memmove((void *)SRAM_MEM, (void *)ECC_SRAM_MEM, CONFIG_RAM_CODE_LOAD_SIZE);
}
