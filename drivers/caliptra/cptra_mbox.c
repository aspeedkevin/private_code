#include <drivers/caliptra.h>
#include <errno.h>
#include <io.h>
#include <platform.h>
#include <utils.h>

uint32_t cptra_mbox_csum(uint32_t csum, uint8_t *data, uint32_t dlen)
{
	uint32_t i;

	if (!data)
		return csum;

	for (i = 0; i < dlen; ++i)
		csum -= data[i];

	return csum;
}

uint32_t cptra_mbox_status(void)
{
	return readl(CPTRA_MBOX_STS);
}

int cptra_mbox_lock(void)
{
	uint32_t reg, sts;

	sts = cptra_mbox_status();
	if (sts & CPTRA_MBOX_STS_SOC_LOCK)
		return 0;

	reg = readl(CPTRA_MBOX_LOCK);

	return (reg) ? -EBUSY : 0;
}

int cptra_mbox_send(uint32_t cmd, uint8_t *data, uint32_t dlen)
{
	uint32_t sts;
	int i;

	if (!data || dlen >= CPTRA_MBOX_SZ || (dlen & 0x3))
		return -EINVAL;

	sts = cptra_mbox_status();

	if (!(sts & CPTRA_MBOX_STS_SOC_LOCK))
		return -EPERM;

	if (FIELD_GET(CPTRA_MBOX_STS_FSM_PS, sts) != CPTRA_MBFSM_RDY_FOR_CMD)
		return -EACCES;

	switch (cmd) {
	case CPTRA_MBCMD_CALIPTRA_FW_LOAD:
	case CPTRA_MBCMD_ECDSA384_SIGNATURE_VERIFY:
		break;
	default:
		return -ENOTSUP;
	}

	writel(cmd, CPTRA_MBOX_CMD);
	writel(dlen, CPTRA_MBOX_DLEN);
	for (i = 0; i < dlen; i += sizeof(uint32_t))
		writel(*(uint32_t *)(data + i), CPTRA_MBOX_DATAIN);

	writel(0x1, CPTRA_MBOX_EXEC);

	return 0;
}

int cptra_mbox_recv(uint32_t *cmd, uint8_t *data, uint32_t *dlen)
{
	uint32_t sts, mb_sts, mb_fsm;
	uint32_t idlen, odlen;
	int i;

	if (!cmd || !data || !dlen || (*dlen & 0x3))
		return -EINVAL;

	sts = cptra_mbox_status();
	mb_fsm = FIELD_GET(CPTRA_MBOX_STS_FSM_PS, sts);
	mb_sts = FIELD_GET(CPTRA_MBOX_STS_PS, sts);

	if (mb_fsm != CPTRA_MBFSM_EXEC_SOC)
		return -EACCES;

	idlen = *dlen;
	odlen = 0;

	switch (mb_sts) {
	case CPTRA_MBSTS_CMD_BUSY:
	case CPTRA_MBSTS_DATA_READY:
		odlen = readl(CPTRA_MBOX_DLEN);
		if (idlen < odlen)
			return -ENOMEM;

		for (i = 0; i < odlen; i += sizeof(uint32_t))
			*(uint32_t *)(data + i) = readl(CPTRA_MBOX_DATAOUT);

		__attribute__ ((fallthrough));
	case CPTRA_MBSTS_CMD_COMPLETE:
	case CPTRA_MBSTS_CMD_FAILURE:
		*cmd = readl(CPTRA_MBOX_CMD);
		*dlen = odlen;
		break;
	default:
		return -ENOTSUP;
	}

	return 0;
}

int cptra_mbox_unlock(void)
{
	uint32_t sts;
	uint32_t mb_sts;

	sts = readl(CPTRA_MBOX_STS);
	if (!(sts & CPTRA_MBOX_STS_SOC_LOCK))
		return -EPERM;

	mb_sts = FIELD_GET(CPTRA_MBOX_STS_PS, sts);
	if (mb_sts == CPTRA_MBSTS_CMD_BUSY)
		return -EACCES;

	writel(0x0, CPTRA_MBOX_EXEC);

	return 0;
}
