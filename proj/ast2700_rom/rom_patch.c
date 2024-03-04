#include <boot.h>
#include <drivers/otp.h>
#include <io.h>
#include <otp_mem.h>
#include <rom_patch.h>
#include <utils.h>

bootstage_t rom_patch_f(void)
{
	bootstage_t sts = { ROMPATCH_ERR_ABORT, 0 };
	uint16_t patch_ofst, patch_size;
	uint16_t *sram;
	uint16_t data;
	int i, rc;

	sram = (uint16_t *)CONFIG_RAM_CODE_LOAD_ADDR;

	/* check pre-ROM patch enabling */
	rc = otp_read_data(OTPCFG2, &data);
	if (rc) {
		sts.syndrome = rc;
		goto out;
	}

	if (data & OTPCFG2_DIS_PRE_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check pre-ROM patch validity */
	rc = otp_read_data(OTPCFG4, &data);
	if (rc) {
		sts.syndrome = rc;
		goto out;
	}

	if (!(data & OTPCFG4_PRE_OTP_PATCH_VLD)) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check patch offset & size */
	patch_ofst = FIELD_GET(OTPCFG4_PRE_OTP_PATCH_LOCATION, data);

	rc = otp_read_data(OTPCFG5, &data);
	if (rc) {
		sts.syndrome = rc;
		goto out;
	}

	patch_size = FIELD_GET(OTPCFG5_PRE_OTP_PATCH_SIZE, data);
	if (patch_size == 0) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* copy pre-ROM patch to SRAM */
	for (i = 0; i < patch_size; ++i) {
		rc = otp_read_data(OTP_MEM_ROMEXT_BASE + patch_ofst + i, &data);
		if (rc) {
			sts.syndrome = rc;
			goto out;
		}

		writew(data, sram + i);
	}

	/* specify the boot to next image indicator */
	sts.boot2img = BOOTSTAGE_JMP_BOOT2IMG;

	/* update the entry */
	boot_entry_set((uintptr_t)sram);

out:
	return sts;
}

bootstage_t rom_patch_r(void)
{
	bootstage_t sts = { ROMPATCH_ERR_ABORT, 0 };
	uint16_t patch_ofst, patch_size;
	uint16_t *sram;
	uint16_t data;
	int i, rc;

	sram = (uint16_t *)CONFIG_RAM_CODE_LOAD_ADDR;

	/* check post-ROM patch enabling */
	rc = otp_read_data(OTPCFG2, &data);
	if (rc) {
		sts.syndrome = rc;
		goto out;
	}

	if (data & OTPCFG2_DIS_POST_ROM_PATCH) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check post-ROM patch validity */
	rc = otp_read_data(OTPCFG6, &data);
	if (rc) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	if (!(data & OTPCFG6_POST_OTP_PATCH_VLD)) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* check patch offset & size */
	patch_ofst = FIELD_GET(OTPCFG6_POST_OTP_PATCH_LOCATION, data);

	rc = otp_read_data(OTPCFG7, &data);
	if (rc) {
		sts.syndrome = rc;
		goto out;
	}

	patch_size = FIELD_GET(OTPCFG7_POST_OTP_PATCH_SIZE, data);
	if (patch_size == 0) {
		sts.errno = ROMPATCH_ERR_SKIP;
		goto out;
	}

	/* copy post-ROM patch to SRAM */
	for (i = 0; i < patch_size; ++i) {
		rc = otp_read_data(OTP_MEM_ROMEXT_BASE + patch_ofst + i, &data);
		if (rc) {
			sts.syndrome = rc;
			goto out;
		}

		writew(data, sram + i);
	}

	/* specify the boot to next image indicator */
	sts.boot2img = BOOTSTAGE_JMP_BOOT2IMG;

	/* update the entry */
	boot_entry_set((uintptr_t)sram);

out:
	return sts;
}
