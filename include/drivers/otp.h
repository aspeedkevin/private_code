#ifndef __OTP_H__
#define __OTP_H__

#include <types.h>

#define OTP_PASSWD			0x349fe38a
#define OTP_CMD_READ			0x23b1e361
#define OTP_CMD_PROG			0x23b1e364

/* OTP register definitions */
#define OTP_CMD_OFFSET			0x20
#define OTP_KEY				(OTP_REG + 0x0)
#define OTP_CMD(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x4)
#define OTP_WDATA_0(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x8)
#define OTP_WDATA_1(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0xc)
#define OTP_WDATA_2(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x10)
#define OTP_WDATA_3(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x14)
#define OTP_STS(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x18)
#define   OTP_STS_ERR			GENMASK(7, 4)
#define   OTP_STS_ERR_MASTER		0x4
#define   OTP_STS_ERR_REGION		0x3
#define   OTP_STS_ERR_CMP		0x2
#define   OTP_STS_ERR_FAIL		0x1
#define   OTP_STS_ERR_PASS		0x0
#define   OTP_STS_BUSY			BIT(0)

#define OTP_ADDR(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x1c)
#define OTP_RDATA(x)			(OTP_REG + (x) * OTP_CMD_OFFSET + 0x20)
#define OTP_ECC_EN			(OTP_REG + 0x0D4)
#define OTP_REGION_SECURE0		(OTP_REG + 0x120)
#define OTP_REGION_SECURE0_RANGE	(OTP_REG + 0x124)
#define OTP_REGION_SECURE1_RANGE	(OTP_REG + 0x12c)
#define OTP_REGION_SECURE2_RANGE	(OTP_REG + 0x134)
#define OTP_REGION_SECURE3_RANGE	(OTP_REG + 0x13c)
#define OTP_REGION_USR0			(OTP_REG + 0x140)
#define OTP_REGION_USR0_RANGE		(OTP_REG + 0x144)
#define OTP_REGION_USR1_RANGE		(OTP_REG + 0x14c)
#define OTP_REGION_USR2_RANGE		(OTP_REG + 0x154)
#define OTP_REGION_USR3_RANGE		(OTP_REG + 0x15c)
#define OTP_REGION_CALIPTRA_0		(OTP_REG + 0x160)
#define OTP_REGION_CALIPTRA_0_RANGE	(OTP_REG + 0x164)
#define OTP_REGION_CALIPTRA_1_RANGE	(OTP_REG + 0x16c)
#define OTP_REGION_CALIPTRA_2_RANGE	(OTP_REG + 0x174)
#define OTP_REGION_CALIPTRA_3_RANGE	(OTP_REG + 0x17c)
#define   OTP_REGION_LOCK		BIT(31)
#define   OTP_REGION_W_EN		GENMASK(15, 8)
#define   OTP_REGION_R_EN		GENMASK(7, 0)
#define OTP_PUF				(OTP_REG + 0x1a0)
#define   OTP_HW_PUF_RLOCK		BIT(4)
#define OTP_SOC_ECCKEY			(OTP_REG + 0x1c0)
#define   OTP_KEY_MASK			GENMASK(15, 0)
#define   OTP_KEY_WLOCK			BIT(31)
#define OTP_SEC_BOOT_EN_STS		(OTP_REG + 0x1c4)
#define   OTP_SEC_BOOT_EN		BIT(0)
#define   OTP_SEC_BOOT_WLOCK		BIT(31)
#define OTP_SOC_LMSKEY			(OTP_REG + 0x1c8)
#define OTP_CPTRA_MANU_KEY		(OTP_REG + 0x1cc)
#define OTP_CPTRA_OWN_KEY		(OTP_REG + 0x1d0)
#define OTP_SOC_SVN_LSB			(OTP_REG + 0x1d4)
#define OTP_SOC_SVN_MSB			(OTP_REG + 0x1d8)
#define OTP_CPTRA_FMC_SVN		(OTP_REG + 0x1dc)
#define OTP_CPTRA_RT_SVN0		(OTP_REG + 0x1e0)
#define OTP_CPTRA_RT_SVN1		(OTP_REG + 0x1e4)
#define OTP_CPTRA_RT_SVN2		(OTP_REG + 0x1e8)
#define OTP_CPTRA_RT_SVN3		(OTP_REG + 0x1ec)
#define OTP_SVN_CTRL			(OTP_REG + 0x1f0)
#define   OTP_FMC_SVN_WLOCK		BIT(0)
#define   OTP_CPTRA_FMC_SVN_WLOCK	BIT(1)
#define   OTP_CPTRA_RT_SVN_WLOCK	BIT(2)

#define OTP_TIMEOUT_US			10000

enum otp_master_id {
	OTP_M0 = 0,
	OTP_M1,
	OTP_M2,
	OTP_M3,
	OTP_M4,
	OTP_M5,
	OTP_MID_MAX,
};

enum otp_errno {
	OTP_SUCCESS = 0,
	OTP_ERR_READ = 1,
	OTP_ERR_PROG = 2,
};

void otp_unlock(void);
void otp_lock(void);
int otp_readw(uint32_t addr, uint16_t *data);
int otp_readl(uint32_t addr, uint32_t *data);
int otp_write(uint16_t data, uint32_t addr);
int otp_write_ecc(uint16_t data, uint32_t addr);

#endif /* __OTP_H__ */
