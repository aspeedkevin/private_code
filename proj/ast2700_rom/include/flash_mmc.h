/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __FLASH_MMC_H__
#define __FLASH_MMC_H__

#include <types.h>

int flash_mmc_strap_read(uint16_t fs_val[8]);
void flash_mmc_init_f(void);
void flash_mmc_init_r(void);
void flash_mmc_image_load(void);

#endif
