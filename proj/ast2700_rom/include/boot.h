#ifndef __BOOT_H__
#define __BOOT_H__

#include <bootstage.h>
#include <rom_context.h>

enum boot_mode_type {
	BOOT_SPI = 0,
	BOOT_EMMC,
	BOOT_UFS,
	BOOT_USB,
	BOOT_I2C,
	BOOT_I3C,
	BOOT_UART,
	BOOT_TYPE,
};

#define IS_RECOVERY(n) ((n) > BOOT_UFS)

enum boot_mode_type boot_mode(void);

bootstage_t boot_banner(struct rom_context *rc);
bootstage_t boot_extrst_pen(struct rom_context *rc);
void boot_fmc(struct rom_context *rc);

#endif
