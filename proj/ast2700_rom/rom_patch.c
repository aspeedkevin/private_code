#include <boot.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <io.h>
#include <otp_mem.h>
#include <rom_patch.h>
#include <utils.h>

bootstage_t rom_patch_f(struct rom_context *rom_ctx)
{
	bootstage_t sts = { ROMPATCH_ERR_ABORT, 0 };
	uint16_t patch_ofst, patch_size;
	uint16_t *sram;
	uint16_t data;
	uint32_t reg;
	int rc;

	/* check efuse */
	reg = readl(SCU1_EFUSE);
	if (reg & SCU1_EFUSE_DIS_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	sram = (uint16_t *)rom_ctx->fmc_lda;

	reg = readl(SCU1_OTPCFG_03_02);
	/* check pre-ROM patch enabling */
	if (reg & OTPCFG2_DIS_PRE_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	reg = readl(SCU1_OTPCFG_05_04);
	/* check pre-ROM patch validity */
	if (!(reg & OTPCFG4_PRE_OTP_PATCH_VLD)) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check patch offset & size */
	patch_ofst = FIELD_GET(OTPCFG4_PRE_OTP_PATCH_LOCATION, reg);
	patch_size = FIELD_GET(OTPCFG5_PRE_OTP_PATCH_SIZE, reg);
	if (!patch_size) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* copy pre-ROM patch to SRAM */
	for (int i = 0; i < patch_size; ++i) {
		rc = otp_readw(ROM_REGION_START_ADDR + patch_ofst + i, &data);
		if (rc) {
			sts.syndrome = rc;
			goto out;
		}

		writew(data, sram + i);
	}

	/* update the entry */
	rom_ctx->fmc_epa = (uintptr_t)sram;

	boot_fmc(rom_ctx);

	/* Executed rom patch and return */
	sts.errno = ROMPATCH_SUCCESS;

out:
	return sts;
}

bootstage_t rom_patch_r(struct rom_context *rom_ctx)
{
	bootstage_t sts = { ROMPATCH_ERR_ABORT, 0 };
	uint16_t patch_ofst, patch_size;
	uint16_t *sram;
	uint16_t data;
	uint32_t reg;
	int rc;

	/* check efuse */
	reg = readl(SCU1_EFUSE);
	if (reg & SCU1_EFUSE_DIS_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	sram = (uint16_t *)rom_ctx->fmc_lda;

	reg = readl(SCU1_OTPCFG_03_02);
	/* check post-ROM patch enabling */
	if (reg & OTPCFG2_DIS_POST_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	reg = readl(SCU1_OTPCFG_07_06);
	/* check post-ROM patch validity */
	if (!(reg & OTPCFG6_POST_OTP_PATCH_VLD)) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check patch offset & size */
	patch_ofst = FIELD_GET(OTPCFG6_POST_OTP_PATCH_LOCATION, reg);
	patch_size = FIELD_GET(OTPCFG7_POST_OTP_PATCH_SIZE, reg);
	if (!patch_size) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* copy post-ROM patch to SRAM */
	for (int i = 0; i < patch_size; ++i) {
		rc = otp_readw(ROM_REGION_START_ADDR + patch_ofst + i, &data);
		if (rc) {
			sts.syndrome = rc;
			goto out;
		}

		writew(data, sram + i);
	}

	/* update the entry */
	rom_ctx->fmc_epa = (uintptr_t)sram;

	boot_fmc(rom_ctx);

	/* Executed rom patch and return */
	sts.errno = ROMPATCH_SUCCESS;

out:
	return sts;
}
