/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __FLASH_SPI_H__
#define __FLASH_SPI_H__

#include <types.h>

int flash_spi_strap_read(uint16_t fs_val[8]);
void flash_spi_init_f(void);
void flash_spi_init_r(void);
void flash_spi_image_load(void);

#endif
