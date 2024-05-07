#ifndef __DRV_CALIPTRA_H__
#define __DRV_CALIPTRA_H__

#include <platform.h>
#include <types.h>
#include <utils.h>

/* common & fuse registers */
#define CPTRA_HW_ERROR_FATAL		(CPTRA_COMM_REG + 0x000)
#define CPTRA_HW_ERROR_NONFATAL		(CPTRA_COMM_REG + 0x004)
#define CPTRA_FW_ERROR_FATAL		(CPTRA_COMM_REG + 0x008)
#define CPTRA_FW_ERROR_NONFATAL		(CPTRA_COMM_REG + 0x00c)
#define CPTRA_HW_ERROR_ENC		(CPTRA_COMM_REG + 0x010)
#define CPTRA_FW_ERROR_ENC		(CPTRA_COMM_REG + 0x014)
#define CPTRA_FW_EXT_ERROR_INFO		(CPTRA_COMM_REG + 0x018)
#define CPTRA_BOOT_STS			(CPTRA_COMM_REG + 0x038)
#define CPTRA_FLOW_STS			(CPTRA_COMM_REG + 0x03c)
#define   CPTRA_FLOW_STS_RDY_FOR_FUSES	BIT(30)
#define   CPTRA_FLOW_STS_RDY_FOR_RT	BIT(29)
#define   CPTRA_FLOW_STS_RDY_FOR_FW	BIT(28)
#define   CPTRA_FLOW_STS_FSM_PS		GENMASK(27, 25)
#define   CPTRA_FLOW_STS_IDEVID_CSR_RDY	BIT(24)
#define CPTRA_RST_REASON		(CPTRA_COMM_REG + 0x040)
#define CPTRA_SEC_STAT			(CPTRA_COMM_REG + 0x044)
#define CPTRA_MBOX_PAUSER(n)		(CPTRA_COMM_REG + 0x048 + ((n) << 2))
#define CPTRA_MBOX_PAUSER_LOCK(n)	(CPTRA_COMM_REG + 0x05c + ((n) << 2))
#define CPTRA_TRNG_PAUSER		(CPTRA_COMM_REG + 0x070)
#define CPTRA_TRNG_PAUSER_LOCK		(CPTRA_COMM_REG + 0x074)
#define CPTRA_TRNG_DATA(n)		(CPTRA_COMM_REG + 0x078 + ((n) << 2))
#define CPTRA_TRNG_CTRL			(CPTRA_COMM_REG + 0x0a8)
#define CPTRA_TRNG_STS			(CPTRA_COMM_REG + 0x0ac)
#define   CPTRA_TRNG_STS_DATA_WR_DONE	BIT(1)
#define   CPTRA_TRNG_STS_DATA_REQ	BIT(0)
#define CPTRA_FUSE_WR_DONE		(CPTRA_COMM_REG + 0x0b0)
#define CPTRA_TIMER_CFG			(CPTRA_COMM_REG + 0x0b4)
#define CPTRA_DBG_MANUF_SERV		(CPTRA_COMM_REG + 0x0bc)
#define   CPTRA_DBG_MANUF_SERV_GEN_CSR	BIT(0)
#define CPTRA_FUSE_PAUSER		(CPTRA_COMM_REG + 0x108)
#define CPTRA_FUSE_PAUSER_LOCK		(CPTRA_COMM_REG + 0x10c)
#define CPTRA_WDT_CFG(n)		(CPTRA_COMM_REG + 0x110 + ((n) << 2))
#define CPTRA_FUSE_UDS(n)		(CPTRA_COMM_REG + 0x200 + ((n) << 2))
#define CPTRA_FUSE_FE(n)		(CPTRA_COMM_REG + 0x230 + ((n) << 2))
#define CPTRA_FUSE_MANIF_PKHASH(n)	(CPTRA_COMM_REG + 0x250 + ((n) << 2))
#define CPTRA_FUSE_MANIF_PKHASH_MASK	(CPTRA_COMM_REG + 0x280)
#define CPTRA_FUSE_OWNER_PKHASH(n)	(CPTRA_COMM_REG + 0x284 + ((n) << 2))
#define CPTRA_FUSE_FMC_SVN		(CPTRA_COMM_REG + 0x2b4)
#define CPTRA_FUSE_RT_SVN(n)		(CPTRA_COMM_REG + 0x2b8 + ((n) << 2))
#define CPTRA_FUSE_ANTIROLLBACK_DIS	(CPTRA_COMM_REG + 0x2c8)
#define CPTRA_FUSE_IDEVID_CERT_ATTR(n)	(CPTRA_COMM_REG + 0x2cc + ((n) << 2))
#define CPTRA_FUSE_IDEVID_MANUF_HSM(n)	(CPTRA_COMM_REG + 0x32c + ((n) << 2))
#define CPTRA_FUSE_LIFE_CYCLE		(CPTRA_COMM_REG + 0x33c)
#define CPTRA_FUSE_LMS_VERIFY		(CPTRA_COMM_REG + 0x340)
#define CPTRA_FUSE_LMS_REVOCATION	(CPTRA_COMM_REG + 0x344)
#define CPTRA_FUSE_SOC_STEPPING_ID	(CPTRA_COMM_REG + 0x348)

/* Mailbox registers */
#define CPTRA_MBOX_LOCK			(CPTRA_MBOX_REG + 0x00)
#define CPTRA_MBOX_USER			(CPTRA_MBOX_REG + 0x04)
#define CPTRA_MBOX_CMD			(CPTRA_MBOX_REG + 0x08)
#define CPTRA_MBOX_DLEN			(CPTRA_MBOX_REG + 0x0c)
#define CPTRA_MBOX_DATAIN		(CPTRA_MBOX_REG + 0x10)
#define CPTRA_MBOX_DATAOUT		(CPTRA_MBOX_REG + 0x14)
#define CPTRA_MBOX_EXEC			(CPTRA_MBOX_REG + 0x18)
#define CPTRA_MBOX_STS			(CPTRA_MBOX_REG + 0x1c)
#define   CPTRA_MBOX_STS_SOC_LOCK	BIT(9)
#define   CPTRA_MBOX_STS_FSM_PS		GENMASK(8, 6)
#define   CPTRA_MBOX_STS_PS		GENMASK(3, 0)
#define CPTRA_MBOX_UNLOCK		(CPTRA_MBOX_REG + 0x20)

/* SHA registers */
#define CPTRA_SHA_LOCK			(CPTRA_SHA_REG + 0x00)
#define CPTRA_SHA_USER			(CPTRA_SHA_REG + 0x04)
#define CPTRA_SHA_MODE			(CPTRA_SHA_REG + 0x08)
#define   CPTRA_SHA_MODE_ENDIAN		BIT(2)
#define   CPTRA_SHA_MODE_SEL		GENMASK(1, 0)
#define CPTRA_SHA_DLEN			(CPTRA_SHA_REG + 0x10)
#define CPTRA_SHA_DATAIN		(CPTRA_SHA_REG + 0x14)
#define CPTRA_SHA_EXEC			(CPTRA_SHA_REG + 0x18)
#define CPTRA_SHA_STS			(CPTRA_SHA_REG + 0x1c)
#define   CPTRA_SHA_STS_SOC_LOCK	BIT(1)
#define   CPTRA_SHA_STS_VLD		BIT(0)
#define CPTRA_SHA_DIGEST(n)		(CPTRA_SHA_REG + 0x20 + ((n) << 2))
#define CPTRA_SHA_CTRL			(CPTRA_SHA_REG + 0x60)
#define   CPTRA_SHA_CTRL_ZEROIZE	BIT(0)

/* Caliptra Common */
#define CPTRA_MAX_MBOX_PAUSER		5
#define CPTRA_MAX_TRNG			12
#define CPTRA_OBF_KEYLEN		8
#define CPTRA_UDS_SEED_LEN		12
#define CPTRA_FE_LEN			8
#define CPTRA_PK_HASH_LEN		12
#define CPTRA_RT_SVN_LEN		4
#define CPTRA_IDEVID_CERT_ATTR_LEN	24
#define CPTRA_IDEVID_MANUF_HSM_ID_LEN	4

struct cptra_fuse {
	uint32_t uds_seed[CPTRA_UDS_SEED_LEN];
	uint32_t field_entropy[CPTRA_FE_LEN];
	uint32_t key_manifest_pk_hash[CPTRA_PK_HASH_LEN];
	uint32_t key_manifest_pk_hash_mask;
	uint32_t owner_pk_hash[CPTRA_PK_HASH_LEN];
	uint32_t fmc_key_manifest_svn;
	uint32_t runtime_svn[CPTRA_RT_SVN_LEN];
	uint32_t anti_rollback_disable;
	uint32_t idevid_cert_attr[CPTRA_IDEVID_CERT_ATTR_LEN];
	uint32_t idevid_manuf_hsm_id[CPTRA_IDEVID_MANUF_HSM_ID_LEN];
	uint32_t life_cycle;
	uint32_t lms_verify;
	uint32_t lms_revocation;
	uint32_t soc_stepping_id;
};

struct cptra_obf_key {
	uint32_t data[CPTRA_OBF_KEYLEN];
};

enum cptra_fsm_stat {
	CPTRA_FSM_BOOT_IDLE,
	CPTRA_FSM_BOOT_FUSE,
	CPTRA_FSM_BOOT_FW_RST,
	CPTRA_FSM_BOOT_WAIT,
	CPTRA_FSM_BOOT_DONE,
};

uint32_t cptra_get_flow_status(void);
uint32_t cptra_get_boot_status(void);
uint32_t cptra_get_trng_status(void);
int cptra_set_csr_gen_request(void);
int cptra_set_csr_gen_complete(void);
int cptra_set_mbox_pauser(uint32_t *id, uint32_t id_num);
int cptra_set_trng_pauser(uint32_t id);
int cptra_set_fuse_pauser(uint32_t id);
int cptra_set_fuse_data(struct cptra_fuse *fuse);
int cptra_set_wdtcfg(uint32_t tmout_h, uint32_t tmout_l);

/* Caliptra Mailbox */
enum cptra_mbox_cmd {
	CPTRA_MBCMD_CALIPTRA_FW_LOAD = 0x46574c44,
	CPTRA_MBCMD_ECDSA384_SIGNATURE_VERIFY = 0x53494756,
	CPTRA_MBCMD_LMS_SIGNATURE_VERIFY = 0x4c4d5356,
	CPTRA_MBCMD_FW_INFO = 0x494e464f,
};

enum cptra_mbox_sts {
	CPTRA_MBSTS_CMD_BUSY,
	CPTRA_MBSTS_DATA_READY,
	CPTRA_MBSTS_CMD_COMPLETE,
	CPTRA_MBSTS_CMD_FAILURE,
};

enum cptra_mbox_fsm {
	CPTRA_MBFSM_IDLE,
	CPTRA_MBFSM_RDY_FOR_CMD,
	CPTRA_MBFSM_RDY_FOR_DATA,
	CPTRA_MBFSM_RDY_FOR_DLEN,
	CPTRA_MBFSM_EXEC_SOC,
	CPTRA_MBFSM_RSVD_5,
	CPTRA_MBFSM_EXEC_UC,
	CPTRA_MBFSM_ERROR,
};

struct cptra_fw_info {
	uint32_t chksum;
	uint32_t fips_status;
	uint32_t pl0_pauser;
	uint32_t runtime_svn;
	uint32_t min_runtime_svn;
	uint32_t fmc_manifest_svn;
	uint32_t attestation_disabled;
	uint8_t rom_revision[20];
	uint8_t fmc_revision[20];
	uint8_t runtime_revision[20];
	uint32_t rom_sha256_digest[8];
	uint32_t fmc_sha384_digest[12];
	uint32_t runtime_sha384_digest[12];
};

uint32_t cptra_mbox_csum(uint32_t csum, uint8_t *data, uint32_t dlen);
uint32_t cptra_mbox_status(void);
int cptra_mbox_lock(void);
int cptra_mbox_send(uint32_t cmd, uint8_t *data, uint32_t dlen);
int cptra_mbox_recv(uint32_t *cmd, uint8_t *data, uint32_t *dlen);
int cptra_mbox_unlock(void);

/* Caliptra SHA ACC */
enum cptra_sha_mode {
	CPTRA_SHA384_STREAM,
	CPTRA_SHA512_STREAM,
};

uint32_t cptra_sha_status(void);
int cptra_sha_lock(void);
int cptra_sha_digest(uint8_t *digest_be, enum cptra_sha_mode mode, uint8_t *data, uint32_t dlen);
int cptra_sha_init(enum cptra_sha_mode mode);
int cptra_sha_update(uint8_t *data, uint32_t dlen);
int cptra_sha_finish(uint8_t *digest_be);
int cptra_sha_unlock(void);

#endif
