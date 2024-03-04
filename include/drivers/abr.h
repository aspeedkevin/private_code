/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __ABR_H__
#define __ABR_H__

#include <types.h>
#include <utils.h>

#define ABR_FMC_CS_SWAP		BIT(0)
#define ABR_INDICATOR		BIT(1)
#define ABR_EXT_SIGNAL_EN	BIT(2)
#define ABR_INFO_CLR		0xea000000

enum flash_abr_mode {
	DUAL_FLASH_ABR = 0,
	SINGLE_FLASH_ABR,
};

struct flash_abr_info {
	/* FWSPI flash, eMMC and UFS */
	uint32_t abr_boot_indicator;
	uint32_t wdta_timeout_occur;

	/* FWSPI flash */
	enum flash_abr_mode mode;
	uint32_t fmc_boot_cs;
	bool fmc_cs_swap;
};

bool abr_enable(void);
uint32_t get_abr_indictor(void);
bool spi_flash_cs_swap_occur(void);
enum flash_abr_mode get_spi_flash_abr_mode(void);
void abr_early_init(struct flash_abr_info *abr_info);
void abr_post_init(void);
bool fwspi_auxpin_enable(void);
bool ext_abr_signal(void);
void abr_wdta_reconfig(void);

#endif
