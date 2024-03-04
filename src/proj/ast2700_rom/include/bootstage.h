#ifndef __BOOTSTAGE_H__
#define __BOOTSTAGE_H__

#include <types.h>

/* old */
#define BOOTSTAGE_PRE_ROM_PATCH			"P0"
#define BOOTSTAGE_POST_ROM_PATCH		"P1"
#define BOOTSTAGE_RECOVERY_USB			"Rb"
#define BOOTSTAGE_RECOVERY_UART			"Ru"
#define BOOTSTAGE_OTP_FLASHSTRAP_SCU_INIT	"Of"
#define BOOTSTAGE_OTP_SCU_INIT			"Os"
#define BOOTSTAGE_FLASHSTRAP_SCU_INIT		"Fs"
#define BOOTSTAGE_NODE0_RTC			"T0"
#define BOOTSTAGE_NODE1_RTC			"T1"
#define BOOTSTAGE_DCSCM				"M "
#define BOOTSTAGE_LTPI_MASTER			"Lm"
#define BOOTSTAGE_LTPI_SLAVE			"Ls"
#define BOOTSTAGE_LTPI_SP_CAP			"Lc"
#define BOOTSTAGE_LTPI_WAIT_OP			"Lo"
#define BOOTSTAGE_WAIT_RESET_DEASSERT		"W "
#define BOOTSTAGE_KEY_VAULT			"Kv"
#define BOOTSTAGE_KEY_PUF			"Kp"
#define BOOTSTAGE_CALIPTRA			"C "
#define BOOTSTAGE_FLASH_EARLY_INIT		"Fe"
#define BOOTSTAGE_FLASH_POST_INIT		"Fp"
#define BOOTSTAGE_ABR_EARLY_INIT		"Ae"
#define BOOTSTAGE_ABR_POST_INIT			"Ap"
#define BOOTSTAGE_FAILED			"F "
#define BOOTSTAGE_EMMC_BOOT			"E "
#define BOOTSTAGE_FLASH_COPY			"Fc"

/* new, the leading '_' should be removed after fix done */
#define BOOTSTAGE_BANNER			"_B "
#define BOOTSTAGE_WAIT_EXTRST_DEASSERT		"_E "
#define BOOTSTAGE_FLASH_IMAGE_LOAD		"_Fl"
#define BOOTSTAGE_FLASH_INIT_F			"_Ff"
#define BOOTSTAGE_FLASH_INIT_R			"_Fr"
#define BOOTSTAGE_JUMP_IMAGE			"_J "
#define BOOTSTAGE_LTPI_INIT			"_L "
#define BOOTSTAGE_OTPSTRAP_INIT_F		"_Of"
#define BOOTSTAGE_OTPSTRAP_INIT_R		"_Or"
#define BOOTSTAGE_RECOVERY			"_R "
#define BOOTSTAGE_ROMPATCH_R			"_Pr"
#define BOOTSTAGE_SLI_INIT			"_S "
#define BOOTSTAGE_SYSCON_PINMUX_INIT		"_Sp"
#define BOOTSTAGE_SYSCON_DBGCTL_INIT		"_Sd"
#define BOOTSTAGE_SYSCON_RSTLOG_INIT		"_Sr"
#define BOOTSTAGE_WDT_INIT			"_W "

/* common error code */
#define BOOTSTAGE_ERR_SUCCESS	0x00

/* special indicator to directly boot next image */
#define BOOTSTAGE_JMP_BOOT2IMG	0xb007

typedef struct {
	uint8_t syndrome;
	uint8_t errno;
	uint16_t boot2img;
} bootstage_t;

void bootstage_start_mark(char *str);
void bootstage_end_status(uint8_t status);

void bootstage_prologue(char *mark);
void bootstage_epilogue(bootstage_t sts);
bootstage_t bootstage_init(void);

#endif
