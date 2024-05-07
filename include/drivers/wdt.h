#ifndef __WDT_H__
#define __WDT_H__

#include <bootstage.h>
#include <rom_context.h>
#include <utils.h>
#include <types.h>

#define WDT_CNT_RELOAD(x)		(WDT_REG + ((x) * 0x80) + 0x04)
#define WDT_CNT_RESTART(x)		(WDT_REG + ((x) * 0x80) + 0x08)
#define WDT_CTRL(x)			(WDT_REG + ((x) * 0x80) + 0x0c)
#define   WDT_CTRL_RESET_BY_SOCRST	BIT(4)
#define   WDT_CTRL_RESET_SYS		BIT(1)
#define   WDT_CTRL_EN			BIT(0)
#define WDT_RSTMASK1(x)			(WDT_REG + ((x) * 0x80) + 0x1c)
#define WDT_RSTMASK2(x)			(WDT_REG + ((x) * 0x80) + 0x20)
#define WDT_RSTMASK3(x)			(WDT_REG + ((x) * 0x80) + 0x24)
#define WDT_RSTMASK4(x)			(WDT_REG + ((x) * 0x80) + 0x28)
#define WDT_RSTMASK5(x)			(WDT_REG + ((x) * 0x80) + 0x2c)
#define WDT_SW_RSTMASK1(x)		(WDT_REG + ((x) * 0x80) + 0x34)
#define WDT_SW_RSTMASK2(x)		(WDT_REG + ((x) * 0x80) + 0x38)
#define WDT_SW_RSTMASK3(x)		(WDT_REG + ((x) * 0x80) + 0x3c)
#define WDT_SW_RSTMASK4(x)		(WDT_REG + ((x) * 0x80) + 0x40)
#define WDT_SW_RSTMASK5(x)		(WDT_REG + ((x) * 0x80) + 0x44)
#define WDT_SCRATCH(x)			(WDT_REG + ((x) * 0x80) + 0x4c)
#define WDT_ABR(x)			WDT_SCRATCH(x)	/* alias */
#define   WDT_ABR_EXTSIG_EN		BIT(2)
#define   WDT_ABR_INDICATOR		BIT(1)
#define   WDT_ABR_FMC_CS_SWAP		BIT(0)

#define WDT_RESTART_KEY		0x4755
#define WDT_ABR_CLEAR		0xea000000

#define WDT_RSTMASK_1_VAL	0x0203e779
#define WDT_RSTMASK_2_VAL	0x000003f6
#define WDT_RSTMASK_3_VAL	0x000093ec
#define WDT_RSTMASK_4_VAL	0x00303803
#define WDT_RSTMASK_5_VAL	0x00020000

enum wdt_device {
	WDT_DEV0,
	WDT_DEV1,
	WDT_DEV2,
	WDT_DEV3,
	WDT_DEV4,
	WDT_DEV5,
	WDT_DEV6,
	WDT_DEV7,
	WDT_DEVA,

	WDT_DEVS
};

enum wdt_errno {
    WDT_ERR_SUCCESS,
};

void wdt_enable(uint32_t dev_id, uint32_t timeout_us);
void wdt_disable(uint32_t dev_id);

bootstage_t wdt_rstmask_init(struct rom_context *rom_ctx);

#endif
