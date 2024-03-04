/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __DELAY_H__
#define __DELAY_H__

void udelay(unsigned long usec);

static inline void mdelay(unsigned long msec)
{
	udelay(1000 * msec);
}

#endif /* defined(__DELAY_H__) */
