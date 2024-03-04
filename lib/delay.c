// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2023 Aspeed Technology Inc.
 */

#include <timer.h>

static uint64_t usec_to_tick(unsigned long usec)
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
