/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#ifndef __RECOVERY_H__
#define __RECOVERY_H__

#include <bootstage.h>
#include <types.h>
#include <utils.h>

enum recovery_errno {
	REC_ERR_SUCCESS,
	REC_ERR_UART_INIT,
	REC_ERR_UART_CONF,
	REC_ERR_RECEIVE_IMG_SZ,
	REC_ERR_ZERO_IMG_SZ,
	REC_ERR_LARGE_IMG_SZ,
	REC_ERR_RECEIVE_DATA,

	REC_ERRNO,
};

enum recovery_syndrome {
	REC_SYN_SKIP,

	REC_SYNDROME,
};

enum recovery_mode_type {
	BOOT_USB,
	BOOT_UART,
	BOOT_UNKNOWN,
};

enum recovery_status {
	REC_PASS,
	REC_FAIL,
	REC_NO_NEED,
};

bootstage_t recovery_boot(void);

#endif
