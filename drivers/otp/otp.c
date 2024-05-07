#include <bootstage.h>
#include <debug.h>
#include <drivers/otp.h>
#include <io.h>
#include <otp_mem.h>
#include <platform.h>
#include <utils.h>

void otp_unlock(void)
{
	writel(OTP_PASSWD, OTP_KEY);
}

void otp_lock(void)
{
	writel(0x1, OTP_KEY);
}

static int wait_complete(int mid)
{
	uint32_t val;
	int ret;

	ret = readl_poll_timeout(OTP_STS(mid), val, (val == 0x0), 1,
				 OTP_TIMEOUT_US);

	return ret;
}

static int otp_read_data(uint32_t offset, uint16_t *data)
{
	int mid = OTP_M0;
	int ret;

	otp_unlock();

	/* Using non-ecc mode by default */
	writel(0, OTP_ECC_EN);
	writel(offset, OTP_ADDR(mid));
	writel(OTP_CMD_READ, OTP_CMD(mid));
	ret = wait_complete(mid);
	if (ret)
		return OTP_ERR_READ;

	data[0] = readl(OTP_RDATA(mid));

	otp_lock();

	return OTP_SUCCESS;
}

/* Read OTP 32 bits data */
int otp_readl(uint32_t addr, uint32_t *data)
{
	uint16_t data0, data1;
	int ret;

	ret = otp_read_data(addr, &data0);
	ret += otp_read_data(addr + 1, &data1);
	if (ret)
		*data = 0;
	else
		*data = data1 << 16 | data0;

	return ret;
}

/* Read OTP 16 bits data */
int otp_readw(uint32_t addr, uint16_t *data)
{
	int ret;

	ret = otp_read_data(addr, data);
	if (ret)
		*data = 0;

	return ret;
}

static int otp_prog_data(uint32_t offset, uint16_t data, int ecc_en)
{
	int mid = OTP_M0;
	int ret;

	otp_unlock();

	/* Using non-ecc mode by default */
	writel(ecc_en, OTP_ECC_EN);
	writel(offset, OTP_ADDR(mid));
	writel(data, OTP_WDATA_0(mid));
	writel(OTP_CMD_PROG, OTP_CMD(mid));
	ret = wait_complete(mid);
	if (ret)
		return OTP_ERR_PROG;

	otp_lock();

	return OTP_SUCCESS;
}

int otp_write_ecc(uint16_t data, uint32_t addr)
{
	return otp_prog_data(addr, data, 1);
}

int otp_write(uint16_t data, uint32_t addr)
{
	return otp_prog_data(addr, data, 0);
}
