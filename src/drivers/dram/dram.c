#include <drivers/dram.h>

#define DRAMC_UNLOCK_KEY		0x1688a8a8
#define DRAMC_VIDEO_UNLOCK_KEY	0x00440003

/*
 * Bandwidth configuration parameters for different SDRAM requests.
 * These are hardcoded settings taken from Aspeed SDK.
 */
#if defined(CONFIG_FPGA)
static const uint32_t ddr_max_grant_params[4] = {
	0x88888888, 0x88888888, 0x88888888, 0x88888888 };
#else
static const uint32_t ddr_max_grant_params[4] = {
	0x44444444, 0x44444466, 0x44444444, 0x44444444 };
#endif

#if defined(CONFIG_DDR4_3200)
#define CL	20
#define RTP	12
#define CWL	16
#define BL	8
#define CCD_L	8
#if defined(CONFIG_DDR4_16G)
#define RFC	880
#elif defined(CONFIG_DDR4_8G)
#define RFC	560
#elif defined(CONFIG_DDR4_4G)
#define RFC	416
#else
#define RFC	256
#endif
#elif defined(CONFIG_DDR4_2400)
#define CL	15
#define RTP	10
#define CWL	12
#define BL	8
#define CCD_L	7
#elif defined(CONFIG_DDR4_1600)
#define CL	10
#define RTP	6
#define CWL	9
#define BL	8
#define CCD_L	5
#if defined(CONFIG_DDR4_16G)
#define RFC	440
#elif defined(CONFIG_DDR4_8G)
#define RFC	280
#elif defined(CONFIG_DDR4_4G)
#define RFC	208
#else
#define RFC	128
#endif
#endif



enum ddr_speed_bin {
	DDR4_1600,
	DDR4_2400,
	DDR4_3200,
	DDR5_3200,
};

struct dramc_ac_timing {
	int t_rcd;		/* ACT-to-read/write command delay */
	int t_rp;		/* PRE command period */
	int t_ras;		/* ACT-to-PRE command delay */
	int t_rrd;		/* ACT-to-ACT delay for different BG */
	int t_rrd_l;		/* ACT-to-ACT delay for same BG */
	int t_faw;		/* Four active window */
	int t_rtp;		/* Read-to-PRE command delay */
	int t_wtr;		/* Minimum write to read command for different BG */
	int t_wtr_l;		/* Minimum write to read command for same BG */
	int t_wtp;		/* Minimum write to precharge command delay */
	int t_rtw;		/* minimum read to write command */
	int t_ccd_l;		/* CAS-to-CAS delay for same BG */
	int t_dllk;		/* DLL locking time */
	int t_cksre;		/* valid clock before after self-refresh or power-down entry/exit process */
	int t_pd;		/* power-down entry to exit minimum width */
	int t_xp;		/* exit power-down to valid command delay */
	int t_rfc;		/* refresh time period */
};

#if !defined(CONFIG_FPGA)
static struct dramc_ac_timing ac_table[] = {
	/* DDR4 1600 */
	{
		10, 10, 28, 5, 6, 28, 6,
		(CWL + (BL / 2) + 2),		/* t_wtr */
		(CWL + (BL / 2) + 6),		/* t_wtr_l */
		(CWL + (BL / 2) + 12),		/* t_wtp */
		(CL - CWL + (BL / 2) + 2),		/* t_rtw */
		CCD_L, 597, 8, 4, 5, RFC,
	},
	/* DDR4 2400 */
	{
		16, 16, 39, 7, 8, 37, 10,
		(CWL + (BL / 2) + 4),		/* t_wtr */
		(CWL + (BL / 2) + 10),		/* t_wtr_l */
		(CWL + (BL / 2) + 19),		/* t_wtp */
		(CL - CWL + (BL / 2) + 2),		/* t_rtw */
		CCD_L, 768, 13, 7, 8, RFC,
	},
	/* DDR4 3200 */
	{
		20, 20, 52, 9, 11, 48, 12,
		(CWL + (BL / 2) + 4),		/* t_wtr */
		(CWL + (BL / 2) + 12),		/* t_wtr_l */
		(CWL + (BL / 2) + 24),		/* t_wtp */
		(CL - CWL + (BL / 2) + 2),		/* t_rtw */
		CCD_L, 1023, 16, 8, 10, RFC,
	},
	/* DDR5 3200 */
	{
		/* TODO */
	},
};
#endif

#define ACTIME1(ccd, rrd_l, rrd, mrd)	\
	(((ccd) << 24) | (((rrd_l) >> 1) << 16) | (((rrd) >> 1) << 8) | ((mrd) >> 1))

#define ACTIME2(faw, rp, ras, rcd)	\
	((((faw) >> 1) << 24) | (((rp) >> 1) << 16) | (((ras) >> 1) << 8) | ((rcd) >> 1))

#define ACTIME3(wtr, rtw, wtp, rtp)	\
	((((wtr) >> 1) << 24) | (((rtw) >> 1) << 16) | (((wtp) >> 1) << 8) | ((rtp) >> 1))

#define ACTIME4(wtr_a, wtr_l)		\
	(((wtr_a) << 8) | (wtr_l))

#define ACTIME5(refsbrd, rfcsb, rfc)	\
	((((refsbrd) >> 1) << 20) | (((rfcsb) >> 1) << 10) | ((rfc) >> 1))

#define ACTIME6(cshsr, pd, xp, cksre)	\
	((((cshsr) >> 1) << 24) | ((((pd) >> 1) - 1) << 16) | ((((xp) >> 1) - 1) << 8) | (((cksre) >> 1) - 1))

#define ACTIME7(zqcs, dllk)	\
	((((zqcs) >> 1) << 10) | (((dllk) >> 1) - 1))

static inline void dramc_mr_send(uint32_t addr)
{
	writel((addr << 8) | DRAMC_MRCTL_CMD_START | DRAMC_MRCTL_CMD_WR_CTL, DRAMC_MRCTL);

	while (!(readl(DRAMC_IRQSTA) & DRAMC_IRQSTA_MR_DONE))
		;

	writel(DRAMC_IRQSTA_MR_DONE, DRAMC_IRQCLR);
}

static void dramc_unlock(void)
{
	writel(DRAMC_UNLOCK_KEY, DRAMC_PROT);

	while (!readl(DRAMC_PROT))
		;
}

static void dramc_configure_ac_timing(int speed)
{
#if defined(CONFIG_FPGA)
	writel(0x05030204, DRAMC_ACTIME1);
	writel(0x0e050e05, DRAMC_ACTIME2);
	writel(0x07040c03, DRAMC_ACTIME3);
	writel(0x00000009, DRAMC_ACTIME4);
	writel(0x05000068, DRAMC_ACTIME5);
	writel(0x00010103, DRAMC_ACTIME6);
	writel(0x00000129, DRAMC_ACTIME7);
#else
	uint8_t t_zqcs	= 80;	/* zq calibration short operation time */
	uint8_t t_rfcsb = 0;	/* refresh time period for same BG */
	uint8_t t_refsbrd = 0;	/* refresh time period for different bank ACT command */
	uint8_t t_mrd = 24;	/* mode register command update delay */
	uint8_t t_wtr_a = 0;	/* not used, write to read command for same BG with auto-precharge. */
	uint8_t t_cshsr = 0;	/* not used, self-refresh exit cs_n high pulse width */
	struct dramc_ac_timing *tbl = &ac_table[speed];

	writel(ACTIME1(tbl->t_ccd_l, tbl->t_rrd_l, tbl->t_rrd, t_mrd), DRAMC_ACTIME1);
	writel(ACTIME2(tbl->t_faw, tbl->t_rp, tbl->t_ras, tbl->t_rcd), DRAMC_ACTIME2);
	writel(ACTIME3(tbl->t_wtr, tbl->t_rtw, tbl->t_wtp, tbl->t_rtp), DRAMC_ACTIME3);
	writel(ACTIME4(t_wtr_a, tbl->t_wtr_l), DRAMC_ACTIME4);
	writel(ACTIME5(t_refsbrd, t_rfcsb, tbl->t_rfc), DRAMC_ACTIME5);
	writel(ACTIME6(t_cshsr, tbl->t_pd, tbl->t_xp, tbl->t_cksre), DRAMC_ACTIME6);
	writel(ACTIME7(t_zqcs, tbl->t_dllk), DRAMC_ACTIME7);
#endif
}

static void dramc_configure_register(int ddr5_mode)
{
	uint32_t dram_size;

#if defined(CONFIG_FPGA)
	uint32_t t_phy_wrdata = 1;
	uint32_t t_phy_wrlat = CWL - 6;
	uint32_t t_phy_rddata_en = CL - 5;
	uint32_t t_phy_odtlat = 1;
	uint32_t t_phy_odtext = 0;
#else
	// - Tphy_wrlat = N+4 (nCK) for DDR4, N+3 (nCK) for DDR5, where N is setting value.
	//	 * For DDR4 SDRAM, t_{phy_wrlat} = WL - 5.
	//	 * For DDR5 SDRAM, t_{phy_wrlat} = WL - 13.
	uint32_t t_phy_wrlat = CWL - 5 - 4;
	uint32_t t_phy_odtlat = CWL - 5 - 4;
	uint32_t t_phy_odtext = 0;

	// - Tphy_rddata_en = N+4 (nCK) for DDR4, N+3 (nCK) for DDR5, where N is setting value.
	//	 * For DDR4 SDRAM, t_{phy_rddata_en} = RL - 5.
	//	 * For DDR5 SDRAM, t_{phy_rddata_en} = RL - 13.
	uint32_t t_phy_rddata_en = CL - 5 - 4;

	// - Tphy_wrdata = N (nCK)
	//	 * For DDR4 SDRAM, t_{phy_wrdata} = 2.
	//	 * For DDR5 SDRAM, t_{phy_wrdata} = 6.
	uint32_t t_phy_wrdata = 2;
#endif

#if defined(CONFIG_DDR4_64G)
	dram_size = 5;
#elif defined(CONFIG_DDR4_32G)
	dram_size = 4;
#elif defined(CONFIG_DDR4_16G)
	dram_size = 3;
#elif defined(CONFIG_DDR4_8G)
	dram_size = 2;
#elif defined(CONFIG_DDR4_4G)
	dram_size = 1;
#elif defined(CONFIG_DDR4_2G)
	dram_size = 0;
#else
	dram_size = 0;
#endif

	writel(0x20 + (dram_size << 2) + ddr5_mode, DRAMC_MCFG);

	/* [5:0], t_phy_wrlat, for cycles from WR command to write data enable.
	 * [8:6], t_phy_wrdata, for cycles from write data enable to write data.
	 * [9], reserved
	 * [15:10] t_phy_rddata_en, for cycles from RD command to read data enable.
	 * [19:16], t_phy_odtlat, for cycles from WR command to ODT signal control.
	 * [21:20], ODT signal extension control
	 * [22], ODT signal enable
	 * [23], ODT signal auto mode
	 */
	writel((t_phy_odtext << 20) + (t_phy_odtlat << 16) + (t_phy_rddata_en << 10) + (t_phy_wrdata << 6) + t_phy_wrlat, DRAMC_DFITIME);
	writel(0, DRAMC_DFICTLMSG);

	/* [31:24]: refresh felxibility time period
	 * [23:16]: refresh time interfal
	 * [15]   : refresh function disable
	 * [14:10]: reserved
	 * [9:6]  : refresh threshold
	 * [5]	  : refresh option
	 * [4]	  : auto MR command sending for mode change
	 * [3]	  : same bank refresh operation
	 * [2]	  : refresh rate selection
	 * [1]	  : refresh mode selection
	 * [0]	  : refresh mode update trigger
	 */
	writel(0x40b48200, DRAMC_REFCTL);

	/* [31:16]: ZQ calibration period
	 * [15:8] : ZQ latch time period
	 * [7]	  : ZQ control status
	 * [6:3]  : reserved
	 * [2]	  : ZQCL command enable
	 * [1]	  : ZQ calibration auto mode
	 */
	writel(0x42aa1800, DRAMC_ZQCTL);

	/* [31:14]: reserved
	 * [13:12]: selection of limited request number for page-hit request
	 * [11]   : enable control of limitation for page-hit request counter
	 * [10]   : arbiter read threshold limitation disable control
	 * [9]	  : arbiter write threshold limitation disable control
	 * [8:5]  : read access limit threshold selection
	 * [4]	  : read request limit threshold enable
	 * [3:1]  : write request limit threshold selection
	 * [0]	  : write request limit enable
	 */
	writel(0, DRAMC_ARBCTL);

	writel(0xffffffff, DRAMC_IRQMSK);
}

static void dramc_configure_mrs(void)
{
	uint32_t mr0_cas, mr0_rtp, mr2_cwl, mr6_tccd_l;
	uint32_t mr0_val, mr1_val, mr2_val, mr3_val, mr4_val, mr5_val, mr6_val;

	//-------------------------------------------------------------------
	// CAS Latency (Table-15)
	//-------------------------------------------------------------------
	switch (CL) {
	case 9:
		mr0_cas = 0x00; //5'b00000;
		break;
	case 10:
		mr0_cas = 0x01; //5'b00001;
		break;
	case 11:
		mr0_cas = 0x02; //5'b00010;
		break;
	case 12:
		mr0_cas = 0x03; //5'b00011;
		break;
	case 13:
		mr0_cas = 0x04; //5'b00100;
		break;
	case 14:
		mr0_cas = 0x05; //5'b00101;
		break;
	case 15:
		mr0_cas = 0x06; //5'b00110;
		break;
	case 16:
		mr0_cas = 0x07; //5'b00111;
		break;
	case 18:
		mr0_cas = 0x08; //5'b01000;
		break;
	case 20:
		mr0_cas = 0x09; //5'b01001;
		break;
	case 22:
		mr0_cas = 0x0a; //5'b01010;
		break;
	case 24:
		mr0_cas = 0x0b; //5'b01011;
		break;
	case 23:
		mr0_cas = 0x0c; //5'b01100;
		break;
	case 17:
		mr0_cas = 0x0d; //5'b01101;
		break;
	case 19:
		mr0_cas = 0x0e; //5'b01110;
		break;
	case 21:
		mr0_cas = 0x0f; //5'b01111;
		break;
	case 25:
		mr0_cas = 0x10; //5'b10000;
		break;
	case 26:
		mr0_cas = 0x11; //5'b10001;
		break;
	case 27:
		mr0_cas = 0x12; //5'b10010;
		break;
	case 28:
		mr0_cas = 0x13; //5'b10011;
		break;
	case 30:
		mr0_cas = 0x15; //5'b10101;
		break;
	case 32:
		mr0_cas = 0x17; //5'b10111;
		break;
	}

	//-------------------------------------------------------------------
	// WR and RTP (Table-14)
	//-------------------------------------------------------------------
	switch (RTP)  {
	case 5:
		mr0_rtp = 0x0; //4'b0000;
		break;
	case 6:
		mr0_rtp = 0x1; //4'b0001;
		break;
	case 7:
		mr0_rtp = 0x2; //4'b0010;
		break;
	case 8:
		mr0_rtp = 0x3; //4'b0011;
		break;
	case 9:
		mr0_rtp = 0x4; //4'b0100;
		break;
	case 10:
		mr0_rtp = 0x5; //4'b0101;
		break;
	case 12:
		mr0_rtp = 0x6; //4'b0110;
		break;
	case 11:
		mr0_rtp = 0x7; //4'b0111;
		break;
	case 13:
		mr0_rtp = 0x8; //4'b1000;
		break;
	}

	//-------------------------------------------------------------------
	// CAS Write Latency (Table-21)
	//-------------------------------------------------------------------
	switch (CWL)  {
	case 9:
		mr2_cwl = 0x0; // 3'b000; // 1600
		break;
	case 10:
		mr2_cwl = 0x1; // 3'b001; // 1866
		break;
	case 11:
		mr2_cwl = 0x2; // 3'b010; // 2133
		break;
	case 12:
		mr2_cwl = 0x3; // 3'b011; // 2400
		break;
	case 14:
		mr2_cwl = 0x4; // 3'b100; // 2666
		break;
	case 16:
		mr2_cwl = 0x5; // 3'b101; // 2933/3200
		break;
	case 18:
		mr2_cwl = 0x6; // 3'b110;
		break;
	case 20:
		mr2_cwl = 0x7; // 3'b111;
		break;
	}

	//-------------------------------------------------------------------
	// tCCD_L and tDLLK
	//-------------------------------------------------------------------
	switch (CCD_L) {
	case 4:
		mr6_tccd_l = 0x0; //3'b000;  // rate <= 1333
		break;
	case 5:
		mr6_tccd_l = 0x1; //3'b001;  // 1333 < rate <= 1866
		break;
	case 6:
		mr6_tccd_l = 0x2; //3'b010;  // 1866 < rate <= 2400
		break;
	case 7:
		mr6_tccd_l = 0x3; //3'b011;  // 2400 < rate <= 2666
		break;
	case 8:
		mr6_tccd_l = 0x4; //3'b100;  // 2666 < rate <= 3200
		break;
	}

	/*
	 * mr0_val = {
	 * mr0_rtp[3],		// 13
	 * mr0_cas[4],		// 12
	 * mr0_rtp[2:0],	// 13,11-9: WR and RTP
	 * 1'b0,		// 8: DLL reset
	 * 1'b0,		// 7: TM
	 * mr0_cas[3:1],	// 6-4,2: CAS latency
	 * 1'b0,		// 3: sequential
	 * mr0_cas[0],
	 * 2'b00		// 1-0: burst length
	 */
	mr0_val = ((mr0_cas & 0x1) << 2) | (((mr0_cas >> 1) & 0x7) << 4) | (((mr0_cas >> 4) & 0x1) << 12) |
			  ((mr0_rtp & 0x7) << 9) | (((mr0_rtp >> 3) & 0x1) << 13);

	/*
	 * 3'b2 //[10:8]: rtt_nom, 000:disable,001:rzq/4,010:rzq/2,011:rzq/6,100:rzq/1,101:rzq/5,110:rzq/3,111:rzq/7
	 * 1'b0 //[7]: write leveling enable
	 * 2'b0 //[6:5]: reserved
	 * 2'b0 //[4:3]: additive latency
	 * 2'b0 //[2:1]: output driver impedance
	 * 1'b1 //[0]: enable dll
	 */
	mr1_val = 0x201;

	/*
	 * [10:9]: rtt_wr, 00:dynamic odt off, 01:rzq/2, 10:rzq/1, 11: hi-z
	 * [8]: 0
	 */
	mr2_val = ((mr2_cwl & 0x7) << 3) | 0x200;

	mr3_val = 0;

	mr4_val = 0;

	/*
	 * mr5_val = {
	 * 1'b0,		// 13: RFU
	 * 1'b0,		// 12: read DBI
	 * 1'b0,		// 11: write DBI
	 * 1'b1,		// 10: Data mask
	 * 1'b0,		// 9: C/A parity persistent error
	 * 3'b000,		// 8-6: RTT_PARK (disable)
	 * 1'b1,		// 5: ODT input buffer during power down mode
	 * 1'b0,		// 4: C/A parity status
	 * 1'b0,		// 3: CRC error clear
	 * 3'b0			// 2-0: C/A parity latency mode
	 * };
	 */
	mr5_val = 0x420;

	/*
	 * mr6_val = {
	 * 1'b0,		// 13, 9-8: RFU
	 * mr6_tccd_l[2:0],	// 12-10: tCCD_L
	 * 2'b0,		// 13, 9-8: RFU
	 * 1'b0,		// 7: VrefDQ training enable
	 * 1'b0,		// 6: VrefDQ training range
	 * 6'b0			// 5-0: VrefDQ training value
	 * };
	 */
	mr6_val = ((mr6_tccd_l & 0x7) << 10);

	writel((mr1_val << 16) + mr0_val, DRAMC_MRSR01);
	writel((mr3_val << 16) + mr2_val, DRAMC_MRSR23);
	writel((mr5_val << 16) + mr4_val, DRAMC_MRSR45);
	writel(mr6_val, DRAMC_MRSR67);

	/* Power-up initialization sequence */
	dramc_mr_send(3);
	dramc_mr_send(6);
	dramc_mr_send(5);
	dramc_mr_send(4);
	dramc_mr_send(2);
	dramc_mr_send(1);
	dramc_mr_send(0);

	/* refresh update */
	writel(0x40b40200, DRAMC_REFCTL);
}

static int dramc_init(void)
{
	int speed;

#if defined(CONFIG_DDR4_1600)
	speed = DDR4_1600;
#elif defined(CONFIG_DDR4_2400)
	speed = DDR4_2400;
#elif defined(CONFIG_DDR4_3200)
	speed = DDR4_3200;
#endif

	/* 2.2 configure ac timing */
	dramc_configure_ac_timing(speed);

	/* 2.3 configure register */
	dramc_configure_register(0);

	return 0;
}

#if defined(CONFIG_FPGA)
static int fpga_phy_init(void)
{
	/* adjust CLK4RX delay */
	writel(0x10f, SCU_CPU_PINMUX1);
	writel(0x30f, SCU_CPU_PINMUX1);

	/* adjust DQS window */
	writel(0x18, DRAMC_TESTCFG);

	/* assert DFI reset */
	writel(DRAMC_DFICFG_RESET | DRAMC_DFICFG_WD_POL, DRAMC_DFICFG);

	/* power up control (switch power FSM) */
	writel(DRAMC_MCTL_PHY_RESET, DRAMC_MCTL);
	writel(DRAMC_MCTL_PHY_RESET | DRAMC_MCTL_PHY_POWER_ON, DRAMC_MCTL);
	writel(DRAMC_MCTL_PHY_POWER_ON, DRAMC_MCTL);

	/* de-assert DFI reset */
	clrbits(DRAMC_DFICFG, DRAMC_DFICFG_RESET);

	/* DFI start */
	setbits(DRAMC_MCTL, DRAMC_MCTL_PHY_INIT_START);

	/* query phy init done */
	while (!(readl(DRAMC_IRQSTA) & DRAMC_IRQSTA_PHY_INIT_DONE))
		;

	writel(DRAMC_IRQSTA_PHY_INIT_DONE, DRAMC_IRQCLR);

	return 0;
}
#endif

void dramc_ecc_enable(uint32_t prot_size)
{
	printf("enable ecc protect\n");

	/* enable ecc */
	clrbits(DRAMC_MCFG, DRAMC_MCFG_PAGE_MATCH_EN);
	setbits(DRAMC_MCFG, DRAMC_MCFG_ECC_EN);

	/* ecc protect within 1MB */
	writel(prot_size >> 4, DRAMC_ECCADDR);

	/* enable ecc test mode */
	setbits(DRAMC_ECCTESTCTL, DRAMC_ECCTESTCTL_TEST_EN);
}

void dramc_ecc_disable(void)
{
	printf("disable ecc protect\n");

	clrbits(DRAMC_ECCTESTCTL, DRAMC_ECCTESTCTL_TEST_EN);

	clrbits(DRAMC_MCFG, DRAMC_MCFG_ECC_EN);
	setbits(DRAMC_MCFG, DRAMC_MCFG_PAGE_MATCH_EN);
}

void dramc_aes_enable(uint32_t addr, uint32_t size)
{
	printf("enable aes\n");

	writel(addr, DRAMC_AESADDR_MIN);
	writel(addr + size, DRAMC_AESADDR_MAX);

	setbits(DRAMC_MCFG, DRAMC_MCFG_AES_EN);
}

void dramc_aes_disable(void)
{
	printf("disable aes\n");
	clrbits(DRAMC_MCFG, DRAMC_MCFG_AES_EN);
}

int dramc_dq_shift_cali(void)
{
	int i, err, dq[128 + 16], dq_left_0, dq_right_0;
	uint32_t shift_val = 0x100;
	uint32_t shift_en = (1 << 9);
	uint32_t bistcfg;
	int flag = 0, found = 0;

	writel(0x0f, SCU_CPU_PINMUX1);
	writel(0x20f, SCU_CPU_PINMUX1);

	bistcfg = FIELD_PREP(DRAMC_BISTCFG_PMODE, BIST_PMODE_CRC)
		| FIELD_PREP(DRAMC_BISTCFG_BMODE, BIST_BMODE_RW_SWITCH)
		| DRAMC_BISTCFG_ENABLE;
	dramc_bist(0, 0x10000, bistcfg, 200);

	writel(0x0f, SCU_CPU_PINMUX1);
	writel(0x20f, SCU_CPU_PINMUX1);

	for (i = 0; i < 128 + 16; i++) {
		writel(shift_val, SCU_CPU_PINMUX1);
		writel(shift_en | shift_val, SCU_CPU_PINMUX1);

		err = dramc_bist(0, 0x1000000, bistcfg, 200);
		if (err) {
			printf("0");
			dq[i] = 0;
		} else {
			printf("1");
			dq[i] = 1;
			found = 1;
		}
	}

	printf("\n");
	if (!found) {
		printf("No window found !!!\n");
		return 1;
	}

	for (i = 0; i < 128 + 16; i++) {
		if (dq[i] && !flag) {
			printf("left=%d\n", i);
			dq_left_0 = i;
			flag = 1;
		} else if (!dq[i] && flag) {
			printf("right=%d\n", i);
			dq_right_0 = i;
			flag = 0;
		}
	}

	printf("dq left delay=%d\n", dq_left_0 - 16 + 1);
	printf("dq right delay=%d\n", dq_right_0 - 16 + 1);
	printf("dq center delay= %d\n", ((dq_right_0 + dq_left_0) / 2) - 16 + 1);
	printf("\n");

	return 0;
}

int dramc_bist(uintptr_t addr, uint32_t size, uint32_t cfg, uint32_t timeout)
{
	volatile uint32_t val;
	uint32_t err = 0;
	uint32_t i = 0;

	writel(0, DRAMC_BISTCFG);
	writel(cfg, DRAMC_BISTCFG);
	writel(addr >> 4, DRAMC_BISTADDR);
	writel(size >> 4, DRAMC_BISTSIZE);
	writel(0x89abcdef, DRAMC_BISTPAT);
	setbits(DRAMC_BISTCFG, DRAMC_BISTCFG_START);

	while (i < timeout) {
		if ((readl(DRAMC_IRQSTA) & DRAMC_IRQSTA_BIST_DONE))
			break;

		i++;
	};

	writel(DRAMC_IRQSTA_BIST_DONE, DRAMC_IRQCLR);

	val = readl(DRAMC_BISTRES);

	/* bist done */
	if (val & DRAMC_BISTRES_DONE) {
		/* bist pass [9]=0 */
		if (val & DRAMC_BISTRES_FAIL)
			err++;
	} else {
		err++;
	}

	return err;
}

int dram_init(void)
{
	uint32_t val, bistcfg;
	int err = 0;

	if (readl(SCU_CPU_SOC1_SCRATCH) & 0x40) {
		printf("DDR has been initialized\n");
		return 0;
	}

	dramc_unlock();

	dramc_init();

	/* initialize phy */
#if defined(CONFIG_FPGA)
	fpga_phy_init();
#else
	dwc_phy_init();
#endif

	/* exit self-refresh after phy init */
	setbits(DRAMC_MCTL, DRAMC_MCTL_SELF_REF_START);

	/* query if self-ref done */
	while (!(readl(DRAMC_IRQSTA) & DRAMC_IRQSTA_REF_DONE))
		;

	writel(DRAMC_IRQSTA_REF_DONE, DRAMC_IRQCLR);

	dramc_configure_mrs();

	bistcfg = FIELD_PREP(DRAMC_BISTCFG_PMODE, BIST_PMODE_CRC)
		| FIELD_PREP(DRAMC_BISTCFG_BMODE, BIST_BMODE_RW_SWITCH)
		| DRAMC_BISTCFG_ENABLE;
	err = dramc_bist(0, 0x10000, bistcfg, 0x200000);
	if (err)
		return err;

	val = readl(SCU_CPU_SOC1_SCRATCH);
	val |= 0x70;
	writel(val, SCU_CPU_SOC1_SCRATCH);

	return err;
}
