#ifndef __DELAY_H__
#define __DELAY_H__

#include <types.h>

uint64_t usec_to_tick(uint32_t usec);
void udelay(uint64_t usec);
void mdelay(uint64_t msec);

#endif /* defined(__DELAY_H__) */
