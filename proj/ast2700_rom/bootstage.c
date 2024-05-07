#include <bootstage.h>
#include <drivers/otp.h>
#include <drivers/uart.h>
#include <drivers/scu.h>
#include <lib/console.h>
#include <lib/printf.h>
#include <otp_mem.h>
#include <types.h>
#include <io.h>

#define EARLY_BOOTSTAGE_COUNT		6

static bool bootstage_disabled = true;
static struct bootmsg early_console[EARLY_BOOTSTAGE_COUNT];
static int early_bs_count;

void bootstage_prologue(char *mark)
{
	if (bootstage_disabled) {
		if (early_bs_count < EARLY_BOOTSTAGE_COUNT)
			early_console[early_bs_count].mark = mark;
		return;
	}

	if (!mark)
		return;

	printf("%s", mark);
}

void bootstage_epilogue(bootstage_t sts)
{
	if (bootstage_disabled) {
		if (early_bs_count < EARLY_BOOTSTAGE_COUNT) {
			early_console[early_bs_count].errno = sts.errno;
			early_console[early_bs_count].syndrome = sts.syndrome;
			early_bs_count++;
		}
		return;
	}

	printf(" %02x%02x\n", sts.errno, sts.syndrome);
}

bootstage_t bootstage_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	uint16_t cfg;

	bootstage_disabled = true;

	cfg = readl(SCU1_OTPCFG_03_02);
	if (cfg & OTPCFG2_DIS_BOOT_MSG)
		goto out;

	bootstage_disabled = false;

	for (int i = 0; i < EARLY_BOOTSTAGE_COUNT; i++) {
		if (!early_console[i].mark)
			continue;

		printf("%s %02x%02x\n", early_console[i].mark, early_console[i].errno, early_console[i].syndrome);
	}

out:
	return sts;
}
