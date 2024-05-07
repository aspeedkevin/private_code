#include <bootstage.h>
#include <drivers/scu.h>
#include <drivers/trng.h>
#include <errno.h>
#include <io.h>
#include <lib/rand.h>
#include <rng.h>
#include <timer.h>

#define RNG_SELF_TEST_COUNT		12

static bool rng_ready;
static bool nisttrng_ready;

static int scu_wait_complete(void)
{
	uint32_t val;

	return readl_poll_timeout(SCU1_RNG_CTRL, val, (val & SCU1_RNG_CTRL_VLD),
				  1, 1000);
}

static uint32_t scu_rand(void)
{
	return scu_wait_complete() ? 0 : readl(SCU1_RNG_DATA);
}

static void scu_srand(uint32_t seed)
{
	/* do nothing */
}

static int rng_self_test(void)
{
	uint32_t data = 0;

	for (int i = 0; i < RNG_SELF_TEST_COUNT; i++)
		data |= rand();

	return data ? 0 : -EIO;
}

bool is_rng_ready(void)
{
	return rng_ready;
}

bool is_nisttrng_ready(void)
{
	return nisttrng_ready;
}

bootstage_t rng_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { RNG_SUCCESS, 0 };
	struct rng rng[1];
	int rc;

	rc = nisttrng_init();
	if (!rc) {
		sts.syndrome = RNG_NIST;
		rng->rand = trng_rand;
		rng->srand = trng_srand;
		nisttrng_ready = true;

	} else if (readl(SCU1_RNG_CTRL) & SCU1_RNG_CTRL_VLD) {
		sts.syndrome = RNG_SCU;
		rng->rand = scu_rand;
		rng->srand = scu_srand;
	} else {
		sts.errno = RNG_ERR_INIT;
		goto end;
	}

	rc = rng_register(rng);
	if (rc) {
		sts.errno = RNG_ERR_REGISTER;
		sts.syndrome = rc;
	} else {
		srand((uint32_t)get_ticks());
	}

	rc = rng_self_test();
	if (rc) {
		sts.errno = RNG_ERR_SELF_TEST;
		sts.syndrome = rc;
		goto end;
	}

	rng_ready = true;
end:
	return sts;
}
