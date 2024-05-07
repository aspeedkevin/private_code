#include <bootstage.h>
#include <caliptra.h>
#include <drivers/otp.h>
#include <drivers/sec.h>
#include <drivers/scu.h>
#include <drivers/sli.h>
#include <errno.h>
#include <io.h>
#include <lib/rand.h>
#include <otp_mem.h>
#include <otp_init.h>
#include <rng.h>

#define CPU_DIE		0
#define IO_DIE		1

static int otp_dbgctrl_init(int die)
{
	bool auto_load, low_secure;
	uint16_t otpcfg10;
	uint16_t otpcfg9;
	uint32_t val;
	int rc;

	rc = otp_readw(OTPCFG9, &otpcfg9);
	if (rc)
		return rc;

	rc = otp_readw(OTPCFG10, &otpcfg10);
	if (rc)
		return rc;

	auto_load = !!(otpcfg9 & OTPCFG9_EN_AUTO_LOAD);

	low_secure = !!(readl(SCU1_HWSTRAP1) & SCU1_HWSTRAP1_LOW_SECURE);

	/* init the debug control in CPU/IO-die SCU0C8 */
	if (die == IO_DIE) {
		if (auto_load) {
			val = otpcfg10 & GENMASK(7, 0);
			writel(val, SCU1_DBGCTL);
			writel(SCU1_WPROT2_0C8, SCU1_WPROT2);
		} else {
			if (low_secure)
				val = SCU1_DBGCTL_MASK & ~SCU1_DBGCTL_UARTDBG;
			else
				val = SCU1_DBGCTL_MASK;

			writel(val, SCU1_DBGCTL);
		}

	} else if (die == CPU_DIE) {
		/* Check SLI first */
		if (!sli_get_availability())
			return -EIO;

		if (auto_load) {
			val = otpcfg9 & GENMASK(14, 0);
			writel(val, SCU0_DBGCTL);
			writel(SCU0_WPROT1_0C8, SCU0_WPROT1);
		} else {
			if (low_secure)
				val = SCU0_DBGCTL_MASK & ~SCU0_DBGCTL_UARTDBG;
			else
				val = SCU0_DBGCTL_MASK;

			writel(val, SCU0_DBGCTL);
		}

	} else {
		return -EINVAL;
	}

	return 0;
}

static int otp_strapext_init(int die)
{
	uint16_t se_val[8] = {0};
	uint16_t se_vld[8] = {0};
	uint32_t val_otp, vld_otp, v;
	uint32_t reg;
	int val;
	int rc;

	/* Skip if not cold reset */
	reg = readl(SCU1_RSTLOG0);
	if (!(reg & SCU1_RSTLOG0_SRST))
		return 0;

	/* Read strap extension and its validity in OTP */
	for (int i = 0; i < ARRAY_SIZE(se_val); i++) {
		rc = otp_readw(STRAPEXT_REGION_START_ADDR + i, &se_val[i]);
		if (rc)
			return rc;

		rc = otp_readw(STRAPEXT_REGION_START_ADDR + i + ARRAY_SIZE(se_val), &se_vld[i]);
		if (rc)
			return rc;
	}

	if (die == IO_DIE) {
		/*
		 * IO-die OTP Strap Ext
		 * - I_SCU030[31:0] = OTPFLASHSTRAP[63:32]
		 * - I_SCUA00[15:0] = OTPFLASHSTRAP[79:64]
		 * - I_SCUA10[15:0] = OTPFLASHSTRAP[95:80]
		 */
		val = readl(SCU1_HWSTRAP2);
		val_otp = se_val[3] << 16 | se_val[2];
		vld_otp = se_vld[3] << 16 | se_vld[2];

		/* If valid, assign value to scu */
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU1_HWSTRAP2);

		val = readl(SCU1_HCFG0);
		val_otp = se_val[4];
		vld_otp = se_vld[4];

		/* If valid, assign value to scu */
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU1_HCFG0);

		val = readl(SCU1_HCFG1);
		val_otp = se_val[5];
		vld_otp = se_vld[5];
		/* If valid, assign value to scu */
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU1_HCFG1);

	} else if (die == CPU_DIE) {
		/*
		 * CPU-die OTP Strap Ext
		 * - C_SCU010[31:16] = OTPFLASHSTRAP[31:16]
		 * - C_SCUA70[3:0] = OTPFLASHSTRAP[106:103]
		 * - C_SCUAF0[3:0] = OTPFLASHSTRAP[110:107]
		 * - DRAMC100[0] = OTPFLASHSTRAP[100]
		 */

		/* Check SLI first */
		if (!sli_get_availability())
			return -EIO;

		val = readl(SCU0_HWSTRAP);
		val_otp = se_val[1] << 16;
		vld_otp = se_vld[1] << 16;
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU0_HWSTRAP);

		val = readl(SCU0_PCI_MISC70);
		val_otp = se_val[6] & GENMASK(10, 7);
		vld_otp = se_vld[6] & GENMASK(10, 7);
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU0_PCI_MISC70);

		val = readl(SCU0_PCI_MISCF0);
		val_otp = se_val[6] & GENMASK(14, 11);
		vld_otp = se_vld[6] & GENMASK(14, 11);
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, SCU0_PCI_MISCF0);

		/* unlock DRAMC */
		writel(0x1688a8a8, DRAMC_REG);

		val = readl(DRAMC_REG + 0x100);
		val_otp = (se_val[6] & BIT(4)) >> 4;
		vld_otp = (se_vld[6] & BIT(4)) >> 4;
		v = (val & ~vld_otp) | (val_otp & vld_otp);
		writel(v, DRAMC_REG + 0x100);

		/* soft-lock DRAMC */
		writel(0x1, DRAMC_REG);
	} else {
		return -EINVAL;
	}

	return 0;
}

static int otp_cfg_init(void)
{
	uint32_t data;
	int rc;

	for (int i = 0; i < 16; i++) {
		rc = otp_readl(CFG_REGION_START_ADDR + i * 2, &data);
		if (rc)
			return rc;

		writel(data, SCU1_OTPCFG + i * 4);
	}

	return 0;
}

static int otp_irot_uds_init(void)
{
	uint32_t data;
	int rc;

	for (int i = 0; i < 8; i++) {
		rc = otp_readl(HW_PUF_IROT_UDS + i * 2, &data);
		if (rc)
			return rc;

		writel(data, SCU1_PRIV_SCRATCH_0 + i * 4);
	}

	return 0;
}

bootstage_t otp_init_cpu(struct rom_context *rom_ctx)
{
	bootstage_t sts = {BOOTSTAGE_ERR_SUCCESS, 0};
	int rc;

	rc = otp_strapext_init(CPU_DIE);
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_STRAPEXT_FAILED;
		sts.syndrome = rc;
		goto out;
	}

	rc = otp_dbgctrl_init(CPU_DIE);
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_DBGCTRL_FAILED;
		sts.syndrome = rc;
		goto out;
	}

out:
	return sts;
}

bootstage_t otp_init_io(struct rom_context *rom_ctx)
{
	bootstage_t sts = {BOOTSTAGE_ERR_SUCCESS, 0};
	int rc;

	rc = otp_cfg_init();
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_CFG_FAILED;
		sts.syndrome = rc;
		goto out;
	}

	rc = otp_strapext_init(IO_DIE);
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_STRAPEXT_FAILED;
		sts.syndrome = rc;
		goto out;
	}

	rc = otp_dbgctrl_init(IO_DIE);
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_DBGCTRL_FAILED;
		sts.syndrome = rc;
		goto out;
	}

	rc = otp_irot_uds_init();
	if (rc) {
		sts.errno = OTP_SCU_INIT_ERR_IROT_UDS_FAILED;
		sts.syndrome = rc;
		goto out;
	}

out:
	return sts;
}

static void otp_usr0_region_protect(uint32_t offset, uint32_t size, uint32_t w_prot, uint32_t r_prot)
{
	uint32_t val = 0;

	otp_unlock();

	writel((size << 16) | (offset & GENMASK(15, 0)), OTP_REGION_USR0_RANGE);
	if (!w_prot)
		val |= OTP_REGION_W_EN;
	if (!r_prot)
		val |= OTP_REGION_R_EN;
	writel(val, OTP_REGION_USR0);

	/* lock */
	writel(val | OTP_REGION_LOCK, OTP_REGION_USR0);

	/* block other ranges */
	writel(0x0, OTP_REGION_USR1_RANGE);
	writel(0x0, OTP_REGION_USR2_RANGE);
	writel(0x0, OTP_REGION_USR3_RANGE);

	otp_lock();
}

static void otp_secure0_region_protect(uint32_t offset, uint32_t size, uint32_t w_prot, uint32_t r_prot)
{
	uint32_t val = 0;

	otp_unlock();

	writel((size << 16) | (offset & GENMASK(15, 0)), OTP_REGION_SECURE0_RANGE);
	if (!w_prot)
		val |= OTP_REGION_W_EN;
	if (!r_prot)
		val |= OTP_REGION_R_EN;
	writel(val, OTP_REGION_SECURE0);

	/* lock */
	writel(val | OTP_REGION_LOCK, OTP_REGION_SECURE0);

	/* block other ranges */
	writel(0x0, OTP_REGION_SECURE1_RANGE);
	writel(0x0, OTP_REGION_SECURE2_RANGE);
	writel(0x0, OTP_REGION_SECURE3_RANGE);

	otp_lock();
}

static void otp_cptra0_region_protect(uint32_t offset, uint32_t size, uint32_t w_prot, uint32_t r_prot)
{
	uint32_t val = 0;

	otp_unlock();

	writel((size << 16) | (offset & GENMASK(15, 0)), OTP_REGION_CALIPTRA_0_RANGE);
	if (!w_prot)
		val |= OTP_REGION_W_EN;
	if (!r_prot)
		val |= OTP_REGION_R_EN;
	writel(val, OTP_REGION_CALIPTRA_0);

	/* lock */
	writel(val | OTP_REGION_LOCK, OTP_REGION_CALIPTRA_0);

	/* block other ranges */
	writel(0x0, OTP_REGION_CALIPTRA_1_RANGE);
	writel(0x0, OTP_REGION_CALIPTRA_2_RANGE);
	writel(0x0, OTP_REGION_CALIPTRA_3_RANGE);

	otp_lock();
}

/* Program UDS Seed:
 * - AES(Chip Unique ID + RND)
 */
static int otp_uds_seed_init(void)
{
	uint32_t uds_obf_buff[UDS_SEED_SIZE / 2] = {0};
	uint32_t uds_buff[UDS_SEED_SIZE / 2] = {0};
	uint32_t key_buff[OBF_KEY_SIZE / 2] = {0};
	uint16_t *us_ptr;
	int rc = 0;
	int ret;

	uds_buff[0] = readl(SCU1_CHIP_UNIQ_ID0);
	uds_buff[1] = readl(SCU1_CHIP_UNIQ_ID1);

	/* Check if chip unique id is zero */
	if (!uds_buff[0] || !uds_buff[1]) {
		rc = PUF_UID_ERR;
		goto out;
	}

	for (int i = 2; i < UDS_SEED_SIZE / 2; i++)
		uds_buff[i] = rand();

	for (int i = 0; i < OBF_KEY_SIZE; i++) {
		ret = otp_readl(HW_PUF_OBF_KEY, &key_buff[i]);
		if (ret) {
			rc = PUF_READ_ERR;
			goto out;
		}
	}

	if (!sli_get_availability()) {
		rc = PUF_UDS_SLI_ERR;
		goto out;
	}

	/* Do aes encryption */
	ret = sec_aes_256_cbc_enc((uint8_t *)uds_buff, sizeof(uds_buff), (uint8_t *)uds_obf_buff,
				  (uint8_t *)key_buff, sizeof(key_buff), (uint8_t *)CPTRA_UDS_OBF_IV,
				  sizeof(CPTRA_UDS_OBF_IV));
	if (ret) {
		rc = PUF_UDS_OBF_ERR;
		goto out;
	}

	us_ptr = (uint16_t *)uds_obf_buff;
	for (int i = 0; i < UDS_SEED_SIZE; i++) {
		ret = otp_write_ecc(us_ptr[i], HW_PUF_UDS_SEED + i);
		if (ret) {
			rc = PUF_PROG_RND_ERR;
			goto out;
		}
	}

	return 0;
out:
	return rc;
}

bootstage_t otp_init_region(struct rom_context *rom_ctx)
{
	bootstage_t sts = {OTP_REGION_SUCCESS, 0};
	bool uds_seed_ready = false;
	bool puf_ready = false;
	uint32_t val, offset, size;
	uint32_t w_prot, r_prot;
	uint32_t rnd;
	uint16_t data;
	int ret;

	/* Static user region protection */
	val = readl(SCU1_OTPCFG_11_10);
	if (val & SCU1_OTPCFG11_EN_AUTO_LOAD_USR0) {
		offset = FIELD_GET(SCU1_OTPCFG11_OFFSET_USR0, val);
		size = FIELD_GET(SCU1_OTPCFG12_SIZE_USR0, readl(SCU1_OTPCFG_13_12));
		w_prot = FIELD_GET(SCU1_OTPCFG11_W_PROT_USR0, val);
		r_prot = FIELD_GET(SCU1_OTPCFG11_R_PROT_USR0, val);
		otp_usr0_region_protect(offset, size, w_prot, r_prot);
		sts.syndrome |= OTP_REGION_USR_DONE;
	}

	/* Static secure region protection */
	val = readl(SCU1_OTPCFG_13_12);
	if (val & SCU1_OTPCFG13_EN_AUTO_LOAD_SEC0) {
		offset = FIELD_GET(SCU1_OTPCFG13_OFFSET_SEC0, val);
		size = FIELD_GET(SCU1_OTPCFG14_SIZE_SEC0, readl(SCU1_OTPCFG_15_14));
		w_prot = FIELD_GET(SCU1_OTPCFG13_W_PROT_SEC0, val);
		r_prot = FIELD_GET(SCU1_OTPCFG13_R_PROT_SEC0, val);
		otp_secure0_region_protect(offset, size, w_prot, r_prot);
		sts.syndrome |= OTP_REGION_SECURE_DONE;
	}

	/* Static cptra region protection */
	val = readl(SCU1_OTPCFG_21_20);
	if (val & SCU1_OTPCFG20_EN_AUTO_LOAD_CPTRA0) {
		offset = FIELD_GET(SCU1_OTPCFG20_OFFSET_CPTRA0, val);
		size = FIELD_GET(SCU1_OTPCFG21_SIZE_CPTRA0, val);
		w_prot = FIELD_GET(SCU1_OTPCFG20_W_PROT_CPTRA0, val);
		r_prot = FIELD_GET(SCU1_OTPCFG20_R_PROT_CPTRA0, val);
		otp_cptra0_region_protect(offset, size, w_prot, r_prot);
		sts.syndrome |= OTP_REGION_CPTRA_DONE;
	}

	/* PUF region initialize */
	/* Check efuse */
	if (readl(SCU1_EFUSE) & SCU1_EFUSE_DIS_PROG_PUF) {
		sts.errno = OTP_REGION_PUF_SKIP;
		goto out;
	}

	/* Check if it's programmed or not */
	if (readl(SCU1_OTPCFG_01_00) & OTPCFG0_WR_PROT_PUF) {
		sts.errno = OTP_REGION_PUF_ALREADY_DONE;
		goto out;
	}

	/* Check if nisttrng is ready */
	if (!is_nisttrng_ready()) {
		sts.errno = OTP_REGION_PUF_RNG_ERR;
		goto out;
	}

	/* Check if PUF is programmed */
	ret = otp_readw(SW_PUF_REGION_START_ADDR, &data);
	if (ret) {
		sts.errno = OTP_REGION_PUF_PROG_ERR;
		sts.syndrome |= PUF_READ_ERR;
		goto out;
	}

	if (data)
		puf_ready = true;

	/* Program PUF region with nisttrng */
	for (int i = 0; i < PUF_REGION_SIZE / 2; i++) {
		if (puf_ready)
			break;

		/* Skip UDS seed area */
		offset = (HW_PUF_UDS_SEED - SW_PUF_REGION_START_ADDR) / 2;
		if (i >= offset && i < (offset + UDS_SEED_SIZE / 2))
			continue;

		rnd = rand();
		ret = otp_write_ecc(rnd & GENMASK(15, 0), SW_PUF_REGION_START_ADDR + i * 2);
		if (ret) {
			sts.errno = OTP_REGION_PUF_PROG_ERR;
			sts.syndrome |= PUF_PROG_RND_ERR;
			goto out;
		}

		ret = otp_write_ecc((rnd >> 16) & GENMASK(15, 0), SW_PUF_REGION_START_ADDR + 1 + i * 2);
		if (ret) {
			sts.errno = OTP_REGION_PUF_PROG_ERR;
			sts.syndrome |= PUF_PROG_RND_ERR;
			goto out;
		}
	}

	/* Check if UDS Seed is programmed */
	ret = otp_readw(HW_PUF_UDS_SEED, &data);
	if (ret) {
		sts.errno = OTP_REGION_PUF_UDS_PROG_ERR;
		sts.syndrome |= PUF_READ_ERR;
		goto out;
	}

	if (data)
		uds_seed_ready = true;

	/* Program UDS Seed */
	if (!uds_seed_ready) {
		ret = otp_uds_seed_init();
		if (ret) {
			sts.errno = OTP_REGION_PUF_UDS_PROG_ERR;
			sts.syndrome |= ret;
			goto out;
		}
	}

	/* Static puf region protection */
	ret = otp_write(OTPCFG0_WR_PROT_PUF, OTPCFG0);
	if (ret) {
		sts.errno = OTP_REGION_PUF_PROT_ERR;
		sts.syndrome |= PUF_PROG_PROT_ERR;
		goto out;
	}

	sts.errno = OTP_REGION_PUF_PROG_DONE;

out:
	return sts;
}
