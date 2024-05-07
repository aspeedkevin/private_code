#include <errno.h>
#include <lib/rand.h>

static struct rng sys_rng;

uint32_t rand(void)
{
	if (!sys_rng.rand)
		return RAND_BADNUM;

	return sys_rng.rand();
}

void srand(uint32_t seed)
{
	if (!sys_rng.srand)
		return;

	sys_rng.srand(seed);
}

int rng_register(struct rng *rng)
{
	if (!rng)
		return -EINVAL;

	if (sys_rng.rand || sys_rng.srand)
		return -EBUSY;

	sys_rng.rand = rng->rand;
	sys_rng.srand = rng->srand;

	return 0;
}
