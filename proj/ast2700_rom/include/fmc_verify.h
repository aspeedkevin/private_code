#ifndef __FMC_VERIFY_H__
#define __FMC_VERIFY_H__

#include <drivers/scu.h>
#include <io.h>

/* fmc verify errno & syndrome */
#define FMC_VER_SUCCESS			0
#define FMC_VER_ERR_HDR			1
#define FMC_VER_ERR_CPTRA		2
#define FMC_VER_ERR_SIG			3
#define FMC_VER_ERR_SVN			4
#define FMC_VER_ERR_DGST		5

#define SEC_BOOT_EN			BIT(7)
#define FMC_VER_ECC			BIT(6)
#define FMC_VER_LMS			BIT(5)
#define ERR_HDR_MAGIC			1
#define ERR_HDR_ANTI_RBK		2
#define FMC_VER_SYND_MASK		GENMASK(4, 0)

#define FMC_HDR_MAGIC			0x48545341 /* ASTH */
#define INTPUT_FILE_MAX			10

#define LMS_PUB_KEY_TREE_TYPE		12
#define LMS_PUB_KEY_OTS_TYPE		7
#define LMS_PUB_KEY_ID_LEN		16
#define LMS_PUB_KEY_DGST		24
#define LMS_SIG_OTS_LEN			1252
#define LMS_SIG_TREE_PATH		360

#define ECC_SIGN_LEN			96
#define LMS_SIGN_LEN			1620
#define SHA_DGST_LEN			48

/* SoC FMC Header Structure */
struct hdr_preamble {
	uint32_t magic;
	uint32_t version;
	uint32_t ecc_key_idx;
	uint32_t lms_key_idx;
	uint8_t ecc_sig[ECC_SIGN_LEN];
	uint8_t lms_sig[LMS_SIGN_LEN];
	uint32_t raz[15];
};

struct hdr_body {
	uint32_t svn;
	uint32_t size;
	uint8_t dgst[SHA_DGST_LEN];
	union {
		struct {
			uint32_t type;
			uint32_t size;
			uint8_t dgst[SHA_DGST_LEN];
		} pbs[0];
		uint32_t raz[178];
	};
};

struct ast_fmc_header {
	struct hdr_preamble preamble;
	struct hdr_body body;
} __packed;

/* LMS public key structure */
struct lms_pub_key {
	uint32_t pub_key_tree_type;
	uint32_t pub_key_ots_type;
	uint8_t pub_key_id[LMS_PUB_KEY_ID_LEN];
	uint8_t pub_key_digest[LMS_PUB_KEY_DGST];
} __packed;

/* LMS signature structure */
struct lms_signature {
	uint32_t q;
	uint8_t ots[LMS_SIG_OTS_LEN];
	uint32_t tree_type;
	uint8_t tree_path[LMS_SIG_TREE_PATH];
} __packed;

static inline bool is_secboot(void)
{
	return FIELD_GET(SCU1_HWSTRAP1_EN_SECBOOT, readl(SCU1_HWSTRAP1)) ? true : false;
}

bootstage_t fmc_verify(struct rom_context *rc);
int is_ast_hdr(struct ast_fmc_header *fmc_hdr);

#endif /* __FMC_VERIFY_H__ */
