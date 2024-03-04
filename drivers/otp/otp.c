// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <bootstage.h>
#include <debug.h>
#include <drivers/otp.h>
#include <drivers/sli.h>
#include <drivers/scu.h>
#include <errno.h>
#include <io.h>
#include <platform.h>
#include <utils.h>
#include <otp_mem.h>

#define OTP_PASSWD		0x349fe38a
#define OTP_CMD_READ		0x23b1e361

enum otp_master_id {
	OTP_M0 = 0,
	OTP_M1,
	OTP_M2,
	OTP_M3,
	OTP_M4,
	OTP_M5,
	OTP_MID_MAX,
};

/* register offsets */
#define OTP_CMD_OFFSET		0x20
#define OTP_KEY			(OTP_REG + 0x0)
#define OTP_CMD(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x4)
#define OTP_WDATA_0(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x8)
#define OTP_WDATA_1(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0xc)
#define OTP_WDATA_2(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x10)
#define OTP_WDATA_3(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x14)
#define OTP_STS(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x18)
#define   OTP_STS_ERR		GENMASK(7, 4)
#define   OTP_STS_ERR_MASTER	0x4
#define   OTP_STS_ERR_REGION	0x3
#define   OTP_STS_ERR_CMP	0x2
#define   OTP_STS_ERR_FAIL	0x1
#define   OTP_STS_ERR_PASS	0x0
#define   OTP_STS_BUSY		BIT(0)
#define OTP_ADDR(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x1c)
#define OTP_RDATA(x)		(OTP_REG + (x) * OTP_CMD_OFFSET + 0x20)
#define OTP_DBG00		(OTP_REG + 0x0c4)
#define OTP_MASTER_PID		(OTP_REG + 0x0d0)
#define OTP_ECC_EN		(OTP_REG + 0x0d4)
#define   OTP_ECC_EN_CFG_ECCBRP	BIT(2)
#define   OTP_ECC_EN_ECCBRP	BIT(0)

#define OTP_TIMEOUT_US		1000

#define SCU0_HW_STRAP_BASE	(SCU0_REG + 0x10)
#define SCU1_HW_STRAP_BASE	(SCU1_REG + 0x10)

static void otp_unlock(void)
{
	writel(OTP_PASSWD, OTP_KEY);
}

static void otp_lock(void)
{
	writel(0x1, OTP_KEY);
}

static int wait_complete(int mid)
{
	uint32_t val;
	int ret;

	ret = readl_poll_timeout(OTP_STS(mid), val, (val == 0x0), 1000,
				 OTP_TIMEOUT_US);

	return ret;
}

int otp_read_data(uint32_t offset, uint16_t *data)
{
	int cfg_ecc_en = 0;
	int mem_ecc_en = 0;
	int mid = OTP_M0;
	uint32_t val;
	int ret;

	otp_unlock();

	/* Check cfg_ecc_en */
	writel(0, OTP_ECC_EN);
	writel(OTPSTRAP14, OTP_ADDR(mid));
	writel(OTP_CMD_READ, OTP_CMD(mid));
	ret = wait_complete(mid);
	if (ret)
		return OTP_ERR_READ;

	val = readl(OTP_RDATA(mid));
	if (val & OTPSTRAP14_OTP_CFG_ECCBRP_EN)
		cfg_ecc_en = 0x1;

	/* Check mem_ecc_en */
	if (cfg_ecc_en)
		writel(OTP_ECC_EN_CFG_ECCBRP, OTP_ECC_EN);

	writel(OTPCFG0, OTP_ADDR(mid));
	writel(OTP_CMD_READ, OTP_CMD(mid));
	ret = wait_complete(mid);
	if (ret)
		return OTP_ERR_READ;

	val = readl(OTP_RDATA(mid));
	if (val & OTPCFG0_OTP_MEM_ECC_ENABLE)
		mem_ecc_en = 0x1;

	/* Set cfg/non-cfg ecc */
	if ((offset >= OTP_MEM_CFG_BASE) &&
	    (offset < (OTP_MEM_CFG_BASE + OTP_MEM_CFG_SIZE)) &&
	    cfg_ecc_en)
		writel(OTP_ECC_EN_CFG_ECCBRP, OTP_ECC_EN);
	else if (mem_ecc_en)
		writel(OTP_ECC_EN_ECCBRP, OTP_ECC_EN);
	else
		writel(0, OTP_ECC_EN);

	writel(offset, OTP_ADDR(mid));
	writel(OTP_CMD_READ, OTP_CMD(mid));
	ret = wait_complete(mid);
	if (ret)
		return OTP_ERR_READ;

	data[0] = readl(OTP_RDATA(mid));

	otp_lock();

	return OTP_ERR_SUCCESS;
}
