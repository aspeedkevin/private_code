/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __BOOT_H__
#define __BOOT_H__

#include <types.h>

enum boot_mode_type {
	BOOT_SPI = 0,
	BOOT_EMMC,
	BOOT_UFS,
	BOOT_TYPE,
};

enum boot_mode_type boot_mode(void);
void boot_entry_get(uintptr_t *cur_ep);
void boot_entry_set(uintptr_t new_ep);
void boot_image(void);

#endif
