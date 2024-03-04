// SPDX-License-Identifier: GPL-2.0+
#include <timer.h>
#include <encoding.h>

uint32_t get_tbclk(void)
{
	return CONFIG_COUNTER_FREQUENCY;
}

uint64_t get_ticks(void)
{
	uint32_t tl, th;

	tl = read_csr(mcycle);
	th = read_csr(mcycleh);

	return (((uint64_t)th) << 32 | tl);
}
