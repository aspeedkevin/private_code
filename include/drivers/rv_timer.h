#ifndef __RV_TIMER_H__
#define __RV_TIMER_H__

#include <bootstage.h>
#include <platform.h>
#include <types.h>
#include <utils.h>

/* registers */
#define RVTMR_COUNT_L		(RVTMR_REG + 0x00)
#define RVTMR_COUNT_H		(RVTMR_REG + 0x04)
#define RVTMR_ALARM_L		(RVTMR_REG + 0x08)
#define RVTMR_ALARM_H		(RVTMR_REG + 0x0c)
#define RVTMR_CTRL		(RVTMR_REG + 0x10)
#define   RVTMR_CTRL_INT_STS	BIT(16)
#define   RVTMR_CTRL_COUNT_CLR	BIT(4)
#define   RVTMR_CTRL_WDTRST_EN	BIT(3)
#define   RVTMR_CTRL_CLK1M	BIT(1)
#define   RVTMR_CTRL_INT_EN	BIT(0)

/* timer clock rate */
#define RVTMR_CLK_RATE	1000000

uint64_t rvtmr_get_count(void);
void rvtmr_set_alarm_callback(int (*cb)(void *), void *cb_arg);
void rvtmr_set_alarm_abs(uint64_t cnt);
void rvtmr_set_alarm_rel(uint64_t cnt_delta);
void rvtmr_clr_alarm(void);
void rvtmr_clr_count(void);
void rvtmr_init(uint32_t interrupt_mode);

#endif
