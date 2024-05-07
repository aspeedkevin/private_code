#include <csr.h>
#include <timer.h>

uint32_t get_tbclk(void)
{
	return CONFIG_COUNTER_FREQUENCY;
}

uint64_t get_ticks(void)
{
	uint32_t tl, th;

	tl = csr_read(mcycle);
	th = csr_read(mcycleh);

	return (((uint64_t)th) << 32 | tl);
}
