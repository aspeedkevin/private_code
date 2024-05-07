#include <bootstage.h>
#include <drivers/scu.h>
#include <drivers/ltpi.h>
#include <drivers/gpio.h>
#include <drivers/sgpio.h>
#include <io.h>
#include <lib/delay.h>
#include <lib/clz.h>
#include <platform.h>
#include <timer.h>
#include <syscon.h>
#include <debug.h>

#include "ltpi_top.h"
#include "ltpi_ctrl.h"
#include "internal.h"

#define ADVERTISE_TIMEOUT_US			105000 /* 105 ms */

struct ltpi_reset {
	uintptr_t regs_assert;
	uintptr_t regs_deassert;
	uint32_t bit_mask;
};

struct ltpi_clk_ctrl {
	uintptr_t regs_gate;
	uintptr_t regs_ungate;
	uint32_t bit_mask;
};

struct ltpi_clk_info {
	int16_t freq;		/* clock frequency in MHz*/
	int16_t clk_sel;	/* clock selection */
};

static const struct ltpi_clk_info ltpi_clk_lookup_sdr[13] = {
	{ 25, REG_LTPI_PLL_25M },
	{ 50, REG_LTPI_PLL_LPLL },
	{ 75, REG_LTPI_PLL_LPLL },
	{ 100, REG_LTPI_PLL_LPLL },
	{ 150, REG_LTPI_PLL_LPLL },
	{ 200, REG_LTPI_PLL_LPLL },
	{ 250, REG_LTPI_PLL_LPLL },
	{ 300, REG_LTPI_PLL_LPLL },
	{ 400, REG_LTPI_PLL_LPLL },
	{ 600, REG_LTPI_PLL_LPLL },
	{ -1, -1 },
	{ -1, -1 },
	{ 500, REG_LTPI_PLL_LPLL }
};

static const struct ltpi_clk_info ltpi_clk_lookup_ddr[13] = {
	{ 50, REG_LTPI_PLL_LPLL },
	{ 100, REG_LTPI_PLL_LPLL },
	{ 150, REG_LTPI_PLL_LPLL },
	{ 200, REG_LTPI_PLL_LPLL },
	{ 300, REG_LTPI_PLL_LPLL },
	{ 400, REG_LTPI_PLL_LPLL },
	{ 500, REG_LTPI_PLL_LPLL },
	{ 600, REG_LTPI_PLL_LPLL },
	{ 800, REG_LTPI_PLL_LPLL },
	{ 1200, REG_LTPI_PLL_LPLL },
	{ -1, -1 },
	{ -1, -1 },
	{ 1000, REG_LTPI_PLL_LPLL }
};

struct ltpi_priv {
	uintptr_t base;
	uintptr_t phy_base;
	uintptr_t top_base;
	uintptr_t gpio_base;

	struct ltpi_reset reset;
	struct ltpi_clk_ctrl clk_ctrl;

	/* encoding as LTPI speed capability */
	uint16_t otp_speed_cap;	/* limit the speed via OTP strap */
	uint16_t phy_speed_cap; /* limit the speed with physical line status */
	bool otp_ddr_dis;

	int crc_format;
	int io_driving;

#define RX_CLK_INVERSE		BIT(1)
#define TX_CLK_INVERSE		BIT(0)
	int clk_inverse;

	int index;
	bootstage_t *bootstage;
};

static struct ltpi_priv ltpi_data[2];

static uint32_t get_pin_strap(void);

/**
 * @brief find the bit index of the max attainable speed from the bitmap
 * @param [IN] cap - bitmap of the speed capability
 * @return the bit index of the max attainable speed
 */
static uint16_t find_max_speed(uint16_t cap)
{
	return 15 - clz16(cap & ~LTPI_SP_CAP_DDR);
}

static void ltpi_phy_unlock(struct ltpi_priv *ltpi)
{
	writel(LTPI_PROT_KEY_UNLOCK, ltpi->phy_base + LTPI_PROT_KEY);
}

static void ltpi_enable_rx_bias(struct ltpi_priv *ltpi)
{
	setbits(ltpi->top_base + LTPI_LVDS_RX_CTRL,
		REG_LTPI_LVDS_RX1_BIAS_EN | REG_LTPI_LVDS_RX0_BIAS_EN);
	udelay(1);
}

static int ltpi_phy_get_mode(struct ltpi_priv *ltpi)
{
	uint32_t reg = readl(ltpi->phy_base + LTPI_PHY_CTRL);

	return FIELD_GET(REG_LTPI_PHY_MODE, reg);
}

static int ltpi_phy_set_mode(struct ltpi_priv *ltpi, int mode)
{
	uint32_t reg;

	if (mode < 0 || mode > LTPI_PHY_MODE_CDR_HI_SP) {
		LOG_ERR("%s: invalid mode %d\n", __func__, mode);
		return -1;
	}

	reg = readl(ltpi->phy_base + LTPI_PHY_CTRL);
	reg &= ~REG_LTPI_PHY_MODE;
	reg |= mode;
	writel(reg, ltpi->phy_base + LTPI_PHY_CTRL);

	return 0;
}

static int ltpi_phy_set_clksel(struct ltpi_priv *ltpi, int clksel, bool is_op_clk)
{
	uint32_t reg;

#ifdef CONFIG_FPGA_ASPEED
	/* FPGA only supports CLKIN 25M */
	clksel = REG_LTPI_PLL_25M;
#endif

	reg = readl(ltpi->phy_base + LTPI_PLL_CTRL);
	reg &= ~(REG_LTPI_PLL_SELECT | REG_LTPI_PLL_SET |
		 REG_LTPI_RX_PHY_CLK_INV | REG_LTPI_TX_PHY_CLK_INV);
	reg |= FIELD_PREP(REG_LTPI_PLL_SELECT, clksel);

	if (ltpi->clk_inverse & RX_CLK_INVERSE)
		reg |= REG_LTPI_RX_PHY_CLK_INV;

	if (ltpi->clk_inverse & TX_CLK_INVERSE)
		reg |= REG_LTPI_TX_PHY_CLK_INV;

	if (is_op_clk)
		reg |= REG_LTPI_PLL_SET;

	writel(reg, ltpi->phy_base + LTPI_PLL_CTRL);

	return 0;
}

static void ltpi_set_crc_format(struct ltpi_priv *ltpi, int crc_fmt)
{
	uint32_t val = readl(ltpi->base + LTPI_CRC_OPTION);

	val &= ~(REG_LTPI_SW_CRC_OUT_ML_FIRST | REG_LTPI_SW_CRC_IN_LSB_FIRST);
	if (crc_fmt)
		val |= REG_LTPI_SW_CRC_OUT_ML_FIRST | REG_LTPI_SW_CRC_IN_LSB_FIRST;

	writel(val, ltpi->base + LTPI_CRC_OPTION);
}

static int ltpi_reset(struct ltpi_priv *ltpi)
{
	writel(ltpi->reset.bit_mask, ltpi->reset.regs_assert);
	readl(ltpi->reset.regs_assert);

	udelay(1);

	writel(ltpi->clk_ctrl.bit_mask, ltpi->clk_ctrl.regs_ungate);
	readl(ltpi->clk_ctrl.regs_ungate);

	writel(ltpi->reset.bit_mask, ltpi->reset.regs_deassert);
	readl(ltpi->reset.regs_deassert);

	ltpi_phy_unlock(ltpi);

	return 0;
}

static void ltpi_hpm_init_sgpio(void)
{
	uint32_t value;

	/*
	 * SGPIO master controller #1:
	 *
	 * Register 0x0
	 * - bit[31:16] clock divider
	 *     SGPIO clock = (PCLK 100M / 2) / (divider + 1)
	 *     select divider = 4 -> SGPIO clock = 50MHz / (4 + 1) = 10MHz
	 * - bit[11: 3] pin number
	 *     enable 80 parallel pins (BMC_GPIO 64 pins + BMC_SGPIO 16 pins)
	 * - bit[0] SGPIO controller enabling
	 */
	value = FIELD_PREP(GENMASK(31, 16), 4) |
		FIELD_PREP(GENMASK(11, 3), 80) | BIT(0);
	writel(value, SGPIOM1_REG + 0x0);
}

static uint32_t ltpi_get_link_mng_state(struct ltpi_priv *ltpi)
{
	return FIELD_GET(REG_LTPI_LINK_MNG_ST,
			 readl(ltpi->base + LTPI_LINK_MNG_ST));
}

static int ltpi_poll_link_mng_state(struct ltpi_priv *ltpi, uint32_t expected,
				    uint32_t unexpected, int timeout_us)
{
	uint64_t start, timeout_tick;
	uint32_t addr = ltpi->base + LTPI_LINK_MNG_ST;
	uint32_t reg = readl(addr);
	uint32_t state;
	int ret = LTPI_ERR_NONE;

	if (timeout_us) {
		start = get_ticks();
		timeout_tick = timeout_us * (CONFIG_COUNTER_FREQUENCY / 1000000);
	}

	do {
		reg = readl(addr);
		state = FIELD_GET(REG_LTPI_LINK_MNG_ST, reg);

		if (state == expected)
			break;

		if (state == unexpected) {
			/* link is disconnected, break the loop directly */
			ret = LTPI_ERR_DISCON;
			break;
		}

		if (timeout_us && ((get_ticks() - start) > timeout_tick)) {
			ret = LTPI_ERR_TIMEOUT;
			break;
		}
	} while (1);

	return ret;
}

static int ltpi_wait_state_pll_set(struct ltpi_priv *ltpi, int timeout_us)
{
	return ltpi_poll_link_mng_state(ltpi, LTPI_LINK_MNG_ST_WAIT_PLL_SET, -1,
					timeout_us);
}

static int ltpi_wait_state_op(struct ltpi_priv *ltpi)
{
	setbits(ltpi->base + LTPI_LINK_ST,
		REG_LTPI_CON_ACC_TO_ERR | REG_LTPI_FRM_CRC_ERR | REG_LTPI_LINK_LOST_ERR);

	return ltpi_poll_link_mng_state(ltpi, LTPI_LINK_MNG_ST_OP,
					LTPI_LINK_MNG_ST_DETECT_ALIGN,
					ADVERTISE_TIMEOUT_US);
}

static int ltpi_set_lvds_io_driving(struct ltpi_priv *ltpi, int driving)
{
	uint32_t val;

	setbits(ltpi->top_base + LTPI_SW_FORCE_EN, REG_LTPI_SW_FORCE_LVDS_TX_DS_EN);

	val = readl(ltpi->top_base + LTPI_LVDS_TX_CTRL);
	val &= ~(REG_LTPI_LVDS_TX1_DS1 | REG_LTPI_LVDS_TX1_DS0 |
		 REG_LTPI_LVDS_TX0_DS1 | REG_LTPI_LVDS_TX0_DS0);

	/* tx1: clk, tx0: data */
	if (driving & BIT(1))
		val |= (REG_LTPI_LVDS_TX1_DS1 | REG_LTPI_LVDS_TX0_DS1);

	if (driving & BIT(0))
		val |= (REG_LTPI_LVDS_TX1_DS0 | REG_LTPI_LVDS_TX0_DS0);

	writel(val, ltpi->top_base + LTPI_LVDS_TX_CTRL);

	return 0;
}

static int ltpi_set_local_speed_cap(struct ltpi_priv *ltpi, uint32_t speed_cap)
{
	uint32_t reg;

	/* only set bits that Aspeed SOC supported */
	speed_cap &= LTPI_SP_CAP_ASPEED_SUPPORTED;
	if (ltpi->otp_ddr_dis)
		speed_cap &= ~LTPI_SP_CAP_DDR;

	reg = readl(ltpi->base + LTPI_CAP_LOCAL);
	reg &= ~REG_LTPI_SP_CAP_LOCAL;
	reg |= FIELD_PREP(REG_LTPI_SP_CAP_LOCAL, speed_cap);
	writel(reg, ltpi->base + LTPI_CAP_LOCAL);

	return 0;
}

static void ltpi_log_exit(struct ltpi_priv *ltpi, int reason)
{
	ltpi->bootstage->errno |= LTPI_STATUS_EXIT;
	ltpi->bootstage->syndrome = reason;
}

static void ltpi_log_restart(struct ltpi_priv *ltpi, int reason)
{
	ltpi->bootstage->errno |= LTPI_STATUS_RESTART;
	ltpi->bootstage->syndrome = reason;
	bootstage_epilogue(*ltpi->bootstage);

	/* Restart a boot log */
	bootstage_prologue(BOOTSTAGE_LTPI_INIT);
	ltpi->bootstage->errno &= ~LTPI_STATUS_RESTART;
	ltpi->bootstage->errno &= ~LTPI_STATUS_HAS_CRC_ERR;
	ltpi->bootstage->syndrome = LTPI_SYND_OK;
}

static void ltpi_log_phy_mode(struct ltpi_priv *ltpi, int phy_mode)
{
	ltpi->bootstage->errno &= ~LTPI_STATUS_MODE;
	ltpi->bootstage->errno |= FIELD_PREP(LTPI_STATUS_MODE, phy_mode);
}

/*
 * Link training phase:
 * Link lost -> Link detect frame alignment -> Link detect -> Link speed -> Wait PLL set
 */
static void ltpi_do_link_training(struct ltpi_priv *ltpi)
{
	/* Reset the PHY to PHY_MODE_OFF */
	ltpi_reset(ltpi);

	ltpi_enable_rx_bias(ltpi);
	ltpi_set_local_speed_cap(ltpi, ltpi->phy_speed_cap);
	ltpi_set_lvds_io_driving(ltpi, ltpi->io_driving);
	ltpi_set_crc_format(ltpi, ltpi->crc_format);

	/* Set the clock source to the base frequency 25MHz */
	ltpi_phy_set_clksel(ltpi, REG_LTPI_PLL_25M, false);

	/* To make the remote side back to the link lost state */
	udelay(ADVERTISE_TIMEOUT_US);

	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_SDR);
}

static int ltpi_set_operational_clk(struct ltpi_priv *ltpi, uint16_t speed_cap)
{
	const struct ltpi_clk_info *info;
	int target_speed, clksel, phy_mode, pll_id;

	if (ltpi->index)
		pll_id = SCU_PLL_ID_IO_L1PLL;
	else
		pll_id = SCU_PLL_ID_IO_L0PLL;

	/* find max attainable speed */
	target_speed = find_max_speed(speed_cap);

	/* set phy mode "OFF" */
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);

	if (speed_cap & LTPI_SP_CAP_DDR) {
		phy_mode = LTPI_PHY_MODE_DDR;
		info = ltpi_clk_lookup_ddr;
	} else {
		phy_mode = LTPI_PHY_MODE_SDR;
		info = ltpi_clk_lookup_sdr;
	}
	clksel = info[target_speed].clk_sel;
	ltpi_phy_set_clksel(ltpi, clksel, true);
	if (clksel == REG_LTPI_PLL_LPLL)
		scu_set_pll_freq(pll_id, info[target_speed].freq * 1000000);

	/* Start TX with the operational frequency */
	ltpi_phy_set_mode(ltpi, phy_mode);

	ltpi_log_phy_mode(ltpi, phy_mode);

	return target_speed;
}

static void ltpi_scm_init(struct ltpi_priv *ltpi)
{
	int ret, target_speed;
	uint32_t reg, state;

	/* Check whether LTPI is initialized */
	state = ltpi_get_link_mng_state(ltpi);
	if (state == LTPI_LINK_MNG_ST_OP) {
		ltpi_log_phy_mode(ltpi, ltpi_phy_get_mode(ltpi));
		ltpi_log_exit(ltpi, LTPI_SYND_OK_ALREADY_INIT);
		return;
	}

	/* LTPI initialization is required, start link training phase */
	do {
		ltpi_do_link_training(ltpi);
		do {
			ret = ltpi_wait_state_pll_set(ltpi, 20000);
			if (ret == LTPI_ERR_NONE)
				break;

			if (scu_rstlog_get_extrstn() == 0) {
				ltpi_log_exit(ltpi, LTPI_SYND_EXTRST_LINK_TRAINING);
				goto ltpi_scm_exit;
			}
		} while (1);

		/* read intersection of the speed capabilities */
		reg = FIELD_GET(REG_LTPI_SP_INTERSETION, readl(ltpi->base + LTPI_LINK_MNG_ST));
		if (reg == 0) {
			ltpi_log_exit(ltpi, LTPI_SYND_NO_COMMOM_SPEED);
			goto ltpi_scm_exit;
		}

		target_speed = ltpi_set_operational_clk(ltpi, reg);

		/* poll link state 0x7 */
		ret = ltpi_wait_state_op(ltpi);
		if (ret == LTPI_ERR_NONE) {
			setbits(ltpi->base + LTPI_OEM_BUS_SETTING,
				REG_LTPI_OEM_RX_START_TRIG | REG_LTPI_OEM_TX_START_TRIG);
			break;
		}

		if (readl(ltpi->base + LTPI_LINK_ST) & REG_LTPI_FRM_CRC_ERR)
			ltpi->bootstage->errno |= LTPI_STATUS_HAS_CRC_ERR;

		if (scu_rstlog_get_extrstn() == 0) {
			ltpi_log_exit(ltpi, LTPI_SYND_EXTRST_LINK_CONFIG);
			goto ltpi_scm_exit;
		}

		/* clear the bit to specify the current speed doesn't work */
		ltpi->phy_speed_cap &= ~BIT(target_speed);

		/* the lowest speed 25M should always be supported */
		if (ltpi->phy_speed_cap == 0)
			ltpi->phy_speed_cap |= BIT(0);

		ltpi_log_restart(ltpi, LTPI_SYND_WAIT_OP_TO);
	} while (1);

	return;

ltpi_scm_exit:
	ltpi_reset(ltpi);
}

static void ltpi_hpm_init_addr_map(struct ltpi_priv *ltpi)
{
	uint32_t reg;

	/*
	 * AHB_ADDR_MAP0: bit[34:26] of the destination address
	 *
	 * For AST1700, set AHB_ADDR_MAP0 to 0x4 so that:
	 * AST1700 address [0x3000_0000, 0x33FF_FFFF] will map to
	 * AST2700 address [0x1000_0000, 0x13FF_FFFF]
	 *
	 * This is to redirect the AST1700 IRQ signal to AST2700
	 * interrupt controller (0x1210_0000)
	 */
	reg = readl(ltpi->base + LTPI_AHB_CTRL0);
	reg &= ~REG_LTPI_AHB_ADDR_MAP0;
	reg |= FIELD_PREP(REG_LTPI_AHB_ADDR_MAP0, 0x10000000 >> 26);
	writel(reg, ltpi->base + LTPI_AHB_CTRL0);
}

static void ltpi_hpm_init(struct ltpi_priv *ltpi)
{
	uint32_t reg, state;
	int reason;

	ltpi->bootstage->errno |= LTPI_STATUS_HPM;

	/* Check whether LTPI is initialized */
	state = ltpi_get_link_mng_state(ltpi);
	if (state == LTPI_LINK_MNG_ST_OP) {
		ltpi_log_phy_mode(ltpi, ltpi_phy_get_mode(ltpi));
		ltpi_log_exit(ltpi, LTPI_SYND_OK_ALREADY_INIT);
		return;
	}

	/* LTPI initialization is required, start link training phase */
	do {
		ltpi_do_link_training(ltpi);
		ltpi_wait_state_pll_set(ltpi, 0);

		/* read intersection of the speed capabilities */
		reg = FIELD_GET(REG_LTPI_SP_INTERSETION,
				readl(ltpi->base + LTPI_LINK_MNG_ST));
		if (reg == 0) {
			reason = LTPI_SYND_NO_COMMOM_SPEED;
			goto ltpi_hpm_retrain;
		}

		ltpi_set_operational_clk(ltpi, reg);

		/* poll link state 0x7 */
		if (ltpi_wait_state_op(ltpi) == LTPI_ERR_NONE)
			break;

		if (readl(ltpi->base + LTPI_LINK_ST) & REG_LTPI_FRM_CRC_ERR)
			ltpi->bootstage->errno |= LTPI_STATUS_HAS_CRC_ERR;

		reason = LTPI_SYND_WAIT_OP_TO;
ltpi_hpm_retrain:
		ltpi_log_restart(ltpi, reason);

		/* Stuck here if debug flag is set by the UART debug */
		while (readl(SCU1_IO_SCRATCH_32) & SCU1_IO_EXPDR_LTPI_DBG)
			;
	} while (1);

	setbits(ltpi->base + LTPI_OEM_BUS_SETTING,
		REG_LTPI_OEM_RX_START_TRIG | REG_LTPI_OEM_TX_START_TRIG);
	ltpi_hpm_init_sgpio();
	ltpi_hpm_init_addr_map(ltpi);
}

static uint32_t get_pin_strap(void)
{
	return readl(SCU1_HWSTRAP1);
}

#define LTPI_SGPIOS_PARALLEL_PIN_NUM 64
#define SGPIOS_INVERT_POINT 10
/*
 * Default value:
 * BMC_SGPO [3:0] = 1
 * BMC_SGPO [15:4] = 0
 * BMC_SGPO [19:16] = 1
 * BMC_SGPO [23:20] = 0
 * BMC_SGPO [27:24] = 1
 * BMC_SGPO [31:28] = 0
 * BMC_SGPO [35:32] = 1
 * BMC_SGPO [47:36] = 0
 * BMC_SGPO [51:48] = 1
 * BMC_SGPO [63:52] = 0
 */
static u8 sgpo_hl_invert_point[SGPIOS_INVERT_POINT] = {
	4, 16, 20, 24, 28, 32, 36, 48, 52, LTPI_SGPIOS_PARALLEL_PIN_NUM
};

static void ltpi_scm_sgpios_init(void)
{
	u32 invert_index = 0;
	u8 val = 1;

	for (u32 i = 0; i < LTPI_SGPIOS_PARALLEL_PIN_NUM;) {
		if (val)
			setbits(SGPIOS_REG + SGPIO_G7_CTRL_REG_OFFSET(i),
				SGPIO_G7_PARALLEL_OUT_DATA);
		else
			clrbits(SGPIOS_REG + SGPIO_G7_CTRL_REG_OFFSET(i),
				SGPIO_G7_PARALLEL_OUT_DATA);
		i++;
		if (i == sgpo_hl_invert_point[invert_index]) {
			val = !val;
			invert_index++;
		}
	}
	writel(0x1, SGPIOS_REG);
}

static void ltpi_scm_set_pins(void)
{
	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOB7    5: SCM_GPO7
	 * GPIOB6    5: SCM_GPO6
	 * GPIOB5    5: SCM_GPO5
	 * GPIOB4    5: SCM_GPO4
	 * GPIOB3    5: SCM_GPO3
	 * GPIOB2    5: SCM_GPO2
	 * GPIOB1    5: SCM_GPO1
	 * GPIOB0    5: SCM_GPO0
	 */
	writel(0x55555555, SCU1_PINMUX_GRP_B);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOC7    5: SCM_GPI3
	 * GPIOC6    5: SCM_GPI2
	 * GPIOC5    5: SCM_GPI1
	 * GPIOC4    5: SCM_GPI0
	 * GPIOC3    5: SCM_GPO11
	 * GPIOC2    5: SCM_GPO10
	 * GPIOC1    5: SCM_GPO9
	 * GPIOC0    5: SCM_GPO8
	 */
	writel(0x55555555, SCU1_PINMUX_GRP_C);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOD7    5: HPM0_GPO3
	 * GPIOD6    5: HPM0_GPO2
	 * GPIOD5    5: HPM0_GPO1
	 * GPIOD4    5: HPM0_GPO0
	 * GPIOD3    5: HPM0_GPI3
	 * GPIOD2    5: HPM0_GPI2
	 * GPIOD1    5: HPM0_GPI1
	 * GPIOD0    5: HPM0_GPI0
	 */
	writel(0x55555555, SCU1_PINMUX_GRP_D);

	/*
	 * Pin         MF
	 * ----------------------------
	 * GPIOP6    5: HPM1_GPO3
	 *
	 * GPIOF4    5: HPM1_GPO2
	 * GPIOF1    5: HPM1_GPO1
	 * GPIOF0    5: HPM1_GPO0
	 */
	clrsetbits(SCU1_PINMUX_GRP_P, SCU1_PINMUX_PIN6,
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x5));

	clrsetbits(SCU1_PINMUX_GRP_F,
		   SCU1_PINMUX_PIN4 | SCU1_PINMUX_PIN1 | SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x5));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOH3    5: HPM1_GPI3
	 * GPIOH2    5: HPM1_GPI2
	 *
	 * GPIOAA7   5: HPM1_GPI1
	 * GPIOAA6   5: HPM1_GPI0
	 */
	clrsetbits(SCU1_PINMUX_GRP_H, SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2,
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x5));

	clrsetbits(SCU1_PINMUX_GRP_AA, SCU1_PINMUX_PIN7 | SCU1_PINMUX_PIN6,
		   FIELD_PREP(SCU1_PINMUX_PIN7, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x5));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOT6    5: SGPSCK
	 * GPIOT1    5: SGPSLD
	 *
	 * GPIOU3    5: SGPSMI
	 * GPIOU2    5: SGPSMO
	 */
	clrsetbits(SCU1_PINMUX_GRP_T, SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN1,
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x5));

	clrsetbits(SCU1_PINMUX_GRP_U, SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2,
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x5) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x5));

	/* Enable SGPIO slave */
	ltpi_scm_sgpios_init();
}

static void ltpi_hpm_set_pins(void)
{
	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOQ6    1: MTDO
	 * GPIOQ5    6: GPINL18
	 * GPIOQ4    6: GPONL18
	 * GPIOQ3    6: GPINL17
	 * GPIOQ2    6: GPONL17
	 */
	clrsetbits(SCU1_PINMUX_GRP_Q,
		   SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN5 | SCU1_PINMUX_PIN4 |
		   SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2,
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x1) |
		   FIELD_PREP(SCU1_PINMUX_PIN5, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOX7    6: GPINL31
	 * GPIOX6    6: GPONL31
	 * GPIOX5    6: GPINL30
	 * GPIOX4    6: GPONL30
	 * GPIOX3    6: GPINL29
	 * GPIOX2    6: GPONL29
	 * GPIOX1    6: GPINL28
	 * GPIOX0    6: GPONL28
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_X);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOV7    1: I2CSDA3
	 * GPIOV6    1: I2CSCL3
	 * GPIOV5    1: I2CSDA2
	 * GPIOV4    1: I2CSCL2
	 * GPIOV3    1: I2CSDA1
	 * GPIOV2    1: I2CSCL1
	 * GPIOV1    1: I2CSDA0
	 * GPIOV0    1: I2CSCL0
	 */
	writel(0x11111111, SCU1_PINMUX_GRP_V);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOG7    6: GPINL7
	 * GPIOG6    6: GPONL7
	 * GPIOG5    6: GPINL6
	 * GPIOG4    6: GPONL6
	 * GPIOG3    6: GPINL5
	 * GPIOG2    6: GPONL5
	 * GPIOG1    6: GPINL4
	 * GPIOG0    6: GPONL4
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_G);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOH1    6: GPINL8
	 * GPIOH0    6: GPONL8
	 */
	clrsetbits(SCU1_PINMUX_GRP_H,
		   SCU1_PINMUX_PIN1 | SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x6));
	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOE7    1: UART_RXD0
	 * GPIOE6    1: UART_TXD0
	 * GPIOE5    1: UART_RTS0
	 * GPIOE4    6: GPONL41
	 * GPIOE3    6: GPONL12
	 * GPIOE1    6: GPONL11
	 * GPIOE2    6: GPONL40
	 * GPIOE0    1: UART_CTS0
	 */
	writel(0x11166661, SCU1_PINMUX_GRP_E);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOF7    1: UART_RXD1
	 * GPIOF6    1: UART_TXD1
	 * GPIOF5    1: UART_RTS1

	 * GPIOF3    6: GPONL14
	 * GPIOF2    6: GPONL42
	 * GPIOF1    6: GPONL13
	 * GPIOF0    1: UART_CTS1
	 */
	clrsetbits(SCU1_PINMUX_GRP_F,
		   SCU1_PINMUX_PIN7 | SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN5 |
		   SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2 | SCU1_PINMUX_PIN1 |
		   SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN7, 0x1) |
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x1) |
		   FIELD_PREP(SCU1_PINMUX_PIN5, 0x1) |
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x1));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOY7    0: ADC7
	 * GPIOY6    0: ADC6
	 * GPIOY5    0: ADC5
	 * GPIOY4    0: ADC4
	 * GPIOY3    0: ADC3
	 * GPIOY2    0: ADC2
	 * GPIOY1    0: ADC1
	 * GPIOY0    0: ADC0
	 */
	writel(0x00000000, SCU1_PINMUX_GRP_Y);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOZ7    6: GPINL11
	 * GPIOZ6    6: GPINL12
	 * GPIOZ5    6: GPINL13
	 * GPIOZ4    6: GPINL14
	 * GPIOZ3    6: GPINL19
	 * GPIOZ2    6: GPINL20
	 * GPIOZ1    6: GPINL21
	 * GPIOZ0    6: GPINL27
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_Z);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOI7    6: GPINL3
	 * GPIOI6    6: GPONL3
	 * GPIOI5    6: GPINL2
	 * GPIOI4    6: GPONL2
	 * GPIOI3    6: GPINL1
	 * GPIOI2    6: GPONL1
	 * GPIOI1    6: GPINL0
	 * GPIOI0    6: GPONL0
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_I);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOJ7    1: I3CSDA7
	 * GPIOJ6    1: I3CSCL7
	 * GPIOJ5    1: I3CSDA6
	 * GPIOJ4    1: I3CSCL6
	 * GPIOJ3    1: I3CSDA5
	 * GPIOJ2    1: I3CSCL5
	 * GPIOJ1    1: I3CSDA4
	 * GPIOJ0    1: I3CSCL4
	 */
	writel(0x11111111, SCU1_PINMUX_GRP_J);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOK7    1: I3CSDA11
	 * GPIOK6    1: I3CSCL11
	 * GPIOK5    1: I3CSDA10
	 * GPIOK4    1: I3CSCL10
	 * GPIOK3    1: I3CSDA9
	 * GPIOK2    1: I3CSCL9
	 * GPIOK1    1: I3CSDA8
	 * GPIOK0    1: I3CSCL8
	 */
	writel(0x11111111, SCU1_PINMUX_GRP_K);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOL7    6: GPINL24
	 * GPIOL6    6: GPONL24
	 * GPIOL5    6: GPINL23
	 * GPIOL4    6: GPONL23
	 * GPIOL3    6: GPINL16
	 * GPIOL2    6: GPONL16
	 * GPIOL1    6: GPINL15
	 * GPIOL0    6: GPONL15
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_L);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOB7    6: GPINL39
	 * GPIOB6    6: GPINL38
	 * GPIOB5    6: GPINL37
	 * GPIOB4    6: GPINL36
	 * GPIOB3    6: GPINL35
	 * GPIOB2    6: GPINL34
	 * GPIOB1    6: GPINL33
	 * GPIOB0    6: GPINL32
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_B);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOC7    6: GPINL47
	 * GPIOC6    6: GPINL46
	 * GPIOC5    6: GPINL45
	 * GPIOC4    6: GPINL44
	 * GPIOC3    6: GPINL43
	 * GPIOC2    6: GPINL42
	 * GPIOC1    6: GPINL41
	 * GPIOC0    6: GPINL40
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_C);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOD7    6: GPONL39
	 * GPIOD6    6: GPONL38
	 * GPIOD5    6: GPONL37
	 * GPIOD4    6: GPONL36
	 * GPIOD3    6: GPONL35
	 * GPIOD2    6: GPONL34
	 * GPIOD1    6: GPONL33
	 * GPIOD0    6: GPONL32
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_D);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOAA7   6: LTPI_LINK_ALIGNED
	 * GPIOAA6   1: SGPM1LD
	 * GPIOAA5   1: SGPM1CK
	 * GPIOAA4   6: GPINL10
	 * GPIOAA3   6: GPONL10
	 * GPIOAA2   2: HBLED#
	 * GPIOAA1   6: GPINL9
	 * GPIOAA0   6: GPONL9
	 */
	writel(0x61166266, SCU1_PINMUX_GRP_AA);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOH3    1: SGPM1I
	 * GPIOH2    1: SGPM1O
	 */
	clrsetbits(SCU1_PINMUX_GRP_H,
		   SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2,
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x1) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x1));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOP6    6: GPONL43
	 * GPIOP5    6: GPONL21
	 * GPIOP4    6: GPONL20
	 * GPIOP3    6: GPONL19
	 * GPIOP2    6: GPONL46
	 * GPIOP1    6: GPONL45
	 * GPIOP0    6: GPONL44
	 */
	clrsetbits(SCU1_PINMUX_GRP_P,
		   SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN5 | SCU1_PINMUX_PIN4 |
		   SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2 | SCU1_PINMUX_PIN1 |
		   SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN5, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOO6    6: GPILL10
	 *
	 * GPIOO4    6: GPOLL10
	 *
	 * GPIOO3    6: GPILL9
	 * GPIOO2    6: GPOLL9
	 * GPIOO1    6: GPILL8
	 * GPIOO0    6: GPOLL8
	 */
	clrsetbits(SCU1_PINMUX_GRP_O,
		   SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN4 | SCU1_PINMUX_PIN3 |
		   SCU1_PINMUX_PIN2 | SCU1_PINMUX_PIN1 | SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOS5    6: GPONL22
	 * GPIOS4    6: GPINL22
	 *
	 * GPIOS1    6: GPONL47
	 * GPIOS0    6: GPONL27
	 */
	clrsetbits(SCU1_PINMUX_GRP_S,
		   SCU1_PINMUX_PIN5 | SCU1_PINMUX_PIN4 |
		   SCU1_PINMUX_PIN1 | SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN5, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOT7    6: GPILL13
	 * GPIOT6    6: GPOLL13
	 * GPIOT5    6: GPILL12
	 * GPIOT4    6: GPOLL12
	 * GPIOT3    6: GPILL11
	 * GPIOT2    6: GPOLL11
	 */
	clrsetbits(SCU1_PINMUX_GRP_T,
		   SCU1_PINMUX_PIN7 | SCU1_PINMUX_PIN6 | SCU1_PINMUX_PIN5 |
		   SCU1_PINMUX_PIN4 | SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2,
		   FIELD_PREP(SCU1_PINMUX_PIN7, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN6, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN5, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN4, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOU3    6: GPILL15
	 * GPIOU2    6: GPOLL15
	 * GPIOU1    6: GPILL14
	 * GPIOU0    6: GPOLL14
	 */
	clrsetbits(SCU1_PINMUX_GRP_U,
		   SCU1_PINMUX_PIN3 | SCU1_PINMUX_PIN2 |
		   SCU1_PINMUX_PIN1 | SCU1_PINMUX_PIN0,
		   FIELD_PREP(SCU1_PINMUX_PIN3, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN2, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x6) |
		   FIELD_PREP(SCU1_PINMUX_PIN0, 0x6));

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOM7    6: GPILL3
	 * GPIOM6    6: GPOLL3
	 * GPIOM5    6: GPILL2
	 * GPIOM4    6: GPOLL2
	 * GPIOM3    6: GPILL1
	 * GPIOM2    6: GPOLL1
	 * GPIOM1    6: GPILL0
	 * GPIOM0    6: GPOLL0
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_M);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOA7    6: GPILL7
	 * GPIOA6    6: GPOLL7
	 * GPIOA5    6: GPILL6
	 * GPIOA4    6: GPOLL6
	 * GPIOA3    6: GPILL5
	 * GPIOA2    6: GPOLL5
	 * GPIOA1    6: GPILL4
	 * GPIOA0    6: GPOLL4
	 */
	writel(0x66666666, SCU1_PINMUX_GRP_A);

	/*
	 * Pin       MF
	 * --------------------------
	 * GPIOW7    6: GPINL26
	 * GPIOW6    6: GPONL26
	 * GPIOW5    6: GPINL25
	 * GPIOW4    6: GPONL25
	 * GPIOW3    1: I2CSDA5
	 * GPIOW2    1: I2CSCL5
	 * GPIOW1    1: I2CSDA4
	 * GPIOW0    1: I2CSCL4
	 */
	writel(0x66661111, SCU1_PINMUX_GRP_W);
}

bootstage_t ltpi_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { 0, 0 };

	struct ltpi_priv *ltpi0 = &ltpi_data[0];
	struct ltpi_priv *ltpi1 = &ltpi_data[1];
	uint32_t pin_strap = get_pin_strap();
	uint32_t otpcfg_31_30, otpcfg_23_22;
	uint16_t unsupported_speed;
	bool rtfw_en;

	ltpi0->index = 0;
	ltpi1->index = 1;
	ltpi0->bootstage = &sts;
	ltpi1->bootstage = &sts;

	ltpi0->base = LTPI_REG;
	ltpi1->base = LTPI_REG + 0x1000;

	ltpi0->phy_base = ltpi0->base + 0x200;
	ltpi0->top_base = ltpi0->base + 0x800;
	ltpi0->gpio_base = ltpi0->base + 0xc00;
	ltpi0->reset.regs_assert = SCU1_RSTCTL2;
	ltpi0->reset.regs_deassert = SCU1_RSTCTL2_CLR;
	ltpi0->reset.bit_mask = SCU1_RSTCTL2_LTPI0;
	ltpi0->clk_ctrl.regs_gate = SCU1_CLKGATE2;
	ltpi0->clk_ctrl.regs_ungate = SCU1_CLKGATE2_CLR;
	ltpi0->clk_ctrl.bit_mask = SCU1_CLKGATE2_LTPI0_TX;

	ltpi1->phy_base = ltpi1->base + 0x200;
	ltpi1->top_base = ltpi1->base + 0x800;
	ltpi1->gpio_base = ltpi1->base + 0xc00;
	ltpi1->reset.regs_assert = SCU1_RSTCTL2;
	ltpi1->reset.regs_deassert = SCU1_RSTCTL2_CLR;
	ltpi1->reset.bit_mask = SCU1_RSTCTL2_LTPI1;
	ltpi1->clk_ctrl.regs_gate = SCU1_CLKGATE2;
	ltpi1->clk_ctrl.regs_ungate = SCU1_CLKGATE2_CLR;
	ltpi1->clk_ctrl.bit_mask = SCU1_CLKGATE2_LTPI1_TX;

	/*
	 * Enable the LTPI AHB clock.
	 * This clock should always be on and can be safely enabled regardless
	 * of its current status.
	 */
	writel(SCU1_CLKGATE2_LTPI_AHB, SCU1_CLKGATE2_CLR);

#ifdef CONFIG_FPGA_ASPEED
	/* Debug purpose */
	debug("[%08x] %08x\n", SCU1_OTPCFG_31_30, readl(SCU1_OTPCFG_31_30));
	setbits(SCU1_OTPCFG_31_30, SCU1_OTPCFG31_LTPI1_DDR_DIS | SCU1_OTPCFG30_LTPI0_DDR_DIS);
	readl(SCU1_OTPCFG_31_30);
	debug("[%08x] %08x\n", SCU1_OTPCFG_31_30, readl(SCU1_OTPCFG_31_30));
#endif

	/* Parse configurations from the OTP */
	otpcfg_31_30 = readl(SCU1_OTPCFG_31_30);
	otpcfg_23_22 = readl(SCU1_OTPCFG_23_22);

	unsupported_speed = FIELD_GET(SCU1_OTPCFG30_LTPI0_SPEED_CAPA_DIS, otpcfg_31_30);
	ltpi0->otp_speed_cap = LTPI_SP_CAP_ASPEED_SUPPORTED & ~unsupported_speed;
	ltpi0->otp_ddr_dis = !!(otpcfg_31_30 & SCU1_OTPCFG30_LTPI0_DDR_DIS);
	ltpi0->io_driving = FIELD_GET(SCU1_HWSTRAP1_LTPI0_IO_DRIVING, pin_strap);

	unsupported_speed = FIELD_GET(SCU1_OTPCFG31_LTPI1_SPEED_CAPA_DIS, otpcfg_31_30);
	ltpi1->otp_speed_cap = LTPI_SP_CAP_ASPEED_SUPPORTED & ~unsupported_speed;
	ltpi1->otp_ddr_dis = !!(otpcfg_31_30 & SCU1_OTPCFG31_LTPI1_DDR_DIS);
	ltpi1->io_driving = FIELD_GET(SCU1_OTPCFG23_LTPI1_IO_DRIVING, otpcfg_23_22);

	ltpi0->crc_format = !!(otpcfg_23_22 & SCU1_OTPCFG23_LTPI_CRC_FORMAT);
	ltpi1->crc_format = ltpi0->crc_format;

	ltpi0->phy_speed_cap = ltpi0->otp_speed_cap;
	ltpi1->phy_speed_cap = ltpi1->otp_speed_cap;

	ltpi0->clk_inverse = FIELD_GET(SCU1_OTPCFG23_LTPI0_PHYCLK_INV, otpcfg_23_22);
	ltpi1->clk_inverse = FIELD_GET(SCU1_OTPCFG23_LTPI1_PHYCLK_INV, otpcfg_23_22);

	/*
	 * LTPI_MODE    LTPI0_EN    LTPI1_EN    Description
	 * --------------------------------------------------------------------
	 *         1           x           x    SOC is AST1700, HPM mode
	 *         0           0           0    SOC is AST2700, not in SCM mode, skip
	 *         0           0           1    SOC is AST2700, illegal case, skip
	 *         0           1           0    SOC is AST2700, SCM mode + single node
	 *         0           1           1    SOC is AST2700, SCM mode + dual node
	 */
	if (pin_strap & SCU1_HWSTRAP1_LTPI_MODE)
		goto ltpi_hpm_proc;

	if (pin_strap & SCU1_HWSTRAP1_LTPI0_EN) {
		ltpi_scm_set_pins();
		ltpi_scm_init(ltpi0);

		if (pin_strap & SCU1_HWSTRAP1_LTPI1_EN) {
			bootstage_epilogue(*ltpi0->bootstage);
			bootstage_prologue(BOOTSTAGE_LTPI_INIT);
			ltpi1->bootstage->errno = LTPI_STATUS_IDX;
			ltpi1->bootstage->syndrome = LTPI_SYND_OK;
			ltpi_scm_init(ltpi1);
		}
	}

	goto ltpi_done;

ltpi_hpm_proc:
	ltpi_hpm_set_pins();
	ltpi_hpm_init(ltpi0);
	bootstage_epilogue(*ltpi0->bootstage);

	rtfw_en = !!(otpcfg_23_22 & SCU1_OTPCFG23_LTPI_FW_DL_ENA);

	while (1) {
		if (ltpi_get_link_mng_state(ltpi0) != LTPI_LINK_MNG_ST_OP) {
			bootstage_prologue(BOOTSTAGE_LTPI_INIT);
			ltpi_hpm_init(ltpi0);
			bootstage_epilogue(*ltpi0->bootstage);
		}

		if (rtfw_en) {
			if (readl(SCU1_IO_SCRATCH_32) & SCU1_IO_EXPDR_FW_READY) {
				bootstage_prologue(BOOTSTAGE_LTPI_FW_LOAD);
				/* Runtime firmware ready, setup the jump address */
				rom_ctx->fmc_epa = SRAM_MEM;

				ltpi0->bootstage->boot2fmc = BOOTSTAGE_JMP_BOOT2FMC;
				ltpi0->bootstage->errno = BOOTSTAGE_ERR_SUCCESS;
				ltpi0->bootstage->syndrome = 0;
				break;
			}
		}
	}

ltpi_done:
	return sts;
}
