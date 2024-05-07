#include <bootstage.h>
#include <io.h>
#include <types.h>
#include <syscon.h>
#include <drivers/scu.h>
#include <errno.h>

#define PLL_REG1_RESET		BIT(25)
#define PLL_REG1_BYPASS		BIT(24)
#define PLL_REG1_DIS		BIT(23)
#define PLL_REG1_P		GENMASK(22, 19)
#define PLL_REG1_N		GENMASK(18, 13)
#define PLL_REG1_M		GENMASK(12, 0)

#define PLL_REG2_LOCK		BIT(31)
#define PLL_REG2_BWADJ		GENMASK(11, 0)

struct pll_info {
	uint32_t reg_offset0;
	uint32_t reg_offset1;
};

struct pll_param {
	int freq;
	uint32_t n_m_p;
	uint16_t bwadj;
};

static const struct pll_info scu_pll_info[SCU_PLL_ID_MAX + 1] = {
	[SCU_PLL_ID_IO_HPLL] = { .reg_offset0 = SCU1_HPLL_1, .reg_offset1 = SCU1_HPLL_2 },
	[SCU_PLL_ID_IO_APLL] = { .reg_offset0 = SCU1_APLL_1, .reg_offset1 = SCU1_APLL_2 },
	[SCU_PLL_ID_IO_L0PLL] = { .reg_offset0 = SCU1_L0PLL_1, .reg_offset1 = SCU1_L0PLL_2 },
	[SCU_PLL_ID_IO_L1PLL] = { .reg_offset0 = SCU1_L1PLL_1, .reg_offset1 = SCU1_L1PLL_2 },
};

#define MHZ(x)			((x) * 1000000)
#define NUM_PLL_PARAM		13
#define REG_N_M_P(n, m, p)                                               \
	(FIELD_PREP(PLL_REG1_N, (n) - 1) | FIELD_PREP(PLL_REG1_M, (m) - 1) | \
	 FIELD_PREP(PLL_REG1_P, (p) - 1))
#define REG_BWADJ(bwadj)	FIELD_PREP(PLL_REG2_BWADJ, ((bwadj) - 1))

static const struct pll_param pll_param_lookup[NUM_PLL_PARAM] = {
	{ .freq = MHZ(50), .n_m_p = REG_N_M_P(1, 32, 16), .bwadj = REG_BWADJ(16) },
	{ .freq = MHZ(75), .n_m_p = REG_N_M_P(1, 48, 16), .bwadj = REG_BWADJ(24) },
	{ .freq = MHZ(100), .n_m_p = REG_N_M_P(1, 56, 14), .bwadj = REG_BWADJ(28) },
	{ .freq = MHZ(150), .n_m_p = REG_N_M_P(1, 60, 10), .bwadj = REG_BWADJ(30) },
	{ .freq = MHZ(200), .n_m_p = REG_N_M_P(1, 48, 6), .bwadj = REG_BWADJ(24) },
	{ .freq = MHZ(250), .n_m_p = REG_N_M_P(1, 60, 6), .bwadj = REG_BWADJ(30) },
	{ .freq = MHZ(300), .n_m_p = REG_N_M_P(1, 48, 4), .bwadj = REG_BWADJ(24) },
	{ .freq = MHZ(400), .n_m_p = REG_N_M_P(1, 32, 2), .bwadj = REG_BWADJ(16) },
	{ .freq = MHZ(500), .n_m_p = REG_N_M_P(1, 40, 2), .bwadj = REG_BWADJ(20) },
	{ .freq = MHZ(600), .n_m_p = REG_N_M_P(1, 48, 2), .bwadj = REG_BWADJ(24) },
	{ .freq = MHZ(800), .n_m_p = REG_N_M_P(1, 32, 1), .bwadj = REG_BWADJ(16) },
	{ .freq = MHZ(1000), .n_m_p = REG_N_M_P(1, 40, 1), .bwadj = REG_BWADJ(20) },
	{ .freq = MHZ(1200), .n_m_p = REG_N_M_P(1, 48, 1), .bwadj = REG_BWADJ(24) },
};

bootstage_t scu_rstlog_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { SCU_INIT_ERR_SUCCESS, 0 };

	/* clear IO-die to prevent OTP re-init */
	writel(SCU1_RSTLOG0_SRST, SCU1_RSTLOG0);

	return sts;
}

int scu_get_pll_freq(int pll_id)
{
	const struct pll_info *info;
	uint32_t reg;
	int m, n, p;

	if (pll_id < 0 || pll_id > SCU_PLL_ID_MAX)
		return -1;

	info = &scu_pll_info[pll_id];
	reg = readl(info->reg_offset0);
	m = FIELD_GET(PLL_REG1_M, reg);
	n = FIELD_GET(PLL_REG1_N, reg);
	p = FIELD_GET(PLL_REG1_P, reg);

	return (25000000 * (m + 1) / (n + 1) / (p + 1));
}

int scu_set_pll_freq(int pll_id, int freq)
{
	const struct pll_info *info;
	const struct pll_param *param;
	int curr_freq, i;
	bool match = false;

	if (pll_id < 0 || pll_id > SCU_PLL_ID_MAX)
		return -EINVAL;

	curr_freq = scu_get_pll_freq(pll_id);
	if (curr_freq == freq)
		return 0;

	for (i = 0; i < NUM_PLL_PARAM; i++) {
		if (freq == pll_param_lookup[i].freq) {
			match = true;
			break;
		}
	}

	if (!match)
		return -EINVAL;

	param = &pll_param_lookup[i];

	info = &scu_pll_info[pll_id];
	setbits(info->reg_offset0, PLL_REG1_RESET);
	clrsetbits(info->reg_offset0, PLL_REG1_P | PLL_REG1_N | PLL_REG1_M,
		   param->n_m_p);

	clrsetbits(info->reg_offset1, PLL_REG2_BWADJ, param->bwadj);

	/* Wait 5us to ensure the parameters are set  */
	udelay(5);
	clrbits(info->reg_offset0, PLL_REG1_RESET);

	/* PLL should be locked after 20us */
	udelay(20);

	return 0;
}

int scu_rstlog_get_extrstn(void)
{
	/* W1C EXTRST# indicator and return the EXTRSTN value */
	writel(SCU1_RSTLOG0_EXTRSTN, SCU1_RSTLOG0);

	return !!(readl(SCU1_RSTLOG0) & SCU1_RSTLOG0_EXTRSTN);
}
