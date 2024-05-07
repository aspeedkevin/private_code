#ifndef __ROM_PATCH_H__
#define __ROM_PATCH_H__

#include <bootstage.h>
#include <rom_context.h>

enum rom_patch_errno {
	ROMPATCH_SUCCESS = 0,
	ROMPATCH_ERR_SKIP,
	ROMPATCH_ERR_ABORT,
};

bootstage_t rom_patch_f(struct rom_context *rc);
bootstage_t rom_patch_r(struct rom_context *rc);

#endif
