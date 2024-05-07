#include <bootstage.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/sec.h>
#include <io.h>
#include <otp_mem.h>
#include <platform.h>
#include <sec_vault.h>
#include <utils.h>
#include <lib/string.h>

#define SEC_VAULT_KEY_MAX_LEN		4

static void sec_vault_lock(void)
{
	writel(VK_WR_PROT, SEC_REG + SEC_VK_CTRL_REG);
}

static void sec_vault_set(uint32_t *vault_key, int num)
{
	uint32_t reg;

	switch (num) {
	case 0:
		reg = SEC_VAULT_KEY0_REG;
		break;
	case 1:
		reg = SEC_VAULT_KEY1_REG;
		break;
	case 2:
		reg = SEC_VAULT_KEY2_REG;
		break;
	case 3:
		reg = SEC_VAULT_KEY3_REG;
		break;
	default:
		return;
	}

	/* Set vault key in SEC */
	for (int i = 0; i < VAULT_KEY_LEN; i++)
		writel(vault_key[i], reg + i * 4);
}

bootstage_t sec_vault_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };
	uint32_t vault_key_seed[VAULT_KEY_LEN];
	uint32_t vault_key_out[VAULT_KEY_LEN];
	uint32_t vault_key[VAULT_KEY_LEN];
	union otp_key_header_u kh;
	int count_vk = 0;
	int rc;

	memset(vault_key, 0, sizeof(vault_key));
	memset(vault_key_seed, 0, sizeof(vault_key_seed));
	memset(vault_key_out, 0, sizeof(vault_key_out));

	for (int i = 0; i < OTP_KEY_HEADER_LEN / 2; i++) {
		rc = otp_readl(OTP_KEY_HEADER_START_ADDR + i * 2, &kh.value);
		if (rc) {
			sts.errno = SEC_VAULT_ERR_OTP;
			sts.syndrome = rc;
			goto end;
		}

		if (count_vk >= SEC_VAULT_KEY_MAX_LEN)
			break;

		/* Get Secure Vault Key */
		if (kh.fields.key_type == OTP_KEY_TYPE_VAULT_KEY) {
			for (int j = 0; j < VAULT_KEY_LEN; j++) {
				rc = otp_readl(OTP_KEY_HEADER_START_ADDR +
						   kh.fields.offset + j * 2,
					       &vault_key[j]);
				if (rc) {
					sts.errno = SEC_VAULT_ERR_OTP;
					sts.syndrome = rc;
					goto end;
				}
			}

			sec_vault_set(vault_key, count_vk);
			count_vk++;

		} else if (kh.fields.key_type == OTP_KEY_TYPE_VAULT_KEY_SEED) {
			/* HMAC-SHA-256's data */
			for (int j = 0; j < VAULT_KEY_LEN; j++) {
				rc = otp_readl(OTP_KEY_HEADER_START_ADDR +
						   kh.fields.offset + j * 2,
					       &vault_key_seed[j]);
				if (rc) {
					sts.errno = SEC_VAULT_ERR_OTP;
					sts.syndrome = rc;
					goto end;
				}
			}

			/* HMAC-SHA-256's key */
			for (int j = 0; j < VAULT_KEY_LEN; j++) {
				rc = otp_readl(HW_PUF_VAULT_KEY + j * 2, &vault_key[j]);
				if (rc) {
					sts.errno = SEC_VAULT_ERR_OTP;
					sts.syndrome = rc;
					goto end;
				}
			}

			/* Do HMAC-SHA-256 */
			rc = sec_hmac_sha256((uint8_t *)vault_key, VAULT_KEY_LEN * 4,
					     (uint8_t *)vault_key_seed, VAULT_KEY_LEN * 4,
					     (uint8_t *)vault_key_out);
			if (rc) {
				sts.errno = SEC_VAULT_ERR_HMAC;
				goto end;
			}

			sec_vault_set(vault_key_out, count_vk);
			count_vk++;
		}
	}

	if (count_vk) {
		sec_vault_lock();
		sts.syndrome = count_vk;
	} else {
		sts.errno = SEC_VAULT_ERR_SKIP;
	}

end:
	return sts;
}
