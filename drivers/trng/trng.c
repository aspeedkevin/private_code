#include <bootstage.h>
#include <debug.h>
#include <drivers/scu.h>
#include <drivers/trng.h>
#include <errno.h>
#include <io.h>
#include <platform.h>

/* NIST TRNG register definitions */
#define NIST_TRNG_REG_CTRL				(TRNG_REG + 0x0)
#define   NIST_TRNG_REG_CTRL_CMD_NOP			0x0
#define   NIST_TRNG_REG_CTRL_CMD_GEN_NOISE		0x1
#define   NIST_TRNG_REG_CTRL_CMD_CREATE_STATE		0x3
#define   NIST_TRNG_REG_CTRL_CMD_GEN_RANDOM		0x6
#define   NIST_TRNG_REG_CTRL_CMD_ADVANCE_STATE		0x7
#define   NIST_TRNG_REG_CTRL_CMD_ZEROIZE		0xf
#define NIST_TRNG_REG_MODE				(TRNG_REG + 0x4)
#define   NIST_TRNG_REG_MODE_SEC_ALG			BIT(0)
#define     ALG_AES128					0
#define     ALG_AES256					1
#define NIST_TRNG_REG_ISTAT				(TRNG_REG + 0x14)
#define   NIST_TRNG_REG_ISTAT_DONE			BIT(4)
#define   NIST_TRNG_REG_ISTAT_ZEROIZED			BIT(0)
#define NIST_TRNG_REG_RAND0				(TRNG_REG + 0x24)

#define TRNG_TIMEOUT_US					1000

static bool nisttrng_ready;

static int wait_complete(uint32_t state)
{
	uint32_t val;
	int ret;

	ret = readl_poll_timeout(NIST_TRNG_REG_ISTAT, val, (val & state),
				 1, TRNG_TIMEOUT_US);

	return ret;
}

void trng_srand(uint32_t seed)
{
	/* do nothing */
}

uint32_t trng_rand(void)
{
	int rc;

	if (!nisttrng_ready)
		return -EIO;

	/* Generate random */
	writel(NIST_TRNG_REG_CTRL_CMD_GEN_RANDOM, NIST_TRNG_REG_CTRL);

	rc = wait_complete(NIST_TRNG_REG_ISTAT_DONE);
	if (rc)
		return -EIO;

	/* Write 1 clear DONE status */
	writel(NIST_TRNG_REG_ISTAT_DONE, NIST_TRNG_REG_ISTAT);

	return readl(NIST_TRNG_REG_RAND0);
}

int nisttrng_init(void)
{
	int rc;

	/* Zeroize */
	writel(NIST_TRNG_REG_CTRL_CMD_ZEROIZE, NIST_TRNG_REG_CTRL);
	rc = wait_complete(NIST_TRNG_REG_ISTAT_ZEROIZED);
	if (rc)
		return rc;

	/* Write 1 clear DONE status */
	writel(NIST_TRNG_REG_ISTAT_ZEROIZED, NIST_TRNG_REG_ISTAT);

	/* select security strength in DRBG - AES256 */
	writel(ALG_AES256, NIST_TRNG_REG_MODE);

	/* Generate noise */
	writel(NIST_TRNG_REG_CTRL_CMD_GEN_NOISE, NIST_TRNG_REG_CTRL);
	rc = wait_complete(NIST_TRNG_REG_ISTAT_DONE);
	if (rc)
		return rc;

	/* Write 1 clear DONE status */
	writel(NIST_TRNG_REG_ISTAT_DONE, NIST_TRNG_REG_ISTAT);

	/* Create state */
	writel(NIST_TRNG_REG_CTRL_CMD_CREATE_STATE, NIST_TRNG_REG_CTRL);
	rc = wait_complete(NIST_TRNG_REG_ISTAT_DONE);
	if (rc)
		return rc;

	/* Write 1 clear DONE status */
	writel(NIST_TRNG_REG_ISTAT_DONE, NIST_TRNG_REG_ISTAT);

	nisttrng_ready = true;

	return 0;
}
