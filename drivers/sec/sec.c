#include <debug.h>
#include <drivers/sec.h>
#include <drivers/scu.h>
#include <errno.h>
#include <io.h>
#include <platform.h>
#include <utils.h>
#include <lib/string.h>

bool is_sec_init;

static bool is_all_zero(uint8_t *data, int slen)
{
	if (!slen)
		return true;

	for (int i = 0; i < slen; i++) {
		if (data[i])
			return false;
	}

	return true;
}

static int wait_complete(void)
{
	int ret;
	u32 val;

	ret = readl_poll_timeout(SEC_DMA_STS_REG, val, ((val & 0x1) == 0x1), 1,
				 100000);

	return ret;
}

static void sec_init(void)
{
	// assert HACE reset
	writel(SCU0_RSTCTL1_HACE, SCU0_RSTCTL1);

	// enable clk
	writel(SCU0_CLKGATE1_CLR_HACE, SCU0_CLKGATE1_CLR);

	// deassert HACE reset
	writel(SCU0_RSTCTL1_CLR_HACE, SCU0_RSTCTL1_CLR);

	// Enable SEC
	writel(0x0, SEC_EN_REG);
	writel(0x1, SEC_EN_REG);
}

int sec_hmac_sha256(uint8_t *key, int klen, uint8_t *src, int slen, uint8_t *dst)
{
	uint8_t key_in[SHA256_BLOCK_SIZE];
	uint8_t key_out[SHA256_DIGEST_SIZE * 2];
	uint32_t dma_mode;
	uint32_t cmd;
	int ret;

	if (!is_sec_init) {
		sec_init();
		is_sec_init = true;
	}

	if (!key || !src || !dst)
		return -EINVAL;

	if (is_all_zero(src, slen))
		slen = 0;

	cmd = HMAC_CAL_HMAC_KEY | SHA256_ALG | BYTE_SWAP_ALL | HASH_MODE_SHA256;

	memcpy(key_in, key, klen);
	memset(key_in + klen, 0, SHA256_BLOCK_SIZE - klen);

	/*
	 * 1. Do Key Gen
	 * hmackey_adr+0x00 = HASH(key0 ^ ipad)
	 * hmackey_adr+0x20 = HASH(key0 ^ opad)
	 */
	writel(key_in, SEC_DMA_SRC_REG);
	writel(0x0, SEC_DMA_SRC_H_REG);
	writel(key_out, SEC_DMA_DST_REG);
	writel(0x0, SEC_DMA_DST_H_REG);
	writel(SHA256_BLOCK_SIZE, SEC_DMA_SZ_REG);
	writel(SHA256_BLOCK_SIZE, SEC_HASH_SZ_REG);

	/*
	 * [11]: HMAC key gen
	 */
	dma_mode = SEC_SHA_MODE | SEC_OUT_TO_DST | SEC_KEY_GEN;

	writel(dma_mode, SEC_DMA_MODE_REG);
	writel(cmd, SEC_HASH_MODE_SEL_REG);

	/* fire */
	writel(0x1, SEC_HASH_FIRE_REG);

	/* DMA enable */
	writel(0x0, SEC_DMA_EN_REG);
	writel(0x1, SEC_DMA_EN_REG);

	/* Wait status */
	ret = wait_complete();
	if (ret)
		return -EIO;

	/*
	 * 2. Do HMAC
	 * HMAC0=HASH(HASH(key0 ^ ipad)||Data)
	 * HMAC=(HASH(key0^ opad)||HMAC0)
	 */

	/* 2.1 DMA to send HASH(key0 ^ ipad) */
	writel(key_out, SEC_DMA_SRC_REG);
	writel(0x0, SEC_DMA_SRC_H_REG);
	writel(dst, SEC_DMA_DST_REG);
	writel(0x0, SEC_DMA_DST_H_REG);
	writel(SHA256_DIGEST_SIZE, SEC_DMA_SZ_REG);
	writel(slen, SEC_HASH_SZ_REG);

	dma_mode = SEC_SHA_MODE;
	cmd = (cmd & ~GENMASK(8, 7)) | HMAC_DIGEST_W_HMAC;

	writel(dma_mode, SEC_DMA_MODE_REG);
	writel(cmd, SEC_HASH_MODE_SEL_REG);

	/* fire */
	writel(0x1, SEC_HASH_FIRE_REG);

	/* DMA enable */
	writel(0x0, SEC_DMA_EN_REG);
	writel(0x1, SEC_DMA_EN_REG);

	/* Wait status */
	ret = wait_complete();
	if (ret)
		return -EIO;

	/* 2.2 DMA to send Data */
	if (slen) {
		writel(src, SEC_DMA_SRC_REG);
		writel(0x0, SEC_DMA_SRC_H_REG);
		writel(slen, SEC_DMA_SZ_REG);

		/* DMA enable */
		writel(0x0, SEC_DMA_EN_REG);
		writel(0x1, SEC_DMA_EN_REG);

		/* Wait status */
		ret = wait_complete();
		if (ret)
			return -EIO;
	}

	/* 2.3 DMA to send HASH(key0 ^ opad) */
	dma_mode = SEC_SHA_MODE | SEC_OUT_TO_DST;

	writel(key_out + SHA256_DIGEST_SIZE, SEC_DMA_SRC_REG);
	writel(0x0, SEC_DMA_SRC_H_REG);
	writel(dma_mode, SEC_DMA_MODE_REG);
	writel(SHA256_DIGEST_SIZE, SEC_DMA_SZ_REG);

	/* DMA enable */
	writel(0x0, SEC_DMA_EN_REG);
	writel(0x1, SEC_DMA_EN_REG);

	/* Wait status */
	ret = wait_complete();
	if (ret)
		return -EIO;

	return 0;
}

int sec_aes_256_cbc_enc(uint8_t *src, int s_size, uint8_t *dst, uint8_t *key, int k_size, uint8_t *iv, int iv_size)
{
	uint32_t dma_mode;
	uint32_t cmd;
	uint32_t *ptr;
	int ret;
	int i;

	if (!is_sec_init) {
		sec_init();
		is_sec_init = true;
	}

	if (!key || !src || !dst)
		return -EINVAL;

	/* AES mode */
	dma_mode = SEC_AES_MODE | SEC_GEN_LAST;
	writel(dma_mode, SEC_DMA_MODE_REG);

	writel((uintptr_t)src, SEC_DMA_SRC_REG);
	writel(0x0, SEC_DMA_SRC_H_REG);
	writel((uintptr_t)dst, SEC_DMA_DST_REG);
	writel(0x0, SEC_DMA_DST_H_REG);
	writel(s_size, SEC_DMA_SZ_REG);
	writel(s_size, SEC_CRYPT_SZ_REG);
	writel(s_size / 16 - 1, SEC_CRYPT_TSZ_REG);

	cmd = HACE_CMD_AES_KEY_HW_EXP | HACE_CMD_ENCRYPT | HACE_CMD_CBC | HACE_CMD_AES256;
	writel(cmd, SEC_CRYPT_MODE_SEL_REG);

	/* initial key */
	ptr = (uint32_t *)key;
	for (i = 0; i < k_size / 4; i++)
		writel(*ptr++, SEC_KEY_BUFF_REG + i * 4);
	for ( ; i < 8; i++)
		writel(0x0, SEC_KEY_BUFF_REG + i * 4);

	/* trigger write key */
	writel(0x0, SEC_KEY_WR_TRIG_L_REG);
	writel(0x0, SEC_KEY_WR_TRIG_H_REG);

	/* initial IV */
	ptr = (uint32_t *)iv;
	for (i = 0; i < iv_size / 4; i++)
		writel(*ptr++, SEC_KEY_BUFF_REG + i * 4);
	for ( ; i < 8; i++)
		writel(0x0, SEC_KEY_BUFF_REG + i * 4);

	/* trigger write IV */
	writel(0x0, SEC_IV_WR_TRIG_REG);

	/* Crypto fire */
	writel(0x1, SEC_CRYPT_FIRE_REG);

	/* DMA fire */
	writel(0x0, SEC_DMA_EN_REG);
	writel(0x1, SEC_DMA_EN_REG);

	/* Wait status */
	ret = wait_complete();
	if (ret)
		return -EIO;

	return 0;
}
