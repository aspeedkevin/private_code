/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __FLASH_H__
#define __FLASH_H__

#include <bootstage.h>
#include <types.h>

#define ERR_STRAP_INVALID_BOOT_TYPE	0x01
#define ERR_STRAP_INVALID_PTR		0x02
#define ERR_STRAP_READ_OTP_FAILED	0x03
#define ERR_STRAP_INCORRECT_MAGIC	0x04
#define ERR_STRAP_INCORRECT_SZ		0x05
#define ERR_STRAP_INCORRECT_ALG		0x06
#define ERR_STRAP_INVALID_CHECKSUM	0x07

#define FLASH_STRAP_MAGIC		0x50415254	/* "PART" */
#define FLASH_STRAP_OFFSET		0x1f000		/* 124KB */
#define FLASH_STRAP_SZ			0x18
#define FLASH_STRAP_ALG_TYPE		0x01

struct flash_strap {
	uint32_t magic;
	uint16_t size;		/* checksum is not included */
	uint16_t algo;
	uint16_t fs_val[8];
	uint32_t csum;		/* checksum of fs_val[8] */
};

int flash_strap_read(uint16_t fs_val[8]);
bootstage_t flash_init_f(void);
bootstage_t flash_init_r(void);
bootstage_t flash_image_load(void);

#endif
