#include <drivers/caliptra.h>
#include <errno.h>
#include <io.h>
#include <platform.h>

uint32_t cptra_sha_status(void)
{
	return readl(CPTRA_SHA_STS);
}

int cptra_sha_lock(void)
{
	uint32_t reg, sts;

	sts = cptra_sha_status();
	if (sts & CPTRA_SHA_STS_SOC_LOCK)
		return 0;

	reg = readl(CPTRA_SHA_LOCK);

	return (reg) ? -EBUSY : 0;
}

int cptra_sha_unlock(void)
{
	uint32_t sts;

	sts = cptra_sha_status();
	if (!(sts & CPTRA_SHA_STS_SOC_LOCK))
		return -EPERM;

	writel(0x1, CPTRA_SHA_LOCK);

	return 0;
}

/* one-shot op*/
int cptra_sha_digest(uint8_t *digest_be, enum cptra_sha_mode mode, uint8_t *data, uint32_t dlen)
{
	uint32_t i, dgst_len;
	uint32_t reg, sts;
	uint32_t din_be;
	uint32_t *p32;

	if (!digest_be || !data || !dlen)
		return -EINVAL;

	switch (mode) {
	case CPTRA_SHA384_STREAM:
		dgst_len = 48;
		break;
	case CPTRA_SHA512_STREAM:
		dgst_len = 64;
		break;
	default:
		return -EINVAL;
	}

	sts = cptra_sha_status();
	if (!(sts & CPTRA_SHA_STS_SOC_LOCK))
		return -EPERM;

	/* zero clear SHA */
	writel(CPTRA_SHA_CTRL_ZEROIZE, CPTRA_SHA_CTRL);

	/* set SHA mode */
	reg = readl(CPTRA_SHA_MODE);
	reg &= ~(CPTRA_SHA_MODE_SEL);
	reg |= FIELD_PREP(CPTRA_SHA_MODE_SEL, mode);
	writel(reg, CPTRA_SHA_MODE);

	/* set data length */
	writel(dlen, CPTRA_SHA_DLEN);

	/* push data */
	din_be = 0;
	for (i = 0; i < dlen; ++i) {
		if (i && (i % sizeof(din_be) == 0)) {
			writel(din_be, CPTRA_SHA_DATAIN);
			din_be = 0;
		}

		din_be <<= 8;
		din_be |= data[i];
	}

	if (i % sizeof(din_be))
		din_be <<= (8 * (sizeof(din_be) - (i % sizeof(din_be))));

	writel(din_be, CPTRA_SHA_DATAIN);

	/* trigger SHA calculation */
	writel(0x1, CPTRA_SHA_EXEC);

	/* wait for completion */
	while (1) {
		sts = cptra_sha_status();
		if (sts & CPTRA_SHA_STS_VLD)
			break;
	}

	/* get the SHA digest in big-endian */
	p32 = (uint32_t *)digest_be;
	for (i = 0; i < dgst_len / sizeof(*p32); ++i) {
		*p32 = readl(CPTRA_SHA_DIGEST(i));
		p32++;
	}

	return 0;
}

/* accumulative ops */
int cptra_sha_init(enum cptra_sha_mode mode)
{
	uint32_t reg, sts;

	switch (mode) {
	case CPTRA_SHA384_STREAM:
	case CPTRA_SHA512_STREAM:
		break;
	default:
		return -EINVAL;
	}

	sts = cptra_sha_status();
	if (!(sts & CPTRA_SHA_STS_SOC_LOCK))
		return -EPERM;

	/* zero clear SHA */
	writel(CPTRA_SHA_CTRL_ZEROIZE, CPTRA_SHA_CTRL);

	/* zero length */
	writel(0x0, CPTRA_SHA_DLEN);

	/* set SHA mode */
	reg = readl(CPTRA_SHA_MODE);
	reg &= ~(CPTRA_SHA_MODE_SEL);
	reg |= FIELD_PREP(CPTRA_SHA_MODE_SEL, mode);
	writel(reg, CPTRA_SHA_MODE);

	return 0;
}

int cptra_sha_update(uint8_t *data, uint32_t dlen)
{
	uint32_t dlen_sum;
	uint32_t din_be;
	uint32_t sts, i;

	if (!data || !dlen)
		return -EINVAL;

	sts = cptra_sha_status();
	if (!(sts & CPTRA_SHA_STS_SOC_LOCK))
		return -EPERM;

	/* update length */
	dlen_sum = readl(CPTRA_SHA_DLEN) + dlen;
	writel(dlen_sum, CPTRA_SHA_DLEN);

	din_be = 0;
	for (i = 0; i < dlen; ++i) {
		if (i && (i % sizeof(din_be) == 0)) {
			writel(din_be, CPTRA_SHA_DATAIN);
			din_be = 0;
		}

		din_be <<= 8;
		din_be |= data[i];
	}

	if (i % sizeof(din_be))
		din_be <<= (8 * (sizeof(din_be) - (i % sizeof(din_be))));

	writel(din_be, CPTRA_SHA_DATAIN);

	return 0;
}

int cptra_sha_finish(uint8_t *digest_be)
{
	uint32_t dgst_len;
	uint32_t sts, i;
	uint32_t mode;
	uint32_t *p32;

	if (!digest_be)
		return -EINVAL;

	mode = readl(CPTRA_SHA_MODE);
	mode = FIELD_PREP(CPTRA_SHA_MODE_SEL, mode);
	switch (mode) {
	case CPTRA_SHA384_STREAM:
		dgst_len = 48;
		break;
	case CPTRA_SHA512_STREAM:
		dgst_len = 64;
		break;
	default:
		return -ENOTSUP;
	}

	sts = cptra_sha_status();
	if (!(sts & CPTRA_SHA_STS_SOC_LOCK))
		return -EPERM;

	/* trigger SHA calculation */
	writel(0x1, CPTRA_SHA_EXEC);

	/* wait for completion */
	while (1) {
		sts = cptra_sha_status();
		if (sts & CPTRA_SHA_STS_VLD)
			break;
	}

	/* get the SHA digest in big-endian */
	p32 = (uint32_t *)digest_be;
	for (i = 0; i < dgst_len / sizeof(*p32); ++i) {
		*p32 = readl(CPTRA_SHA_DIGEST(i));
		p32++;
	}

	return 0;
}
