#include <bootdev.h>
#include <csr.h>
#include <drivers/abr.h>
#include <drivers/wdt.h>
#include <fmc_verify.h>
#include <lib/string.h>
#include <panic.h>
#include <platform.h>
#include <rom_context.h>

void panic(struct rom_context *rc)
{
	struct abr *abr = NULL;

	/* disable all interrupts for safety */
	csr_clear(mstatus, MSTATUS_MIE);

	if (rc && (readl(SCU1_HWSTRAP2) & SCU1_HWSTRAP2_ROM_CLEAR_SRAM))
		memset((void *)rc->fmc_lda, 0x0, rc->fmc_lds);

	if (rc && rc->bd && rc->bd->abr)
		abr = rc->bd->abr;

	/* When secure boot failed and ABR is enabled,
	 * ABR should be triggered immediately in order
	 * to boot from alternate part or execute
	 * recovery operation.
	 */
	if (abr && is_secboot() && abr->enabled) {
		if (!abr->auxpin_enabled ||
		    (abr->auxpin_enabled && !abr->auxpin_val)) {
			/* 1 second */
			wdt_enable(WDT_DEVA, 0xF4240);
		}
	}

	while (1)
		__asm__("wfi");
}
