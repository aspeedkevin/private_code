#include <bootdev.h>
#include <drivers/caliptra.h>
#include <drivers/scu.h>
#include <fw_load.h>
#include <fmc_verify.h>
#include <lib/string.h>
#include <io.h>
#include <types.h>

bootstage_t fw_load_cptra(struct rom_context *rom_ctx)
{
	bootstage_t sts = { FWLD_ERR_SUCC, 0, { 0 } };
	uint32_t ofst = 0x0;
	int ret;

	/* skip loading if bypass Caliptra */
	if ((readl(SCU1_HWSTRAP1) & SCU1_HWSTRAP1_DIS_CPTRA) ||
	    (readl(SCU1_EFUSE) & SCU1_EFUSE_DIS_CPTRA)) {
		sts.errno = FWLD_ERR_SUCC;
		sts.syndrome = 0x1;
		return sts;
	};

	/* read data from boot device to memory */
	ret = bootdev_read(rom_ctx, ofst, (uint32_t *)rom_ctx->cptra_lda, rom_ctx->cptra_lds);
	if (ret) {
		sts.errno = FWLD_ERR_BOOTDEV;
		sts.syndrome = ret;
	}

	return sts;
}

bootstage_t fw_load_fmc(struct rom_context *rom_ctx)
{
	bootstage_t sts = { FWLD_ERR_SUCC, 0, { 0 } };

	sts.syndrome = bootdev_load(rom_ctx, &sts.errno);

	return sts;
}
