#ifndef __BOOTSTAGE_H__
#define __BOOTSTAGE_H__

#include <types.h>
#include <rom_context.h>

#define BOOTSTAGE_BANNER			"B "
#define BOOTSTAGE_CPTRA_BOOTFSM_BOOT		"Cb"
#define BOOTSTAGE_CPTRA_ROM_BOOT		"Cr"
#define BOOTSTAGE_CPTRA_FW_BOOT			"Cf"
#define BOOTSTAGE_EXTRST_HOLDING_PEN		"E "
#define BOOTSTAGE_FWLOAD_CPTRA			"Fc"
#define BOOTSTAGE_FWLOAD_FMC			"Ff"
#define BOOTSTAGE_AHBC_INIT			"H "
#define BOOTSTAGE_ROM_INTEGRITY			"I "
#define BOOTSTAGE_BOOTDEV_FMC_LOAD		"Bl"
#define BOOTSTAGE_BOOTDEV_INIT			"Bi"
#define BOOTSTAGE_JUMP_IMAGE			"J "
#define BOOTSTAGE_LTPI_INIT			"L "
#define BOOTSTAGE_LTPI_FW_LOAD			"Lf"
#define BOOTSTAGE_RECOVERY			"R "
#define BOOTSTAGE_ROMPATCH_F			"Pf"
#define BOOTSTAGE_ROMPATCH_R			"Pr"
#define BOOTSTAGE_SLI_INIT			"S "
#define BOOTSTAGE_SYSCON_PINMUX_INIT		"Sp"
#define BOOTSTAGE_SYSCON_RSTLOG_INIT		"Sr"
#define BOOTSTAGE_TRNG_INIT			"T "
#define BOOTSTAGE_WDT_INIT			"W "
#define BOOTSTAGE_OTP_INIT_IO			"Oi"
#define BOOTSTAGE_OTP_INIT_CPU			"Oc"
#define BOOTSTAGE_OTP_INIT_REGION		"Or"
#define BOOTSTAGE_SECURE_BOOT			"Sb"
#define BOOTSTAGE_SECURE_VAULT			"Sv"
#define BOOTSTAGE_USB_UART			"Uu"
#define BOOTSTAGE_UART_CON			"Uc"

/* common error code */
#define BOOTSTAGE_ERR_SUCCESS	0x00

/* special indicator to directly boot FMC or panic */
#define BOOTSTAGE_JMP_BOOT2FMC	0xb007
#define BOOTSTAGE_JMP_PANIC	0xdead

typedef struct {
	uint8_t errno;
	uint8_t syndrome;
	union {
		uint16_t boot2fmc;
		uint16_t panic;
	};
} bootstage_t;

struct bootmsg {
	char *mark;
	uint8_t errno;
	uint8_t  syndrome;
};

void bootstage_prologue(char *mark);
void bootstage_epilogue(bootstage_t sts);
bootstage_t bootstage_init(struct rom_context *rom_ctx);

#endif
