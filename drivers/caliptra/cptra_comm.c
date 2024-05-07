#include <drivers/caliptra.h>
#include <errno.h>
#include <io.h>
#include <platform.h>

uint32_t cptra_get_flow_status(void)
{
	return readl(CPTRA_FLOW_STS);
}

uint32_t cptra_get_boot_status(void)
{
	return readl(CPTRA_BOOT_STS);
}

uint32_t cptra_get_trng_status(void)
{
	return readl(CPTRA_TRNG_STS);
}

int cptra_set_csr_gen_request(void)
{
	uint32_t reg;

	reg = readl(CPTRA_DBG_MANUF_SERV);
	reg |= CPTRA_DBG_MANUF_SERV_GEN_CSR;
	writel(reg, CPTRA_DBG_MANUF_SERV);

	return 0;
}

int cptra_set_csr_gen_complete(void)
{
	uint32_t reg;

	reg = readl(CPTRA_DBG_MANUF_SERV);
	reg &= ~CPTRA_DBG_MANUF_SERV_GEN_CSR;
	writel(reg, CPTRA_DBG_MANUF_SERV);

	return 0;
}

int cptra_set_mbox_pauser(uint32_t *id, uint32_t id_num)
{
	uint32_t i;
	uint32_t locked;

	if (!id || id_num > CPTRA_MAX_MBOX_PAUSER)
		return -EINVAL;

	locked = readl(CPTRA_MBOX_PAUSER_LOCK(0));
	if (locked)
		return -EACCES;

	for (i = 0; i < id_num; ++i) {
		writel(id[i], CPTRA_MBOX_PAUSER(i));
		writel(0x1, CPTRA_MBOX_PAUSER_LOCK(i));
	}

	return 0;
}

int cptra_set_trng_pauser(uint32_t id)
{
	uint32_t locked;

	locked = readl(CPTRA_TRNG_PAUSER_LOCK);
	if (locked)
		return -EACCES;

	writel(id, CPTRA_TRNG_PAUSER);
	writel(0x1, CPTRA_TRNG_PAUSER_LOCK);

	return 0;
}

int cptra_set_fuse_pauser(uint32_t id)
{
	uint32_t locked;

	locked = readl(CPTRA_FUSE_PAUSER_LOCK);
	if (locked)
		return -EACCES;

	writel(id, CPTRA_FUSE_PAUSER);
	writel(0x1, CPTRA_FUSE_PAUSER_LOCK);

	return 0;
}

int cptra_set_fuse_data(struct cptra_fuse *fuse)
{
	int i;
	uint32_t sts;

	if (!fuse)
		return -EINVAL;

	sts = readl(CPTRA_FLOW_STS);
	if (!(sts & CPTRA_FLOW_STS_RDY_FOR_FUSES))
		return -EACCES;

	for (i = 0; i < ARRAY_SIZE(fuse->uds_seed); ++i)
		writel(fuse->uds_seed[i], CPTRA_FUSE_UDS(i));

	for (i = 0; i < ARRAY_SIZE(fuse->field_entropy); ++i)
		writel(fuse->field_entropy[i], CPTRA_FUSE_FE(i));

	for (i = 0; i < ARRAY_SIZE(fuse->key_manifest_pk_hash); ++i)
		writel(cpu_to_be32(fuse->key_manifest_pk_hash[i]), CPTRA_FUSE_MANIF_PKHASH(i));

	writel(fuse->key_manifest_pk_hash_mask, CPTRA_FUSE_MANIF_PKHASH_MASK);

	for (i = 0; i < ARRAY_SIZE(fuse->owner_pk_hash); ++i)
		writel(cpu_to_be32(fuse->owner_pk_hash[i]), CPTRA_FUSE_OWNER_PKHASH(i));

	writel(fuse->fmc_key_manifest_svn, CPTRA_FUSE_FMC_SVN);

	for (i = 0; i < ARRAY_SIZE(fuse->runtime_svn); ++i)
		writel(fuse->runtime_svn[i], CPTRA_FUSE_RT_SVN(i));

	writel(fuse->anti_rollback_disable, CPTRA_FUSE_ANTIROLLBACK_DIS);

	for (i = 0; i < ARRAY_SIZE(fuse->idevid_cert_attr); ++i)
		writel(fuse->idevid_cert_attr[i], CPTRA_FUSE_IDEVID_CERT_ATTR(i));

	for (i = 0; i < ARRAY_SIZE(fuse->idevid_manuf_hsm_id); ++i)
		writel(fuse->idevid_manuf_hsm_id[i], CPTRA_FUSE_IDEVID_MANUF_HSM(i));

	writel(fuse->life_cycle, CPTRA_FUSE_LIFE_CYCLE);

	writel(fuse->lms_verify, CPTRA_FUSE_LMS_VERIFY);

	writel(fuse->lms_revocation, CPTRA_FUSE_LMS_REVOCATION);

	writel(fuse->soc_stepping_id, CPTRA_FUSE_SOC_STEPPING_ID);

	writel(0x1, CPTRA_FUSE_WR_DONE);

	return 0;
}

int cptra_set_trng_data(uint32_t *rng, uint32_t rng_num)
{
	uint32_t sts;
	uint32_t i;

	if (!rng || rng_num > CPTRA_MAX_TRNG)
		return -EINVAL;

	sts = cptra_get_trng_status();

	if (!(sts & CPTRA_TRNG_STS_DATA_REQ))
		return -EACCES;

	for (i = 0; i < rng_num; ++i)
		writel(rng[i], CPTRA_TRNG_DATA(i));

	writel(CPTRA_TRNG_STS_DATA_WR_DONE, CPTRA_TRNG_STS);

	return 0;
}

int cptra_set_wdtcfg(uint32_t tmout_h, uint32_t tmout_l)
{
	if (!tmout_h && !tmout_l)
		return -EINVAL;

	writel(tmout_l, CPTRA_WDT_CFG(0));
	writel(tmout_h, CPTRA_WDT_CFG(1));

	return 0;
}
