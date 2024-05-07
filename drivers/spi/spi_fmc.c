#include <boot.h>
#include <drivers/abr.h>
#include <drivers/scu.h>
#include <drivers/spi.h>
#include <drivers/wdt.h>
#include <io.h>
#include <lib/printf.h>
#include <lib/string.h>
#include <platform.h>

struct spi {
	struct bootdev *bd;
	uint32_t cs;
	uint32_t flash_sz;
	uint32_t abr_ofst;
};

static struct spi g_spi;

/*
 * The rule of FMC30 is,
 * start_addr <= decoding_range < end_addr.
 */
static uint32_t spi_fmc_segment_addr_start(uint32_t reg_val)
{
	return (((reg_val) & 0x0000ffff) << 16);
}

static uint32_t spi_fmc_segment_addr_val(uint32_t start, uint32_t end)
{
	return ((((start) >> 16) & 0xffff) | ((end + 1) & 0xffff0000));
}

static uint8_t spi_fmc_read_status_cmd(uint32_t cs)
{
	uint8_t status;
	uint32_t ctrl_val;
	uint32_t ctrl_val_bak;
	uint32_t addr_decoding_val;
	uint32_t addr;

	addr_decoding_val = readl(FMC_REG + CE0_ADDR_DECODING + cs * 4);
	addr = spi_fmc_segment_addr_start(addr_decoding_val);

	if (addr < SNOR_SZ_256MB)
		addr = FMC_MEM_L;
	else
		addr = FMC_MEM_H;

	/* Configure to command read mode. */
	ctrl_val = readl(FMC_REG + CE0_CTRL + cs * 4);
	ctrl_val_bak = ctrl_val;
	ctrl_val &= FMC_CLK_FREQ_MASK;
	ctrl_val |= (((0x05) << 16) | 0x1);
	writel(ctrl_val, FMC_REG + CE0_CTRL + cs * 4);
	/* Only enable data byte 0. */
	writel(0xfe, FMC_REG + ADDR_DATA_CTRL);

	status = readb(addr);

	/* Force to inactivate CS signal. */
	ctrl_val = (ctrl_val & FMC_CLK_FREQ_MASK) | 0x7;
	writel(ctrl_val, FMC_REG + CE0_CTRL + cs * 4);

	/* Restore FMC10. */
	writel(ctrl_val_bak, FMC_REG + CE0_CTRL + cs * 4);
	/* Restore FMC0C to default value. */
	writel(0x0, FMC_REG + ADDR_DATA_CTRL);

	return status;
}

/*
 * If SCU010[24], OTPSTRAP[25], is set, FMC will check
 * SPI flash ready bit before it accesses SPI flash.
 */
static void spi_fmc_wait_for_ready(uint32_t cs)
{
	uint8_t status;
	/* timeout after about
	 * 1.2 seconds: 50MHz SPI clock
	 * 5.1 seconds: 12.5MHz SPI clock
	 */
	int count = 4000000;
	uint32_t scu_wait_for_ready;

	scu_wait_for_ready = readl(SCU1_REG + 0x010) & BIT(24);
	if (scu_wait_for_ready == 0)
		return;

	while (count > 0) {
		status = spi_fmc_read_status_cmd(cs);
		if ((status & BIT(0)) != 0)
			count--;
		else
			break;
	}
}

static uint32_t spi_fmc_read_sfdp(uint32_t cs)
{
	uint32_t sfdp;
	uint32_t ctrl_val;
	uint32_t ctrl_val_bak;
	uint32_t addr_decoding_val;
	uint32_t addr;

	addr_decoding_val = readl(FMC_REG + CE0_ADDR_DECODING + cs * 4);
	addr = spi_fmc_segment_addr_start(addr_decoding_val);

	if (addr < SNOR_SZ_256MB)
		addr = FMC_MEM_L;
	else
		addr = FMC_MEM_H;

	/* Configure to command read mode. */
	ctrl_val = readl(FMC_REG + CE0_CTRL + cs * 4);
	ctrl_val_bak = ctrl_val;
	ctrl_val &= FMC_CLK_FREQ_MASK;
	/* cmd: 5Ah, dummy: 1 byte (8 clocks) */
	ctrl_val |= (((0x5a) << 16) | BIT(6) | 0x1);
	writel(ctrl_val, FMC_REG + CE0_CTRL + cs * 4);
	/* Force the controller to transmit 3-byte address length. */
	writel(0x80, FMC_REG + ADDR_DATA_CTRL);

	sfdp = readl(addr);

	/* Force to inactivate CS signal. */
	ctrl_val = (ctrl_val & FMC_CLK_FREQ_MASK) | 0x7;
	writel(ctrl_val, FMC_REG + CE0_CTRL + cs * 4);

	/* Restore FMC10. */
	writel(ctrl_val_bak, FMC_REG + CE0_CTRL + cs * 4);
	/* Restore FMC0C to default value. */
	writel(0x0, FMC_REG + ADDR_DATA_CTRL);

	return sfdp;
}

/*
 * If SCUIO_030[25], OTPSTRAP_EXT[57], is set, FMC will check
 * whether the flash is in reset state before accessing it.
 * Here, SFDP magic number is used to decide whether
 * flash is ready from the reset state.
 */
static void spi_fmc_check_access(uint32_t cs)
{
	uint32_t sfdp_magic;
	/* timeout after about
	 * 1.2 seconds: 50MHz SPI clock
	 * 4.6 seconds: 12.5MHz SPI clock
	 */
	int count = 800000;
	uint32_t scu_check_access;

	scu_check_access = readl(SCU1_REG + 0x030) &
			   SCU1_HWSTRAP2_CHECK_FLASH_ACCESS;
	if (scu_check_access == 0)
		return;

	while (count > 0) {
		sfdp_magic = spi_fmc_read_sfdp(cs);
		if (sfdp_magic == SNOR_SFDP_MAGIC)
			break;

		count--;
	}
}

/*
 * If SCU010[25], OTPSTRAP[26], is set, FMC CS0
 * is set to 4-byte address mode.
 */
static void spi_fmc_addr_mode_init(uint32_t cs, uint32_t flash_sz)
{
	uint32_t scu_addr_mode_val;
	uint32_t fmc_addr_mode_reg;

	scu_addr_mode_val = readl(SCU1_REG + 0x010) & BIT(25);

	if (scu_addr_mode_val != 0 || flash_sz >= SNOR_SZ_32MB) {
		fmc_addr_mode_reg = readl(FMC_REG + ADDR_CTRL);
		fmc_addr_mode_reg |= (0x11 << cs);
		writel(fmc_addr_mode_reg, FMC_REG + ADDR_CTRL);
	}
}

/*
 * SCU030[24:23]
 * 2b'00: 12.5MHz (HCLK / 16)
 * 2b'01: 25MHz (HCLK / 8)
 * 2b'10: 40MHz (HCLK / 5)
 * 2b'11: 50MHz (HCLK / 4)
 */
static void spi_fmc_clk_freq_adjust(uint32_t cs)
{
	uint32_t scu_fmc_clk_val;
	uint32_t fmc_clk_ctrl_reg;

	scu_fmc_clk_val = (readl(SCU1_REG + 0x030) & GENMASK(24, 23)) >> 23;
	fmc_clk_ctrl_reg = readl(FMC_REG + CE0_CTRL + cs * 4);
	fmc_clk_ctrl_reg &= ~(FMC_CLK_FREQ_MASK);

	switch (scu_fmc_clk_val) {
	case 0x0:
		fmc_clk_ctrl_reg |= 0x00000000;
		break;
	case 0x1:
		fmc_clk_ctrl_reg |= 0x00000400;
		break;
	case 0x2:
		fmc_clk_ctrl_reg |= 0x00000d00;
		break;
	case 0x3:
		fmc_clk_ctrl_reg |= 0x00000600;
		break;
	default:
		fmc_clk_ctrl_reg |= 0x00000000;
		break;
	}

	writel(fmc_clk_ctrl_reg, FMC_REG + CE0_CTRL + cs * 4);
}

/*
 * SCU flash size: SCU030[15:13]
 * 7: 512MB
 * 6: 256MB
 * 5: 128MB
 * 4: 64MB
 * 3: 32MB
 * 2: 16MB
 * 1: 8MB
 * 0: disabled
 */
static uint32_t spi_fmc_get_flash_sz_strap(void)
{
	uint32_t scu_flash_sz;
	uint32_t flash_sz_phy;

	scu_flash_sz = (readl(SCU1_REG + 0x030) >> 13) & 0x7;
	switch (scu_flash_sz) {
	case 0x7:
		flash_sz_phy = SNOR_SZ_512MB;
		break;
	case 0x6:
		flash_sz_phy = SNOR_SZ_256MB;
		break;
	case 0x5:
		flash_sz_phy = SNOR_SZ_128MB;
		break;
	case 0x4:
		flash_sz_phy = SNOR_SZ_64MB;
		break;
	case 0x3:
		flash_sz_phy = SNOR_SZ_32MB;
		break;
	case 0x2:
		flash_sz_phy = SNOR_SZ_16MB;
		break;
	case 0x1:
		flash_sz_phy = SNOR_SZ_8MB;
		break;
	case 0x0:
		flash_sz_phy = SNOR_SZ_UNSET;
		break;
	default:
		flash_sz_phy = SNOR_SZ_UNSET;
		break;
	}

	return flash_sz_phy;
}

static void spi_fmc_decoding_range_config(uint32_t cs,
					  uint32_t start_addr,
					  uint32_t end_addr)
{
	uint32_t decoding_reg_val;

	decoding_reg_val = spi_fmc_segment_addr_val(start_addr, end_addr);

	writel(decoding_reg_val, FMC_REG + CE0_ADDR_DECODING + cs * 4);
}

/* For dual flash ABR, CS swap function can be
 * configured by the signal in WDT controller.
 */
static void spi_fmc_cs_swap_enable(void)
{
	uint32_t reg_val;

	reg_val = readl(FMC_REG + CS_SWAP_CRTL);
	reg_val |= CS_SWAP_BY_WDT;
	writel(reg_val, FMC_REG + CS_SWAP_CRTL);

	/* Keep the CS swap control register
	 * settings after WDT SoC reset.
	 */
	reg_val = readl(FMC_REG + FMC_RST_WLOCK1);
	reg_val |= CS_SWAP_CTRL_RST_LOCK;
	writel(reg_val, FMC_REG + FMC_RST_WLOCK1);
}

static void spi_fmc_cs_swap(void)
{
	uint32_t reg_val;

	reg_val = readl(WDT_ABR(WDT_DEVA));
	reg_val |= WDT_ABR_FMC_CS_SWAP;
	writel(reg_val, WDT_ABR(WDT_DEVA));
}

static void spi_fmc_init(struct spi *spi)
{
	struct bootdev *bd = spi->bd;
	struct abr *abr = bd->abr;
	struct decoding_range ce_decoding_range[2];
	uint32_t flash_sz = spi->flash_sz;

	/* Config address decoding ranges. */
	if (abr) {
		if (abr->single) {
			/* Single flash ABR */
			if (flash_sz == SNOR_SZ_UNSET) {
				/*
				 * Force to assign an acceptable
				 * address decoding range.
				 */
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = SNOR_SZ_256MB;
				ce_decoding_range[1].start_addr = 0x0;
				ce_decoding_range[1].end_addr = 0x0;
				flash_sz = SNOR_SZ_256MB;
			} else {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = flash_sz;
				ce_decoding_range[1].start_addr = 0x0;
				ce_decoding_range[1].end_addr = 0x0;
			}

			if (abr->boot_indicator)
				spi->abr_ofst = (ce_decoding_range[0].end_addr) / 2;

		} else {
			/* Dual flash ABR */
			if (flash_sz == SNOR_SZ_UNSET) {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = SNOR_SZ_256MB;
				ce_decoding_range[1].start_addr = SNOR_SZ_256MB;
				ce_decoding_range[1].end_addr = SNOR_SZ_256MB * 2;
			} else {
				ce_decoding_range[0].start_addr = 0x0;
				ce_decoding_range[0].end_addr = flash_sz;
				ce_decoding_range[1].start_addr = flash_sz;
				ce_decoding_range[1].end_addr = flash_sz * 2;
			}

			/* boot from CS1 directly */
			if (abr->boot_indicator && !abr->cs_swap)
				spi->abr_ofst = ce_decoding_range[0].end_addr;

			/* boot from CS1 by HW address mapping automatically */
			if (abr->boot_indicator && abr->cs_swap) {
				spi_fmc_cs_swap_enable();
				spi_fmc_cs_swap();
			}
		}
	} else {
		if (flash_sz == SNOR_SZ_UNSET) {
			ce_decoding_range[0].start_addr = 0x0;
			ce_decoding_range[0].end_addr = SNOR_SZ_512MB;
		} else {
			ce_decoding_range[0].start_addr = 0x0;
			ce_decoding_range[0].end_addr = flash_sz;
		}

		ce_decoding_range[1].start_addr = 0x0;
		ce_decoding_range[1].end_addr = 0x0;
	}

	spi_fmc_decoding_range_config(0,
				      ce_decoding_range[0].start_addr,
				      ce_decoding_range[0].end_addr);
	spi_fmc_decoding_range_config(1,
				      ce_decoding_range[1].start_addr,
				      ce_decoding_range[1].end_addr);
	/* Always close CS2 window */
	spi_fmc_decoding_range_config(2, 0x0, 0x0);

	/* Config address mode according to flash size. */
	spi_fmc_addr_mode_init(spi->cs, flash_sz);
	spi_fmc_clk_freq_adjust(spi->cs);
	spi_fmc_wait_for_ready(spi->cs);
	spi_fmc_check_access(spi->cs);
}

static int spi_get_syndrome(struct abr *abr)
{
	uint32_t syndrome = 0;

	if (!abr)
		return syndrome;

	/* [7]: reserved
	 * [6]: cs swap occurs
	 * [5]: boot cs
	 * [4]: auxpin gpio value
	 *
	 * [3]: recovery mode is disabled when ABR failed
	 * [2]: wdta is triggered
	 * [1]: ABR indicator is set
	 * [0]: ABR enabled bit
	 */
	syndrome |= (abr->enabled & 0x1) << 0;
	syndrome |= (abr->boot_indicator & 0x1) << 1;
	syndrome |= (abr->wdta_triggered & 0x1) << 2;
	syndrome |= (abr->abr_rc_dis & 0x1) << 3;
	syndrome |= (abr->auxpin_val & 0x1) << 4;
	syndrome |= (abr->boot_cs & 0x1) << 5;
	syndrome |= (abr->cs_swap & 0x1) << 6;

	return syndrome;
}

static int spi_init(void)
{
	struct spi *spi = &g_spi;
	struct bootdev *bd = spi->bd;
	struct abr *abr = bd->abr;
	uint32_t cs_swap_dis;
	int syndrome;

	spi->flash_sz = spi_fmc_get_flash_sz_strap();
	spi->cs = 0;
	spi->abr_ofst = 0;
	cs_swap_dis = !!(readl(SCU1_HWSTRAP2) & SCU1_HWSTRAP2_FMC_ABR_CS_SWAP_DIS);

	if (abr) {
		if (!abr->single && abr->boot_indicator) {
			if (cs_swap_dis) {
				abr->cs_swap = 0;
				abr->boot_cs = 1;
				spi->cs = 1;
			} else {
				abr->cs_swap = 1;
				abr->boot_cs = 0;
				spi->cs = 0;
			}
		}
	}

	spi_fmc_init(spi);

	syndrome = spi_get_syndrome(abr);

	return syndrome;
}

static int spi_read(u32 from, u32 *dst, u32 len)
{
	struct spi *spi = &g_spi;
	uint32_t abr_ofst = spi->abr_ofst;

	if (!dst)
		return ERROR_INVALID_DST_PTR;

	/*
	 * From RV view, when the SPI flash accessed offset
	 * is greater than 256MB, RV should access the other
	 * FMC memory address space, FMC_MEM_H.
	 */
	if (abr_ofst < SNOR_SZ_256MB) {
		memcpy(dst, (void *)(FMC_MEM_L + abr_ofst + from),
		       len);
	} else {
		abr_ofst -= SNOR_SZ_256MB;
		memcpy(dst, (void *)(FMC_MEM_H + abr_ofst + from),
		       len);
	}

	return 0;
}

static struct bootdev_ops spi_ops = {
	.init = spi_init,
	.read = spi_read,
};

void spi_register(struct bootdev *bd)
{
	bd->id = BOOT_SPI;
	bd->ops = &spi_ops;
	bd->this = &g_spi;
	g_spi.bd = bd;
}
