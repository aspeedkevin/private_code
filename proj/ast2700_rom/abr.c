#include <drivers/gpio.h>
#include <drivers/wdt.h>
#include <drivers/abr.h>
#include <drivers/scu.h>
#include <io.h>
#include <platform.h>
#include <types.h>

static void aux_abr_gpio_pin_conf(void)
{
	uint32_t reg;

	/* force to change to GPIO mode */
	reg = readl(SCU1_PINMUX_GRP_P);
	reg &= ~(SCU1_PINMUX_PIN7);
	writel(reg, SCU1_PINMUX_GRP_P);

	/* input direction */
	reg = readl(GPIO1_REG + GPIO(P, 7));
	reg &= ~(GPIO_DIRECT);
	writel(reg, GPIO1_REG + GPIO(P, 7));
}

static struct abr g_abr;

static void abr_struct_init(struct abr *abr)
{
	uint32_t hw_strap2;
	uint32_t scu1_rst_log0;
	uint32_t abr_flags;

	hw_strap2 = readl(SCU1_HWSTRAP2);
	scu1_rst_log0 = readl(SCU1_RSTLOG0);
	abr_flags = readl(WDT_ABR(WDT_DEVA));

	abr->enabled = !!(hw_strap2 & SCU1_HWSTRAP2_ABR);
	abr->boot_indicator = !!(abr_flags & WDT_ABR_INDICATOR);
	abr->wdta_triggered = !!(scu1_rst_log0 & SCU1_RSTLOG0_ABR);
	abr->abr_rc_dis = !!(hw_strap2 & SCU1_HWSTRAP2_ABR_REC_DIS);
	abr->single = !!(hw_strap2 & SCU1_HWSTRAP2_FMC_ABR_SINGLE_FLASH);
	abr->auxpin_enabled = !!(hw_strap2 & SCU1_HWSTRAP2_EN_FWSPIAUX);
	abr->auxpin_val = 0;
	abr->boot_cs = 0;
	abr->cs_swap = 0;
}

struct abr *abr_create(struct rom_context *rc)
{
	struct abr *abr = &g_abr;
	uint32_t reg;

	abr_struct_init(abr);

	if (!abr->enabled && !abr->auxpin_enabled)
		return NULL;

	wdt_disable(WDT_DEVA);

	if (abr->auxpin_enabled) {
		aux_abr_gpio_pin_conf();
		abr->auxpin_val = !!(readl(GPIO1_REG + GPIO(P, 7)) & GPIO_DATA_IN);

		if (!abr->auxpin_val) {
			/*
			 * When
			 *   - BMC boots from alternate part (part 1) due to
			 *     external ABR signal,
			 *   - And this signal is cleared since user may want to
			 *     reboot BMC and boot from primary part (part 0),
			 * ABR_EXT_SIGNAL_EN flag on WDT_ABR_CTRL register sould be
			 * cleared, also the ABR indicator.
			 */
			if (readl(WDT_ABR(WDT_DEVA)) & WDT_ABR_EXTSIG_EN) {
				/*
				 * BMC boot from alternate part prevoiusly due
				 * to external signal.
				 */
				writel(WDT_ABR_CLEAR, WDT_ABR(WDT_DEVA));
				abr->boot_indicator = 0;
			}
		} else {
			/* force to boot from alternative part.
			 * no need to trigger WDTA for this scenario.
			 */
			reg = WDT_ABR_INDICATOR | WDT_ABR_EXTSIG_EN;
			writel(reg, WDT_ABR(WDT_DEVA));
			abr->boot_indicator = 1;

			if (abr->wdta_triggered) {
				/* clear WDTA reset log */
				writel(SCU1_RSTLOG0_ABR, SCU1_RSTLOG0);
			}

			return &g_abr;
		}
	}

	/* ABR is triggered due to WDTA timeout */
	if (abr->wdta_triggered) {
		/* get the original boot part after each reset. */
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

		/* clear WDTA reset log */
		writel(SCU1_RSTLOG0_ABR, SCU1_RSTLOG0);
	}

	if (abr->enabled) {
		/* 40 seconds */
		wdt_enable(WDT_DEVA, 0x2625A00);
	}

	return &g_abr;
}
