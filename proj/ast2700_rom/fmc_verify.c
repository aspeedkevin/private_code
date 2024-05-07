#include <bootstage.h>
#include <drivers/caliptra.h>
#include <drivers/gpio.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <errno.h>
#include <fmc_verify.h>
#include <io.h>
#include <lib/string.h>
#include <lib/clz.h>
#include <otp_mem.h>
#include <platform.h>
#include <utils.h>

static void fmc_sec_boot_sts(int sts)
{
	uint32_t addr = GPIO1_REG + GPIO(Q, 1);
	uint32_t reg = 0;

	/* set pinmux MF0: GPIOQ1 */
	clrsetbits(SCU1_PINMUX_GRP_Q, SCU1_PINMUX_PIN1,
		   FIELD_PREP(SCU1_PINMUX_PIN1, 0x0));

	/* set GPIO */
	reg |= FIELD_PREP(GPIO_DIRECT, GPIO_DIRECT_OUT);
	reg |= FIELD_PREP(GPIO_DATA, sts);
	writel(reg, addr);
}

static bool is_soc_ecc_key_retire(int id)
{
	uint16_t val;
	int rc;

	rc = otp_readw(OTPBRP_SOC_ECC_KEY_RETIRE, &val);
	if (rc)
		return false;

	if (val & BIT(id))
		return true;

	return false;
}

static bool is_soc_lms_key_retire(int id)
{
	uint16_t val;
	int rc;

	rc = otp_readw(OTPBRP_SOC_LMS_KEY_RETIRE, &val);
	if (rc)
		return false;

	if (val & BIT(id))
		return true;

	return false;
}

static void otp_update_soc_ecc_keyid(uint32_t keyid)
{
	otp_unlock();
	writel((BIT(keyid) & OTP_KEY_MASK) | OTP_KEY_WLOCK, OTP_SOC_ECCKEY);
	otp_lock();
}

static void otp_update_soc_lms_keyid(uint32_t keyid)
{
	otp_unlock();
	writel((BIT(keyid) & OTP_KEY_MASK) | OTP_KEY_WLOCK, OTP_SOC_LMSKEY);
	otp_lock();
}

static void otp_update_soc_svn(uint32_t svn)
{
	uint32_t svn_bitmap[2] = {0};

	otp_unlock();
	if (!svn)
		goto end;

	if (svn <= 32) {
		svn_bitmap[0] = GENMASK(svn - 1, 0);
	} else if (svn > 32 && svn <= 64) {
		svn_bitmap[0] = GENMASK(31, 0);
		svn_bitmap[1] = GENMASK(svn - 32 - 1, 0);
	}

	writel(svn_bitmap[0], OTP_SOC_SVN_LSB);
	writel(svn_bitmap[1], OTP_SOC_SVN_MSB);
end:
	/* write lock */
	writel(OTP_FMC_SVN_WLOCK, OTP_SVN_CTRL);
	otp_lock();
}

int is_ast_hdr(struct ast_fmc_header *fmc_hdr)
{
	return (fmc_hdr->preamble.magic == FMC_HDR_MAGIC);
}

static int fmc_verify_hdr(struct ast_fmc_header *fmc_hdr)
{
	/* Check Magic */
	if (!is_ast_hdr(fmc_hdr))
		return -ERR_HDR_MAGIC;

	return 0;
}

static int fmc_verify_svn(struct ast_fmc_header *fmc_hdr)
{
	uint32_t hw_svn, sw_svn;
	uint32_t val;
	uint64_t val64;
	int rc;

	rc = otp_readl(OTPBRP_SOC_FMC_SVN, &val);
	if (rc)
		return rc;

	val64 = val;
	rc = otp_readl(OTPBRP_SOC_FMC_SVN + 2, &val);
	if (rc)
		return rc;

	val64 |= (uint64_t)val << 32;

	hw_svn = 64 - clz64(val64);
	sw_svn = fmc_hdr->body.svn;

	if (hw_svn && sw_svn < hw_svn)
		return -ERR_HDR_ANTI_RBK;

	otp_update_soc_svn(sw_svn);

	return 0;
}

static int fmc_verify_signature_ecc(struct ast_fmc_header *fmc_hdr, uint8_t *key)
{
	uint32_t cmd = CPTRA_MBCMD_ECDSA384_SIGNATURE_VERIFY;
	uint32_t cptra_dgst_be[CPTRA_PK_HASH_LEN];
	uint8_t r[48], s[48];
	uint8_t x[48], y[48];
	uint32_t csum = 0;
	uint32_t *p32;
	uint32_t ms;
	uint8_t *p;
	int val;

	while (cptra_sha_lock())
		;

	cptra_sha_digest((uint8_t *)cptra_dgst_be, CPTRA_SHA384_STREAM, (uint8_t *)&fmc_hdr->body,
			 sizeof(struct hdr_body));
	cptra_sha_unlock();

	/* trigger ECDSA384 verification */
	p = (uint8_t *)fmc_hdr->preamble.ecc_sig;
	memcpy(r, p, sizeof(r));
	memcpy(s, p + sizeof(r), sizeof(s));

	memcpy(x, key, sizeof(x));
	memcpy(y, key + sizeof(x), sizeof(y));

	csum = cptra_mbox_csum(csum, (uint8_t *)&cmd, sizeof(cmd));
	csum = cptra_mbox_csum(csum, x, sizeof(x));
	csum = cptra_mbox_csum(csum, y, sizeof(y));
	csum = cptra_mbox_csum(csum, r, sizeof(r));
	csum = cptra_mbox_csum(csum, s, sizeof(s));

	while (cptra_mbox_lock())
		;

	writel(CPTRA_MBCMD_ECDSA384_SIGNATURE_VERIFY, CPTRA_MBOX_CMD);
	writel(sizeof(csum) + sizeof(x) + sizeof(y) + sizeof(r) + sizeof(s), CPTRA_MBOX_DLEN);

	writel(csum, CPTRA_MBOX_DATAIN);
	p32 = (uint32_t *)x;
	for (int i = 0; i < (sizeof(x) / sizeof(uint32_t)); ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);
	p32 = (uint32_t *)y;
	for (int i = 0; i < (sizeof(y) / sizeof(uint32_t)); ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);
	p32 = (uint32_t *)r;
	for (int i = 0; i < (sizeof(r) / sizeof(uint32_t)); ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);
	p32 = (uint32_t *)s;
	for (int i = 0; i < (sizeof(s) / sizeof(uint32_t)); ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);

	writel(0x1, CPTRA_MBOX_EXEC);

	while (1) {
		ms = FIELD_GET(CPTRA_MBOX_STS_PS, readl(CPTRA_MBOX_STS));
		if (ms != CPTRA_MBSTS_CMD_BUSY)
			break;
	}

	cptra_mbox_unlock();

	/* Check if verify pass */
	if (ms == CPTRA_MBSTS_DATA_READY) {
		val = readl(CPTRA_MBOX_DLEN);
		if (val == 0x8) {
			val = readl(CPTRA_MBOX_DATAOUT);
			val += readl(CPTRA_MBOX_DATAOUT);
			if (val == 0x0)
				return 0;
		}
	}

	/* verify failed */
	return ms;
}

static int fmc_verify_signature_lms(struct ast_fmc_header *fmc_hdr, uint32_t *key)
{
	struct lms_signature *lms_sig = (struct lms_signature *)fmc_hdr->preamble.lms_sig;
	struct lms_pub_key *lms_key = (struct lms_pub_key *)key;
	uint32_t cmd = CPTRA_MBCMD_LMS_SIGNATURE_VERIFY;
	uint32_t cptra_dgst_be[CPTRA_PK_HASH_LEN];
	uint32_t csum = 0;
	uint32_t *p32;
	uint32_t ms;
	int val;

	uint32_t pk_tree_type = be32_to_cpu(lms_key->pub_key_tree_type);
	uint32_t pk_ots_type = be32_to_cpu(lms_key->pub_key_ots_type);
	uint8_t *pk_id = lms_key->pub_key_id;
	uint8_t *pk_dgst = lms_key->pub_key_digest;

	uint32_t sig_q = lms_sig->q;
	uint8_t *sig_ots = lms_sig->ots;
	uint32_t sig_tree_type = le32_to_cpu(lms_sig->tree_type);
	uint8_t *sig_tree_path = lms_sig->tree_path;

	while (cptra_sha_lock())
		;

	cptra_sha_digest((uint8_t *)cptra_dgst_be, CPTRA_SHA384_STREAM, (uint8_t *)&fmc_hdr->body,
			 sizeof(struct hdr_body));
	cptra_sha_unlock();

	/* Check LMS public key algorithm type */
	if (pk_tree_type != LMS_PUB_KEY_TREE_TYPE ||
	    pk_ots_type != LMS_PUB_KEY_OTS_TYPE)
		return -EINVAL;

	/* Check LMS signature algorithm type */
	if (sig_tree_type != LMS_PUB_KEY_TREE_TYPE)
		return -EINVAL;

	csum = cptra_mbox_csum(csum, (uint8_t *)&cmd, sizeof(cmd));
	csum = cptra_mbox_csum(csum, (uint8_t *)&pk_tree_type, sizeof(pk_tree_type));
	csum = cptra_mbox_csum(csum, (uint8_t *)&pk_ots_type, sizeof(pk_ots_type));
	csum = cptra_mbox_csum(csum, pk_id, LMS_PUB_KEY_ID_LEN);
	csum = cptra_mbox_csum(csum, pk_dgst, LMS_PUB_KEY_DGST);
	csum = cptra_mbox_csum(csum, (uint8_t *)&sig_q, sizeof(sig_q));
	csum = cptra_mbox_csum(csum, sig_ots, LMS_SIG_OTS_LEN);
	csum = cptra_mbox_csum(csum, (uint8_t *)&sig_tree_type, sizeof(sig_tree_type));
	csum = cptra_mbox_csum(csum, sig_tree_path, LMS_SIG_TREE_PATH);

	while (cptra_mbox_lock())
		;

	writel(cmd, CPTRA_MBOX_CMD);
	writel(sizeof(csum) + sizeof(struct lms_pub_key) + sizeof(struct lms_signature), CPTRA_MBOX_DLEN);

	writel(csum, CPTRA_MBOX_DATAIN);
	writel(pk_tree_type, CPTRA_MBOX_DATAIN);
	writel(pk_ots_type, CPTRA_MBOX_DATAIN);

	p32 = (uint32_t *)pk_id;
	for (int i = 0; i < LMS_PUB_KEY_ID_LEN / 4; ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);

	p32 = (uint32_t *)pk_dgst;
	for (int i = 0; i < LMS_PUB_KEY_DGST / 4; ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);

	writel(sig_q, CPTRA_MBOX_DATAIN);

	p32 = (uint32_t *)sig_ots;
	for (int i = 0; i < LMS_SIG_OTS_LEN / 4; ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);

	writel(sig_tree_type, CPTRA_MBOX_DATAIN);

	p32 = (uint32_t *)sig_tree_path;
	for (int i = 0; i < LMS_SIG_TREE_PATH / 4; ++i)
		writel(p32[i], CPTRA_MBOX_DATAIN);

	writel(0x1, CPTRA_MBOX_EXEC);

	while (1) {
		ms = FIELD_GET(CPTRA_MBOX_STS_PS, readl(CPTRA_MBOX_STS));
		if (ms != CPTRA_MBSTS_CMD_BUSY)
			break;
	};

	cptra_mbox_unlock();

	/* Check if verify pass */
	if (ms == CPTRA_MBSTS_DATA_READY) {
		val = readl(CPTRA_MBOX_DLEN);
		if (val == 0x8) {
			val = readl(CPTRA_MBOX_DATAOUT);
			val += readl(CPTRA_MBOX_DATAOUT);
			if (val == 0x0)
				return 0;
		}
	}

	/* verify failed */
	return ms;
}

static void fmc_verify_signature(bootstage_t *sts, struct ast_fmc_header *fmc_hdr)
{
	uint32_t ecc_key[OEM_DSS_ECDSA384_KEY_LEN];
	uint32_t lms_key[OEM_DSS_LMS_KEY_LEN];
	union otp_key_header_u kh;
	bool ecc_verified, lms_verified;
	bool low_secure;
	uint32_t val;
	int rc;

	if (readl(SCU1_OTPCFG_03_02) && OTPCFG2_DIS_LOW_SECURE_KEY)
		low_secure = false;
	else
		low_secure = FIELD_GET(SCU1_HWSTRAP1_LOW_SECURE, readl(SCU1_HWSTRAP1)) ? true : false;

	/* ECDSA384 verification */
	ecc_verified = false;
	sts->syndrome |= FMC_VER_ECC;
	for (int i = 0; i < OTP_KEY_HEADER_LEN / 2; i++) {
		rc = otp_readl(OTP_KEY_HEADER_START_ADDR + i * 2, &kh.value);
		if (rc) {
			sts->syndrome |= rc & FMC_VER_SYND_MASK;
			goto end;
		}

		/* Get SoC OEM DSS ECDSA384 Key */
		if (kh.fields.key_type == OTP_KEY_TYPE_OEM_DSS_ECDSA384 &&
		    !is_soc_ecc_key_retire(kh.fields.key_id) &&
		    fmc_hdr->preamble.ecc_key_idx == kh.fields.key_id) {
			/* Only key #id=0 is allowed if low secure is enabled */
			if (!low_secure && kh.fields.key_id == 0x0)
				continue;

			for (int j = 0; j < OEM_DSS_ECDSA384_KEY_LEN; j++) {
				rc = otp_readl(OTP_KEY_HEADER_START_ADDR +
						   kh.fields.offset + j * 2,
					       &ecc_key[j]);
				if (rc) {
					sts->syndrome |= rc & FMC_VER_SYND_MASK;
					goto end;
				}
			}

			rc = fmc_verify_signature_ecc(fmc_hdr, (uint8_t *)ecc_key);
			if (!rc) {
				ecc_verified = true;
				otp_update_soc_ecc_keyid(kh.fields.key_id);
			}
			break;
		}

		/* Last key */
		if (kh.fields.key_type == OTP_KEY_TYPE_OEM_DSS_ECDSA384 &&
		    kh.fields.last)
			break;
	}

	if (!ecc_verified)
		goto end;

	/* ECDSA384 verification pass */

	/* Check LMS verify is enabled */
	val = readl(SCU1_OTPCFG_03_02) & OTPCFG2_EN_LMS_VERIFY;
	if (!val)
		return;

	/* LMS verification */
	lms_verified = false;
	sts->syndrome |= FMC_VER_LMS;
	for (int i = 0; i < OTP_KEY_HEADER_LEN / 2; i++) {
		rc = otp_readl(OTP_KEY_HEADER_START_ADDR + i * 2, &kh.value);
		if (rc) {
			sts->syndrome |= rc & FMC_VER_SYND_MASK;
			goto end;
		}

		/* Get SoC OEM DSS LMS Key */
		if (kh.fields.key_type == OTP_KEY_TYPE_OEM_DSS_LMS &&
		    !is_soc_lms_key_retire(kh.fields.key_id) &&
		    fmc_hdr->preamble.lms_key_idx == kh.fields.key_id) {
			/* Only key #id=0 is allowed if low secure is enabled */
			if (!low_secure && kh.fields.key_id == 0x0)
				continue;

			for (int j = 0; j < OEM_DSS_LMS_KEY_LEN; j++) {
				rc = otp_readl(OTP_KEY_HEADER_START_ADDR +
						   kh.fields.offset + j * 2,
					       &lms_key[j]);
				if (rc) {
					sts->syndrome |= rc & FMC_VER_SYND_MASK;
					goto end;
				}
			}

			rc = fmc_verify_signature_lms(fmc_hdr, lms_key);
			if (!rc) {
				lms_verified = true;
				otp_update_soc_lms_keyid(kh.fields.key_id);
			}
			break;
		}

		/* Last key */
		if (kh.fields.key_type == OTP_KEY_TYPE_OEM_DSS_LMS &&
		    kh.fields.last)
			break;
	}

	if (!lms_verified)
		goto end;

	/* LMS verification pass */
	return;

end:
	sts->errno = FMC_VER_ERR_SIG;
}

static int fmc_verify_digest(struct ast_fmc_header *fmc_hdr)
{
	uint32_t cptra_dgst_be[CPTRA_PK_HASH_LEN];
	uint32_t cptra_dgst_le[CPTRA_PK_HASH_LEN];
	int rc;

	while (cptra_sha_lock())
		;

	cptra_sha_digest((uint8_t *)cptra_dgst_be, CPTRA_SHA384_STREAM, (uint8_t *)(fmc_hdr + 1),
			 fmc_hdr->body.size);
	cptra_sha_unlock();

	for (int i = 0; i < ARRAY_SIZE(cptra_dgst_be); ++i)
		cptra_dgst_le[i] = be32_to_cpu(cptra_dgst_be[i]);

	/* Compare SoC FMC digest */
	rc = memcmp(cptra_dgst_le, fmc_hdr->body.dgst, sizeof(cptra_dgst_le));
	if (rc)
		return -EACCES;

	return 0;
}

bootstage_t fmc_verify(struct rom_context *rom_ctx)
{
	struct ast_fmc_header *fmc_hdr = (struct ast_fmc_header *)rom_ctx->fmc_lda;
	bootstage_t sts = { FMC_VER_SUCCESS, 0 };
	int rc;

	/* Check header */
	rc = fmc_verify_hdr(fmc_hdr);
	if (rc) {
		sts.errno = FMC_VER_ERR_HDR;
		sts.syndrome = rc;
		goto end;
	}

	if (!is_secboot()) {
		otp_unlock();
		writel(OTP_SEC_BOOT_WLOCK, OTP_SEC_BOOT_EN_STS);
		otp_lock();
		return sts;
	}

	/* Reset GPIO */
	fmc_sec_boot_sts(0);

	/* Secure boot indicator */
	sts.syndrome = SEC_BOOT_EN;
	otp_unlock();
	writel(OTP_SEC_BOOT_EN | OTP_SEC_BOOT_WLOCK, OTP_SEC_BOOT_EN_STS);
	otp_lock();

	/* Check Caliptra ready */
	if (!rom_ctx->cptra_boot_fw) {
		sts.errno = FMC_VER_ERR_CPTRA;
		sts.syndrome = 0;
		goto end;
	}

	/* Check signature */
	fmc_verify_signature(&sts, fmc_hdr);
	if (sts.errno == FMC_VER_ERR_SIG)
		goto end;

	/* Check FMC SVN */
	rc = fmc_verify_svn(fmc_hdr);
	if (rc) {
		sts.errno = FMC_VER_ERR_SVN;
		sts.syndrome |= rc & FMC_VER_SYND_MASK;
		goto end;
	}

	/* Check FMC digest */
	rc = fmc_verify_digest(fmc_hdr);
	if (rc) {
		sts.errno = FMC_VER_ERR_DGST;
		sts.syndrome |= rc & FMC_VER_SYND_MASK;
		goto end;
	}

	/* FMC verification PASS */
	return sts;

end:
	/* Raise GPIO if verification is failed */
	if (is_secboot())
		fmc_sec_boot_sts(1);

	sts.panic = BOOTSTAGE_JMP_PANIC;

	return sts;
}
