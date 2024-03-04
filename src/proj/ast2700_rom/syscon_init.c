#include <bootstage.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <flash.h>
#include <io.h>
#include <otp_mem.h>
#include <types.h>
#include <syscon_init.h>

static void scu_otpstrap_update(uint16_t val[8], uint16_t vld[8])
{
	uint32_t v, t;

	/*
	 * CPU-die OTP Flash Strap
	 * - C_SCU010[31:16] = OTPFLASHSTRAP[31:16]
	 * - C_SCUA70[3:0] = OTPFLASHSTRAP[106:103]
	 * - C_SCUAF0[3:0] = OTPFLASHSTRAP[110:107]
	 * - DRAMC100[0] = OTPFLASHSTRAP[100]
	 */
	if (sli_get_availability()) {
		v = readl(SCU0_HWSTRAP);
		v &= ~GENMASK(31, 16);
		t = val[1] & vld[1];
		writel(v | t << 16, SCU0_HWSTRAP + 0x10);

		v = readl(SCU0_PCI_MISC70);
		v &= ~GENMASK(3, 0);
		t = (val[6] & vld[6]) & GENMASK(10, 7);
		writel(v | t >> 7, SCU0_PCI_MISC70);

		v = readl(SCU0_PCI_MISCF0);
		v &= ~GENMASK(3, 0);
		t = (val[6] & vld[6]) & GENMASK(14, 11);
		writel(v | t >> 11, SCU0_PCI_MISCF0);

		/* unlock DRAMC */
		writel(0x1688a8a8, DRAMC_REG);

		v = (val[6] & vld[6]) & BIT(4);
		writel((v >> 4) & 0x1, DRAMC_REG + 0x100);

		/* soft-lock DRAMC */
		writel(0x1, DRAMC_REG);
	}

	/*
	 * IO-die OTP Flash Strap
	 * - I_SCU030[31:0] = OTPFLASHSTRAP[63:32]
	 * - I_SCUA00[31:0] = OTPFLASHSTRAP[95:64]
	 */
	t = (val[3] << 16 | val[2]) & (vld[3] << 16 | vld[2]);
	writel(t, SCU1_HWSTRAP2);

	t = (val[5] << 16 | val[4]) & (vld[5] << 16 | vld[4]);
	writel(t, SCU1_HCFG0 + 0xa00);
}

bootstage_t scu_otpstrap_init_f(void)
{
	bootstage_t sts = { SCU_INIT_ERR_SUCCESS, 0 };
	uint16_t fs_val[8] = { 0 };
	uint16_t fs_vld[8] = { 0 };
	uint32_t reg;
	int i, rc;

	/* skip if not cold reset */
	reg = readl(SCU1_RSTLOG0);
	if (!(reg & SCU1_RSTLOG0_SRST)) {
		return sts;
	}

	/* read flash strap and its validity in OTP */
	for (i = 0; i < ARRAY_SIZE(fs_val); i++) {
		rc = otp_read_data(OTP_MEM_FLASHSTRAP_BASE + i, &fs_val[i]);
		if (rc) {
			sts.errno = SCU_INIT_ERR_FAILED;
			sts.syndrome = rc;
			return sts;
		}

		rc = otp_read_data(OTP_MEM_FLASHSTRAP_BASE + i + ARRAY_SIZE(fs_val), &fs_vld[i]);
		if (rc) {
			sts.errno = SCU_INIT_ERR_FAILED;
			sts.syndrome = rc;
			return sts;
		}
	}

	return sts;
}

bootstage_t scu_otpstrap_init_r(void)
{
	bootstage_t sts = { SCU_INIT_ERR_SUCCESS, 0 };
	uint16_t fs_val[8];
	uint16_t fs_vld[8];
	uint16_t cfg;
	uint32_t reg;
	int i, rc;

	/* skip if not cold reset */
	reg = readl(SCU1_RSTLOG0);
	if (!(reg & SCU1_RSTLOG0_SRST))
		return sts;

	/* skip if OTP flash strap is disabled/unknown */
	rc = otp_read_data(OTPCFG2, &cfg);
	if (rc || (cfg & OTPCFG2_DIS_FLASH_STRAP)) {
		sts.errno = SCU_INIT_ERR_FAILED;
		sts.syndrome = rc;
		goto end;
	}

	bootstage_prologue(BOOTSTAGE_FLASHSTRAP_SCU_INIT);

	rc = flash_strap_read(fs_val);
	if (rc) {
		sts.errno = SCU_INIT_ERR_FAILED;
		sts.syndrome = rc;
		goto end;
	}

	for (i = 0; i < ARRAY_SIZE(fs_val); i++) {
		rc = otp_read_data(OTP_MEM_FLASHSTRAP_BASE + i + ARRAY_SIZE(fs_vld), &fs_vld[i]);
		if (rc) {
			sts.errno = SCU_INIT_ERR_FAILED;
			sts.syndrome = rc;
			goto end;
		}

		/* inverse the validity */
		fs_vld[i] = ~fs_vld[i];
	}

	scu_otpstrap_update(fs_val, fs_vld);

end:
	return sts;
}

bootstage_t scu_pinmux_init(void)
{
	bootstage_t sts = { 0, 0 };
	uint32_t reg;

	/* skip if not cold reset */
	reg = readl(SCU1_RSTLOG0);
	if (!(reg & SCU1_RSTLOG0_SRST))
		return sts;

	/*
	 * A0 set GPIOA to be defaule
	 *   C16 ESPI1CK_L1CLK_SD0CLK_HVI3CSCL4_SM3CS0NI_GPIOA0
	 *   C14 ESPI1RSTN_LPC1RSTN_SD0CDN_HVI3CSDA4_SM3CLKI_GPIOA1
	 *   C11 ESPI1ALTN_L1SIRQN_SD0CMD_HVI3CSCL5_SM3MOSII_GPIOA2
	 *   D9  ESPI1CSN_L1FRAMEN_SD0WPN_HVI3CSDA5_SM3MISOI_GPIOA3
	 *   F14 ESPI1D0_L1AD0_SD0DAT0_HVI3CSCL6_SM3IO2I_GPIOA4
	 *   D10 ESPI1D1_L1AD1_SD0DAT1_HVI3CSDA6_SM3IO3I_GPIOA5
	 *   C12 ESPI1D2_L1AD2_SD0DAT2_SM3CS0NO_GPIOA6
	 *   C13 ESPI1D3_L1AD3_SD0DAT3_SM3MUXSEL_GPIOA7
	 *
	 * A0 set ESPI1 defaul to GPIOW pin out
	 *   E9  GPIOW0_SCL4_ESPI1CK_I2CF1SCLI
	 *   F9  GPIOW1_SDA4_ESPI1CSN_I2CF1SDAI
	 *   F8  GPIOW2_SCL5_ESPI1RSTN_I2CF1SCLO
	 *   M13 GPIOW3_SDA5_ESPI1D0_I2CF1SDAO
	 *   F7  GPIOW4_SCL6_ESPI1D1_I2CF2SCLI
	 *   D8  GPIOW5_SDA6_ESPI1D2_I2CF2SDAI
	 *   E8  GPIOW6_SCL7_ESPI1D3_I2CF2SCLO
	 *   L12 GPIOW7_SDA7_ESPI1ALTN_I2CF2SDAO
	 */
	writel(0, SCU1_PINMUX1);

	reg = (0x2 << 28) | (2 << 24) | (2 << 20) | (2 << 16) |
	      (2 << 12) | (2 << 8) | (2 << 4) | 2;
	writel(reg, SCU1_PINMUX23);

	return sts;
}

bootstage_t scu_dbgctrl_init(void)
{
	bootstage_t sts = { SCU_INIT_ERR_SUCCESS, 0 };
	uint32_t val, auto_load;
	uint16_t otpcfg10;
	uint16_t otpcfg9;
	int rc;

	rc = otp_read_data(OTPCFG9, &otpcfg9);
	if (rc) {
		sts.errno = SCU_INIT_ERR_FAILED;
		sts.syndrome = rc;
		goto end;
	}

	rc = otp_read_data(OTPCFG10, &otpcfg10);
	if (rc) {
		sts.errno = SCU_INIT_ERR_FAILED;
		sts.syndrome = rc;
		goto end;
	}

	auto_load = !!(otpcfg9 & OTPCFG9_EN_AUTO_LOAD);

	/* init the debug control in CPU/IO-die SCU0C8 */
	if (auto_load && sli_get_availability()) {
		val = otpcfg9 & GENMASK(14, 0);
		writel(val, SCU0_DBGCTL);
		writel(SCU0_WPROT1_0C8, SCU0_WPROT1);

		val = otpcfg10 & GENMASK(7, 0);
		writel(val, SCU1_DBGCTL);
		writel(SCU1_WPROT2_0C8, SCU1_WPROT2);
	}

end:
	return sts;
}

bootstage_t scu_rstlog_init(void)
{
	bootstage_t sts = { SCU_INIT_ERR_SUCCESS, 0 };

	/* clear IO-die to prevent OTP re-init */
	writel(SCU1_RSTLOG0_SRST, SCU1_RSTLOG0);

	return sts;
}
