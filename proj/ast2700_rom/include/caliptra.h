#ifndef __CALIPTRA_H__
#define __CALIPTRA_H__

#include <bootstage.h>
#include <drivers/caliptra.h>
#include <rom_context.h>

/* caliptra boot FSM errno */
#define CB_FSM_ERR_SUCC			0x0
#define CB_FSM_ERR_OTP_OBFKEY		0x1
#define CB_FSM_ERR_OTP_SECSTAT		0x2
#define CB_FSM_ERR_OTP_FUSE		0x3
#define CB_FSM_ERR_SET_MBOX_PAUSER	0x4
#define CB_FSM_ERR_SET_TRNG_PAUSER	0x5
#define CB_FSM_ERR_SET_FUSE_PAUSER	0x6
#define CB_FSM_ERR_FUSE_REQ		0x7
#define CB_FSM_ERR_FUSE_SET		0x8
#define CB_FSM_ERR_FUSE_DONE		0x9
#define CB_FSM_ERR_NO_BOOT_DONE		0xa
#define CB_FSM_ERR_SET_WDTCFG		0xb
#define CB_FSM_ERR_GENERIC		0xff

/* caliptra boot ROM errno */
#define CB_ROM_ERR_SUCC			0x0
#define CB_ROM_ERR_INVL_STS		0x1
#define CB_ROM_ERR_CSR_READ		0x2
#define CB_ROM_ERR_RNG			0x3
#define CB_ROM_ERR_NO_RDY_FOR_FW	0x4
#define CB_ROM_ERR_FWLD_INVAL		0x5
#define CB_ROM_ERR_FWLD_MBOX_LOCK	0x6
#define CB_ROM_ERR_FWLD_MBOX_EXEC	0x7
#define CB_ROM_ERR_FWLD_MBOX_UNLK	0x8
#define CB_ROM_ERR_GENERIC		0xff

/* caliptra boot FW errno */
#define CB_FW_ERR_SUCC			0x0
#define CB_FW_ERR_INVL_STS		0x1
#define CB_FW_ERR_RNG			0x2
#define CB_FW_ERR_NO_RDY_FOR_RT		0x3
#define CB_FW_ERR_FWIF_MBOX_LOCK	0x4
#define CB_FW_ERR_FWIF_MBOX_EXEC	0x5
#define CB_FW_ERR_FWIF_MBOX_UNLK	0x6
#define CB_FW_ERR_GENERIC		0xff

/* security state */
#define CPTRA_SS_DBG_UNPROVISIONED	0b000
#define CPTRA_SS_DBG_MANUFACTURING	0b001
#define CPTRA_SS_DBG_PRODUCTION		0b011
#define CPTRA_SS_MANUFACTURING		0b101
#define CPTRA_SS_PRODUCTION		0b111
#define   CPTRA_SS_DBG_LOCK		BIT(2)
#define   CPTRA_SS_DEV_LCS		GENMASK(1, 0)

int cptra_otp_obf_key(struct cptra_obf_key *key);
int cptra_otp_sec_stat(uint32_t *ss);
int cptra_otp_fuse(struct cptra_fuse *fuse);
void otp_update_cptra_fmc_svn(uint32_t svn);
void otp_update_cptra_rt_svn(uint32_t svn);

bootstage_t cptra_bootfsm_boot(struct rom_context *rom_ctx);
bootstage_t cptra_rom_boot(struct rom_context *rom_ctx);
bootstage_t cptra_fw_boot(struct rom_context *rom_ctx);

/* IV used for obfuscation engine during UDS encryption */
static const uint32_t CPTRA_UDS_OBF_IV[] = { 0xfb10365b, 0xa1179741, 0xfba193a1, 0x0f406d7e };

#endif
