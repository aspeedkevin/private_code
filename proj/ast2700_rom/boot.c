// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <boot.h>
#include <bootstage.h>
#include <drivers/scu.h>
#include <io.h>
#include <platform.h>
#include <types.h>

static uintptr_t boot_entry = CONFIG_RAM_CODE_ENTRY_ADDR;

/*
 * SCU1_010[11]: 0 -> FWSPI, 1 -> eMMC/UFS
 * SCU1_010[23]: 0 -> eMMC, 1 -> UFS
 */
enum boot_mode_type boot_mode(void)
{
	uint32_t reg;

	reg = readl(SCU1_HWSTRAP1);

	if (reg & SCU1_HWSTRAP1_BOOT_EMMC_UFS) {
		if (reg & SCU1_HWSTRAP1_BOOT_UFS) {
			return BOOT_UFS;
		} else
			return BOOT_EMMC;
	}

	/* leave FWSPI as default for safety */
	return BOOT_SPI;
}

void boot_entry_get(uintptr_t *cur_ep)
{
	*cur_ep = boot_entry;
}

void boot_entry_set(uintptr_t new_ep)
{
	boot_entry = new_ep;
}

void boot_image(void)
{
	void (*img_boot)(void);

	img_boot = (void (*)(void))(boot_entry);
	img_boot();
}
