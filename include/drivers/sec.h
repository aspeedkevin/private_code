#ifndef __SEC_H__
#define __SEC_H__

#include <types.h>

/* SEC register definitions */
#define SEC_DMA_EN_REG			(SEC_REG + 0x0)
#define SEC_DMA_STS_REG			(SEC_REG + 0x4)
#define SEC_DMA_MODE_REG		(SEC_REG + 0x8)
#define   SEC_KEY_GEN			BIT(11)
#define   SEC_OUT_TO_DST		BIT(10)
#define   SEC_GEN_LAST			BIT(8)
#define   SEC_AES_MODE			BIT(5)
#define   SEC_SHA_MODE			BIT(1)

#define SEC_VK_CTRL_REG                 (SEC_REG + 0xC)
#define   VK_WR_PROT                    BIT(2)
#define SEC_DIG_CHK_STS_REG		(SEC_REG + 0x14)
#define SEC_EN_REG			(SEC_REG + 0x20)
#define SEC_DMA_SRC_H_REG		(SEC_REG + 0x30)
#define SEC_DMA_DST_H_REG		(SEC_REG + 0x34)
#define SEC_DMA_SRC_REG			(SEC_REG + 0x40)
#define SEC_DMA_DST_REG			(SEC_REG + 0x44)
#define SEC_DMA_SZ_REG			(SEC_REG + 0x48)
#define SEC_HASH_SZ_REG			(SEC_REG + 0x54)
#define SEC_HASH_MODE_SEL_REG		(SEC_REG + 0x58)
#define   HASH_MODE_SHA256		BIT(0)
#define   HASH_MODE_SHA512		BIT(1)
#define   BYTE_SWAP_ALL			(0x2 << 2)
#define   SHA1_ALG			(0x2 << 4)
#define   SHA224_ALG			(0x4 << 4)
#define   SHA256_ALG			(0x5 << 4)
#define   SHA512_S_ALG			(0x6 << 4)
#define   HMAC_DIGEST_WO_HMAC		(0x0 << 7)
#define   HMAC_DIGEST_W_HMAC		(0x1 << 7)
#define   HMAC_DIGEST_W_ACC		(0x2 << 7)
#define   HMAC_CAL_HMAC_KEY		(0x3 << 7)

#define SEC_HASH_FIRE_REG		(SEC_REG + 0x5C)
#define SEC_CRYPT_MODE_SEL_REG		(SEC_REG + 0x60)
#define   HACE_CMD_AES_KEY_HW_EXP	BIT(13)
#define   HACE_CMD_AES			(0)
#define   HACE_CMD_ENCRYPT		BIT(7)
#define   HACE_CMD_CBC			(0x1 << 4)
#define   HACE_CMD_AES256		(0x2 << 2)

#define SEC_CRYPT_SZ_REG		(SEC_REG + 0x64)
#define SEC_PAD_LEN_REG			(SEC_REG + 0x64)
#define SEC_CRYPT_TSZ_REG		(SEC_REG + 0x68)
#define SEC_KEY_WR_TRIG_L_REG		(SEC_REG + 0x70)
#define SEC_KEY_WR_TRIG_H_REG		(SEC_REG + 0x74)
#define SEC_IV_WR_TRIG_REG		(SEC_REG + 0x78)
#define SEC_CRYPT_FIRE_REG		(SEC_REG + 0x7C)
#define SEC_KEY_BUFF_REG		(SEC_REG + 0xA0)
#define SEC_VAULT_KEY0_REG		(SEC_REG + 0x100)
#define SEC_VAULT_KEY1_REG		(SEC_REG + 0x120)
#define SEC_VAULT_KEY2_REG		(SEC_REG + 0x180)
#define SEC_VAULT_KEY3_REG		(SEC_REG + 0x1A0)

#define SHA256_DIGEST_SIZE		32
#define SHA256_BLOCK_SIZE		64
#define SHA256_IV_SIZE			32

int sec_hmac_sha256(uint8_t *key, int klen, uint8_t *src, int slen, uint8_t *dst);
int sec_aes_256_cbc_enc(uint8_t *src, int s_size, uint8_t *dst, uint8_t *key, int k_size, uint8_t *iv, int iv_size);

#endif /* __SEC_H__ */
