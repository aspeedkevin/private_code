#ifndef __ROM_PATCH_H__
#define __ROM_PATCH_H__

#include <bootstage.h>

enum rom_patch_errno {
	ROMPATCH_ERR_SUCCESS,
	ROMPATCH_ERR_SKIP,
	ROMPATCH_ERR_ABORT,
};

bootstage_t rom_patch_f(void);
bootstage_t rom_patch_r(void);

#endif
