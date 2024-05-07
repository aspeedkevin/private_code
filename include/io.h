#ifndef __IO_H__
#define __IO_H__

#include <lib/delay.h>
#include <timer.h>

#define readb(addr)		(*(volatile unsigned char *)(addr))
#define readw(addr)		(*(volatile unsigned short *)(addr))
#define readl(addr)		(*((volatile unsigned int *)(addr)))
#define readq(addr)		(*((volatile unsigned long long *)(addr)))

#define writeb(value, addr)	(*(volatile unsigned char *)(addr) = (unsigned char)value)
#define writew(value, addr)	(*(volatile unsigned short *)(addr) = (unsigned short)value)
#define writel(value, addr)	(*(volatile unsigned int *)(addr) = (unsigned int)(value))
#define writeq(value, addr)	(*(volatile unsigned long long *)(addr) = (unsigned long long)(value))

#define setbits(addr, set)		writel(readl(addr) | (set), addr)
#define clrbits(addr, clear)		writel(readl(addr) & (~(clear)), addr)
#define clrsetbits(addr, clear, set)	writel((readl(addr) & (~(clear))) | (set), addr)

#define readx_poll_timeout(op, addr, value, cond, interval_us, timeout_us)			\
	({											\
		int __ret = 0;									\
		uint64_t __total = 0;								\
		uint64_t __start = get_ticks();							\
		uint64_t __timeout_ticks = (timeout_us) * (CONFIG_COUNTER_FREQUENCY / 1000000);	\
		for (;;) {									\
			value = op(addr);							\
			if (cond)								\
				break;								\
			__total += interval_us;							\
			if (__total > (timeout_us)) {						\
				__ret = -1;							\
				break;								\
			}									\
			if (get_ticks() - __start > __timeout_ticks) {				\
				__ret = -1;							\
				break;								\
			}									\
			if (interval_us)							\
				udelay(interval_us);						\
		}										\
		__ret;										\
	})

#define readl_poll_timeout(addr, value, cond, interval_us, timeout_us) \
	readx_poll_timeout(readl, addr, value, cond, interval_us, timeout_us)
#endif
