#include <bootstage.h>
#include <platform.h>
#include <io.h>
#include <drivers/sli.h>

#define AHBC_GROUP(x)				(0x40 * (x))
#define AHBC_HREADY_WAIT_CNT_REG		0x34
#define   AHBC_HREADY_WAIT_CNT_MAX		0x1ff

#define NUM_GROUPS_IN_AHBC0			4
#define NUM_GROUPS_IN_AHBC1			8

bootstage_t ahbc_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { .errno = 0, .syndrome = 0 };
	uintptr_t base;
	int i;

	/* IO-die AHBC timeout counter */
	for (i = 0; i < NUM_GROUPS_IN_AHBC1; i++) {
		base = AHBC1_REG + AHBC_GROUP(i);

		/* Disable the AHBC timeout before changing it */
		writel(0, base + AHBC_HREADY_WAIT_CNT_REG);
		readl(base + AHBC_HREADY_WAIT_CNT_REG);

		writel(AHBC_HREADY_WAIT_CNT_MAX,
		       base + AHBC_HREADY_WAIT_CNT_REG);
		readl(base + AHBC_HREADY_WAIT_CNT_REG);
	}

	if (sli_get_availability()) {
		/* CPU-die AHBC timeout counter */
		for (i = 0; i < NUM_GROUPS_IN_AHBC0; i++) {
			base = AHBC0_REG + AHBC_GROUP(i);

			/* Disable the AHBC timeout before changing it */
			writel(0, base + AHBC_HREADY_WAIT_CNT_REG);
			readl(base + AHBC_HREADY_WAIT_CNT_REG);

			writel(AHBC_HREADY_WAIT_CNT_MAX,
			       base + AHBC_HREADY_WAIT_CNT_REG);
			readl(base + AHBC_HREADY_WAIT_CNT_REG);
		}
	}

	return sts;
}
