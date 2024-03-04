// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <boot.h>
#include <bootstage.h>
#include <drivers/ltpi.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <drivers/wdt.h>
#include <flash.h>
#include <io.h>
#include <lib/console.h>
#include <lib/string.h>
#include <platform.h>
#include <recovery.h>
#include <rom_patch.h>
#include <syscon_init.h>

/*
 * A0 workaround: Holding ROM by EXTRST# is
 * emulated by SW ROM.
 *
 * For PFR-integrated solution, BMC must wait for
 * EXTRST# de-assertion. Thus the HW resource can
 * be reclaimed to proceed the execution.
 *
 * In addition, WDT reset de-assertion monitoring
 * is also required. So that modules will not get
 * accessed before they are ready.
 */
static bootstage_t wait_for_extrst_deassert(void)
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

	return sts;
}

static bootstage_t rom_banner(void)
{
	bootstage_t sts;

	sts.errno = BOOTSTAGE_ERR_SUCCESS;
	sts.syndrome = 0;

	return sts;
}

struct rom_init_func {
	char *bootstage_mark;
	bootstage_t (*init_func)(void);
};

struct rom_init_func rom_init_seqs[] = {
	{ NULL,					rom_patch_f			},	/* early patch if needed */
	{ NULL,					console_init			},	/* init console uart */
	{ NULL,					bootstage_init			},	/* init bootstage prologue/epilogue use */
	{ BOOTSTAGE_BANNER,			rom_banner			},	/* start ROM journey */
	{ BOOTSTAGE_SLI_INIT,			sli_init			},	/* check SLI availability */
	{ BOOTSTAGE_RECOVERY,			recovery_boot			},	/* recovery boot from UART/USB */
	{ BOOTSTAGE_WDT_INIT,			wdt_rstmask_init		},	/* A0: init WDT reset mask */
	{ BOOTSTAGE_OTPSTRAP_INIT_F,		scu_otpstrap_init_f		},	/* init SCU strap registers from OTP */
	{ BOOTSTAGE_LTPI_INIT,			ltpi_init			},	/* init LTPI, which is mandatory for PFR to go */
	{ BOOTSTAGE_WAIT_EXTRST_DEASSERT,	wait_for_extrst_deassert	},	/* A0: wait for EXTRST# de-assertion on PFR-existed scheme */
	{ BOOTSTAGE_FLASH_INIT_F,		flash_init_f			},	/* top-half init of flash to get flash strap */
	{ BOOTSTAGE_OTPSTRAP_INIT_R,		scu_otpstrap_init_r		},	/* update SCU strap registers from flash */
	{ BOOTSTAGE_SYSCON_DBGCTL_INIT,		scu_dbgctrl_init		},	/* init SCU debug control */
	{ BOOTSTAGE_FLASH_INIT_R,		flash_init_r			},	/* bottom-half init of flash to load RAM image */
	{ BOOTSTAGE_SYSCON_PINMUX_INIT,		scu_pinmux_init			},	/* A0: init pinmux to align the future design */
	{ BOOTSTAGE_SYSCON_RSTLOG_INIT,		scu_rstlog_init			},	/* init reset log for later use */
	{ BOOTSTAGE_ROMPATCH_R,			rom_patch_r			},	/* post patch if needed */
	{ BOOTSTAGE_FLASH_IMAGE_LOAD,		flash_image_load		},	/* copy next image from flash */

	/* end of init sequence */
	{ NULL,	NULL},
};

int main(void)
{
	bootstage_t sts;
	struct rom_init_func *f;

	for (f = rom_init_seqs; f && f->init_func; f++) {
		if (f->bootstage_mark)
			bootstage_prologue(f->bootstage_mark);

		sts = f->init_func();

		if (f->bootstage_mark)
			bootstage_epilogue(sts);

		/*
		 * this init function intends to boot next image
		 * without further initialization. USE WISELY!
		 */
		if (sts.boot2img == BOOTSTAGE_JMP_BOOT2IMG)
		    break;
	}

	/* init done, jump to next image */
	sts.errno = BOOTSTAGE_ERR_SUCCESS;
	sts.syndrome = 0;

	bootstage_prologue(BOOTSTAGE_JUMP_IMAGE);
	bootstage_epilogue(sts);
	boot_image();

	return 0;
}
