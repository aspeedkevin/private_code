#include <boot.h>
#include <bootstage.h>
#include <drivers/gpio.h>
#include <drivers/wdt.h>
#include <drivers/scu.h>
#include <drivers/spi.h>
#include <flash.h>
#include <io.h>
#include <lib/string.h>
#include <types.h>

struct flash_spi_abr {
	uint32_t enabled;
	uint32_t boot_indicator;
	uint32_t wdta_triggered;
	uint32_t single;
	uint32_t auxpin_enabled;
	uint32_t auxpin_val;
	uint32_t boot_cs;
	uint32_t cs_swap;
};

struct flash_spi_context {
	uint32_t bootmode;
	struct flash_spi_abr abr;
};

static struct flash_spi_context flash_spi[1];

static void flash_spi_abr_init_f(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	struct flash_spi_abr *abr = &flash_spi->abr;
	uint32_t reg, abr_flag;

	/*
	 * ABR can be enabled by two methods:
	 *     - ABR enabled bit in OTP Flash strap.
	 *     - AUX pin strap and externl ABR signal.
	 */
	reg = readl(SCU1_HWSTRAP2);
	abr->enabled = !!(reg & SCU1_HWSTRAP2_ABR);
	abr->auxpin_enabled = !!(reg & SCU1_HWSTRAP2_EN_FWSPIAUX);
	if (!abr->enabled && !abr->auxpin_enabled)
		return;

	bootstage_prologue(BOOTSTAGE_ABR_EARLY_INIT);

	/* disable WDTA first. */
	wdt_disable(WDT_DEVA);

	abr->single = !!(reg & SCU1_HWSTRAP2_FMC_ABR_SINGLE_FLASH);
	abr->boot_cs = 0;
	abr->cs_swap = 0;

	/* get the external auxpin input (GPIOP7) */
	if (abr->auxpin_enabled)
		abr->auxpin_val = !!(readl(GPIO1_REG + GPIO(P, 7)) & GPIO_DATA_IN);

	/*
	 * When
	 *   - BMC boots from alternate flash part (CS1) due to
	 *     external ABR signal,
	 *   - And this signal is cleared since user may want to
	 *     reboot BMC and boot from primary flash part (CS0),
	 * ABR_EXT_SIGNAL_EN flag on WDT_ABR_CTRL register sould be
	 * cleared, also the ABR indicator.
	 */
	if (abr->auxpin_enabled && !abr->auxpin_val) {
		reg = readl(WDT_ABR(WDT_DEVA));
		abr_flag = !!(reg & WDT_ABR_EXTSIG_EN);
		if (abr_flag) {
			/*
			 * BMC boot from alternate part prevoiusly due
			 * to external signal.
			 */
			writel(WDT_ABR_CLEAR, WDT_ABR(WDT_DEVA));
		}
	}

	/* get the original boot part after each reset. */
	reg = readl(WDT_ABR(WDT_DEVA));
	abr->boot_indicator = !!(reg & WDT_ABR_INDICATOR);

	/* ABR is triggered due to WDTA timeout */
	reg = readl(SCU1_RSTLOG0);
	if (reg & SCU1_RSTLOG0_ABR) {
		if (abr->boot_indicator) {
			/*
			 * indicator is set before.
			 * clear ABR indicator and CS swap bit.
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
	 * force to boot from alternative part.
	 * if FWSPI auxpin setting is stored in flash strap,
	 * external ABR signal will take effect after warm reset.
	 */
	if (abr->auxpin_enabled && abr->auxpin_val) {
		reg = WDT_ABR_INDICATOR | WDT_ABR_EXTSIG_EN;
		writel(reg, WDT_ABR(WDT_DEVA));
		abr->boot_indicator = 1;
	}

	if (!abr->single && abr->boot_indicator) {
		reg = readl(SCU1_HWSTRAP2);
		if (reg & SCU1_HWSTRAP2_FMC_ABR_CS_SWAP_DIS) {
			abr->cs_swap = 0;
			abr->boot_cs = 1;
		} else {
			abr->cs_swap = 1;
			abr->boot_cs = 0;
		}
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

	if (abr->single) {
		sts.errno |= BIT(5);
	}
	else {
		sts.errno |= BIT(7);
		if (abr->cs_swap)
			sts.errno |= BIT(6);
		else if (abr->boot_cs)
			sts.errno |= BIT(5);
	}

	/* handle the scenario where only AUX pin is enabled */
	if (!abr->enabled && abr->auxpin_enabled && !abr->auxpin_val)
		sts.errno = 0x0;

	bootstage_epilogue(sts);
}

static void flash_spi_abr_init_r(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	struct flash_spi_abr *abr = &flash_spi->abr;

	if (!abr->enabled && !abr->auxpin_enabled)
		return;

	bootstage_prologue(BOOTSTAGE_ABR_POST_INIT);

	if (!(abr->auxpin_enabled && abr->auxpin_val)) {
		wdt_enable(WDT_DEVA, 0x14FB180); /* 22 seconds */
		sts.errno |= 0x10;
	}

	bootstage_epilogue(sts);
}

int flash_spi_strap_read(uint16_t fs_val[8])
{
	struct flash_spi_abr *abr = &flash_spi->abr;
	struct flash_strap fs;
	uint32_t csum;
	uint32_t *p;
	int i;

	if (abr->boot_indicator != 0)
		return ERR_STRAP_INVALID_BOOT_TYPE;

	memcpy(&fs, (void *)(FMC_MEM_L + FLASH_STRAP_OFFSET), sizeof(fs));

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

void flash_spi_init_f(void)
{
	struct flash_spi_abr *abr;
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	memset(flash_spi, 0, sizeof(flash_spi));

	flash_spi->bootmode = boot_mode();

	abr = &flash_spi->abr;

	flash_spi_abr_init_f();

	bootstage_prologue(BOOTSTAGE_FLASH_EARLY_INIT);

	sts.errno |= (flash_spi->bootmode << 4);
	spi_fmc_init_f(abr->boot_cs);

	bootstage_epilogue(sts);
}

void flash_spi_init_r(void)
{
	struct flash_spi_abr *abr = &flash_spi->abr;
	bootstage_t sts;

	bootstage_prologue(BOOTSTAGE_FLASH_POST_INIT);

	sts.errno = spi_fmc_init_r(abr->boot_cs, abr->enabled,
				   abr->auxpin_enabled & abr->auxpin_val,
				   abr->single);
	sts.errno = (sts.errno & 0xf) | (flash_spi->bootmode << 4);

	bootstage_epilogue(sts);

	flash_spi_abr_init_r();
}

void flash_spi_image_load(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	struct flash_spi_abr *abr = &flash_spi->abr;
	uint32_t ce_decoding_range;
	uint32_t ofst = 0;

	bootstage_prologue(BOOTSTAGE_FLASH_COPY);

	sts.errno = flash_spi->bootmode << 4;

	if (abr->single) {
		/* Get CE0 decoding range. */
		ce_decoding_range = readl(FMC_REG + CE0_ADDR_DECODING);
		ofst = spi_fmc_segment_addr_end(ce_decoding_range) + 1;
		ofst = ofst / 2;
	} else {
		/* Get CE1 decoding range. */
		ce_decoding_range = readl(FMC_REG + CE0_ADDR_DECODING + 4);
		ofst = spi_fmc_segment_addr_start(ce_decoding_range);
	}

	/*
	 * From RV view, when the SPI flash accessed offset
	 * is greater than 256MB, RV should access the other
	 * FMC memory address space, FMC_MEM_H.
	 */
	if (ofst < SNOR_SZ_256MB) {
		memcpy((void *)CONFIG_RAM_CODE_LOAD_ADDR, (void *)(FMC_MEM_L + ofst),
		       CONFIG_RAM_CODE_LOAD_SIZE);
	} else {
		ofst -= SNOR_SZ_256MB;
		memcpy((void *)CONFIG_RAM_CODE_LOAD_ADDR, (void *)(FMC_MEM_H + ofst),
		       CONFIG_RAM_CODE_LOAD_SIZE);
	}

	bootstage_epilogue(sts);
}
