#include <timer.h>

uint64_t usec_to_tick(uint32_t usec)
{
	uint64_t tick = usec;

	tick *= (CONFIG_COUNTER_FREQUENCY / 1000000);

	return tick;
}

void udelay(uint64_t usec)
{
	uint64_t tmp;

	tmp = get_ticks() + usec_to_tick(usec);

	while (get_ticks() < tmp + 1)
		;
}

void mdelay(uint64_t msec)
{
	udelay(1000 * msec);
}
