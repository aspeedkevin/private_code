#include <drivers/mmc.h>
#include <drivers/otp.h>
#include <drivers/scu.h>
#include <drivers/abr.h>
#include <io.h>
#include <lib/delay.h>
#include <lib/printf.h>
#include <lib/string.h>
#include <otp_mem.h>
#include <platform.h>
#include <utils.h>

#define MMC_BLOCK_LENGTH			(0x200)
#define MMC_BOOT_DMA_TMO			(1000 * 1000) // max 1 second

#define EB_DMA_ADDR_REG				(EMMC_BOOT_REG + 0x0)
#define EB_DMA_LEN_REG				(EMMC_BOOT_REG + 0x4)
#define EB_INTR_REG				(EMMC_BOOT_REG + 0x8)
#define EB_CONTROL_REG				(EMMC_BOOT_REG + 0xc)

#define SCU_RESET2_CONTROL_REG			(SCU0_REG + 0x200)
#define SCU_RESET2_CLR_REG			(SCU0_REG + 0x204)
#define SCU_RESET2_EMMC_BIT			BIT(17)
#define SCU_STOP_SET_REG			(SCU0_REG + 0x240)
#define SCU_STOP_CLR_REG			(SCU0_REG + 0x244)
#define SCU_STOP_EMMC_BIT			BIT(27)

#define EMMC_SDMA_ADDR_REG			(EMMC_REG + 0x00)
#define EMMC_BLKCNT_SZ_REG			(EMMC_REG + 0x04)
#define EMMC_ARGUMENT_REG			(EMMC_REG + 0x08)
#define EMMC_COMMAND_REG			(EMMC_REG + 0x0c)
#define EMMC_RESPONSE_REG			(EMMC_REG + 0x10)
#define EMMC_PRESENT_REG			(EMMC_REG + 0x24)
#define EMMC_HOST_CONTROL_0_REG			(EMMC_REG + 0x28)
#define EMMC_HOST_CONTROL_1_REG			(EMMC_REG + 0x2c)
#define EMMC_INT_STATUS_REG			(EMMC_REG + 0x30)
#define EMMC_INT_STATUS_EN_REG			(EMMC_REG + 0x34)
#define EMMC_INT_SIGNAL_EN_REG			(EMMC_REG + 0x38)

#define SDHCI_DATA_0_LVL_MASK			0x00100000

#define EMMC_INT_CMD_DONE			(BIT(0))
#define EMMC_INT_DATA_DONE			(BIT(1))

#define MMC_CMD_TIMEOUT				(300000) // 3ms
#define MMC_DATA_TIMEOUT			(3000000) // 30ms

#define SCU_PINCTRL_REG1			(SCU0_REG + 0x400)
#define GPIOQ7_BASE				(GPIO1_REG + 0x39c)
#define EMMC_HW_RST_PIN				GPIOQ7_BASE

#define EMMC_INIT_FREQUENCY			(0xefa07)

#define SDHCI_CMD_MAX_TIMEOUT			320000
#define SDHCI_CMD_DEFAULT_TIMEOUT		1000000
#define SDHCI_READ_STATUS_TIMEOUT		1000000

#define MMC_TRSTW_DELAY				(5)	// spec defined Min 1us.
#define MMC_TRSCA_DELAY				(300)	// spec defined Min 200us.

static int mmc_boot_read(uint64_t dma_addr, uint32_t dma_len)
{
	uint32_t val, upper, lower, length;
	int ret = 0;

	lower = dma_addr & 0xffffffff;
	upper = dma_addr >> 32;
	length = (upper << MMC_BOOT_DMA_UPPER_ADDR_OFFSET) | dma_len;

	writel(lower, EB_DMA_ADDR_REG);
	writel(length, EB_DMA_LEN_REG);

	val = MMC_BOOT_ENABLE | MMC_BOOT_MODE | MMC_BOOT_DMA_START;
	writel(val, EB_CONTROL_REG);

	ret = readl_poll_timeout(EB_INTR_REG, val,
				 (val & (MMC_BOOT_ERROR | MMC_BOOT_DMA_DONE)), 5, MMC_BOOT_DMA_TMO);
	if (ret)
		return ret;

	writel(MMC_BOOT_ERROR | MMC_BOOT_DMA_DONE, EB_INTR_REG);

	if (val & MMC_BOOT_ERROR)
		return MMC_BOOT_ERROR;

	return ret;
}


static void mmc_bring_to_default(void)
{
	/* quit emmc boot mode */
	writel(0, EB_CONTROL_REG);
	writel(0, EB_DMA_ADDR_REG);
	writel(0, EB_DMA_LEN_REG);
	writel(0xffff, EB_INTR_REG);

	/* assert emmc top reset as default */
	writel(SCU_RESET2_EMMC_BIT, SCU_RESET2_CONTROL_REG);
	udelay(5);

	/* scu stop emmc */
	writel(SCU_STOP_EMMC_BIT, SCU_STOP_SET_REG);

	/* set pinmux to default gpio mode in scu */
	writel(0, SCU_PINCTRL_REG1);
}

struct mmc {
	struct bootdev *bd;

	int sw_rst_en;
	int switch_part;

	struct mmc_regs *regs;

	int id;
	uint32_t card_caps;
	uint32_t host_caps;
	uint32_t dsr;
	uint32_t dsr_imp;

	uint32_t version;
	int bus_width;
	uint32_t ocr;
	uint32_t rca;
	uint32_t cid[4];
	uint32_t csd[4];
	uint32_t scr[2];

	uint32_t high_capacity;
	uint32_t read_bl_len;
	uint32_t write_bl_len;

	char op_cond_pending;

	int dma_mode;

	uint32_t flags;
#define SDHCI_USE_SDMA			BIT(0)	/* Host is SDMA capable */
#define SDHCI_USE_ADMA			BIT(1)	/* Host is ADMA capable */
#define SDHCI_REQ_USE_DMA		BIT(2)	/* Use DMA for this req. */
#define SDHCI_DEVICE_DEAD		BIT(3)	/* Device unresponsive */
#define SDHCI_SDR50_NEEDS_TUNING	BIT(4)	/* SDR50 needs tuning */
#define SDHCI_AUTO_CMD12		BIT(6)	/* Auto CMD12 support */
#define SDHCI_AUTO_CMD23		BIT(7)	/* Auto CMD23 support */
#define SDHCI_PV_ENABLED		BIT(8)	/* Preset value enabled */
#define SDHCI_USE_64_BIT_DMA		BIT(12)	/* Use 64-bit DMA */
#define SDHCI_HS400_TUNING		BIT(13)	/* Tuning for HS400 */
#define SDHCI_SIGNALING_330		BIT(14)	/* Host is capable of 3.3V signaling */
#define SDHCI_SIGNALING_180		BIT(15)	/* Host is capable of 1.8V signaling */
#define SDHCI_SIGNALING_120		BIT(16) /* Host is capable of 1.2V signaling */

	int v4_mode;
	int dma64;

	uint32_t desc_sz;

	u8 ext_csd[MMC_MAX_BLOCK_LEN];
	u32 cardtype;

	enum bus_mode selected_mode;
	uint32_t tran_speed;
	uint32_t legacy_speed;
	int ddr_mode;

	uint32_t intsts;
	uint32_t intmask;
	struct mmc_cmd	*cmd;
	struct mmc_data *data;

	uint32_t ier;

	int clk_disable;

	uint32_t cur_addr;
};

static struct mmc g_mmc;

static int wait_for_completion(struct mmc *mmc, struct mmc_cmd *cmd, uint32_t mask)
{
	uint32_t val;

	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_CMD_DONE), 5, MMC_CMD_TIMEOUT))
		return 0xfe;

	writel(EMMC_INT_CMD_DONE, EMMC_INT_STATUS_REG);
	cmd->error = (val >> 16);

	return cmd->error;
}

static int wait_for_transfer_complete(struct mmc *mmc, struct mmc_data *data)
{
	uint32_t val;

	if (readl_poll_timeout(EMMC_INT_STATUS_REG, val,
			       (val & EMMC_INT_DATA_DONE), 5, MMC_DATA_TIMEOUT))
		return 0xff;

	writel(EMMC_INT_DATA_DONE, EMMC_INT_STATUS_REG);
	data->error = (val >> 16);

	printf("int sts=0x%x\n", readl(&mmc->regs->intr_status));

	return data->error;
}

static void sdhci_set_sdma_addr(struct mmc *mmc, uint32_t addr)
{
	writel(addr, &mmc->regs->sdma_address);
}

static void mmc_cmd_done(struct mmc *mmc, struct mmc_cmd *cmd)
{
	int i;
	uint8_t *reg = (uint8_t *)&mmc->regs->resp[0];

	if (cmd->resp_type & MMC_RSP_136) {
		/* CRC is stripped so we need to do some shifting. */
		for (i = 0; i < 4; i++) {
			cmd->response[i] = readl(reg + (3 - i) * 4) << 8;
			if (i != 3)
				cmd->response[i] |= readb(reg + (3 - i) * 4 - 1);

			printf("resp %x\n", cmd->response[i]);
		}
	} else {
		cmd->response[0] = readl(&mmc->regs->resp[0]);
		printf("resp %x\n", cmd->response[0]);
	}
}

static int mmc_send_cmd(struct mmc *mmc, struct mmc_cmd *cmd, struct mmc_data *data)
{
	uint32_t mask, flags;
	uint32_t trans_bytes, mode = 0, val;
	uintptr_t start_addr;
	uint32_t time = 0;
	int ret = 0;

	/* Timeout unit - ms */
	static unsigned int cmd_timeout = SDHCI_CMD_DEFAULT_TIMEOUT;

	mask = SDHCI_CMD_INHIBIT | SDHCI_DATA_INHIBIT;

	/*
	 * We shouldn't wait for data inihibit for stop commands, even
	 * though they might use busy signaling
	 */
	if (cmd->cmdidx == MMC_CMD_STOP_TRANSMISSION ||
	    ((cmd->cmdidx == MMC_CMD_SEND_TUNING_BLOCK ||
	     cmd->cmdidx == MMC_CMD_SEND_TUNING_BLOCK_HS200) && !data))
		mask &= ~SDHCI_DATA_INHIBIT;

	while (readl(&mmc->regs->present) & mask) {
		if (time >= cmd_timeout) {
			printf("%s: MMC: busy ", __func__);
			if (2 * cmd_timeout <= SDHCI_CMD_MAX_TIMEOUT) {
				cmd_timeout += cmd_timeout;
				printf("timeout increasing to: %u ms.\n",
				       cmd_timeout);
			} else {
				printf("timeout.\n");
				return MMC_ERR_TIMEOUT;
			}
		}
		time++;
		mdelay(1);
	}

	writel(SDHCI_INT_ALL_MASK, &mmc->regs->intr_status);

	mask = SDHCI_INT_RESPONSE;
	if ((cmd->cmdidx == MMC_CMD_SEND_TUNING_BLOCK ||
	     cmd->cmdidx == MMC_CMD_SEND_TUNING_BLOCK_HS200) && !data)
		mask = SDHCI_INT_DATA_AVAIL;

	if (!(cmd->resp_type & MMC_RSP_PRESENT)) {
		flags = SDHCI_CMD_RESP_NONE;
	} else if (cmd->resp_type & MMC_RSP_136) {
		flags = SDHCI_CMD_RESP_LONG;
	} else if (cmd->resp_type & MMC_RSP_BUSY) {
		flags = SDHCI_CMD_RESP_SHORT_BUSY;
		if (data)
			mask |= SDHCI_INT_DATA_END;
	} else {
		flags = SDHCI_CMD_RESP_SHORT;
	}

	if (cmd->resp_type & MMC_RSP_CRC)
		flags |= SDHCI_CMD_CRC;
	if (cmd->resp_type & MMC_RSP_OPCODE)
		flags |= SDHCI_CMD_INDEX;
	if (data || cmd->cmdidx ==	MMC_CMD_SEND_TUNING_BLOCK ||
	    cmd->cmdidx == MMC_CMD_SEND_TUNING_BLOCK_HS200)
		flags |= SDHCI_CMD_DATA;

	/* Set Transfer mode regarding to data flag */
	if (data) {
		mmc->data = data;

		mode = SDHCI_TRNS_BLK_CNT_EN;
		trans_bytes = data->blocks * data->blocksize;
		if (data->blocks > 1)
			mode |= SDHCI_TRNS_MULTI;

		if (data->flags == MMC_DATA_READ)
			mode |= SDHCI_TRNS_READ;

		if (data->flags == MMC_DATA_READ)
			start_addr = (unsigned long)data->dest;
		else
			start_addr = (unsigned long)data->src;

		if (mmc->dma_mode) {
			mode |= SDHCI_TRNS_DMA;
			val = readl(&mmc->regs->host_control_0);
			val &= ~SDHCI_CTRL_DMA_MASK;
			val |= ((mmc->dma_mode - 1) << 3);
			writel(val, &mmc->regs->host_control_0);

			sdhci_set_sdma_addr(mmc, start_addr);
		}

		printf("sdma_address=%x\n", readl(&mmc->regs->sdma_address));
		printf("blk_size=0x%x\n", SDHCI_MAKE_BLKSZ(SDHCI_DEFAULT_BOUNDARY_ARG, data->blocksize));

		writel((data->blocks << 16) | SDHCI_MAKE_BLKSZ(SDHCI_DEFAULT_BOUNDARY_ARG, data->blocksize), &mmc->regs->blk_size);
		printf("0x%x=0x%x\n", &mmc->regs->blk_size, readl(&mmc->regs->blk_size));

		//writel(mode, &mmc->regs->mode);
		printf("mode=0x%x\n", mode);
	}

	mmc->intmask = mask;
	mmc->cmd = cmd;

	writel(cmd->cmdarg, &mmc->regs->argument);
	printf("0x%x=0x%x\n", &mmc->regs->argument, readl(&mmc->regs->argument));

	printf("%s, cmd=%d, arg=%x, flag=%x\n", __func__, cmd->cmdidx, cmd->cmdarg, flags);

	//printf("waiting...mask=%x\n", mask);
	writel((SDHCI_MAKE_CMD(cmd->cmdidx, flags) << 16) | mode, &mmc->regs->command);
	printf("0x1209010c=0x%x\n", readl(0x1209010c));

	ret = wait_for_completion(mmc, cmd, mask);
	if (!ret)
		mmc_cmd_done(mmc, cmd);

	printf("wait_for_completion ret=0x%x\n", ret);

	if (data) {
		ret = wait_for_transfer_complete(mmc, data);
		printf("wait_for_transfer_compl ret=0x%x\n", ret);
	}

	return ret;
}

static void mmc_rst_n_assert(void)
{
	/*
	 * GPIOQ7 as the emmc hw rst_n
	 * bit1: direction. (0:input, 1:output)
	 * bit0: val
	 */
	writel(2, EMMC_HW_RST_PIN);
	udelay(MMC_TRSTW_DELAY);
}

static void mmc_rst_n_deassert(void)
{
	writel(3, EMMC_HW_RST_PIN);
	udelay(MMC_TRSCA_DELAY);
}

static void mmc_hw_reset(void)
{
	mmc_rst_n_assert();
	mmc_rst_n_deassert();
}

static int mmc_go_idle(struct mmc *mmc)
{
	struct mmc_cmd cmd;
	int err = 0;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	printf("%s\n", __func__);

	cmd.cmdidx = MMC_CMD_GO_IDLE_STATE;
	cmd.cmdarg = 0;
	cmd.resp_type = MMC_RSP_NONE;

	err = mmc_send_cmd(mmc, &cmd, NULL);

	return err;
}

static int mmc_go_pre_idle(struct mmc *mmc)
{
	struct mmc_cmd cmd;
	int err = 0;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	printf("%s\n", __func__);

	cmd.cmdidx = MMC_CMD_GO_IDLE_STATE;
	cmd.cmdarg = 0xf0f0f0f0;
	cmd.resp_type = MMC_RSP_NONE;

	err = mmc_send_cmd(mmc, &cmd, NULL);

	return err;
}

static void mmc_sw_reset(struct mmc *mmc)
{
	mmc_go_idle(mmc);
	udelay(MMC_TRSCA_DELAY);
	mmc_go_pre_idle(mmc);
	udelay(MMC_TRSCA_DELAY);
}

static int mmc_send_op_cond_iter(struct mmc *mmc, int use_arg)
{
	struct mmc_cmd cmd;
	int err;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	printf("%s\n", __func__);

	cmd.cmdidx = MMC_CMD_SEND_OP_COND;
	cmd.resp_type = MMC_RSP_R3;
	cmd.cmdarg = 0;
	if (use_arg)
		cmd.cmdarg = OCR_HCS |
			(0x00ff8080 &
			(mmc->ocr & OCR_VOLTAGE_MASK)) |
			(mmc->ocr & OCR_ACCESS_MODE);

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;

	mmc->ocr = cmd.response[0];
	return 0;
}

static int mmc_send_op_cond(struct mmc *mmc)
{
	int err, i;

	/* Some cards seem to need this */
	mmc_go_idle(mmc);

	/* Asking to the card its capabilities */
	for (i = 0; i < 30; i++) {
		err = mmc_send_op_cond_iter(mmc, i != 0);
		if (err)
			return err;

		/* exit if not busy (flag seems to be inverted) */
		if (mmc->ocr & OCR_BUSY)
			break;

		mdelay(50);
	}
	mmc->op_cond_pending = 1;

	mmc->version = MMC_VERSION_UNKNOWN;
	mmc->high_capacity = ((mmc->ocr & OCR_HCS) == OCR_HCS);
	printf("high capacity = %d\n", mmc->high_capacity);
	mmc->rca = 1;

	return 0;
}

static int mmc_send_cmd_retry(struct mmc *mmc, struct mmc_cmd *cmd,
			      struct mmc_data *data, int retries)
{
	int ret;

	do {
		ret = mmc_send_cmd(mmc, cmd, data);
	} while (ret && retries--);

	return ret;
}

static int mmc_send_status(struct mmc *mmc, uint32_t *status)
{
	struct mmc_cmd cmd;
	int err;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	cmd.cmdidx = MMC_CMD_SEND_STATUS;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = mmc->rca << 16;

	err = mmc_send_cmd_retry(mmc, &cmd, NULL, 4);
	if (!err)
		*status = cmd.response[0];

	return err;
}

static int sdhci_reset(struct mmc *mmc, uint8_t mask)
{
	uint32_t val, timeout = 100;

	printf("%s\n", __func__);

	val = (mask << SDHCI_RESET_SHIFT);
	writel(val, &mmc->regs->host_control_1);

	/* wait reset to be cleared */
	while (readl(&mmc->regs->host_control_1) & val) {
		if (timeout == 0) {
			printf("%s: Reset 0x%x never completed.\n",
			       __func__, val);
			return MMC_ERROR;
			mdelay(1);
		}
		timeout--;
	}

	return 0;
}

static void sdhci_set_power(struct mmc *mmc, uint8_t power)
{
	uint32_t pwr;

	pwr = ((power | SDHCI_POWER_ON) << SDHCI_POWER_CONTROL_SHIFT);

	writel(pwr, &mmc->regs->host_control_0);
}

static void sdhci_interrupt_enable(struct mmc *mmc)
{
	mmc->ier = SDHCI_INT_CMD_MASK | SDHCI_INT_DATA_MASK;

	writel(mmc->ier, &mmc->regs->intr_status_en);
	writel(mmc->ier, &mmc->regs->intr_signal_en);
	printf("0x%x=0x%x\n", &mmc->regs->intr_status_en, mmc->ier);
	printf("0x%x=0x%x\n", &mmc->regs->intr_signal_en, mmc->ier);
}

#if defined(CONFIG_FPGA_ASPEED)
#define MPLL_FREQ	(50000000) /* 500MHz */
#elif defined(CONFIG_ASIC_ASPEED)
#define MPLL_FREQ	(400000000) /* 400MHz */
#else
#define MPLL_FREQ	(200000000)
#endif

static int sdhci_set_clock(struct mmc *mmc, uint32_t desired, int disable)
{
	uint32_t out_freq, div, val = 0;
	uint32_t timeout, ctrl;

	/* disable clock */
	val = readl(&mmc->regs->host_control_1);
	val &= ~(SDHCI_CLOCK_CARD_EN | SDHCI_CLOCK_INT_EN);
	writel(val, &mmc->regs->host_control_1);

	if (disable)
		return 0;

	/* source clock from top which has a divider */
	out_freq = MPLL_FREQ;

	if (out_freq <= desired) {
		div = 1;
	} else {
		for (div = 2; div < SDHCI_MAX_DIV_SPEC_300; div += 2) {
			if ((out_freq / div) <= desired)
				break;
		}
	}

	div >>= 1;

	val = 0;
	val |= ((div & SDHCI_DIV_MASK) << SDHCI_DIVIDER_SHIFT);
	val |= (((div & SDHCI_DIV_HI_MASK) >> SDHCI_DIV_MASK_LEN)
		<< SDHCI_DIVIDER_HI_SHIFT);
	val |= SDHCI_CLOCK_INT_EN;
	writel(val, &mmc->regs->host_control_1);

	printf("out_freq = %d, div = %d, val=%x\n", out_freq, div, val);

	/* configure divider */

	/* Wait max 20 ms */
	timeout = 20000;
	while (!((val = readl(&mmc->regs->host_control_1))
		& SDHCI_CLOCK_INT_STABLE)) {
		if (timeout == 0) {
			printf("%s: Internal clock never stabilised.\n",
			       __func__);
			break;
		}
		timeout--;
	}

	/* enable clock */
	val |= SDHCI_CLOCK_CARD_EN;
	writel(val, &mmc->regs->host_control_1);
	printf("0x%x=0x%x\n", &mmc->regs->host_control_1, val);

	writel(val | (0xe << 16), &mmc->regs->host_control_1);
	printf("0x%x=0x%x\n", &mmc->regs->host_control_1, val | (0xe << 16));

	ctrl = readl(&mmc->regs->host_control_0);
	if (desired > 26000000)
		ctrl |= SDHCI_CTRL_HISPD;
	else
		ctrl &= ~SDHCI_CTRL_HISPD;

	writel(ctrl, &mmc->regs->host_control_0);

	return 0;
}

static int sdhci_init(struct mmc *mmc)
{
	int ret;

	/* enable clock */
	writel(SCU_STOP_EMMC_BIT, SCU_STOP_CLR_REG);

	/* top emmc reset deassert */
	writel(SCU_RESET2_EMMC_BIT, SCU_RESET2_CLR_REG);

	/* configure GPIO18A0~A2(CLK/CMD/DAT0) to emmc mode */
	writel(0x7, SCU_PINCTRL_REG1);

	/* pullup emmc hw reset */
	mmc_rst_n_deassert();

	/* reset controller */
	ret = sdhci_reset(mmc, SDHCI_RESET_ALL);

	/* set power */
	sdhci_set_power(mmc, ((mmc->id) ? SDHCI_POWER_330 : SDHCI_POWER_180));

	/* set clock */
	ret = sdhci_set_clock(mmc, 400000, MMC_CLK_ENABLE);

	sdhci_interrupt_enable(mmc);

	/* set bus width */

	return ret;
}

static int mmc_wait_dat0(struct mmc *mmc, int state, uint32_t timeout)
{
	uint32_t tmp, i = 0;

	do {
		tmp = readl(&mmc->regs->present);
		if (!!(tmp & SDHCI_DATA_0_LVL_MASK) == !!state)
			return 0;

	} while (i++ < timeout);

	return MMC_ERROR;
}

static int mmc_set_signal_voltage(struct mmc *mmc, int signal_voltage)
{
	if (signal_voltage == MMC_SIGNAL_VOLTAGE_180)
		writel(0x80000, &mmc->regs->acmd12_status);
	else if (signal_voltage == MMC_SIGNAL_VOLTAGE_330)
		writel(0, &mmc->regs->acmd12_status);

	return 0;
}

static uint32_t mmc_mode2freq(struct mmc *mmc, enum bus_mode mode)
{
	static const int freqs[] = {
		  [MMC_LEGACY]	= 25000000,
		  [MMC_HS]	= 26000000,
		  [SD_HS]	= 50000000,
		  [MMC_HS_52]	= 52000000,
		  [MMC_DDR_52]	= 52000000,
		  [UHS_SDR12]	= 25000000,
		  [UHS_SDR25]	= 50000000,
		  [UHS_SDR50]	= 100000000,
		  [UHS_DDR50]	= 50000000,
		  [UHS_SDR104]	= 208000000,
		  [MMC_HS_200]	= 200000000,
		  [MMC_HS_400]	= 200000000,
	};

	return freqs[mode];
}

static inline bool mmc_is_mode_ddr(enum bus_mode mode)
{
	if (mode == MMC_DDR_52)
		return true;
	else if (mode == UHS_DDR50)
		return true;
	else if (mode == MMC_HS_400)
		return true;
	else
		return false;
}

static int mmc_select_mode(struct mmc *mmc, enum bus_mode mode)
{
	mmc->selected_mode = mode;
	mmc->tran_speed = mmc_mode2freq(mmc, mode);
	printf("tran_speed=%d\n", mmc->tran_speed);
	mmc->ddr_mode = mmc_is_mode_ddr(mode);
	return 0;
}

static inline int bus_width(uint32_t cap)
{
	if (cap == MMC_MODE_8BIT)
		return 8;
	if (cap == MMC_MODE_4BIT)
		return 4;
	if (cap == MMC_MODE_1BIT)
		return 1;
	printf("invalid bus witdh capability 0x%x\n", cap);
	return 0;
}

static int mmc_set_bus_width(struct mmc *mmc, int width)
{
	u32 val;

	mmc->bus_width = width;

	val = readl(EMMC_REG);

	val = readl(&mmc->regs->host_control_0);

	if (width == 8) {
		writel(val | (1 << 24), EMMC_REG);
	} else {
		writel(val & (~(3 << 24)), EMMC_REG);

		if (width == 4)
			val |= SDHCI_CTRL_4BITBUS;
		else
			val &= ~SDHCI_CTRL_4BITBUS;
	}

	writel(val, &mmc->regs->host_control_0);

	return 0;
}

static void mmc_set_initial_state(struct mmc *mmc)
{
	int err;

	/* First try to set 3.3V. If it fails set to 1.8V */
	err = mmc_set_signal_voltage(mmc, MMC_SIGNAL_VOLTAGE_330);
	if (err != 0)
		err = mmc_set_signal_voltage(mmc, MMC_SIGNAL_VOLTAGE_180);
	if (err != 0)
		printf("mmc: failed to set signal voltage\n");
	mmc->legacy_speed = 400000;
	mmc_select_mode(mmc, MMC_LEGACY);
	mmc_set_bus_width(mmc, 1);
}

static int __mmc_switch(struct mmc *mmc, uint8_t set, uint8_t index,
			uint8_t value, int send_status)
{
	struct mmc_cmd cmd;
	int timeout_ms = DEFAULT_CMD6_TIMEOUT_MS;
	int err = 0;
	uint32_t status, i = 0;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	cmd.cmdidx = MMC_CMD_SWITCH;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = (MMC_SWITCH_MODE_WRITE_BYTE << 24) |
				 (index << 16) |
				 (value << 8);

	err = mmc_send_cmd_retry(mmc, &cmd, NULL, 3);
	if (err)
		return err;

	err = mmc_wait_dat0(mmc, 1, timeout_ms * 1000);
	if (err)
		return err;

	if (!send_status)
		return 0;

	do {
		err = mmc_send_status(mmc, &status);

		if (!err && (status & MMC_STATUS_SWITCH_ERROR)) {
			printf("switch failed %d/%d/0x%x !\n", set, index,
			       value);
			return MMC_ERROR;
		}
		if (!err && (status & MMC_STATUS_RDY_FOR_DATA) &&
		    (status & MMC_STATUS_CURR_STATE) == MMC_STATE_TRANS)
			return 0;
	} while (i++ < timeout_ms * 1000);

	return MMC_ERR_TIMEOUT;
}

static int mmc_switch(struct mmc *mmc, u8 set, u8 index, u8 value)
{
	return __mmc_switch(mmc, set, index, value, true);
}

static int mmc_select_mode_and_width(struct mmc *mmc, int speed_mode, int bus_mode)
{
	int err = 0;
	//int bus_width[3] = {1, 4, 8};

	mmc_select_mode(mmc, speed_mode);
	sdhci_set_clock(mmc, mmc->tran_speed, MMC_CLK_ENABLE);

	/* switch part */
//	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
//			EXT_CSD_PART_CONF,
//			0x49);
	return err;
}

static int mmc_startup(struct mmc *mmc, int speed, int bus)
{
	struct mmc_cmd cmd;
	int err = 0;

	memset(&cmd, 0, sizeof(struct mmc_cmd));

	printf("mmc command 2\n");
	cmd.cmdidx = MMC_CMD_ALL_SEND_CID;
	cmd.resp_type = MMC_RSP_R2;
	cmd.cmdarg = 0;
	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;

	printf("mmc command 3\n");
	cmd.cmdidx = SD_CMD_SEND_RELATIVE_ADDR;
	cmd.cmdarg = mmc->rca << 16;
	cmd.resp_type = MMC_RSP_R6;
	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;

	if (IS_SD(mmc))
		mmc->rca = (cmd.response[0] >> 16) & 0xffff;

	/* Get the Card-Specific Data */
	printf("mmc command 9\n");
	cmd.cmdidx = MMC_CMD_SEND_CSD;
	cmd.resp_type = MMC_RSP_R2;
	cmd.cmdarg = mmc->rca << 16;
	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;

	if (mmc->version == MMC_VERSION_UNKNOWN) {
		int version = (cmd.response[0] >> 26) & 0xf;

		printf("VVVVVVVVVVVVersion=%x\n", version);

		switch (version) {
		case 0:
			mmc->version = MMC_VERSION_1_2;
			break;
		case 1:
			mmc->version = MMC_VERSION_1_4;
			break;
		case 2:
			mmc->version = MMC_VERSION_2_2;
			break;
		case 3:
			mmc->version = MMC_VERSION_3;
			break;
		case 4:
			mmc->version = MMC_VERSION_4;
			break;
		default:
			mmc->version = MMC_VERSION_1_2;
			break;
		}
	}

	mmc->legacy_speed = 10000000;

	printf("mmc command 7\n");
	cmd.cmdidx = MMC_CMD_SELECT_CARD;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = mmc->rca << 16;
	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;

	mmc->read_bl_len = MMC_MAX_BLOCK_LEN;
	mmc->write_bl_len = MMC_MAX_BLOCK_LEN;

	err = mmc_select_mode_and_width(mmc, speed, bus);

	return err;
}

static int mmc_init_device(struct mmc *mmc, int speed, int bus)
{
	int ret;

	printf("%s\n", __func__);

	mmc_set_initial_state(mmc);

	ret = mmc_send_op_cond(mmc);
	if (ret) {
		printf("mmc_send_op_cond failed\n");
		return ret;
	}

	ret = mmc_startup(mmc, speed, bus);
	if (ret) {
		printf("mmc_startup failed\n");
		return ret;
	}

	return ret;
}

static int mmc_init(void)
{
	struct mmc *mmc = &g_mmc;
	struct bootdev *bd = mmc->bd;
	struct abr *abr = bd->abr;

	int sw_rst_en = 0;
	int err;
	u16 cfg = 0;

	cfg = readl(SCU1_OTPCFG_03_02);
	if (cfg & OTPCFG2_EN_EMMC_SW_RST)
		sw_rst_en = 1;

	if (sw_rst_en || abr) {
		/*
		 * Init SDHCI accordingly for switch part or sw reset
		 */
		sdhci_init(mmc);

		if (abr) {
			err = mmc_init_device(mmc, 0, 0);
			if (err)
				return err;

			err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
					 EXT_CSD_PART_CONF,
					 abr->boot_indicator ? 0x52 : 0x49);
			if (err)
				return err;
		}

		/*
		 * In case there is no GPIO for emmc hw rst_n,
		 * perform a sw reset according to otp conf.
		 */
		if (sw_rst_en)
			mmc_sw_reset(mmc);

	}

	/*
	 * start emmc boot from hw_rst_n toggling
	 */
	mmc_hw_reset();

	return 0;
}

static void mmc_deinit(void)
{
	mmc_bring_to_default();
}

u8 tmp[MMC_BLOCK_LENGTH];
static int mmc_read(u32 from, u32 *dst, u32 len)
{
	struct mmc *mmc = &g_mmc;
	u32 lba, blks, extra, offset, i, trans;
	u8 *out = (u8 *)dst;
	int err = 0;

	/* mmc boot read doesn't support read back */
	if (mmc->cur_addr > from)
		return MMC_ERR_ADDR_ROLL_BACK;

	lba = from / MMC_BLOCK_LENGTH;
	offset = from % MMC_BLOCK_LENGTH;

	/* discard data if read address is beyond current address */
	if (mmc->cur_addr != from) {
		for (i = 0; i < lba; i++) {
			err = mmc_boot_read((u32)tmp, MMC_BLOCK_LENGTH);
			if (err)
				return MMC_ERR_DUMMY_READ;
		}

		if (offset) {
			err = mmc_boot_read((u32)tmp, MMC_BLOCK_LENGTH);
			if (err)
				return MMC_ERR_DUMMY_READ;
		}
	}

	if (offset) {
		trans = ((len < (MMC_BLOCK_LENGTH - offset)) ? len : (MMC_BLOCK_LENGTH - offset));
		memcpy(out, tmp + offset, trans);
		out += trans;
		from += trans;
		len -= trans;
	}

	/* move remaining data to user buffer by mmc boot mode */
	while (len) {
		blks = len / MMC_BLOCK_LENGTH;
		extra = len % MMC_BLOCK_LENGTH;

		lba = from / MMC_BLOCK_LENGTH;
		offset = from % MMC_BLOCK_LENGTH;

		if (len == extra) {
			err = mmc_boot_read((u32)tmp, MMC_BLOCK_LENGTH);
			if (err)
				return err;

			memcpy(out, tmp, extra);

			out += extra;
			from += extra;
			len -= extra;
		} else {
			/* general case, data offset is 512 byte align */
			for (i = 0; i < blks; i++) {
				err = mmc_boot_read((u32)(out + i * MMC_BLOCK_LENGTH), MMC_BLOCK_LENGTH);
				if (err)
					return err;
			}

			out += (MMC_BLOCK_LENGTH * blks);
			from += (MMC_BLOCK_LENGTH * blks);
			len -= (MMC_BLOCK_LENGTH * blks);
		}
	};

	mmc->cur_addr = from;

	return err;
}

static struct bootdev_ops mmc_ops = {
	.init = mmc_init,
	.read = mmc_read,
	.deinit = mmc_deinit,
};

void mmc_register(struct bootdev *bd)
{
	bd->id = BOOT_EMMC;
	bd->ops = &mmc_ops;
	bd->this = &g_mmc;
	g_mmc.bd = bd;

	g_mmc.regs = (struct mmc_regs *)(EMMC_REG);
	g_mmc.dma_mode = SDHCI_TRANS_SDMA;
	g_mmc.id = 0;
	g_mmc.cur_addr = 0;
}
