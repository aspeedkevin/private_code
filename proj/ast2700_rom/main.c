#include <boot.h>
#include <bootdev.h>
#include <bootstage.h>
#include <caliptra.h>
#include <console_uart.h>
#include <csr.h>
#include <drivers/ltpi.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <drivers/wdt.h>
#include <drivers/ahbc.h>
#include <drivers/usb.h>
#include <fmc_verify.h>
#include <fw_load.h>
#include <io.h>
#include <lib/rand.h>
#include <lib/string.h>
#include <otp_init.h>
#include <panic.h>
#include <platform.h>
#include <recovery.h>
#include <rng.h>
#include <rom_context.h>
#include <rom_integrity.h>
#include <rom_patch.h>
#include <syscon.h>
#include <sec_vault.h>

struct rom_init_func {
	char *bootstage_mark;
	bootstage_t (*init_func)(struct rom_context *rom_ctx);
};

struct rom_init_func rom_init_seqs[] = {
	{ BOOTSTAGE_BANNER,			boot_banner			},	/* start the ROM boot journey */
	{ BOOTSTAGE_TRNG_INIT,			rng_init			},	/* init RNG */
	{ BOOTSTAGE_OTP_INIT_IO,		otp_init_io			},	/* init OTP for IO-die */
	{ BOOTSTAGE_ROMPATCH_F,			rom_patch_f			},	/* early patch if needed */
	{ BOOTSTAGE_USB_UART,			usb2uart_init			},	/* init usb to uart */
	{ BOOTSTAGE_UART_CON,			console_uart_init		},	/* init console uart */
	{ NULL,					bootstage_init			},	/* init bootstage prologue/epilogue use */
	{ BOOTSTAGE_ROM_INTEGRITY,		rom_integrity_check		},	/* check ROM integrity by SHA256 */
	{ BOOTSTAGE_SLI_INIT,			sli_init			},	/* check SLI availability */
	{ BOOTSTAGE_OTP_INIT_CPU,		otp_init_cpu			},	/* init OTP for CPU-die */
	{ BOOTSTAGE_AHBC_INIT,			ahbc_init			},	/* init AHBC */
	{ BOOTSTAGE_WDT_INIT,			wdt_rstmask_init		},	/* init wdt reset mask */
	{ BOOTSTAGE_LTPI_INIT,			ltpi_init			},	/* init LTPI, which is mandatory for PFR to go */
	{ BOOTSTAGE_EXTRST_HOLDING_PEN,		boot_extrst_pen			},	/* wait for EXTRST# de-assertion on PFR-existed scheme */
	{ BOOTSTAGE_BOOTDEV_INIT,		bootdev_init			},	/* init booting device */
	{ BOOTSTAGE_SYSCON_RSTLOG_INIT,		scu_rstlog_init			},	/* init reset log for later use */
	{ BOOTSTAGE_OTP_INIT_REGION,		otp_init_region			},	/* init OTP region */
	{ BOOTSTAGE_SECURE_VAULT,		sec_vault_init			},	/* init secure vault */
	{ BOOTSTAGE_ROMPATCH_R,			rom_patch_r			},	/* post patch if needed */
	{ BOOTSTAGE_FWLOAD_CPTRA,		fw_load_cptra			},	/* firmware load - Caliptra */
	{ BOOTSTAGE_CPTRA_BOOTFSM_BOOT,		cptra_bootfsm_boot		},	/* bring up Caliptra BootFSM */
	{ BOOTSTAGE_CPTRA_ROM_BOOT,		cptra_rom_boot			},	/* bring up Caliptra ROM */
	{ BOOTSTAGE_CPTRA_FW_BOOT,		cptra_fw_boot			},	/* bring up Caliptra FW */
	{ BOOTSTAGE_FWLOAD_FMC,			fw_load_fmc			},	/* firmware load - SoC First Mutable Code */
	{ BOOTSTAGE_SECURE_BOOT,		fmc_verify			},	/* verify FMC secure boot signature */
	{ NULL,					bootdev_deinit			},	/* boot device deinit to restore register */

	/* end of init sequence */
	{ NULL,	NULL},
};

int main(void)
{
	volatile uint32_t dummy;
	struct rom_init_func *f;
	bootstage_t sts;

	struct rom_context rom_ctx[1] = {
		{
			.major_ver = CONFIG_ROM_MAJOR_VER,
			.minor_ver = CONFIG_ROM_MINOR_VER,
			.fmc_epa = CONFIG_FMC_ENTRY_ADDR,
			.fmc_lda = CONFIG_FMC_LOAD_ADDR,
			.fmc_lds = CONFIG_FMC_LOAD_SIZE,
			.cptra_lda = CONFIG_CPTRA_LOAD_ADDR,
			.cptra_lds = CONFIG_CPTRA_LOAD_SIZE,
			.cnsl_base = CONFIG_SYS_CONSOLE_BASE,
			.cptra_boot_fsm = 0,
			.cptra_boot_rom = 0,
			.cptra_boot_fw = 0,
			.cptra_exec_tmout = CONFIG_CPTRA_EXEC_TMOUT,
			.otp = NULL,
			.bootstrap = 0,
			.bd = NULL,
		},
	};

	rom_ctx->interrupt_mode = !!(readl(SCU1_HWSTRAP1) & SCU1_HWSTRAP1_EN_ROM_INT);

	for (f = rom_init_seqs; f && f->init_func; f++) {

		if (f->bootstage_mark)
			bootstage_prologue(f->bootstage_mark);

		sts = f->init_func(rom_ctx);

		/* random delay before next action */
		dummy = rand() % 100000;
		while (dummy--)
			;

		if (f->bootstage_mark)
			bootstage_epilogue(sts);

		/*
		 * this init function intends to boot FMC
		 * without further initialization.
		 *
		 * USE WISELY!
		 */
		if (sts.boot2fmc == BOOTSTAGE_JMP_BOOT2FMC)
			goto boot_fmc;

		/*
		 * this init function indicates an critial error
		 * that ROM must NOT continue to go
		 *
		 * USE WISELY AND CAREFULLY!!!
		 */
		if (sts.panic == BOOTSTAGE_JMP_PANIC)
			goto boot_panic;
	}

boot_fmc:
	/* init done, jump to next image */
	sts.errno = BOOTSTAGE_ERR_SUCCESS;
	sts.syndrome = 0;

	bootstage_prologue(BOOTSTAGE_JUMP_IMAGE);
	bootstage_epilogue(sts);
	boot_fmc(rom_ctx);

boot_panic:
	/* should NEVER reach here */
	panic(rom_ctx);

	return -1;
}
