#include <boot.h>
#include <bootdev.h>
#include <bootstage.h>
#include <caliptra.h>
#include <drivers/caliptra.h>
#include <drivers/rv_timer.h>
#include <drivers/scu.h>
#include <errno.h>
#include <fmc_verify.h>
#include <io.h>
#include <lib/delay.h>
#include <lib/rand.h>
#include <rng.h>

#include <lib/printf.h>

/* CPTRA SoC interface register configs */
#define CPTRA_PAUSER_BOOTMCU	0x21212121
#define CPTRA_WDT_TMOUT_H	0xffffffff
#define CPTRA_WDT_TMOUT_L	0xffffffff

#define CPTRA_TRNG_ALARM	(RVTMR_CLK_RATE / 10000)	/* 100us in RV timer count */

static inline int cptra_bypassed(void)
{
	/*
	 * Bypass caliptra if:
	 * - OTP strap dis_cptra is enabled
	 * - EFUSE dis_cptra is enabled
	 */
	return (readl(SCU1_HWSTRAP1) & SCU1_HWSTRAP1_DIS_CPTRA) ||
	       (readl(SCU1_EFUSE) & SCU1_EFUSE_DIS_CPTRA);
}

static int poll_for_fuse_req(uint32_t tmout_us)
{
	uint32_t val;

	return readl_poll_timeout(CPTRA_FLOW_STS, val,
				  (val & CPTRA_FLOW_STS_RDY_FOR_FUSES), 1, tmout_us);
}

static int poll_for_fuse_done(uint32_t tmout_us)
{
	uint32_t val;

	return readl_poll_timeout(CPTRA_FLOW_STS, val,
				  !(val & CPTRA_FLOW_STS_RDY_FOR_FUSES), 1, tmout_us);
}

static int poll_for_mbox_lock(uint32_t tmout_us)
{
	uint32_t val;

	return readl_poll_timeout(CPTRA_MBOX_STS, val,
				  (!cptra_mbox_lock()), 1, tmout_us);
}

static int trng_req_serveloop(void *arg)
{
	uint32_t ts = readl(CPTRA_TRNG_STS);
	int i;

	if ((ts & CPTRA_TRNG_STS_DATA_REQ) && is_rng_ready()) {
		for (i = 0; i < CPTRA_MAX_TRNG; ++i)
			writel(rand(), CPTRA_TRNG_DATA(i));
		writel(CPTRA_TRNG_STS_DATA_WR_DONE, CPTRA_TRNG_STS);
	}

	rvtmr_set_alarm_rel(CPTRA_TRNG_ALARM);

	return 0;
}

bootstage_t cptra_bootfsm_boot(struct rom_context *rom_ctx)
{
	bootstage_t sts = { CB_FSM_ERR_GENERIC, 0 };
	uint32_t mbox_pauser[CPTRA_MAX_MBOX_PAUSER];
	struct cptra_obf_key obf_key[1];
	struct cptra_fuse fuse[1];
	uint32_t ss, fs, reg;
	int i, rc;

	if (cptra_bypassed()) {
		sts.errno = CB_FSM_ERR_SUCC;
		sts.syndrome = 0x1;
		goto out;
	}

	/* de-assert pwrgood */
	reg = readl(SCU1_CPTRA_CTRL) & ~SCU1_CPTRA_CTRL_PWRGOOD;
	writel(reg, SCU1_CPTRA_CTRL);

	/* assert reset */
	writel(SCU1_RSTCTL2_CPTRA, SCU1_RSTCTL2);

	/* set UDS obfuscation key */
	rc = cptra_otp_obf_key(obf_key);
	if (rc) {
		sts.errno = CB_FSM_ERR_OTP_OBFKEY;
		sts.syndrome = rc;
		goto out;
	}

	for (i = 0; i < ARRAY_SIZE(obf_key); ++i)
		writel(obf_key->data[i], SCU1_CPTRA_OBF_KEY(i));

	/* set security state */
	rc = cptra_otp_sec_stat(&ss);
	if (rc) {
		sts.errno = CB_FSM_ERR_OTP_SECSTAT;
		sts.syndrome = rc;
		goto out;
	}

	reg = readl(SCU1_CPTRA_CTRL);
	reg &= ~SCU1_CPTRA_CTRL_SEC_STAT;
	reg |= FIELD_PREP(SCU1_CPTRA_CTRL_SEC_STAT, ss);
	writel(reg, SCU1_CPTRA_CTRL);

	/* assert pwrgood */
	reg = readl(SCU1_CPTRA_CTRL) | SCU1_CPTRA_CTRL_PWRGOOD;
	writel(reg, SCU1_CPTRA_CTRL);

	/* de-assert reset and delay */
	writel(SCU1_RSTCTL2_CLR_CPTRA, SCU1_RSTCTL2_CLR);
	udelay(1);

	/* set mbox pauser */
	mbox_pauser[0] = CPTRA_PAUSER_BOOTMCU;
	rc = cptra_set_mbox_pauser(mbox_pauser, 1);
	if (rc) {
		sts.errno = CB_FSM_ERR_SET_MBOX_PAUSER;
		sts.syndrome = rc;
		goto out;
	}

	/* set fuse pauser */
	rc = cptra_set_fuse_pauser(CPTRA_PAUSER_BOOTMCU);
	if (rc) {
		sts.errno = CB_FSM_ERR_SET_FUSE_PAUSER;
		sts.syndrome = rc;
		goto out;
	}

	/* set trng pauser */
	rc = cptra_set_trng_pauser(CPTRA_PAUSER_BOOTMCU);
	if (rc) {
		sts.errno = CB_FSM_ERR_SET_TRNG_PAUSER;
		sts.syndrome = rc;
		goto out;
	}

	/* setup timer to server trng requests */
	if (rom_ctx->interrupt_mode) {
		rvtmr_init(rom_ctx->interrupt_mode);
		rvtmr_set_alarm_callback(trng_req_serveloop, NULL);
		rvtmr_set_alarm_rel(CPTRA_TRNG_ALARM);
	}

	/* set watchdog timeout */
	rc = cptra_set_wdtcfg(CPTRA_WDT_TMOUT_H, CPTRA_WDT_TMOUT_L);
	if (rc) {
		sts.errno = CB_FSM_ERR_SET_WDTCFG;
		sts.syndrome = rc;
		goto out;
	}

	/* enable CSR generation if manufacturing */
	if (ss == CPTRA_SS_MANUFACTURING || ss == CPTRA_SS_DBG_MANUFACTURING)
		cptra_set_csr_gen_request();

	/* set fuse */
	rc = poll_for_fuse_req(rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_FSM_ERR_FUSE_REQ;
		sts.syndrome = rc;
		goto out;
	}

	rc = cptra_otp_fuse(fuse);
	if (rc) {
		sts.errno = CB_FSM_ERR_OTP_FUSE;
		sts.syndrome = rc;
		goto out;
	}

	rc = cptra_set_fuse_data(fuse);
	if (rc) {
		sts.errno = CB_FSM_ERR_FUSE_SET;
		sts.syndrome = rc;
		goto out;
	}

	rc = poll_for_fuse_done(rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_FSM_ERR_FUSE_DONE;
		sts.syndrome = rc;
		goto out;
	}

	/* check BOOT_DONE */
	fs = FIELD_GET(CPTRA_FLOW_STS_FSM_PS, readl(CPTRA_FLOW_STS));
	if (fs != CPTRA_FSM_BOOT_DONE) {
		sts.errno = CB_FSM_ERR_NO_BOOT_DONE;
		sts.syndrome = fs;
		goto out;
	}

	sts.errno = CB_FSM_ERR_SUCC;
	sts.syndrome = 0;

	rom_ctx->cptra_boot_fsm = 1;

out:
	if (sts.errno != CB_FSM_ERR_SUCC) {
		if (rom_ctx->interrupt_mode)
			rvtmr_clr_alarm();

		if (is_secboot())
			sts.panic = BOOTSTAGE_JMP_PANIC;
	}

	return sts;
}

bootstage_t cptra_rom_boot(struct rom_context *rom_ctx)
{
	bootstage_t sts = { CB_ROM_ERR_GENERIC, 0 };
	uint32_t csr_cmd, csr_len, csr_get = 0;
	uint64_t start_ticks, tmout_ticks;
	uint32_t fs, ms, ts;
	uint32_t data;
	int i, rc;

	if (cptra_bypassed()) {
		sts.errno = CB_ROM_ERR_SUCC;
		sts.syndrome = 0x1;
		goto out;
	}

	if (!rom_ctx->cptra_boot_fsm) {
		sts.errno = CB_ROM_ERR_INVL_STS;
		sts.syndrome = 0x0;
		goto out;
	}

	tmout_ticks = (rom_ctx->interrupt_mode) ? (uint64_t)(-1) : usec_to_tick(rom_ctx->cptra_exec_tmout);
	start_ticks = get_ticks();

	while (1) {
		fs = readl(CPTRA_FLOW_STS);
		ts = readl(CPTRA_TRNG_STS);

		/*
		 * check trng status to feed random data.
		 * skip this if interrupt-based service is enabled
		 */
		if (!rom_ctx->interrupt_mode &&
		    (ts & CPTRA_TRNG_STS_DATA_REQ) &&
		    is_rng_ready()) {
			for (i = 0; i < CPTRA_MAX_TRNG; ++i)
				writel(rand(), CPTRA_TRNG_DATA(i));
			writel(CPTRA_TRNG_STS_DATA_WR_DONE, CPTRA_TRNG_STS);

			continue;
		}

		/*
		 * check flow status for
		 *   1. CSR generation
		 *   2. Ready for FW (break if interrupt-based service is enabled)
		 */
		if ((fs & CPTRA_FLOW_STS_IDEVID_CSR_RDY) && csr_get == 0) {
			/* the last 2KB SRAM is reserved for CSR use during manufacturing */
			csr_len = 0x800;

			rc = cptra_mbox_recv(&csr_cmd, (uint8_t *)(SRAM_MEM + SRAM_SZ), &csr_len);
			if (rc) {
				sts.errno = CB_ROM_ERR_CSR_READ;
				sts.syndrome = rc;
				goto out;
			}

			/* notify CSR is consumed */
			cptra_set_csr_gen_complete();

			/*
			 * it takes a little while for Caliptra to pull down the
			 * CSR ready flag, namely a local flag for CSR acquistion
			 * is needed to avoid this pulling loop to re-do CSR get
			 */
			csr_get = 1;

			/* renew start ticks as CSR read could take long time */
			start_ticks = get_ticks();

			continue;
		}

		if ((fs & CPTRA_FLOW_STS_RDY_FOR_FW) && rom_ctx->interrupt_mode)
			break;

		if (get_ticks() - start_ticks > tmout_ticks)
			break;
	}

	fs = readl(CPTRA_FLOW_STS);
	if (!(fs & CPTRA_FLOW_STS_RDY_FOR_FW)) {
		sts.errno = CB_ROM_ERR_NO_RDY_FOR_FW;
		sts.syndrome = -ETIMEDOUT;
		goto out;
	}

	/*
	 * push caliptra FW
	 *   - sanity check
	 *   - get mbox lock
	 *   - set mbox command
	 *   - set mbox data length
	 *   - trigger mbox
	 *   - wait for mbox response
	 *   - check response and unlock mbox
	 */
	if (!rom_ctx->cptra_lda || !rom_ctx->cptra_lds ||
	    rom_ctx->cptra_lds > CPTRA_MBOX_SZ) {
		sts.errno = CB_ROM_ERR_FWLD_INVAL;
		sts.syndrome = 0;
		goto out;
	}

	rc = poll_for_mbox_lock(rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_ROM_ERR_FWLD_MBOX_LOCK;
		sts.syndrome = rc;
		goto out;
	}

	writel(CPTRA_MBCMD_CALIPTRA_FW_LOAD, CPTRA_MBOX_CMD);
	writel(rom_ctx->cptra_lds, CPTRA_MBOX_DLEN);

	for (i = 0; i < rom_ctx->cptra_lds; i += sizeof(data)) {
		if ((rom_ctx->cptra_lds - i) < sizeof(data))
			break;

		data = readl(rom_ctx->cptra_lda + i);
		writel(data, CPTRA_MBOX_DATAIN);
	}

	if (i != rom_ctx->cptra_lds) {
		for (data = 0; i < rom_ctx->cptra_lds; ++i)
			data <<= readb(rom_ctx->cptra_lda + i);

		writel(data, CPTRA_MBOX_DATAIN);
	}

	writel(0x1, CPTRA_MBOX_EXEC);

	rc = readl_poll_timeout(CPTRA_MBOX_STS, ms,
				FIELD_GET(CPTRA_MBOX_STS_PS, ms) != CPTRA_MBSTS_CMD_BUSY,
				1, rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_ROM_ERR_FWLD_MBOX_EXEC;
		sts.syndrome = -ETIMEDOUT;
		goto out;
	}

	ms = FIELD_GET(CPTRA_MBOX_STS_PS, ms);
	if (ms != CPTRA_MBSTS_CMD_COMPLETE) {
		sts.errno = CB_ROM_ERR_FWLD_MBOX_EXEC;
		sts.syndrome = ms;
		goto out;
	}

	rc = cptra_mbox_unlock();
	if (rc) {
		sts.errno = CB_ROM_ERR_FWLD_MBOX_UNLK;
		sts.syndrome = rc;
		goto out;
	}

	sts.errno = CB_ROM_ERR_SUCC;
	sts.syndrome = 0;

	rom_ctx->cptra_boot_rom = 1;

out:
	if (sts.errno != CB_ROM_ERR_SUCC) {
		if (rom_ctx->interrupt_mode)
			rvtmr_clr_alarm();

		if (is_secboot())
			sts.panic = BOOTSTAGE_JMP_PANIC;
	}

	return sts;
}

bootstage_t cptra_fw_boot(struct rom_context *rom_ctx)
{
	bootstage_t sts = { CB_FW_ERR_GENERIC, 0 };
	uint32_t cmd = CPTRA_MBCMD_FW_INFO;
	uint64_t start_ticks, tmout_ticks;
	struct cptra_fw_info fw_info[1];
	uint32_t *p32, dlen;
	uint32_t fs, ms, ts;
	uint32_t csum = 0;
	int i, rc;

	if (cptra_bypassed()) {
		sts.errno = CB_FW_ERR_SUCC;
		sts.syndrome = 0x1;
		goto out;
	}

	if (!rom_ctx->cptra_boot_rom) {
		sts.errno = CB_FW_ERR_INVL_STS;
		sts.syndrome = 0x0;
		goto out;
	}

	tmout_ticks = (rom_ctx->interrupt_mode) ? (uint64_t)(-1) : usec_to_tick(rom_ctx->cptra_exec_tmout);
	start_ticks = get_ticks();

	/* service loop until caliptra gets RT ready */
	while (1) {
		fs = readl(CPTRA_FLOW_STS);
		ts = readl(CPTRA_TRNG_STS);

		/*
		 * check trng status to feed random data.
		 * skip this if interrupt-based service is enabled
		 */
		if (!rom_ctx->interrupt_mode &&
		    (ts & CPTRA_TRNG_STS_DATA_REQ) &&
		    is_rng_ready()) {
			for (i = 0; i < CPTRA_MAX_TRNG; ++i)
				writel(rand(), CPTRA_TRNG_DATA(i));
			writel(CPTRA_TRNG_STS_DATA_WR_DONE, CPTRA_TRNG_STS);

			continue;
		}

		if (fs & CPTRA_FLOW_STS_RDY_FOR_RT)
			break;

		if (get_ticks() - start_ticks > tmout_ticks)
			break;
	}

	fs = readl(CPTRA_FLOW_STS);
	if (!(fs & CPTRA_FLOW_STS_RDY_FOR_RT)) {
		sts.errno = CB_FW_ERR_NO_RDY_FOR_RT;
		sts.syndrome = -ETIMEDOUT;
		goto out;
	}

	/* get cptra fw info */
	csum = cptra_mbox_csum(csum, (uint8_t *)&cmd, sizeof(cmd));

	rc = poll_for_mbox_lock(rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_FW_ERR_FWIF_MBOX_LOCK;
		sts.syndrome = rc;
		goto out;
	}

	writel(cmd, CPTRA_MBOX_CMD);
	writel(sizeof(csum), CPTRA_MBOX_DLEN);
	writel(csum, CPTRA_MBOX_DATAIN);

	writel(0x1, CPTRA_MBOX_EXEC);

	rc = readl_poll_timeout(CPTRA_MBOX_STS, ms,
				FIELD_GET(CPTRA_MBOX_STS_PS, ms) != CPTRA_MBSTS_CMD_BUSY,
				1, rom_ctx->cptra_exec_tmout);
	if (rc) {
		sts.errno = CB_FW_ERR_FWIF_MBOX_EXEC;
		sts.syndrome = -ETIMEDOUT;
		goto out;
	}

	ms = FIELD_GET(CPTRA_MBOX_STS_PS, ms);
	if (ms == CPTRA_MBSTS_DATA_READY) {
		dlen = readl(CPTRA_MBOX_DLEN);
		p32 = (uint32_t *)fw_info;

		while (dlen) {
			*(p32++) = readl(CPTRA_MBOX_DATAOUT);
			dlen -= sizeof(*p32);
		}
	} else {
		sts.errno = CB_FW_ERR_FWIF_MBOX_EXEC;
		sts.syndrome = ms;
		goto out;
	}

	rc = cptra_mbox_unlock();
	if (rc) {
		sts.errno = CB_FW_ERR_FWIF_MBOX_UNLK;
		sts.syndrome = rc;
		goto out;
	}

	otp_update_cptra_fmc_svn(fw_info->fmc_manifest_svn);
	otp_update_cptra_rt_svn(fw_info->runtime_svn);

	sts.errno = CB_FW_ERR_SUCC;
	sts.syndrome = 0;

	rom_ctx->cptra_boot_fw = 1;

out:
	if (rom_ctx->interrupt_mode)
		rvtmr_clr_alarm();

	if (is_secboot() && sts.errno != CB_FW_ERR_SUCC)
		sts.panic = BOOTSTAGE_JMP_PANIC;

	return sts;
}
