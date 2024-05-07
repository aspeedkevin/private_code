#ifndef __FW_LOAD_H__
#define __FW_LOAD_H__

#include <bootstage.h>
#include <rom_context.h>

enum {
	FWLD_ERR_SUCC = 0,
	FWLD_ERR_BOOTDEV,
	FWLD_ERR_READ_HEADER,
	FWLD_ERR_WRONG_MAGIC,
	FWLD_ERR_ILLEGAL_SIZE,
	FWLD_ERR_READ_FMC,
	FWLD_ERR_RECOVERY,
};

bootstage_t fw_load_cptra(struct rom_context *rom_ctx);
bootstage_t fw_load_fmc(struct rom_context *rom_ctx);

#endif
