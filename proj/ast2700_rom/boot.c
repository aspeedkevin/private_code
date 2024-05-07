#include <boot.h>
#include <bootstage.h>
#include <csr.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <drivers/wdt.h>
#include <io.h>
#include <lib/printf.h>
#include <platform.h>
#include <rom_context.h>
#include <types.h>

static void abr_recovery_prepare(void)
{
	uint32_t otp_conf;
	uint32_t hw_strap2;
	uint32_t scu1_rst_log0;
	uint32_t abr_flags;
	uint32_t reg;

	otp_conf = readl(SCU1_OTPCFG_03_02);
	hw_strap2 = readl(SCU1_HWSTRAP2);
	abr_flags = readl(WDT_ABR(WDT_DEVA));
	scu1_rst_log0 = readl(SCU1_RSTLOG0);

	if (otp_conf & OTPCFG2_DIS_RECOVERY_MODE)
		return;

	if (!(hw_strap2 & SCU1_HWSTRAP2_ABR))
		return;

	if ((abr_flags & WDT_ABR_INDICATOR) &&
	    (scu1_rst_log0 & SCU1_RSTLOG0_ABR) &&
	    !(hw_strap2 & SCU1_HWSTRAP2_ABR_REC_DIS)) {
		wdt_disable(WDT_DEVA);

		/* When partition B cannot boot up, recovery mode
		 * should be triggered after WDTA timeout occurs.
		 */
		reg = readl(SCU1_HWSTRAP1);
		reg |= SCU1_HWSTRAP1_EN_RECOVERY_BOOT;
		writel(reg, SCU1_HWSTRAP1);

		/* clear ABR indicator */
		writel(WDT_ABR_CLEAR, WDT_ABR(WDT_DEVA));
		/* clear WDTA reset log */
		writel(SCU1_RSTLOG0_ABR, SCU1_RSTLOG0);
	}
}

/*
 * SCU1_010[11]: 0 -> FWSPI, 1 -> eMMC/UFS
 * SCU1_010[23]: 0 -> eMMC, 1 -> UFS
 */
enum boot_mode_type boot_mode(void)
{
	uint32_t dis, strap;

	abr_recovery_prepare();

	dis = readl(SCU1_OTPCFG_03_02);
	strap = readl(SCU1_HWSTRAP1);

	/* check if recovery is disabled by OTP */
	if (!(dis & OTPCFG2_DIS_RECOVERY_MODE)) {
		/* check if recovery is enabled by hwstrap */
		if (strap & SCU1_HWSTRAP1_EN_RECOVERY_BOOT) {
			if ((strap & SCU1_HWSTRAP1_RECOVERY_INTERFACE) == SCU1_HWSTRAP1_RECOVERY_USB)
				return BOOT_USB;
			else if ((strap & SCU1_HWSTRAP1_RECOVERY_INTERFACE) == SCU1_HWSTRAP1_RECOVERY_I2C)
				return BOOT_I2C;
			else if ((strap & SCU1_HWSTRAP1_RECOVERY_INTERFACE) == SCU1_HWSTRAP1_RECOVERY_I3C)
				return BOOT_I3C;
			else
				return BOOT_UART;
		}
	}

	if (strap & SCU1_HWSTRAP1_BOOT_EMMC_UFS) {
		if (strap & SCU1_HWSTRAP1_BOOT_UFS)
			return BOOT_UFS;
		else
			return BOOT_EMMC;
	}

	/* leave FWSPI as default for safety */
	return BOOT_SPI;
}

/*
 * For PFR-integrated solution, BMC must wait for
 * EXTRST# de-assertion. Thus the HW resource can
 * be reclaimed to proceed the execution.
 *
 * In addition, WDT reset de-assertion monitoring
 * is also required. So that modules will not get
 * accessed before they are ready.
 */
bootstage_t boot_extrst_pen(struct rom_context *rom_ctx)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	while (1) {
		/* keep W1C EXTRST# indicator until it gets zero */
		while (readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_EXTRSTN) {
			writel(SCU1_RSTLOG0_EXTRSTN, SCU1_RSTLOG0);
			udelay(1);
		}

		/* perform de-bouncing against button push by triple read */
		udelay(1);
		if (readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_EXTRSTN)
			continue;

		udelay(1);
		if (readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_EXTRSTN)
			continue;

		udelay(1);
		if (readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_EXTRSTN)
			continue;

		break;
	}

	/* keep W1C BMC CPU reset indicator until it gets zero */
	while (readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_BMC_CPU) {
		writel(SCU1_RSTLOG0_BMC_CPU, SCU1_RSTLOG0);
		udelay(1);
	}

	/* For AST2700, external pin strap can only disable CA35.
	 * However, bootmcu is the first executable CPU after powering
	 * on. Thus, when CPU disabled pin strap is enabled, all CPUs
	 * should be disabled, at least, FWSPI flash cannot be accessed.
	 */
	if (sli_get_availability()) {
		if (readl(SCU0_HWSTRAP) & SCU0_HWSTRAP_HWSTRAP_DISCPU) {
			printf("D ");
			while (1)
				;
		}
	}

	return sts;
}

bootstage_t boot_banner(struct rom_context *rom_ctx)
{
	bootstage_t sts;

	sts.errno = rom_ctx->major_ver;
	sts.syndrome = rom_ctx->minor_ver;

	return sts;
}

void boot_fmc(struct rom_context *rom_ctx)
{
	void (*fmc_boot)(void);

	/* disable interrupt before leaving */
	if (rom_ctx->interrupt_mode) {
		csr_clear(mie, MIE_MSI | MIE_MTI | MIE_MEI);
		csr_clear(mip, MIP_MSI | MIP_MTI | MIP_MEI);
		csr_clear(mstatus, MSTATUS_MIE);
	}

	fmc_boot = (void (*)(void))(rom_ctx->fmc_epa);
	fmc_boot();
}
