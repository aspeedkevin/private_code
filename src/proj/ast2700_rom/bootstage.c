#include <bootstage.h>
#include <drivers/otp.h>
#include <drivers/uart.h>
#include <lib/console.h>
#include <lib/printf.h>
#include <otp_mem.h>
#include <types.h>

static bool bootstage_disabled;


/* FOR TMP COMPATIBILTIY, REMOVED LATER */
void bootstage_end_status(uint8_t status)
{
	if (bootstage_disabled)
		return;

	printf(" %02x\n", status);
}

void bootstage_start_mark(char *str)
{
	if (bootstage_disabled)
		return;

	printf("%s", str);
}
/****************************************/

void bootstage_prologue(char *mark)
{

	if (bootstage_disabled || !mark)
		return;

	printf("%s", mark);
}

void bootstage_epilogue(bootstage_t sts)
{

	if (bootstage_disabled)
		return;

	printf(" %02x%02x\n", sts.errno, sts.syndrome);
}

bootstage_t bootstage_init(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	uint16_t cfg;
	int rc;

	bootstage_disabled = true;

	rc = otp_read_data(OTPCFG2, &cfg);
	if (rc || (cfg & OTPCFG2_DIS_BOOT_MSG))
		goto out;

	bootstage_disabled = false;

out:
	return sts;
}
