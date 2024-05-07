/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2024 ASPEED Technology Inc.
 */

#ifndef __OTP_INIT_H__
#define __OTP_INIT_H__

#include <rom_context.h>

/* otp scu init errno */
#define OTP_SCU_INIT_SUCCESS			0
#define OTP_SCU_INIT_ERR_GENERIC_FAILED		1
#define OTP_SCU_INIT_ERR_CFG_FAILED		2
#define OTP_SCU_INIT_ERR_STRAPEXT_FAILED	3
#define OTP_SCU_INIT_ERR_DBGCTRL_FAILED		4
#define OTP_SCU_INIT_ERR_IROT_UDS_FAILED	5

/* otp region init errno */
#define OTP_REGION_SUCCESS			0
#define OTP_REGION_PUF_SKIP			1
#define OTP_REGION_PUF_ALREADY_DONE		2
#define OTP_REGION_PUF_RNG_ERR			3
#define OTP_REGION_PUF_PROG_ERR			4
#define OTP_REGION_PUF_UDS_PROG_ERR		5
#define OTP_REGION_PUF_PROT_ERR			6
#define OTP_REGION_PUF_PROG_DONE		7

/* otp region syndrome */
#define OTP_REGION_USR_DONE			BIT(7)
#define OTP_REGION_SECURE_DONE			BIT(6)
#define OTP_REGION_CPTRA_DONE			BIT(5)
#define PUF_READ_ERR				0x1
#define PUF_PROG_RND_ERR			0x2
#define PUF_PROG_PROT_ERR			0x3
#define PUF_UID_ERR				0x4
#define PUF_UDS_SLI_ERR				0x5
#define PUF_UDS_OBF_ERR				0x6


bootstage_t otp_init_io(struct rom_context *rom_ctx);
bootstage_t otp_init_cpu(struct rom_context *rom_ctx);
bootstage_t otp_init_region(struct rom_context *rom_ctx);

#endif
