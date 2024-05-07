#include <caliptra.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <errno.h>
#include <lib/string.h>
#include <otp_mem.h>
#include <io.h>

static bool is_cptra_own_key_retire(int id)
{
	uint16_t val;
	int rc;

	rc = otp_readw(OTPBRP_CPTRA_OWN_PK_KEYHASH_RETIRE, &val);
	if (rc)
		return false;

	if (val & BIT(id))
		return true;

	return false;
}

static void otp_update_cptra_own_keyid(uint32_t keyid)
{
	otp_unlock();
	writel((BIT(keyid) & OTP_KEY_MASK) | OTP_KEY_WLOCK, OTP_CPTRA_OWN_KEY);
	otp_lock();
}

void otp_update_cptra_fmc_svn(uint32_t svn)
{
	uint32_t svn_bitmap;

	otp_unlock();
	if (!svn)
		goto end;

	svn_bitmap = GENMASK(svn - 1, 0);
	writel(svn_bitmap, OTP_CPTRA_FMC_SVN);
end:
	/* write lock */
	writel(OTP_CPTRA_FMC_SVN_WLOCK, OTP_SVN_CTRL);
	otp_lock();
}

void otp_update_cptra_rt_svn(uint32_t svn)
{
	uint32_t svn_bitmap[4] = {0};

	otp_unlock();
	if (!svn)
		goto end;

	if (svn <= 32) {
		svn_bitmap[0] = GENMASK(svn - 1, 0);
	} else if (svn > 32 && svn <= 64) {
		svn_bitmap[0] = GENMASK(31, 0);
		svn_bitmap[1] = GENMASK(svn - 32 - 1, 0);
	} else if (svn > 64 && svn <= 96) {
		svn_bitmap[0] = GENMASK(31, 0);
		svn_bitmap[1] = GENMASK(31, 0);
		svn_bitmap[2] = GENMASK(svn - 64 - 1, 0);
	} else if (svn > 96 && svn <= 128) {
		svn_bitmap[0] = GENMASK(31, 0);
		svn_bitmap[1] = GENMASK(31, 0);
		svn_bitmap[2] = GENMASK(31, 0);
		svn_bitmap[3] = GENMASK(svn - 96 - 1, 0);
	}

	writel(svn_bitmap[0], OTP_CPTRA_RT_SVN0);
	writel(svn_bitmap[1], OTP_CPTRA_RT_SVN1);
	writel(svn_bitmap[2], OTP_CPTRA_RT_SVN2);
	writel(svn_bitmap[3], OTP_CPTRA_RT_SVN3);
end:
	/* write lock */
	writel(OTP_CPTRA_RT_SVN_WLOCK, OTP_SVN_CTRL);
	otp_lock();
}

static int otp_cptra_manuf_key_get(struct cptra_manuf_key *key)
{
	int rc;

	if (!key)
		return -EINVAL;

	/* Get:
	 * - Caliptra manuf pk hash
	 * - Caliptra manuf ecc key mask
	 * - Caliptra manuf lms key mask
	 */
	for (int i = 0; i < OTP_CPTRA_PK_HASH_LEN; i++) {
		rc = otp_readl(OTPCAL_MANU_KEY_HASH + i * 2, &key->manuf_pk_hash[i]);
		if (rc)
			return rc;
	}

	rc = otp_readw(OTPBRP_CPTRA_MANU_ECC_KEY_MASK, &key->manuf_ecc_key_mask);
	if (rc)
		return rc;

	rc = otp_readl(OTPBRP_CPTRA_MANU_LMS_KEY_MASK, &key->manuf_lms_key_mask);
	if (rc)
		return rc;

	return 0;
}

static int otp_cptra_own_key_get(uint32_t *key)
{
	union otp_key_header_u kh;
	int rc;

	if (!key)
		return -EINVAL;

	for (int i = 0; i < OTP_KEY_HEADER_LEN / 2; i++) {
		rc = otp_readl(OTP_KEY_HEADER_START_ADDR + i * 2, &kh.value);
		if (rc)
			return rc;

		/* Get:
		 * - Caliptra owner pk hash
		 */
		if (kh.fields.key_type == OTP_KEY_TYPE_CPTRA_OWN_PK_HASH &&
		    !is_cptra_own_key_retire(kh.fields.key_id)) {
			for (int j = 0; j < OTP_CPTRA_PK_HASH_LEN; j++) {
				rc = otp_readl(OTP_KEY_HEADER_START_ADDR +
					       kh.fields.offset + j * 2,
					       &key[j]);
				if (rc)
					return rc;
			}

			/* record key id for hardware prevention */
			otp_update_cptra_own_keyid(kh.fields.key_id);
			return 0;
		}

		/* Last key */
		if (kh.fields.key_type == OTP_KEY_TYPE_CPTRA_OWN_PK_HASH &&
		    kh.fields.last)
			break;
	}

	return -ENODATA;
}

int cptra_otp_obf_key(struct cptra_obf_key *key)
{
	int rc;

	if (!key)
		return -EINVAL;

	/* read OBF_KEY from OTP */
	for (int i = 0; i < CPTRA_OBF_KEYLEN; i++) {
		rc = otp_readl(HW_PUF_OBF_KEY + i * 2, &key->data[i]);
		if (rc)
			return rc;
	}

	return 0;
}

int cptra_otp_sec_stat(uint32_t *ss)
{
	uint32_t dev_lcs;
	uint32_t val;

	if (!ss)
		return -EINVAL;

	/* read Caliptra security state from OTP
	 * [2]:   debug state
	 * [1:0]: device life cycle state
	 */
	dev_lcs = FIELD_GET(OTPCFG2_DEV_LIFE_CYCLE, readl(SCU1_OTPCFG_03_02));

	/* Unprovisioned + Debug only */
	if (!dev_lcs) {
		*ss = CPTRA_SS_DBG_UNPROVISIONED;
		return 0;
	}

	val = ~FIELD_GET(SCU1_HWSTRAP2_EN_CPTRA_DBG, readl(SCU1_HWSTRAP2)) & 0x1;
	*ss = FIELD_PREP(CPTRA_SS_DBG_LOCK, val) | dev_lcs;

	return 0;
}

int cptra_otp_fuse(struct cptra_fuse *fuse)
{
	uint32_t owner_pk_hash[CPTRA_PK_HASH_LEN];
	struct cptra_manuf_key manuf_key[1];
	int rc;

	if (!fuse)
		return -EINVAL;

	memset(fuse, 0x0, sizeof(*fuse));

	/* read Caliptra fuse from OTP */
	/* Caliptra fuse: uds_seed */
	for (int i = 0; i < CPTRA_UDS_SEED_LEN; i++) {
		rc = otp_readl(HW_PUF_UDS_SEED + i * 2, &fuse->uds_seed[i]);
		if (rc)
			return rc;
	}

	/* HW PUF read protect */
	otp_unlock();
	writel(OTP_HW_PUF_RLOCK, OTP_PUF);
	otp_lock();

	/* Caliptra fuse: field_entropy */
	for (int i = 0; i < CPTRA_FE_LEN; i++) {
		rc = otp_readl(OTPCAL_FIELD_ENTROPY + i * 2, &fuse->field_entropy[i]);
		if (rc)
			return rc;
	}

	/* Caliptra fuse: FMC/RT SVN */
	rc = otp_readl(OTPBRP_CPTRA_FMC_SVN, &fuse->fmc_key_manifest_svn);
	if (rc)
		return rc;

	for (int i = 0; i < CPTRA_RT_SVN_LEN; i++) {
		rc = otp_readl(OTPBRP_CPTRA_RT_SVN + i * 2, &fuse->runtime_svn[i]);
		if (rc)
			return rc;
	}

	rc = otp_readl(OTPCAL0, &fuse->lms_verify);
	if (rc)
		return rc;

	rc = otp_readl(OTPCAL1, &fuse->anti_rollback_disable);
	if (rc)
		return rc;

	/* Caliptra fuse: IDEVID Cert Attr */
	for (int i = 0; i < CPTRA_IDEVID_CERT_ATTR_LEN; i++) {
		rc = otp_readl(OTPCAL_IDEVID_CERT_ATTR + i * 2, &fuse->idevid_cert_attr[i]);
		if (rc)
			return rc;
	}

	/* Caliptra fuse: IDEVID Manuf HSM ID */
	for (int i = 0; i < CPTRA_IDEVID_MANUF_HSM_ID_LEN; i++) {
		rc = otp_readl(OTPCAL_IDEVID_MANUF_HSM_ID + i * 2, &fuse->idevid_manuf_hsm_id[i]);
		if (rc)
			return rc;
	}

	/* Caliptra fuse: life cycle - Caliptra Boot Media Integrated mode usage only. */

	/* Caliptra fuse:
	 * - key_manifest_pk_hash
	 * - key_manifest_pk_hash_mask
	 * - owner_pk_hash
	 * - lms_revocation
	 */
	rc = otp_cptra_manuf_key_get(manuf_key);
	if (rc)
		return rc;

	memcpy(fuse->key_manifest_pk_hash, manuf_key[0].manuf_pk_hash, sizeof(fuse->key_manifest_pk_hash));
	fuse->key_manifest_pk_hash_mask = manuf_key[0].manuf_ecc_key_mask;
	fuse->lms_revocation = manuf_key[0].manuf_lms_key_mask;

	rc = otp_cptra_own_key_get(owner_pk_hash);
	if (rc) {
		if (rc != -ENODATA)
			return rc;

		/* key not provisioned, make it blank */
		memset(owner_pk_hash, 0x0, sizeof(owner_pk_hash));
	}

	memcpy(fuse->owner_pk_hash, owner_pk_hash, sizeof(fuse->owner_pk_hash));

	/* Caliptra fuse: soc_stepping_id */
	fuse->soc_stepping_id = readl(SCU1_CHIP_REV_ID);

	return 0;
}
