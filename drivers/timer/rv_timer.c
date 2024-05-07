#include <csr.h>
#include <exception.h>
#include <io.h>
#include <drivers/rv_timer.h>
#include <drivers/scu.h>

struct rvtmr {
	int (*cb)(void *);
	void *cb_arg;
};

static struct rvtmr rvtmr[1];

static int rvtmr_isr(void *arg, uint32_t *epc)
{
	struct rvtmr *rvtmr = arg;

	if (!rvtmr->cb)
		return 0;

	return rvtmr->cb(rvtmr->cb_arg);
}

uint64_t rvtmr_get_count(void)
{
	return ((uint64_t)readl(RVTMR_COUNT_H) << 32) | readl(RVTMR_COUNT_L);
}

void rvtmr_set_alarm_callback(int (*cb)(void *), void *cb_arg)
{
	rvtmr->cb = cb;
	rvtmr->cb_arg = cb_arg;
}

void rvtmr_set_alarm_abs(uint64_t cnt)
{
	uint32_t cnt_l, cnt_h;
	uint32_t reg;

	cnt_h = (uint32_t)(cnt >> 32);
	cnt_l = (uint32_t)(cnt & 0xffffffff);

	writel(0xffffffff, RVTMR_ALARM_H);
	writel(cnt_l, RVTMR_ALARM_L);
	writel(cnt_h, RVTMR_ALARM_H);

	/* enable alarm interrupt */
	reg = readl(RVTMR_CTRL) | RVTMR_CTRL_INT_EN;
	writel(reg, RVTMR_CTRL);
}

void rvtmr_set_alarm_rel(uint64_t cnt_delta)
{
	uint64_t cnt;

	cnt = rvtmr_get_count() + cnt_delta;

	rvtmr_set_alarm_abs(cnt);
}

void rvtmr_clr_alarm(void)
{
	uint32_t reg;

	/* disable alarm interrupt */
	reg = readl(RVTMR_CTRL) & ~RVTMR_CTRL_INT_EN;
	writel(reg, RVTMR_CTRL);

	/* set alarm value to maximum, also clear interrupt */
	writel(0xffffffff, RVTMR_ALARM_H);
	writel(0xffffffff, RVTMR_ALARM_L);
}

void rvtmr_clr_count(void)
{
	uint32_t reg;

	reg = readl(RVTMR_CTRL) | RVTMR_CTRL_COUNT_CLR;
	writel(reg, RVTMR_CTRL);
}

void rvtmr_init(uint32_t interrupt_mode)
{
	uint32_t reg;

	writel(0xffffffff, RVTMR_ALARM_H);
	writel(0xffffffff, RVTMR_ALARM_L);

	reg = RVTMR_CTRL_COUNT_CLR |
	      RVTMR_CTRL_WDTRST_EN |
	      RVTMR_CTRL_CLK1M;
	writel(reg, RVTMR_CTRL);

	if (interrupt_mode)
		exception_callback_register(MCAUSE_CODE_MTI, rvtmr_isr, rvtmr);
}
