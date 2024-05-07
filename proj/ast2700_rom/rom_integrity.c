#include <bootstage.h>
#include <lib/printf.h>
#include <lib/sha256.h>
#include <lib/string.h>
#include <rom_integrity.h>
#include <types.h>
#include <utils.h>

uint8_t rom_dgst_golden[SHA256_SUM_SIZE] __section(".rom_digest") = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

bootstage_t rom_integrity_check(struct rom_context *rom_ctx)
{
	bootstage_t sts = { ROM_IC_ERR_PASSED, 0, { 0 } };
	uint8_t rom_dgst[SHA256_SUM_SIZE] = {0};
	struct sha256_context ctx[1];
	int rc;

	sha256_init(ctx);

	sha256_update(ctx, (uint8_t *)(CONFIG_SYS_TEXT_BASE),
		      ((uintptr_t)rom_dgst_golden - CONFIG_SYS_TEXT_BASE));

	sha256_finish(ctx, (uint8_t *)rom_dgst);

	rc = memcmp(rom_dgst_golden, rom_dgst, sizeof(rom_dgst));
	if (rc) {
		sts.errno = ROM_IC_ERR_FAILED;
		sts.syndrome = 0;
		sts.panic = BOOTSTAGE_JMP_PANIC;
	}

	return sts;
}
