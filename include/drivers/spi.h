/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __SPI_H__
#define __SPI_H__

#include <drivers/abr.h>
#include <types.h>
#include <utils.h>

#define SNOR_SZ_UNSET		0x0
#define SNOR_SZ_8MB		0x800000
#define SNOR_SZ_16MB		0x1000000
#define SNOR_SZ_32MB		0x2000000
#define SNOR_SZ_64MB		0x4000000
#define SNOR_SZ_128MB		0x8000000
#define SNOR_SZ_256MB		0x10000000
#define SNOR_SZ_512MB		0x20000000


/* FMC REG OFFSET */
#define ADDR_CTRL		(0x04)
#define ADDR_DATA_CTRL		(0x0C)
#define CE0_CTRL		(0x10)
#define CE0_ADDR_DECODING	(0x30)
#define FMC_RST_LOCK		(0x1EC)

/* CE control */
#define FMC_CLK_FREQ_MASK	(0x0f000f00)
#define CS_STOP_ACTIVE		(BIT(2))
#define USER_MODE		(0x3)

/* SPI error code */
#define ERROR_INVALID_FLASH_SZ	0x1

struct decoding_range {
	uint32_t start_addr;
	uint32_t end_addr;
};

void spi_fmc_init_f(uint32_t cs);
int spi_fmc_init_r(uint32_t cs, uint32_t abr_enabled, uint32_t auxpin_abr_enabled, uint32_t abr_single);
uint32_t spi_fmc_segment_addr_start(uint32_t reg_val);
uint32_t spi_fmc_segment_addr_end(uint32_t reg_val);
void spi_fmc_decoding_range_config(uint32_t idx, uint32_t start_addr, uint32_t end_addr);
uint32_t spi_fmc_get_flash_sz_strap(void);
void fmc_reg_reset_config(void);

#endif
