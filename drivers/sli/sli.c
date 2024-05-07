#include <bootstage.h>
#include <drivers/sli.h>
#include <drivers/scu.h>
#include <drivers/otp.h>
#include <io.h>
#include <lib/delay.h>
#include <platform.h>
#include <utils.h>
#include <otp_mem.h>
#include <debug.h>

#define SLIM_REG_OFFSET		0x000	/* SLI Memory bus */
#define SLIH_REG_OFFSET		0x200	/* SLI AHB bus */
#define SLIV_REG_OFFSET		0x400	/* SLI Video bus */

#define SLIM_CPU_BASE		(SLI0_REG + SLIM_REG_OFFSET)
#define SLIM_IO_BASE		(SLI1_REG + SLIM_REG_OFFSET)
#define SLIH_CPU_BASE		(SLI0_REG + SLIH_REG_OFFSET)
#define SLIH_IO_BASE		(SLI1_REG + SLIH_REG_OFFSET)
#define SLIV_CPU_BASE		(SLI0_REG + SLIV_REG_OFFSET)
#define SLIV_IO_BASE		(SLI1_REG + SLIV_REG_OFFSET)

struct sli_data {
	int is_available;
};

static struct sli_data ast2700_sli_data;

static void sli_clear_intr_status(uintptr_t base)
{
	writel(0xffffffff, base + SLI_INTR_STATUS);
}

static int sli_wait_suspend(uintptr_t base, int timeout_us)
{
	uint32_t value, target;

	sli_clear_intr_status(base);

	/*
	 * The target is for both RX and TX to enter the suspend state, meaning
	 * that both the RX and TX hardware blocks are not in the training
	 * state, and are therefore ready for software use.
	 */
	target = SLI_INTR_RX_SUSPEND | SLI_INTR_TX_SUSPEND;

	return readl_poll_timeout(base + SLI_INTR_STATUS, value,
				  (value & target) == target, 1, timeout_us);
}

static int sli_reset(uintptr_t base)
{
	uint32_t val;

	/* Trigger reset */
	setbits(base + SLI_CTRL_I, SLI_RESET);

	/* The SLI_RESET bit will be auto-cleared. Check timeout */
	return readl_poll_timeout(base + SLI_CTRL_I, val,
				  (val & SLI_RESET) == 0, 1, 10);
}

/*
 * 4b'0000:  25M
 * 4b'0001:   1G
 * 4b'001x: 800M
 * 4b'01xx: 500M
 * 4b'1xxx: 400M
 */
static int sli_otp_to_phyclk(int otp)
{
	int i;
	int table[4] = { SLI_PHY_CLK_SEL_1G, SLI_PHY_CLK_SEL_800M,
			 SLI_PHY_CLK_SEL_500M, SLI_PHY_CLK_SEL_400M };

	for (i = 3; i >= 0; i--) {
		if (otp & BIT(i))
			return table[i];
	}

	return SLI_PHY_CLK_SEL_25M;
}

static int sli_set_vbus_delay(bootstage_t *sts)
{
	uint32_t val, reg;
	int ret;

	/* Start configuration, turn off auto-training */
	setbits(SLIV_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	val = readl(SCU1_OTPCFG_29_28);
	reg = FIELD_PREP(SLIV_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG29_IO_SLI_V_RXDLY_1, val)) |
	      FIELD_PREP(SLIV_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG29_IO_SLI_V_RXDLY_0, val));

	clrsetbits(SLIV_IO_BASE + SLI_CTRL_III,
		   SLIV_PAD_DLY_RX1 | SLIV_PAD_DLY_RX0, reg);

	setbits(SLIV_CPU_BASE + SLI_CTRL_II, SLIV_TX_ENT_SUSPEND);

	reg = FIELD_PREP(SLIV_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG29_CPU_SLI_V_RXDLY_1, val)) |
	      FIELD_PREP(SLIV_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG29_CPU_SLI_V_RXDLY_0, val));

	clrsetbits(SLIV_CPU_BASE + SLI_CTRL_III,
		   SLIV_PAD_DLY_RX1 | SLIV_PAD_DLY_RX0, reg);

	/* Load latch phase pos/neg swap */
	val = readl(SCU1_OTPCFG_25_24);
	if (val & SCU1_OTPCFG25_CPU_SLI_V_PN_SWAP)
		setbits(SLIV_CPU_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);
	else
		clrbits(SLIV_CPU_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);

	if (val & SCU1_OTPCFG25_IO_SLI_V_PN_SWAP)
		setbits(SLIV_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);
	else
		clrbits(SLIV_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);

	/* Trigger reset: IO SLIV must reset prior to CPU SLIV */
	ret = sli_reset(SLIV_IO_BASE);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_VDO_IO);
		sts->syndrome = SLI_WAIT_BUS_RESET_TIMEOUT;
		return ret;
	}

	ret = sli_reset(SLIV_CPU_BASE);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_VDO_CPU);
		sts->syndrome = SLI_WAIT_BUS_RESET_TIMEOUT;
		return ret;
	}

	/* Finished, turn on auto-training */
	clrbits(SLIV_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	ret = sli_wait_suspend(SLIV_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_VDO_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
	}

	return ret;
}

static int sli_set_mbus_delay(bootstage_t *sts)
{
	uint32_t val, reg;
	int ret;

	setbits(SLIM_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	/* IO SLIM RX pad delay */
	val = readl(SCU1_OTPCFG_29_28);
	reg = FIELD_PREP(SLIM_PAD_DLY_RX3,
			 FIELD_GET(SCU1_OTPCFG28_IO_SLI_M_RXDLY_3, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX2,
			 FIELD_GET(SCU1_OTPCFG28_IO_SLI_M_RXDLY_2, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG28_IO_SLI_M_RXDLY_1, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG28_IO_SLI_M_RXDLY_0, val));

	clrsetbits(SLIM_IO_BASE + SLI_CTRL_III,
		   SLIM_PAD_DLY_RX3 | SLIM_PAD_DLY_RX2 |
		   SLIM_PAD_DLY_RX1 | SLIM_PAD_DLY_RX0,
		   reg);

	/* CPU SLIM RX pad delay */
	val = readl(SCU1_OTPCFG_27_26);
	reg = FIELD_PREP(SLIM_PAD_DLY_RX3,
			 FIELD_GET(SCU1_OTPCFG27_CPU_SLI_M_RXDLY_3, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX2,
			 FIELD_GET(SCU1_OTPCFG27_CPU_SLI_M_RXDLY_2, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG27_CPU_SLI_M_RXDLY_1, val)) |
	      FIELD_PREP(SLIM_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG27_CPU_SLI_M_RXDLY_0, val));

	clrsetbits(SLIM_CPU_BASE + SLI_CTRL_III,
		   SLIM_PAD_DLY_RX3 | SLIM_PAD_DLY_RX2 |
		   SLIM_PAD_DLY_RX1 | SLIM_PAD_DLY_RX0,
		   reg);

	/* Load latch phase pos/neg swap */
	val = readl(SCU1_OTPCFG_25_24);
	if (val & SCU1_OTPCFG25_CPU_SLI_M_PN_SWAP)
		setbits(SLIM_CPU_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);
	else
		clrbits(SLIM_CPU_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);

	if (val & SCU1_OTPCFG25_IO_SLI_M_PN_SWAP)
		setbits(SLIM_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);
	else
		clrbits(SLIM_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);

	/* Trigger reset */
	ret = sli_reset(SLIM_CPU_BASE);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_MEM_CPU);
		sts->syndrome = SLI_WAIT_BUS_RESET_TIMEOUT;
		return ret;
	}

	ret = sli_reset(SLIM_IO_BASE);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_MEM_IO);
		sts->syndrome = SLI_WAIT_BUS_RESET_TIMEOUT;
		return ret;
	}

	clrbits(SLIM_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	ret = sli_wait_suspend(SLIM_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_MEM_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	return ret;
}

/*
 * SLI-H programming sequence:
 *
 * IOD auto-training OFF
 *     CPU TXCLK speed up
 *     IOD adjust RXCLK delay
 *     IOD adjust RXPAD delay
 * IOD auto-training ON
 * IOD wait suspend
 * IOD wait TRAIN packet received --> remove this, use udelay(10)
 *
 * IOD auto-training OFF
 *     CPU adjust RXPAD delay
 *     IOD adjust TXCLK delay
 *     IOD TXCLK speed up
 *     IOD adjust TXPAD delay --> remove this
 * IOD auto-training ON
 * IOD wait suspend
 */
static int sli_speed_up(bootstage_t *sts)
{
	uint32_t val, reg;
	int ret;

	ret = sli_wait_suspend(SLIM_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_MEM_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	ret = sli_wait_suspend(SLIM_CPU_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_MEM_CPU);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	ret = sli_wait_suspend(SLIV_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_VDO_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	ret |= sli_wait_suspend(SLIV_CPU_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_VDO_CPU);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	/* Enable hardware auto clear */
	clrbits(SLIH_IO_BASE + SLI_CTRL_I,
		SLI_AUTO_CLR_OFF_DAT | SLI_AUTO_CLR_OFF_CLK);
	clrbits(SLIH_CPU_BASE + SLI_CTRL_I,
		SLI_AUTO_CLR_OFF_DAT | SLI_AUTO_CLR_OFF_CLK);

	/* Turn off auto-training before adjusting clock and delay */
	setbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	/* Speed up CPU die engine clock and PHY TX clock */
	val = FIELD_GET(SCU1_OTPCFG25_CPU_SLI_TXCLK_SEL,
			readl(SCU1_OTPCFG_25_24));
	reg = FIELD_PREP(SLI_CLK_SEL, SLI_CLK_SEL_500M) |
	      FIELD_PREP(SLI_PHY_CLK_SEL, sli_otp_to_phyclk(val));

	clrsetbits(SLIH_CPU_BASE + SLI_CTRL_III, SLI_CLK_SEL | SLI_PHY_CLK_SEL,
		   reg);

	/* Specify the DS direction has speeded up */
	sts->errno |= SLI_SPEED_HI_CPU;

	sli_clear_intr_status(SLIH_IO_BASE);

	/* Load IO SLIH RX clock delay */
	val = readl(SCU1_OTPCFG_25_24);
	reg = FIELD_PREP(SLIH_CLK_INV_RX,
			 FIELD_GET(SCU1_OTPCFG24_IO_SLI_RXCLK_INV, val)) |
	      FIELD_PREP(SLIH_CLK_DLY_RX,
			 FIELD_GET(SCU1_OTPCFG24_IO_SLI_RXCLK_DLY, val));

	clrsetbits(SLIH_IO_BASE + SLI_CTRL_IV,
		   SLIH_CLK_INV_RX | SLIH_CLK_DLY_RX, reg);

	/* Load IO SLIH RX pad delay */
	val = readl(SCU1_OTPCFG_27_26);
	reg = FIELD_PREP(SLIH_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG26_IO_SLI_H_RXDLY_1, val)) |
	      FIELD_PREP(SLIH_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG26_IO_SLI_H_RXDLY_0, val));

	clrsetbits(SLIH_IO_BASE + SLI_CTRL_III,
		   SLIH_PAD_DLY_RX1 | SLIH_PAD_DLY_RX0, reg);

	/* Load latch phase pos/neg swap */
	val = readl(SCU1_OTPCFG_25_24);
	if (val & SCU1_OTPCFG25_IO_SLI_H_PN_SWAP)
		setbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);
	else
		clrbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_PHY_LAH_SEL_SWAP);

	/* wait at least 8us */
	udelay(8);
	sli_clear_intr_status(SLIH_IO_BASE);

	/* Turn on auto-training after adjusting clock and delay */
	clrbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	ret = sli_wait_suspend(SLIH_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	/*
	 * Wait for the RX_TRAIN interrupt to ensure the CPU die is ready.
	 * Note: The RX_TRAIN interrupt is only triggered when the SLI engine
	 * starts training from a power-on state. This interrupt may not be
	 * triggered during resets initiated externally or by the watchdog.
	 * Therefore, to ensure the CPU die is ready in these scenarios, wait
	 * for a brief period (10 us is sufficient).
	 *
	 * ret = readl_poll_timeout(SLIH_IO_BASE + SLI_INTR_STATUS, val,
	 *                          (val & SLI_INTR_RX_TRAIN_PKT) == SLI_INTR_RX_TRAIN_PKT,
	 *                          1, 10);
	 * if (ret) {
	 *         sts->errno |= SLI_STATUS_ERR | FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_IO);
	 *         sts->syndrome = SLI_WAIT_TRAIN_PKT_TIMEOUT;
	 *         return ret;
	 * }
	 *
	 */
	udelay(10);

	/* Start to change IO SLIH TX clock */
	setbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	/* CPU SLIH RX PAD delay */
	val = readl(SCU1_OTPCFG_27_26);
	reg = FIELD_PREP(SLIH_PAD_DLY_RX1,
			 FIELD_GET(SCU1_OTPCFG26_CPU_SLI_H_RXDLY_1, val)) |
	      FIELD_PREP(SLIH_PAD_DLY_RX0,
			 FIELD_GET(SCU1_OTPCFG26_CPU_SLI_H_RXDLY_0, val));

	clrsetbits(SLIH_IO_BASE + SLI_CTRL_III,
		   SLIH_PAD_DLY_RX1 | SLIH_PAD_DLY_RX0, reg);

	sli_clear_intr_status(SLIH_IO_BASE);

	/* Load IO SLIH TX clock delay */
	val = readl(SCU1_OTPCFG_25_24);
	reg = FIELD_PREP(SLIH_CLK_INV_TX,
			 FIELD_GET(SCU1_OTPCFG24_IO_SLI_TXCLK_INV, val)) |
	      FIELD_PREP(SLIH_CLK_DLY_TX,
			 FIELD_GET(SCU1_OTPCFG24_IO_SLI_TXCLK_DLY, val));

	clrsetbits(SLIH_IO_BASE + SLI_CTRL_IV,
		   SLIH_CLK_INV_TX | SLIH_CLK_DLY_TX, val);

	/* Speed up IO die engine clock and PHY TX clock */
	val = FIELD_GET(SCU1_OTPCFG24_IO_SLI_TXCLK_SEL,
			readl(SCU1_OTPCFG_25_24));
	reg = FIELD_PREP(SLI_CLK_SEL, SLI_CLK_SEL_500M) |
	      FIELD_PREP(SLI_PHY_CLK_SEL, sli_otp_to_phyclk(val));

	clrsetbits(SLIH_IO_BASE + SLI_CTRL_III, SLI_CLK_SEL | SLI_PHY_CLK_SEL,
		   reg);

	/* Specify the US direction has speeded up */
	sts->errno |= SLI_SPEED_HI_IO;

	/* Turn on auto-training after adjusting clock and delay */
	clrbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_AUTO_SEND_TRN_OFF);

	ret = sli_wait_suspend(SLIH_IO_BASE, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_IO);
		sts->syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return ret;
	}

	setbits(SLIH_IO_BASE + SLI_CTRL_I, SLI_CLEAR_BUS);
	ret = readl_poll_timeout(SLIH_IO_BASE + SLI_CTRL_I, val,
				 (val & SLI_CLEAR_BUS) == 0, 1, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_IO);
		sts->syndrome = SLI_WAIT_BUS_CLEAR_TIMEOUT;
		return ret;
	}

	setbits(SLIH_CPU_BASE + SLI_CTRL_I, SLI_CLEAR_BUS);
	ret = readl_poll_timeout(SLIH_CPU_BASE + SLI_CTRL_I, val,
				 (val & SLI_CLEAR_BUS) == 0, 1, 10);
	if (ret) {
		sts->errno |= SLI_STATUS_ERR |
			      FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_CPU);
		sts->syndrome = SLI_WAIT_BUS_CLEAR_TIMEOUT;
		return ret;
	}

	/*
	 * Return 0 regardless of the SLIM and SLIV training results. As only
	 * SLIH will be used during the ROM stage.
	 */
	sli_set_mbus_delay(sts);
	sli_set_vbus_delay(sts);

	return 0;
}

static void sli_set_availability(int avl)
{
	ast2700_sli_data.is_available = avl;
}

int sli_get_availability(void)
{
	return ast2700_sli_data.is_available;
}

bootstage_t sli_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { 0, SLI_STATUS_OK };
	uint32_t value;
	int ret;

	sli_set_availability(0);

	value = readl(SCU1_HWSTRAP1);
	if (value & SCU1_HWSTRAP1_LTPI_MODE) {
		/*
		 * For AST1700, this is not considered a genuine failure case.
		 * However, SLI is not available since it only has the IO-die.
		 */
		sts.errno |= SLI_STATUS_NA;
		return sts;
	}

	/* Check whether the SLI is available, regardingless the physical speed */
	ret = sli_wait_suspend(SLIH_IO_BASE, 10);
	if (ret) {
		sts.errno |= SLI_STATUS_ERR |
			     FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_IO);
		sts.syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return sts;
	}

	ret = sli_wait_suspend(SLIH_CPU_BASE, 2);
	if (ret) {
		sts.errno |= SLI_STATUS_ERR |
			     FIELD_PREP(SLI_BUS_ID, SLI_BUS_ID_AHB_CPU);
		sts.syndrome = SLI_WAIT_SUSPEND_TIMEOUT;
		return sts;
	}

	value = FIELD_GET(SLI_CLK_SEL, readl(SLIH_IO_BASE + SLI_CTRL_III));
	if (value)
		sts.errno |= SLI_SPEED_HI_IO;

	value = FIELD_GET(SLI_CLK_SEL, readl(SLIH_CPU_BASE + SLI_CTRL_III));
	if (value)
		sts.errno |= SLI_SPEED_HI_CPU;

	/* Exit if the SLI is already speeded up  */
	if (sts.errno & (SLI_SPEED_HI_IO | SLI_SPEED_HI_CPU))
		goto sli_available;

	/* Exit if no OTPCFG */
	ret = readl(SCU1_OTPCFG_25_24) | readl(SCU1_OTPCFG_27_26) |
	      readl(SCU1_OTPCFG_29_28);
	if (ret == 0)
		goto sli_available;

	ret = sli_speed_up(&sts);
	if (ret)
		return sts;

sli_available:
	sli_set_availability(1);

	return sts;
}
