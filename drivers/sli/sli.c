#include <bootstage.h>
#include <drivers/sli.h>
#include <drivers/scu.h>
#include <io.h>
#include <lib/delay.h>
#include <platform.h>

#define SLIM_REG_OFFSET		0x000	/* SLI Memory bus */
#define SLIH_REG_OFFSET		0x200	/* SLI AHB bus */
#define SLIV_REG_OFFSET		0x400	/* SLI Video bus */

#define SLIH_CPU_BASE		(SLI0_REG + SLIH_REG_OFFSET)
#define SLIH_IO_BASE		(SLI1_REG + SLIH_REG_OFFSET)

static int is_sli_available;

static void sli_set_availability(int avl)
{
	is_sli_available = avl;
}

int sli_get_availability(void)
{
	return is_sli_available;
}

bootstage_t sli_init(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	uint32_t value, target;
	int ret;

	bootstage_start_mark(BOOTSTAGE_SLI_INIT);

	sli_set_availability(0);

	value = readl(SCU1_HWSTRAP1);
	if (value & SCU1_HWSTRAP1_LTPI_MODE) {
		/* AST1700: SLI is not available since it only has IO-die */
		sts.errno = SLI_ERR_UNAVAIL_AST1700;
		return sts;
	}

	/*
	 * The target is for both RX and TX to enter the suspend state, meaning
	 * that both the RX and TX hardware blocks are not in the training
	 * state, and are therefore ready for software use.
	 */
	target = SLI_INTR_RX_SUSPEND | SLI_INTR_TX_SUSPEND;

	/* Polling IO-die interrupt status */
	ret = readl_poll_timeout(SLIH_IO_BASE + SLI_INTR_STATUS, value,
				 (value & target) == target, 1, 10);
	if (ret) {
		sts.errno = SLI_ERR_UNAVAIL_IO_DIE;
		return sts;
	}

	/* Polling CPU-die interrupt status */
	ret = readl_poll_timeout(SLIH_CPU_BASE + SLI_INTR_STATUS, value,
				 (value & target) == target, 1, 2);
	if (ret) {
		sts.errno = SLI_ERR_UNAVAIL_CPU_DIE;
		return sts;
	}

	sli_set_availability(1);

	sts.errno = SLI_STATUS_PASS;

	return sts;
}
