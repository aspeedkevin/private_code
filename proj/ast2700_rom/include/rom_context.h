#ifndef __ROM_CONTEXT_H__
#define __ROM_CONTEXT_H__

#include <types.h>

/*
 * The ROM context aims to provide a global data strcuture to hold
 * runtime information needed across different ROM init. stages.
 */
struct rom_context {
	uint8_t major_ver;
	uint8_t minor_ver;
	uintptr_t fmc_epa;
	uintptr_t fmc_lda;
	uint32_t fmc_lds;
	uintptr_t cptra_lda;
	uint32_t cptra_lds;
	uintptr_t cnsl_base;

	uint32_t cptra_boot_fsm;
	uint32_t cptra_boot_rom;
	uint32_t cptra_boot_fw;
	uint32_t cptra_exec_tmout;

	uint32_t interrupt_mode;

	struct otp *otp;

	int bootstrap;
	struct bootdev *bd;
};

#endif
