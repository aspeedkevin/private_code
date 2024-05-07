#ifndef __SEC_VAULT_H__
#define __SEC_VAULT_H__

/* secure vault init errno */
#define SEC_VAULT_SUCCESS		0
#define SEC_VAULT_ERR_SKIP		1
#define SEC_VAULT_ERR_OTP		2
#define SEC_VAULT_ERR_HMAC		3

bootstage_t sec_vault_init(struct rom_context *rom_ctx);

#endif /* __SEC_VAULT_H__ */
