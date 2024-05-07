#include <drivers/wdt.h>
#include <drivers/scu.h>
#include <io.h>
#include <platform.h>
#include <types.h>

void wdt_enable(uint32_t dev_id, uint32_t timeout_us)
{
	uint32_t ctrl;

	if (dev_id > WDT_DEVS)
		return;

	writel(timeout_us, WDT_CNT_RELOAD(dev_id));
	writel(WDT_RESTART_KEY, WDT_CNT_RESTART(dev_id));

	ctrl = WDT_CTRL_RESET_BY_SOCRST |
	       WDT_CTRL_RESET_SYS |
	       WDT_CTRL_EN;
	writel(ctrl, WDT_CTRL(dev_id));
}

void wdt_disable(uint32_t dev_id)
{
	if (dev_id > WDT_DEVS)
		return;

	writel(0, WDT_CTRL(dev_id));
}

/*
 * Some of HW default values of WDT reset mask are unexpected.
 * These values should be initialized before leaving BROM stage.
 */
bootstage_t wdt_rstmask_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { WDT_ERR_SUCCESS, 0 };
	uint32_t idx, reg;

	reg = readl(SCU1_RSTLOG0);
	if (!(reg & SCU1_RSTLOG0_SRST))
		return sts;

	for (idx = 0; idx < WDT_DEVS; idx++) {
		/* SoC reset mask */
		writel(WDT_RSTMASK_1_VAL, WDT_RSTMASK1(idx));
		writel(WDT_RSTMASK_2_VAL, WDT_RSTMASK2(idx));
		writel(WDT_RSTMASK_3_VAL, WDT_RSTMASK3(idx));
		writel(WDT_RSTMASK_4_VAL, WDT_RSTMASK4(idx));
		writel(WDT_RSTMASK_5_VAL, WDT_RSTMASK5(idx));

		/* SW reset mask */
		writel(WDT_RSTMASK_1_VAL, WDT_SW_RSTMASK1(idx));
		writel(WDT_RSTMASK_2_VAL, WDT_SW_RSTMASK2(idx));
		writel(WDT_RSTMASK_3_VAL, WDT_SW_RSTMASK3(idx));
		writel(WDT_RSTMASK_4_VAL, WDT_SW_RSTMASK4(idx));
		writel(WDT_RSTMASK_5_VAL, WDT_SW_RSTMASK5(idx));
	}

	return sts;
}
