#include <boot.h>
#include <bootstage.h>
#include <drivers/gpio.h>
#include <drivers/mmc.h>
#include <drivers/wdt.h>
#include <drivers/scu.h>
#include <drivers/spi.h>
#include <flash.h>
#include <io.h>
#include <lib/string.h>
#include <types.h>

struct flash_mmc_abr {
	uint32_t enabled;
	uint32_t boot_indicator;
	uint32_t wdta_triggered;
};

struct flash_mmc_context {
	uint32_t bootmode;
	struct flash_mmc_abr abr;
};

static struct flash_mmc_context flash_mmc[1];

static void flash_mmc_abr_init_f(void)
{
	struct flash_mmc_abr *abr = &flash_mmc->abr;
	uint32_t reg;
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	reg = readl(SCU1_HWSTRAP2);
	abr->enabled = !!(reg & SCU1_HWSTRAP2_ABR);
	if (!abr->enabled)
		return;

	bootstage_prologue(BOOTSTAGE_ABR_EARLY_INIT);

	/* disable WDTA first. */
	wdt_disable(WDT_DEVA);

	/* get the original boot part after each reset. */
	reg = readl(WDT_ABR(WDT_DEVA));
	abr->boot_indicator = !!(reg & WDT_ABR_INDICATOR);

	/* ABR is triggered due to WDTA timeout */
	reg = readl(SCU1_RSTLOG0);
	if (reg & SCU1_RSTLOG0_ABR) {
		if (abr->boot_indicator) {
			/*
			 * indicator is set before.
			 * clear ABR indicator
			 */
			writel(WDT_ABR_CLEAR, WDT_ABR(WDT_DEVA));
			abr->boot_indicator = 0;
		} else {
			/*
			 * indicator is NOT set before.
			 * set ABR indicator.
			 */
			writel(WDT_ABR_INDICATOR, WDT_ABR(WDT_DEVA));
			abr->boot_indicator = 1;
		}

		abr->wdta_triggered = 1;

		/* clear WDTA reset log */
		writel(SCU1_RSTLOG0_ABR, SCU1_RSTLOG0);
	}

	/*
	 * sts[3] = 1b'1: WDTA is triggerred
	 * sts[4] = 1b'1: boot indicator
	 * sts[5] = 1b'1: single SPI flash ABR
	 * sts[7] = 1b'1: dual flash ABR
	 *     - sts[6]    = 1b'1 : CS swap
	 *     - sts[6][5] = 2b'11: boot from CS1
	 */
	if (abr->wdta_triggered)
		sts.errno |= BIT(3);

	if (abr->boot_indicator)
		sts.errno |= BIT(4);

	bootstage_epilogue(sts);
}

static void flash_mmc_abr_init_r(void)
{
	struct flash_mmc_abr *abr = &flash_mmc->abr;
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	if (!abr->enabled)
		return;

	bootstage_prologue(BOOTSTAGE_ABR_POST_INIT);

	wdt_enable(WDT_DEVA, 0x14FB180); /* 22 seconds */
	sts.errno |= 0x10;

	bootstage_epilogue(sts);
}

int flash_mmc_strap_read(uint16_t fs_val[8])
{
	struct flash_mmc_abr *abr = &flash_mmc->abr;
	struct flash_strap fs;
	uint32_t csum;
	uint32_t *p;
	int i;

	if (abr->boot_indicator != 0)
		return ERR_STRAP_INVALID_BOOT_TYPE;

	memcpy(&fs, (void *)(SRAM_MEM + FLASH_STRAP_OFFSET), sizeof(fs));

	if (fs.magic != FLASH_STRAP_MAGIC)
		return ERR_STRAP_INCORRECT_MAGIC;

	if (fs.size != FLASH_STRAP_SZ)
		return ERR_STRAP_INCORRECT_SZ;

	if (fs.algo != FLASH_STRAP_ALG_TYPE)
		return ERR_STRAP_INCORRECT_ALG;

	csum = 0;
	p = (uint32_t *)&fs.fs_val[0];
	for (i = 0; i < 8; ++i)
		csum += p[i];

	if (fs.csum != csum)
		return ERR_STRAP_INVALID_CHECKSUM;

	memcpy(fs_val, fs.fs_val, sizeof(fs.fs_val));

	return 0;
}

void flash_mmc_init_f(void)
{
	struct flash_mmc_abr *abr = &flash_mmc->abr;
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	flash_mmc_abr_init_f();

	bootstage_prologue(BOOTSTAGE_FLASH_EARLY_INIT);

	sts.errno = mmc_boot_start(abr->wdta_triggered, abr->boot_indicator) & 0xf;
	sts.errno |= (flash_mmc->bootmode << 4);

	bootstage_epilogue(sts);
}

void flash_mmc_init_r(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	bootstage_prologue(BOOTSTAGE_FLASH_POST_INIT);

	sts.errno = (flash_mmc->bootmode << 4);

	bootstage_epilogue(sts);

	flash_mmc_abr_init_r();
}

void flash_mmc_image_load(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	sts.errno = flash_mmc->bootmode << 4;

	bootstage_prologue(BOOTSTAGE_FLASH_COPY);

	memmove((void *)CONFIG_RAM_CODE_LOAD_ADDR, (void *)SRAM_MEM, CONFIG_RAM_CODE_LOAD_SIZE);

	bootstage_epilogue(sts);
}
