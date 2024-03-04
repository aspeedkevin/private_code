// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 *
 */
#include <bootstage.h>
#include <drivers/scu.h>
#include <drivers/ltpi.h>
#include <drivers/gpio.h>
#include <io.h>
#include <lib/delay.h>
#include <platform.h>
#include <timer.h>

#include "ltpi_top.h"
#include "ltpi_ctrl.h"
#include "internal.h"

#define ADVERTISE_TIMEOUT_US			3000 /* 2.696ms */

struct ltpi_priv {
	uint32_t base[2];
	uint32_t top_base;

	/* encoding as LTPI speed capability */
	uint16_t otp_speed_cap;	/* limit the speed via OTP strap */
	uint16_t phy_speed_cap; /* limit the speed with physical line status */

	int bus_topology;	/* for master mode only.  0: unknown 1:normal mode, 2:cdr mode */

	int dbg_link_partner;
	int dbg_speed;
	int dbg_pll;
};

static struct ltpi_priv ltpi_data;

/* constant lookup tables */
static const int16_t speed_to_pll_lookup[12][2] = {
	{ LTPI_SP_CAP_25M, REG_LTPI_PLL_25M },
	{ LTPI_SP_CAP_50M, REG_LTPI_PLL_50M },
	{ LTPI_SP_CAP_75M, -1 },
	{ LTPI_SP_CAP_100M, REG_LTPI_PLL_100M },
	{ LTPI_SP_CAP_150M, -1 },
	{ LTPI_SP_CAP_200M, REG_LTPI_PLL_200M },
	{ LTPI_SP_CAP_250M, REG_LTPI_PLL_250M },
	{ LTPI_SP_CAP_300M, -1 },
	{ LTPI_SP_CAP_400M, REG_LTPI_PLL_400M },
	{ LTPI_SP_CAP_600M, -1 },
	{ LTPI_SP_CAP_800M, REG_LTPI_PLL_800M },
	{ LTPI_SP_CAP_1G, REG_LTPI_PLL_1G }
};

static const int16_t cdr_speed_to_pll_lookup[12][2] = {
	{ LTPI_SP_CAP_25M, REG_LTPI_PLL_100M },
	{ LTPI_SP_CAP_50M, REG_LTPI_PLL_200M },
	{ LTPI_SP_CAP_75M, -1 },
	{ LTPI_SP_CAP_100M, REG_LTPI_PLL_400M },
	{ LTPI_SP_CAP_150M, -1 },
	{ LTPI_SP_CAP_200M, REG_LTPI_PLL_800M },
	{ LTPI_SP_CAP_250M, REG_LTPI_PLL_250M },
	{ LTPI_SP_CAP_300M, -1 },
	{ LTPI_SP_CAP_400M, REG_LTPI_PLL_400M },
	{ LTPI_SP_CAP_600M, -1 },
	{ LTPI_SP_CAP_800M, REG_LTPI_PLL_800M },
	{ LTPI_SP_CAP_1G, REG_LTPI_PLL_1G }
};

static const int16_t otp_to_speed_mask_lookup[8] = {
	LTPI_SP_CAP_MASK_1G & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_800M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_400M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_250M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_200M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_100M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_50M & LTPI_SP_CAP_ASPEED_SUPPORTED,
	LTPI_SP_CAP_MASK_25M & LTPI_SP_CAP_ASPEED_SUPPORTED
};

static uint32_t get_pin_strap(void);

/**
 * @brief Count the number of leading zeros of a uint16_t
 * @param [IN] x - the uint16_t to be counted
 * @return the number of leading zeros in x
 */
static int clz16(uint16_t x)
{
	int n = 0;

	if (x == 0)
		return sizeof(uint16_t) * 8;

	if (x <= 0x00ff) {
		n += 8;
		x <<= 8;
	}
	if (x <= 0x0fff) {
		n += 4;
		x <<= 4;
	}
	if (x <= 0x3fff) {
		n += 2;
		x <<= 2;
	}
	if (x <= 0x7fff)
		n += 1;

	return n;
}

/**
 * @brief find the bit index of the max attainable speed from the bitmap
 * @param [IN] cap - bitmap of the speed capability
 * @return the bit index of the max attainable speed
 */
static uint16_t find_max_speed(uint16_t cap)
{
	return 15 - clz16(cap & ~LTPI_SP_CAP_DDR);
}

static int ltpi_phy_set_mode(struct ltpi_priv *ltpi, int mode)
{
	uint32_t reg;

	if (mode < 0 || mode > LTPI_PHY_MODE_CDR_HI_SP) {
		LOG_ERR("%s: invalid mode %d\n", __func__, mode);
		return -1;
	}

	reg = readl(ltpi->top_base + LTPI_PHY_CTRL);
	reg &= ~REG_LTPI_PHY_MODE;
	reg |= mode;
	writel(reg, ltpi->top_base + LTPI_PHY_CTRL);

	return 0;
}

static int ltpi_phy_set_pll(struct ltpi_priv *ltpi, int freq, int set)
{
	uint32_t reg;

	if (freq < REG_LTPI_PLL_25M || freq > REG_LTPI_PLL_1G) {
		LOG_ERR("%s: invalid freq %d\n", __func__, freq);
		return -1;
	}

	reg = readl(ltpi->top_base + LTPI_PLL_CTRL);
	reg &= ~(REG_LTPI_PLL_SELECT | REG_LTPI_PLL_SET);
	reg |= FIELD_PREP(REG_LTPI_PLL_SELECT, freq);

	if (set)
		reg |= REG_LTPI_PLL_SET;

	writel(reg, ltpi->top_base + LTPI_PLL_CTRL);

	return 0;
}

static int ltpi_reset(struct ltpi_priv *ltpi)
{
	writel(BIT(20), SCU1_REG + 0x220);
	readl(SCU1_REG + 0x220);

	udelay(1);

	writel(BIT(20), SCU1_REG + 0x224);
	readl(SCU1_REG + 0x224);

	return 0;
}

/**
 * @brief Set LTPI_LINK_ALIGNED (GPIOAA7) pin
 * @param [IN] value - 0: not aligned, others: aligned
 */
static void ltpi_set_link_aligned_pin(int value)
{
	uint32_t addr = GPIO1_REG + GPIO(AA, 7);
	uint32_t reg = 0;

	reg |= FIELD_PREP(GPIO_DIRECT, GPIO_DIRECT_OUT);
	reg |= FIELD_PREP(GPIO_DATA, !!value);
	writel(reg, addr);
}

static void ltpi_slave_init_sgpio(void)
{
	uint32_t value;
	uint32_t pin_strap = get_pin_strap();

	/*
	 * SGPIO master controller #1:
	 *
	 * Register 0x0
	 * - bit[31:16] clock divider
	 *     SGPIO clock = (PCLK 100M / 2) / (divider + 1)
	 *     select divider = 4 -> SGPIO clock = 50MHz / (4 + 1) = 10MHz
	 * - bit[11: 3] pin number
	 *     enable 112 parallel pins (BMC_GPIO 96 pins + PFR_GPIO 16 pins)
	 * - bit[0] SGPIO controller enabling
	 */
	if ((pin_strap & SCU1_HWSTRAP1_LTPI_NUM) && (pin_strap & SCU1_HWSTRAP1_LTPI_IDX)) {
		/*
		 * The 2nd AST1700 does't need to configure SGPIO since GPIO
		 * channel only exists in the 1st AST1700
		 */
		writel(0, SGPIOM1_REG + 0x0);
	} else {
		value = FIELD_PREP(GENMASK(31, 16), 4) |
			FIELD_PREP(GENMASK(11, 3), 112) | BIT(0);
		writel(value, SGPIOM1_REG + 0x0);
	}
}

static uint32_t ltpi_get_link_manage_state(struct ltpi_priv *ltpi, int index)
{
	uint32_t reg;

	reg = readl(ltpi->base[index] + LTPI_LINK_MANAGE_ST);
	return FIELD_GET(REG_LTPI_LINK_MANAGE_ST, reg);
}

static int ltpi_poll_link_manage_state(struct ltpi_priv *ltpi, int index, uint32_t expected,
				       uint32_t unexpected, int timeout_us)
{
	uint64_t start, timeout_tick;
	uint32_t addr = ltpi->base[index] + LTPI_LINK_MANAGE_ST;
	uint32_t reg = readl(addr);
	uint32_t state;
	int ret = LTPI_OK;

	if (timeout_us) {
		start = get_ticks();
		timeout_tick = timeout_us * (CONFIG_COUNTER_FREQUENCY / 1000000);
	}

	do {
		reg = readl(addr);
		state = FIELD_GET(REG_LTPI_LINK_MANAGE_ST, reg);

		if (state == expected)
			break;

		if (state == unexpected) {
			/* link is disconnected, break the loop directly */
			ret = LTPI_ERR_REMOTE_DISCON;
			break;
		}

		if (timeout_us && ((get_ticks() - start) > timeout_tick)) {
			ret = LTPI_ERR_TIMEOUT;
			break;
		}
	} while (1);

	return ret;
}

static int ltpi_slave_wait_pll_set_state(struct ltpi_priv *ltpi)
{
	return ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_WAIT_PLL_SET, -1, 0);
}

static int ltpi_slave_wait_op_state(struct ltpi_priv *ltpi)
{
	return ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_OP,
					   LTPI_LINK_MANAGE_ST_DETECT_ALIGN, ADVERTISE_TIMEOUT_US);
}

static int ltpi_master_get_link_partner(struct ltpi_priv *ltpi, int index)
{
	uint32_t reg = readl(ltpi->base[index] + LTPI_LINK_MANAGE_ST);

	return FIELD_GET(REG_LTPI_LINK_PARTNER_FLAG, reg);
}

static int ltpi_master_set_local_speed_cap(struct ltpi_priv *ltpi, int index, uint32_t speed_cap)
{
	uint32_t reg;

	/* only set bits that Aspeed SOC supported */
	speed_cap &= LTPI_SP_CAP_ASPEED_SUPPORTED;

	reg = readl(ltpi->base[index] + LTPI_CAP_LOCAL);
	reg &= ~REG_LTPI_SP_CAP_LOCAL;
	reg |= FIELD_PREP(REG_LTPI_SP_CAP_LOCAL, speed_cap);
	writel(reg, ltpi->base[index] + LTPI_CAP_LOCAL);

	return 0;
}

static int ltpi_master_set_sdr_mode(struct ltpi_priv *ltpi)
{
	ltpi_reset(ltpi);
	ltpi_master_set_local_speed_cap(ltpi, 0, ltpi->phy_speed_cap);
	ltpi_phy_set_pll(ltpi, REG_LTPI_PLL_25M, 0);
	udelay(1600);
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_SDR);

	return ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_SPEED,
					   -1, ADVERTISE_TIMEOUT_US);
}

static int ltpi_master_set_cdr_mode(struct ltpi_priv *ltpi)
{
	ltpi_reset(ltpi);
	ltpi_master_set_local_speed_cap(ltpi, 0, ltpi->phy_speed_cap);
	ltpi_master_set_local_speed_cap(ltpi, 1, ltpi->phy_speed_cap);

	/* Disable LTPI1 I2C/UART/GPIO passthrough */
	writel(0x18, ltpi->base[1] + LTPI_AD_CAP_LOW_LOCAL);
	writel(0x0, ltpi->base[1] + LTPI_AD_CAP_HIGH_LOCAL);

	ltpi_phy_set_pll(ltpi, REG_LTPI_PLL_100M, 0);
	udelay(1600);
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_LO_SP);

	return ltpi_poll_link_manage_state(ltpi, 1, LTPI_LINK_MANAGE_ST_SPEED,
					   -1, ADVERTISE_TIMEOUT_US);
}

static void ltpi_master_normal_mode_training(struct ltpi_priv *ltpi)
{
	uint32_t reg, speed_cap;
	int target_speed, ret;

	do {
		ret = ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_WAIT_PLL_SET, -1, 0);

		/* read intersection of the speed capabilities */
		reg = readl(ltpi->base[0] + LTPI_LINK_MANAGE_ST);
		speed_cap = FIELD_GET(REG_LTPI_SP_INTERSETION, reg);
		if (speed_cap == 0) {
			bootstage_start_mark(BOOTSTAGE_LTPI_SP_CAP);
			bootstage_end_status(BOOTSTAGE_LTPI_SP_CAP_E_NC |
					     BOOTSTAGE_LTPI_MODE_SDR);
			return;
		}
		ltpi->phy_speed_cap = speed_cap;

		/* find max attainable speed */
		target_speed = find_max_speed(speed_cap);

		/* set phy mode "OFF" */
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);

		/* set PLL freq to the target speed */
		ltpi_phy_set_pll(ltpi, speed_to_pll_lookup[target_speed][1], 1);
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_SDR);

		/* poll link state 0x7 */
		ret = ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_OP,
						  LTPI_LINK_MANAGE_ST_DETECT_ALIGN,
						  ADVERTISE_TIMEOUT_US);
		if (ret == 0)
			break;

		/* clear the bit to specify the current speed doesn't work */
		ltpi->phy_speed_cap &= ~BIT(target_speed);
		ltpi_master_set_sdr_mode(ltpi);
		bootstage_start_mark(BOOTSTAGE_LTPI_WAIT_OP);
		bootstage_end_status(ret | BOOTSTAGE_LTPI_MODE_SDR);
	} while (1);

	ltpi->dbg_link_partner = ltpi_master_get_link_partner(ltpi, 0);
	ltpi->dbg_speed = target_speed;
	ltpi->dbg_pll = speed_to_pll_lookup[target_speed][1];
	LOG_DBG("Link partner is %s\n", ltpi->dbg_link_partner ? "ast1700" : "fpga");
}

static void ltpi_master_cdr_mode_training(struct ltpi_priv *ltpi)
{
	uint32_t reg, speed_cap[2];
	int target_speed, max_speed[2], ret;

	do {
		ret = ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_WAIT_PLL_SET, -1, 0);
		ret = ltpi_poll_link_manage_state(ltpi, 1, LTPI_LINK_MANAGE_ST_WAIT_PLL_SET, -1, 0);

		/* read intersection of the speed capabilities */
		reg = readl(ltpi->base[0] + LTPI_LINK_MANAGE_ST);
		speed_cap[0] = FIELD_GET(REG_LTPI_SP_INTERSETION, reg);
		reg = readl(ltpi->base[1] + LTPI_LINK_MANAGE_ST);
		speed_cap[1] = FIELD_GET(REG_LTPI_SP_INTERSETION, reg);
		if ((speed_cap[0] & speed_cap[1]) == 0) {
			bootstage_start_mark(BOOTSTAGE_LTPI_SP_CAP);
			bootstage_end_status(BOOTSTAGE_LTPI_SP_CAP_E_NC |
					     BOOTSTAGE_LTPI_MODE_CDR);
			return;
		}
		ltpi->phy_speed_cap = speed_cap[0] & speed_cap[1];

		/* find max attainable speed */
		max_speed[0] = find_max_speed(speed_cap[0]);
		max_speed[1] = find_max_speed(speed_cap[1]);
		if (max_speed[0] != max_speed[1]) {
			bootstage_start_mark(BOOTSTAGE_LTPI_SP_CAP);
			bootstage_end_status(BOOTSTAGE_LTPI_SP_CAP_E_NS |
					     BOOTSTAGE_LTPI_MODE_CDR);
			goto retrain_cdr;
		}
		target_speed = max_speed[0];

		/* set phy mode "OFF" */
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);

		/* set PLL freq to the target speed */
		ltpi_phy_set_pll(ltpi, cdr_speed_to_pll_lookup[target_speed][1], 1);

		if (BIT(target_speed) > LTPI_SP_CAP_200M)
			ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_HI_SP);
		else
			ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_LO_SP);

		/* poll link state 0x7 */
		ret = ltpi_poll_link_manage_state(ltpi, 0, LTPI_LINK_MANAGE_ST_OP,
						  LTPI_LINK_MANAGE_ST_DETECT_ALIGN,
						  ADVERTISE_TIMEOUT_US);
		ret |= ltpi_poll_link_manage_state(ltpi, 1, LTPI_LINK_MANAGE_ST_OP,
						   LTPI_LINK_MANAGE_ST_DETECT_ALIGN,
						   ADVERTISE_TIMEOUT_US);
		if (ret == LTPI_OK)
			break;

		/* clear the bit to specify the current speed doesn't work */
		ltpi->phy_speed_cap &= ~BIT(target_speed);
retrain_cdr:
		ltpi_master_set_cdr_mode(ltpi);
		bootstage_start_mark(BOOTSTAGE_LTPI_WAIT_OP);
		bootstage_end_status(ret | BOOTSTAGE_LTPI_MODE_CDR);
	} while (1);

	LOG_DBG("Link partner #0 is %s\n",
		ltpi_master_get_link_partner(ltpi, 0) ? "ast1700" : "fpga");

	LOG_DBG("Link partner #1 is %s\n",
		ltpi_master_get_link_partner(ltpi, 1) ? "ast1700" : "fpga");

	ltpi->dbg_speed = target_speed;
	ltpi->dbg_pll = cdr_speed_to_pll_lookup[target_speed][1];
}

static void ltpi_init_master_mode(struct ltpi_priv *ltpi)
{
	int ret;
	uint32_t reg, phy_mode, state0, state1;

	bootstage_start_mark(BOOTSTAGE_LTPI_INIT);
	/* start checking whether LTPI is initialized */
	reg = readl(ltpi->top_base + LTPI_PHY_CTRL);
	phy_mode = FIELD_GET(REG_LTPI_PHY_MODE, reg);

	/* if the phy mode is in SDR mode, check the state of ltpi0 */
	if (phy_mode == LTPI_PHY_MODE_SDR) {
		state0 = ltpi_get_link_manage_state(ltpi, 0);
		if (state0 == LTPI_LINK_MANAGE_ST_OP) {
			ltpi->bus_topology = 1;
			bootstage_end_status(BOOTSTAGE_LTPI_INIT_SKIP |
					     BOOTSTAGE_LTPI_MODE_SDR);
			return;
		}
	}

	/* if the phy mode is in CDR mode, check the states of ltpi0 and ltpi1 */
	if (phy_mode == LTPI_PHY_MODE_CDR_HI_SP ||
	    phy_mode == LTPI_PHY_MODE_CDR_LO_SP) {
		state0 = ltpi_get_link_manage_state(ltpi, 0);
		state1 = ltpi_get_link_manage_state(ltpi, 1);
		if (state0 == LTPI_LINK_MANAGE_ST_OP &&
		    state1 == LTPI_LINK_MANAGE_ST_OP) {
			ltpi->bus_topology = 2;
			bootstage_end_status(BOOTSTAGE_LTPI_INIT_SKIP |
					     BOOTSTAGE_LTPI_MODE_CDR);
			return;
		}
	}

	/*
	 * LTPI initialization is required. At this stage, the topology (SDR or
	 * CDR) is not known yet.
	 */
	bootstage_end_status(BOOTSTAGE_LTPI_INIT_REQUIRE |
			     BOOTSTAGE_LTPI_MODE_NONE);

	ltpi->bus_topology = 0;
	while (1) {
		ret = ltpi_master_set_sdr_mode(ltpi);
		if (ret == LTPI_OK) {
			ltpi->bus_topology = 1;
			break;
		}

		ret = ltpi_master_set_cdr_mode(ltpi);
		if (ret == LTPI_OK) {
			ltpi->bus_topology = 2;
			break;
		}
	}

	LOG_INF("master bus topology: %d\n", ltpi->bus_topology);

	if (ltpi->bus_topology == 2)
		ltpi_master_cdr_mode_training(ltpi);
	else
		ltpi_master_normal_mode_training(ltpi);
}

static int ltpi_init_slave_normal_mode(struct ltpi_priv *ltpi)
{
	uint32_t reg, speed_cap;
	int target_speed, ret;

	ltpi_master_set_local_speed_cap(ltpi, 0, ltpi->phy_speed_cap);
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_SDR);

	/* wait forever until PLL_SET_STATE */
	ret = ltpi_slave_wait_pll_set_state(ltpi);

	reg = readl(ltpi->base[0] + LTPI_LINK_MANAGE_ST);
	speed_cap = FIELD_GET(REG_LTPI_SP_INTERSETION, reg);
	if (speed_cap == 0) {
		bootstage_start_mark(BOOTSTAGE_LTPI_SP_CAP);
		bootstage_end_status(BOOTSTAGE_LTPI_SP_CAP_E_NC |
				     BOOTSTAGE_LTPI_MODE_SDR);
		ret = LTPI_ERR_SEVERE;
		goto end;
	}

	/* find max attainable speed */
	target_speed = find_max_speed(speed_cap);

	/* set phy mode "OFF" */
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);

	/* set PLL freq to the target speed */
	ltpi_phy_set_pll(ltpi, speed_to_pll_lookup[target_speed][1], 1);
	/* set phy mode "SDR" */
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_SDR);

	/* poll link state 0x7 */
	ret = ltpi_slave_wait_op_state(ltpi);
end:
	if (ret) {
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);
		ltpi_phy_set_pll(ltpi, REG_LTPI_PLL_25M, 0);
		ltpi_reset(ltpi);
		bootstage_start_mark(BOOTSTAGE_LTPI_WAIT_OP);
		bootstage_end_status(ret | BOOTSTAGE_LTPI_MODE_SDR);
		return ret;
	}

	ltpi->dbg_link_partner = ltpi_master_get_link_partner(ltpi, 0);
	ltpi->dbg_speed = target_speed;
	ltpi->dbg_pll = speed_to_pll_lookup[target_speed][1];
	LOG_DBG("Link partner is %s\n",
		ltpi->dbg_link_partner ? "ast1700/2700" : "fpga");

	return LTPI_OK;
}

static void ltpi_slave_normal_mode_loop(struct ltpi_priv *ltpi)
{
	int ret;
	uint32_t state = ltpi_get_link_manage_state(ltpi, 0);

	bootstage_start_mark(BOOTSTAGE_LTPI_INIT);
	if (state == LTPI_LINK_MANAGE_ST_OP) {
		bootstage_end_status(BOOTSTAGE_LTPI_INIT_SKIP |
				     BOOTSTAGE_LTPI_MODE_SDR);
		return;
	}
	bootstage_end_status(BOOTSTAGE_LTPI_INIT_REQUIRE |
			     BOOTSTAGE_LTPI_MODE_SDR);

	ltpi_set_link_aligned_pin(0);

	do {
		LOG_DBG("%s: %x\n", __func__, ltpi->phy_speed_cap);
		ret = ltpi_init_slave_normal_mode(ltpi);

		/* Severe error! do not retry */
		if (ret == LTPI_ERR_SEVERE)
			break;

	} while (ret != LTPI_OK);

	if (ret == LTPI_OK) {
		ltpi_slave_init_sgpio();
		ltpi_set_link_aligned_pin(1);
	}
}

static int ltpi_init_slave_cdr_mode(struct ltpi_priv *ltpi)
{
	uint32_t reg, speed_cap;
	int target_speed, ret;

	ltpi_master_set_local_speed_cap(ltpi, 0, ltpi->phy_speed_cap);
	ltpi_phy_set_pll(ltpi, REG_LTPI_PLL_100M, 0);
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_LO_SP);

	ret = ltpi_slave_wait_pll_set_state(ltpi);
	reg = readl(ltpi->base[0] + LTPI_LINK_MANAGE_ST);
	speed_cap = FIELD_GET(REG_LTPI_SP_INTERSETION, reg);
	if (speed_cap == 0) {
		bootstage_start_mark(BOOTSTAGE_LTPI_SP_CAP);
		bootstage_end_status(BOOTSTAGE_LTPI_SP_CAP_E_NC |
				     BOOTSTAGE_LTPI_MODE_CDR);
		ret = LTPI_ERR_SEVERE;
		goto cdr_end;
	}

	/* find max attainable speed */
	target_speed = find_max_speed(speed_cap);

	/* set phy mode "OFF" */
	ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);

	/* set PLL freq to the target speed */
	ltpi_phy_set_pll(ltpi, cdr_speed_to_pll_lookup[target_speed][1], 1);

	if (BIT(target_speed) > LTPI_SP_CAP_200M)
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_HI_SP);
	else
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_CDR_LO_SP);

	/* poll link state 0x7 */
	ret = ltpi_slave_wait_op_state(ltpi);
cdr_end:
	if (ret) {
		ltpi_phy_set_mode(ltpi, LTPI_PHY_MODE_OFF);
		ltpi_phy_set_pll(ltpi, REG_LTPI_PLL_100M, 0);
		ltpi_reset(ltpi);
		bootstage_start_mark(BOOTSTAGE_LTPI_WAIT_OP);
		bootstage_end_status(ret | BOOTSTAGE_LTPI_MODE_CDR);
		return ret;
	}

	LOG_DBG("Link partner is %s\n",
		ltpi_master_get_link_partner(ltpi, 0) ? "ast1700/2700" : "fpga");

	ltpi->dbg_speed = target_speed;
	ltpi->dbg_pll = cdr_speed_to_pll_lookup[target_speed][1];

	return LTPI_OK;
}

static void ltpi_slave_cdr_mode_loop(struct ltpi_priv *ltpi)
{
	int ret;
	uint32_t state = ltpi_get_link_manage_state(ltpi, 0);

	bootstage_start_mark(BOOTSTAGE_LTPI_INIT);
	if (state == LTPI_LINK_MANAGE_ST_OP) {
		bootstage_end_status(BOOTSTAGE_LTPI_INIT_SKIP |
				     BOOTSTAGE_LTPI_MODE_CDR);
		return;
	}
	bootstage_end_status(BOOTSTAGE_LTPI_INIT_REQUIRE |
			     BOOTSTAGE_LTPI_MODE_CDR);

	ltpi_set_link_aligned_pin(0);

	do {
		LOG_DBG("%s: %x\n", __func__, ltpi->phy_speed_cap);
		ret = ltpi_init_slave_cdr_mode(ltpi);

		/* Severe error! do not retry */
		if (ret == LTPI_ERR_SEVERE)
			break;

	} while (ret != LTPI_OK);

	if (ret == LTPI_OK) {
		ltpi_slave_init_sgpio();
		ltpi_set_link_aligned_pin(1);
	}
}

static uint32_t get_pin_strap(void)
{
	return readl(SCU1_HWSTRAP1);
}

static uint32_t get_otp_strap(void)
{
	return readl(SCU1_HWSTRAP2);
}

static void ltpi_master_set_pins(void)
{
	uint32_t otp_strap = get_otp_strap();
	uint32_t reg;

	/* if LTPI_IO_TYPE == 1, FSI mode */
	if (otp_strap & SCU1_HWSTRAP2_LTPI_IO_TYPE) {
		/*
		 * 0x42c[15:12] = 0x3 -> LTPI_RXDAT
		 * 0x42c[11:8]  = 0x3 -> LTPI_TXDAT
		 * 0x42c[7:4]   = 0x3 -> LTPI_RXCLK
		 * 0x42c[3:0]   = 0x3 -> LTPI_TXCLK
		 */
		reg = readl(SCU1_REG + 0x42c);
		reg &= ~GENMASK(15, 0);
		reg |= 0x3333;
		writel(reg, SCU1_REG + 0x42c);
	}

	/*
	 * 0x404[31:28] = 0x6 -> SCM_GPO7
	 * 0x404[27:24] = 0x6 -> SCM_GPO6
	 * 0x404[23:20] = 0x6 -> SCM_GPO5
	 * 0x404[19:16] = 0x6 -> SCM_GPO4
	 * 0x404[15:12] = 0x6 -> SCM_GPO3
	 * 0x404[11:8]  = 0x6 -> SCM_GPO2
	 * 0x404[7:4]   = 0x6 -> SCM_GPO1
	 * 0x404[3:0]   = 0x6 -> SCM_GPO0
	 */
	writel(0x66666666, SCU1_REG + 0x404);

	/*
	 * 0x408[31:28] = 0x6 -> SCM_GPI3
	 * 0x408[27:24] = 0x6 -> SCM_GPI2
	 * 0x408[23:20] = 0x6 -> SCM_GPI1
	 * 0x408[19:16] = 0x6 -> SCM_GPI0
	 * 0x408[15:12] = 0x6 -> SCM_GPO11
	 * 0x408[11:8]  = 0x6 -> SCM_GPO10
	 * 0x408[7:4]   = 0x6 -> SCM_GPO9
	 * 0x408[3:0]   = 0x6 -> SCM_GPO8
	 *
	 * 0x40c[31:28] = 0x6 -> HPM_GPO3
	 * 0x40c[27:24] = 0x6 -> HPM_GPO2
	 * 0x40c[23:20] = 0x6 -> HPM_GPO1
	 * 0x40c[19:16] = 0x6 -> HPM_GPO0
	 * 0x40c[15:12] = 0x6 -> HPM_GPI3
	 * 0x40c[11:8]  = 0x6 -> HPM_GPI2
	 * 0x40c[7:4]   = 0x6 -> HPM_GPI1
	 * 0x40c[3:0]   = 0x6 -> HPM_GPI0
	 */
	writel(0x66666666, SCU1_REG + 0x408);
	writel(0x66666666, SCU1_REG + 0x40c);

	/*
	 * 0x44c[27:24] = 0x5 -> SGPSCK
	 * 0x44c[7:4]   = 0x5 -> SGPSLD
	 */
	reg = readl(SCU1_REG + 0x44c);
	reg &= ~(GENMASK(27, 24) | GENMASK(7, 4));
	reg |= ((0x5 << 24) | (0x5 << 4));
	writel(reg, SCU1_REG + 0x44c);

	/*
	 * 0x450[15:12] = 0x5 -> SGPSMI
	 * 0x450[11:8]  = 0x5 -> SGPSMO
	 */
	reg = readl(SCU1_REG + 0x450);
	reg &= ~GENMASK(15, 8);
	reg |= (0x55 << 8);
	writel(reg, SCU1_REG + 0x450);

	/* Enable SGPIO slave */
	writel(0x1, SGPIOS_REG);
}

static void ltpi_slave_set_pins(void)
{
	uint32_t value;
	uint32_t otp_strap = get_otp_strap();

	/*
	 * 0x400[31:28] = 0x7 -> GPILL7 (SIOPWRGD1)
	 * 0x400[27:24] = 0x7 -> GPOLL7 (SIOPWREQN1)
	 * 0x400[23:20] = 0x7 -> GPILL6 (SIOS3N1)
	 * 0x400[19:16] = 0x7 -> GPOLL6 (SIOSCIN1) OD
	 * 0x400[15:12] = 0x7 -> GPILL5 (SIOPBIN1)
	 * 0x400[11:8]  = 0x7 -> GPOLL5 (SIOONCTRLN1) OD
	 * 0x400[7:4]   = 0x7 -> GPILL4 (SIOS5N1)
	 * 0x400[3:0]   = 0x7 -> GPOLL4 (SIOPBON1) OD
	 */
	writel(0x77777777, SCU1_REG + 0x400);

	/*
	 * 0x404[31:28] = 0x1 -> TACH7
	 * 0x404[27:24] = 0x1 -> TACH6
	 * 0x404[23:20] = 0x1 -> TACH5
	 * 0x404[19:16] = 0x1 -> TACH4
	 * 0x404[15:12] = 0x1 -> TACH3
	 * 0x404[11:8]  = 0x1 -> TACH2
	 * 0x404[7:4]   = 0x1 -> TACH1
	 * 0x404[3:0]   = 0x1 -> TACH0
	 *
	 * 0x408[31:28] = 0x1 -> TACH15
	 * 0x408[27:24] = 0x1 -> TACH14
	 * 0x408[23:20] = 0x1 -> TACH13
	 * 0x408[19:16] = 0x1 -> TACH12
	 * 0x408[15:12] = 0x1 -> TACH11
	 * 0x408[11:8]  = 0x1 -> TACH10
	 * 0x408[7:4]   = 0x1 -> TACH9
	 * 0x408[3:0]   = 0x1 -> TACH8
	 *
	 * 0x40c[31:28] = 0x1 -> PWM7
	 * 0x40c[27:24] = 0x1 -> PWM6
	 * 0x40c[23:20] = 0x1 -> PWM5
	 * 0x40c[19:16] = 0x1 -> PWM4
	 * 0x40c[15:12] = 0x1 -> PWM3
	 * 0x40c[11:8]  = 0x1 -> PWM2
	 * 0x40c[7:4]   = 0x1 -> PWM1
	 * 0x40c[3:0]   = 0x1 -> PWM0
	 */
	writel(0x11111111, SCU1_REG + 0x404);
	writel(0x11111111, SCU1_REG + 0x408);
	writel(0x11111111, SCU1_REG + 0x40c);

	/*
	 * 0x410[31:28] = 0x1 -> UART_RXD0
	 * 0x410[27:24] = 0x1 -> UART_TXD0
	 * 0x410[23:20] = 0x1 -> UART_RTS0
	 * 0x410[19:16] = 0x6 -> GPINL12
	 * 0x410[15:12] = 0x6 -> GPONL12
	 * 0x410[11:8]  = 0x6 -> GPINL11
	 * 0x410[7:4]   = 0x6 -> GPONL11
	 * 0x410[3:0]   = 0x1 -> UART_CTS0
	 */
	writel(0x11166661, SCU1_REG + 0x410);

	/*
	 * 0x414[31:28] = 0x1 -> UART_RXD1
	 * 0x414[27:24] = 0x1 -> UART_TXD1
	 * 0x414[23:20] = 0x1 -> UART_RTS1
	 * 0x414[19:16] = 0x0 -> GPIOF4
	 * 0x414[15:12] = 0x6 -> GPONL14
	 * 0x414[11:8]  = 0x6 -> GPINL13
	 * 0x414[7:4]   = 0x6 -> GPONL13
	 * 0x414[3:0]   = 0x1 -> UART_CTS1
	 */
	writel(0x11106661, SCU1_REG + 0x414);

	/*
	 * 0x418[31:28] = 0x6 -> GPINL7
	 * 0x418[27:24] = 0x6 -> GPONL7
	 * 0x418[23:20] = 0x6 -> GPINL6
	 * 0x418[19:16] = 0x6 -> GPONL6
	 * 0x418[15:12] = 0x6 -> GPINL5
	 * 0x418[11:8]  = 0x6 -> GPONL5
	 * 0x418[7:4]   = 0x6 -> GPINL4
	 * 0x418[3:0]   = 0x6 -> GPONL4
	 */
	writel(0x66666666, SCU1_REG + 0x418);

	/*
	 * 0x41c[15:12] = 0x1 -> SGPM1I
	 * 0x41c[11:8]  = 0x1 -> SGPM1O
	 * 0x41c[7:4]   = 0x6 -> GPINL8
	 * 0x41c[3:0]   = 0x6 -> GPONL8
	 */
	value = readl(SCU1_REG + 0x41c);
	value &= ~GENMASK(15, 0);
	value |= 0x1166;
	writel(value, SCU1_REG + 0x41c);

	/*
	 * 0x420[31:28] = 0x6 -> GPINL3
	 * 0x420[27:24] = 0x6 -> GPONL3
	 * 0x420[23:20] = 0x6 -> GPINL2
	 * 0x420[19:16] = 0x6 -> GPONL2
	 * 0x420[15:12] = 0x6 -> GPINL1
	 * 0x420[11:8]  = 0x6 -> GPONL1
	 * 0x420[7:4]   = 0x6 -> GPINL0
	 * 0x420[3:0]   = 0x6 -> GPONL0
	 */
	writel(0x66666666, SCU1_REG + 0x420);

	/*
	 * 0x424[31:28] = 0x1 -> I3CSDA3
	 * 0x424[27:24] = 0x1 -> I3CSCL3
	 * 0x424[23:20] = 0x1 -> I3CSDA2
	 * 0x424[19:16] = 0x1 -> I3CSCL2
	 * 0x424[15:12] = 0x1 -> I3CSDA1
	 * 0x424[11:8]  = 0x1 -> I3CSCL1
	 * 0x424[7:4]   = 0x1 -> I3CSDA0
	 * 0x424[3:0]   = 0x1 -> I3CSCL0
	 *
	 * 0x428[31:28] = 0x1 -> I3CSDA7
	 * 0x428[27:24] = 0x1 -> I3CSCL7
	 * 0x428[23:20] = 0x1 -> I3CSDA6
	 * 0x428[19:16] = 0x1 -> I3CSCL6
	 * 0x428[15:12] = 0x1 -> I3CSDA5
	 * 0x428[11:8]  = 0x1 -> I3CSCL5
	 * 0x428[7:4]   = 0x1 -> I3CSDA4
	 * 0x428[3:0]   = 0x1 -> I3CSCL4
	 */
	writel(0x11111111, SCU1_REG + 0x424);
	writel(0x11111111, SCU1_REG + 0x428);

	/*
	 * if LTPI_IO_TYPE == 1, FSI mode
	 *   0x42c[15:12] = 0x3 -> LTPI_RXDAT
	 *   0x42c[11:8]  = 0x3 -> LTPI_TXDAT
	 *   0x42c[7:4]   = 0x3 -> LTPI_RXCLK
	 *   0x42c[3:0]   = 0x3 -> LTPI_TXCLK
	 * else
	 *   0x42c[15:12] = 0x6 -> GPONL16
	 *   0x42c[11:8]  = 0x6 -> GPINL16
	 *   0x42c[7:4]   = 0x6 -> GPONL15
	 *   0x42c[3:0]   = 0x6 -> GPINL15
	 */
	if (otp_strap & SCU1_HWSTRAP2_LTPI_IO_TYPE)
		writel(0x00003333, SCU1_PINMUX12);
	else
		writel(0x00006666, SCU1_PINMUX12);

	/*
	 * 0x430[31:28] = 0x6 -> GPILL3 (SIOPWRGD0)
	 * 0x430[27:24] = 0x6 -> GPOLL3 (SIOPWREQN0)
	 * 0x430[23:20] = 0x6 -> GPILL2 (SIOS3N0)
	 * 0x430[19:16] = 0x6 -> GPOLL2 (SIOSCIN0) OD
	 * 0x430[15:12] = 0x6 -> GPILL1 (SIOPBIN0)
	 * 0x430[11:8]  = 0x6 -> GPOLL1 (SIOONCTRLN0) OD
	 * 0x430[7:4]   = 0x6 -> GPILL0 (SIOS5N0)
	 * 0x430[3:0]   = 0x6 -> GPOLL0 (SIOPBON0) OD
	 */
	writel(0x66666666, SCU1_PINMUX13);

	/*
	 * 0x434[31:28] = 0x0 -> GPION7
	 * 0x434[27:24] = 0x0 -> GPION6
	 * 0x434[23:20] = 0x0 -> GPION5
	 * 0x434[19:16] = 0x0 -> GPION4
	 * 0x434[15:12] = 0x0 -> GPION3
	 * 0x434[11:8]  = 0x0 -> GPION2
	 * 0x434[7:4]   = 0x0 -> GPION1
	 * 0x434[3:0]   = 0x0 -> GPION0
	 */
	writel(0x00000000, SCU1_REG + 0x434);

	/*
	 * 0x438[31:28] = 0x0 -> GPIOO7
	 * 0x438[27:24] = 0x6 -> GPILL10
	 * 0x438[23:20] = 0x0 -> GPIOO5
	 * 0x438[19:16] = 0x6 -> GPOLL10
	 * 0x438[15:12] = 0x6 -> GPILL19
	 * 0x438[11:8]  = 0x6 -> GPOLL9
	 * 0x438[7:4]   = 0x6 -> GPILL8
	 * 0x438[3:0]   = 0x6 -> GPOLL8
	 */
	writel(0x06066666, SCU1_REG + 0x438);

	/*
	 * 0x43c[31:28] = 0x0 -> GPIOP7
	 * 0x43c[27:24] = 0x6 -> GPINL14
	 * 0x43c[23:20] = 0x1 -> SPIDQ3
	 * 0x43c[19:16] = 0x1 -> SPIDQ2
	 * 0x43c[15:12] = 0x1 -> SPIMISO
	 * 0x43c[11:8]  = 0x1 -> SPIMOSI
	 * 0x43c[7:4]   = 0x1 -> SPICK
	 * 0x43c[3:0]   = 0x1 -> SPICS0#
	 */
	writel(0x06111111, SCU1_REG + 0x43c);

	/*
	 * 0x440[31:28] = 0x0 -> GPIOQ7
	 * 0x440[27:24] = 0x1 -> MTDO
	 * 0x440[23:20] = 0x1 -> MTDI
	 * 0x440[19:16] = 0x1 -> MTMS
	 * 0x440[15:12] = 0x1 -> MTCK
	 * 0x440[11:8]  = 0x1 -> MNTRST
	 * 0x440[7:4]   = 0x0 -> GPIOQ1
	 * 0x440[3:0]   = 0x0 -> GPIOQ0
	 */
	writel(0x01111100, SCU1_REG + 0x440);

	/*
	 * 0x444[31:28] = 0x6 -> GPINL26
	 * 0x444[27:24] = 0x6 -> GPONL26
	 * 0x444[23:20] = 0x6 -> GPINL25
	 * 0x444[19:16] = 0x6 -> GPONL25
	 * 0x444[15:12] = 0x6 -> GPINL24
	 * 0x444[11:8] = 0x6 -> GPONL24
	 * 0x444[7:4] = 0x6 -> GPINL23
	 * 0x444[3:0] = 0x6 -> GPONL23
	 */
	writel(0x66666666, SCU1_REG + 0x444);

	/*
	 * 0x448[31:28] = 0x0 -> GPIOS7
	 * 0x448[27:24] = 0x0 -> GPIOS6
	 * 0x448[23:20] = 0x1 -> MDIO
	 * 0x448[19:16] = 0x1 -> MDC
	 * 0x448[15:12] = 0x0 -> GPIOS3
	 * 0x448[11:8]  = 0x0 -> GPIOS2
	 * 0x448[7:4]   = 0x6 -> GPINL27
	 * 0x448[3:0]   = 0x6 -> GPONL27
	 */
	writel(0x00110066, SCU1_REG + 0x448);

	/*
	 * 0x44c[31:28] = 0x6 -> GPILL13
	 * 0x44c[27:24] = 0x6 -> GPOLL13
	 * 0x44c[23:20] = 0x6 -> GPILL12
	 * 0x44c[19:16] = 0x6 -> GPOLL12
	 * 0x44c[15:12] = 0x6 -> GPILL11
	 * 0x44c[11:8]  = 0x6 -> GPOLL11
	 * 0x44c[7:4]   = 0x0 -> GPIOT1
	 * 0x44c[3:0]   = 0x0 -> GPIOT0
	 */
	writel(0x66666600, SCU1_REG + 0x44c);

	/*
	 * 0x450[31:28] = 0x0 -> GPIOU7
	 * 0x450[27:24] = 0x0 -> GPIOU6
	 * 0x450[23:20] = 0x0 -> GPIOU5
	 * 0x450[19:16] = 0x0 -> GPIOU4
	 * 0x450[15:12] = 0x6 -> GPILL15
	 * 0x450[11:8]  = 0x6 -> GPOLL15
	 * 0x450[7:4]   = 0x6 -> GPILL14
	 * 0x450[3:0]   = 0x6 -> GPOLL14
	 */
	writel(0x00006666, SCU1_REG + 0x450);

	/*
	 * 0x454[31:28] = 0x1 -> I2CSDA3
	 * 0x454[27:24] = 0x1 -> I2CSCL3
	 * 0x454[23:20] = 0x1 -> I2CSDA2
	 * 0x454[19:16] = 0x1 -> I2CSCL2
	 * 0x454[15:12] = 0x1 -> I2CSDA1
	 * 0x454[11:8]  = 0x1 -> I2CSCL1
	 * 0x454[7:4]   = 0x1 -> I2CSDA0
	 * 0x454[3:0]   = 0x1 -> I2CSCL0
	 */
	writel(0x11111111, SCU1_REG + 0x454);

	/*
	 * 0x458[31:28] = 0x0 -> GPIOW7
	 * 0x458[27:24] = 0x0 -> GPIOW6
	 * 0x458[23:20] = 0x0 -> GPIOW5
	 * 0x458[19:16] = 0x0 -> GPIOW4
	 * 0x458[15:12] = 0x1 -> I2CSDA5
	 * 0x458[11:8]  = 0x1 -> I2CSCL5
	 * 0x458[7:4]   = 0x1 -> I2CSDA4
	 * 0x458[3:0]   = 0x1 -> I2CSCL4
	 */
	writel(0x00001111, SCU1_REG + 0x458);

	/*
	 * 0x45c[31:28] = 0x6 -> GPONL31
	 * 0x45c[27:24] = 0x6 -> GPINL31
	 * 0x45c[23:20] = 0x6 -> GPONL30
	 * 0x45c[19:16] = 0x6 -> GPINL30
	 * 0x45c[15:12] = 0x6 -> GPONL29
	 * 0x45c[11:8]  = 0x6 -> GPINL29
	 * 0x45c[7:4]   = 0x6 -> GPONL28
	 * 0x45c[3:0]   = 0x6 -> GPINL28
	 */
	writel(0x66666666, SCU1_REG + 0x45c);

	/*
	 * 0x460[31:28] = 0x0 -> ADC7
	 * 0x460[27:24] = 0x0 -> ADC6
	 * 0x460[23:20] = 0x0 -> ADC5
	 * 0x460[19:16] = 0x0 -> ADC4
	 * 0x460[15:12] = 0x0 -> ADC3
	 * 0x460[11:8]  = 0x0 -> ADC2
	 * 0x460[7:4]   = 0x0 -> ADC1
	 * 0x460[3:0]   = 0x0 -> ADC0
	 *
	 * 0x464[31:28] = 0x0 -> ADC15
	 * 0x464[27:24] = 0x0 -> ADC14
	 * 0x464[23:20] = 0x0 -> ADC13
	 * 0x464[19:16] = 0x0 -> ADC12
	 * 0x464[15:12] = 0x0 -> ADC11
	 * 0x464[11:8]  = 0x0 -> ADC10
	 * 0x464[7:4]   = 0x0 -> ADC9
	 * 0x464[3:0]   = 0x0 -> ADC8
	 */
	writel(0x00000000, SCU1_REG + 0x460);
	writel(0x00000000, SCU1_REG + 0x464);

	/*
	 * 0x468[31:28] = 0x0 -> GPIOAA7  (LTPI_LINK_ALIGNED)
	 * 0x468[27:24] = 0x1 -> SGPM1LD
	 * 0x468[23:20] = 0x1 -> SGPM1CK
	 * 0x468[19:16] = 0x6 -> GPINL10
	 * 0x468[15:12] = 0x6 -> GPONL10
	 * 0x468[11:8]  = 0x2 -> HBLED#
	 * 0x468[7:4]   = 0x6 -> GPINL9
	 * 0x468[3:0]   = 0x6 -> GPONL9
	 */
	writel(0x01166266, SCU1_REG + 0x468);
}

static void ltpi_slave_init_addr_map(struct ltpi_priv *ltpi)
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
	reg = readl(ltpi->base[0] + LTPI_AHB_CTRL0);
	reg &= ~REG_LTPI_AHB_ADDR_MAP0;
	reg |= FIELD_PREP(REG_LTPI_AHB_ADDR_MAP0, 0x10000000 >> 26);
	writel(reg, ltpi->base[0] + LTPI_AHB_CTRL0);
}

bootstage_t ltpi_init(void)
{
	bootstage_t sts = { 0, 0 };

	struct ltpi_priv *ltpi = &ltpi_data;
	uint32_t pin_strap = get_pin_strap();
	uint32_t otp_strap = get_otp_strap();

	ltpi->top_base = LTPI_REG + 0x200;
	ltpi->base[0] = LTPI_REG;
	ltpi->base[1] = LTPI_REG + 0x1000;

	ltpi->otp_speed_cap =
		otp_to_speed_mask_lookup[FIELD_GET(SCU1_HWSTRAP2_LTPI_MAX, otp_strap)];
	ltpi->phy_speed_cap = ltpi->otp_speed_cap;

	if (pin_strap & SCU1_HWSTRAP1_LTPI_MODE) {
		/* AST1700: LTPI slave */
		bootstage_start_mark(BOOTSTAGE_LTPI_SLAVE);
		bootstage_end_status(BOOTSTAGE_ERR_SUCCESS);
		ltpi_slave_set_pins();
		if (pin_strap & SCU1_HWSTRAP1_LTPI_NUM)
			ltpi_slave_cdr_mode_loop(ltpi);
		else
			ltpi_slave_normal_mode_loop(ltpi);

		ltpi_slave_init_addr_map(ltpi);
	} else {
		if (pin_strap & SCU1_HWSTRAP1_SCM_MODE) {
			/* AST2700 SCM mode: LTPI master */
			bootstage_start_mark(BOOTSTAGE_LTPI_MASTER);
			bootstage_end_status(BOOTSTAGE_ERR_SUCCESS);
			ltpi_master_set_pins();
			ltpi_init_master_mode(ltpi);
		} else {
			/* AST2700 non-SCM mode, skip LTPI */
			bootstage_start_mark(BOOTSTAGE_LTPI_INIT);
			bootstage_end_status(BOOTSTAGE_LTPI_INIT_SKIP |
					     BOOTSTAGE_LTPI_MODE_NONE);
		}
	}

	return sts;
}
