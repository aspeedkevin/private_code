#ifndef __ROM_INTEGRITY_H__
#define __ROM_INTEGRITY_H__

#include <rom_context.h>

#define ROM_IC_ERR_PASSED	0
#define ROM_IC_ERR_FAILED	1

bootstage_t rom_integrity_check(struct rom_context *rom_ctx);

#endif
