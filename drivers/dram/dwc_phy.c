// SPDX-License-Identifier: GPL-2.0+
#include <drivers/dram.h>
#include <boot.h>

#define DWC_PHY_BIN_BASE_SPI	(0x20020000)
#define DWC_PHY_BIN_BASE_SRAM	(0x10000000)

#define DWC_PHY_IMEM_OFFSET	(0x50000)
#define DWC_PHY_DMEM_OFFSET	(0x58000)

struct train_data {
	uint32_t imem_base;
	uint32_t imem_len;
	uint32_t dmem_base;
	uint32_t dmem_len;
};

struct train_data bin[] = {
	// 1d
	{0, 30680, 30680, 65536},
	// 2d
	{131072, 29880, 160952, 65536},
};

void dwc_get_mailbox(const int bit32_mode, uint32_t *mail)
{
	uint32_t ddrphy_val;

	/* 1. Poll the UctWriteProtShadow, looking for a 0 */
	while (1) {
		ddrphy_val = dwc_ddrphy_apb_rd(0xd0004);
		if (!(ddrphy_val & 0x1))
			break;
	}

	/* 2. When a 0 is seen, read the UctWriteOnlyShadow register to get the major message number. */
	*mail = dwc_ddrphy_apb_rd(0xd0032) & 0xffff;

	/* 3. If reading a streaming or SMBus message, also read the UctDatWriteOnlyShadow register. */
	if (bit32_mode)
		*mail += (dwc_ddrphy_apb_rd(0xd0034) & 0xffff) << 16;

	/* 4. Write the DctWriteProt to 0 to acknowledge the reception of the message */
	dwc_ddrphy_apb_wr(0xd0031, 0);

	/* 5. Poll the UctWriteProtShadow, looking for a 1 */
	while (1) {
		ddrphy_val = dwc_ddrphy_apb_rd(0xd0004);
		if (ddrphy_val & 0x1)
			break;
	};

	/* 6. When a 1 is seen, write the DctWriteProt to 1 to complete the protocol */
	dwc_ddrphy_apb_wr(0xd0031, 1);
}

void dwc_init_mailbox(void)
{
	printf("%s\n", __func__);

	dwc_ddrphy_apb_wr(0xd0031, 1);
	dwc_ddrphy_apb_wr(0xd0033, 1);
}

uint32_t dwc_readMsgBlock(const uint32_t addr_half)
{
	uint32_t data_word;

	data_word = dwc_ddrphy_apb_rd_32b((addr_half >> 1) << 1);

	if (addr_half & 0x1)
		data_word = data_word >> 16;
	else
		data_word &= 0xffff;

	return data_word;
}

int dwc_ddrphy_phyinit_userCustom_H_readMsgBlock(int train2D)
{
	uint32_t  message;

#if defined(CONFIG_DDR4_TYPE)
	if (train2D) {
		printf("%s: Read 2D message block by train2D = 1\n", __func__);

		/* uint16_t PmuRevision;  // Byte offset 0x02, CSR Addr 0x58001, Direction=Out */
		message = dwc_readMsgBlock(0x58001);
		printf("%s: PMU firmware revision ID (PmuRevision)\n", __func__, message);

		/* uint8_t CsTestFail;   // Byte offset 0x14, CSR Addr 0x5800a, Direction=Out */
		message = dwc_readMsgBlock(0x5800a);

		if ((message & 0xff) > 0) {
			printf("%s: Training Failure index (CsTestFail)\n", __func__, message);
		} else {
			// uint8_t	R0_RxClkDly_Margin; // Byte offset 0x25, CSR Addr 0x58012, Direction=Out
			// uint8_t	R0_VrefDac_Margin; // Byte offset 0x26, CSR Addr 0x58013, Direction=Out
			// uint8_t	R0_TxDqDly_Margin; // Byte offset 0x27, CSR Addr 0x58013, Direction=Out
			// uint8_t	R0_DeviceVref_Margin; // Byte offset 0x28, CSR Addr 0x58014, Direction=Out
			message = dwc_readMsgBlock(0x58012);

			//print_dec("- <DWC_DDRPHY Message Block>: R0_RxClkDly_Margin", message[15:8]);
			message = dwc_readMsgBlock(0x58013);

			//print_dec("- <DWC_DDRPHY Message Block>: R0_VrefDac_Margin", message[7:0]);
			//print_dec("- <DWC_DDRPHY Message Block>: R0_VrefDac_Margin", message[15:8]);
			message = dwc_readMsgBlock(0x58014);

			//print_dec("- <DWC_DDRPHY Message Block>: R0_DeviceVref_Margin", message[7:0]);
			// uint8_t	MR1_RX_CTLE_CTRL0; // Byte offset 0x2c, CSR Addr 0x58016, Direction=Out
			// uint8_t	MR1_RX_CTLE_CTRL1; // Byte offset 0x2d, CSR Addr 0x58016, Direction=Out
			// uint8_t	MR1_RX_CTLE_CTRL2; // Byte offset 0x2e, CSR Addr 0x58017, Direction=Out
			// uint8_t	MR1_RX_CTLE_CTRL3; // Byte offset 0x2f, CSR Addr 0x58017, Direction=Out
			message = dwc_readMsgBlock(0x58016);

			//print_dec("- <DWC_DDRPHY Message Block>: MR1_RX_CTLE_CTRL0", message[7:0]);
			//print_dec("- <DWC_DDRPHY Message Block>: MR1_RX_CTLE_CTRL1", message[15:8]);
			message = dwc_readMsgBlock(0x58017);

			//print_dec("- <DWC_DDRPHY Message Block>: MR1_RX_CTLE_CTRL2", message[7:0]);
			//print_dec("- <DWC_DDRPHY Message Block>: MR1_RX_CTLE_CTRL3", message[15:8]);

			// uint8_t	MR6_RX_CTLE_CTRL0; // Byte offset 0x3a, CSR Addr 0x5801d, Direction=Out
			// uint8_t	MR6_RX_CTLE_CTRL1; // Byte offset 0x3b, CSR Addr 0x5801d, Direction=Out
			// uint8_t	MR6_RX_CTLE_CTRL2; // Byte offset 0x3c, CSR Addr 0x5801e, Direction=Out
			// uint8_t	MR6_RX_CTLE_CTRL3; // Byte offset 0x3d, CSR Addr 0x5801e, Direction=Out
			message = dwc_readMsgBlock(0x5801d);
			//print_dec("- <DWC_DDRPHY Message Block>: MR6_RX_CTLE_CTRL0", message[7:0]);
			//print_dec("- <DWC_DDRPHY Message Block>: MR6_RX_CTLE_CTRL1", message[15:8]);
			message = dwc_readMsgBlock(0x5801e);
			//print_dec("- <DWC_DDRPHY Message Block>: MR6_RX_CTLE_CTRL2", message[7:0]);
			//print_dec("- <DWC_DDRPHY Message Block>: MR6_RX_CTLE_CTRL3", message[15:8]);
			printf("%s: 2D Training Passed\n", __func__);
		}
	} else {  // train 1D
		printf("%s: Read 1D message block by train2D = 0\n", __func__);
		// 1. Check PMU revision
		// uint16_t PmuRevision;  // Byte offset 0x02, CSR Addr 0x58001, Direction=Out
		message = dwc_readMsgBlock(0x58001);
		printf("%s: PMU firmware revision ID (PmuRevision)\n", __func__, message);

		// 2. Check pass / Failure of the training (CsTestFail)
		// uint8_t CsTestFail;   // Byte offset 0x14, CSR Addr 0x5800a, Direction=Out
		message = dwc_readMsgBlock(0x5800a);
		if ((message & 0xff) > 0)
			printf("%s: Training Failure index (CsTestFail)\n", __func__, message);
		else
			printf("%s: 1D Training Passed\n", __func__);
	}
#elif defined(CONFIG_DDR5_TYPE)	// TEST_DDR5_MODEL
	printf("%s: Read 2D message block by train2D = 1\n", __func__);
	// 1. Check PMU revision
	// uint16_t PmuRevision;  // Byte offset 0x02, CSR Addr 0x58001, Direction=Out
	message = dwc_readMsgBlock(0x58001);
	printf("%s: PMU firmware revision ID (PmuRevision)\n", __func__, message);

	// 2. Check pass / Failure of the training (CsTestFail)
	// uint8_t CsTestFail;   // Byte offset 0x0f, CSR Addr 0x58007, Direction=Out
	message = dwc_readMsgBlock(0x58007);
	if (((message >> 8) & 0xff) > 0)
		printf("%s: Training Failure index (CsTestFail)\n", __func__, message);
	else
		printf("%s: DDR5 1D/2D Training Passed\n", __func__);

	// 3. Read ResultAddrOffset
	// uint16_t ResultAddrOffset; // Byte offset 0x14, CSR Addr 0x5800a, Direction=Out
	message = dwc_readMsgBlock(0x5800a);
	printf("%s: Result Address Offset (ResultAddrOffset)\n", __func__, message);
#endif
	return 0;
}

void dwc_ddrphy_phyinit_userCustom_A_bringupPower(void)
{
}

void dwc_ddrphy_phyinit_userCustom_B_startClockResetPhy(void)
{
	//// 1. Drive PwrOkIn to 0. Note: Reset, DfiClk, and APBCLK can be X.
	//// 2. Start DfiClk and APBCLK
	//// 3. Drive Reset to 1 and PRESETn_APB to 0.
	////	Note: The combination of PwrOkIn=0 and Reset=1 signals a cold reset to the PHY.
	writel(0x00020000, DRAMC_MCTL);
	//// 4. Wait a minimum of 8 cycles.
	udelay(2);
	//// 5. Drive PwrOkIn to 1. Once the PwrOkIn is asserted (and Reset is still asserted),
	////	DfiClk synchronously switches to any legal input frequency.
	writel(0x00030000, DRAMC_MCTL);
	//// 6. Wait a minimum of 64 cycles. Note: This is the reset period for the PHY.
	udelay(2);
	//// 7. Drive Reset to 0. Note: All DFI and APB inputs must be driven at valid reset states before the deassertion of Reset.
	writel(0x00010000, DRAMC_MCTL);
	//// 8. Wait a minimum of 1 Cycle.
	//// 9. Drive PRESETn_APB to 1 to de-assert reset on the ABP bus.
	////10. The PHY is now in the reset state and is ready to accept APB transactions.
	udelay(2);
}

void dwc_ddrphy_phyinit_userCustom_overrideUserInput(void)
{
}

void dwc_ddrphy_phyinit_userCustom_customPostTrain(void)
{
}

void dwc_ddrphy_phyinit_userCustom_E_setDfiClk(int a)
{
	dwc_init_mailbox();
}

void dwc_ddrphy_phyinit_userCustom_G_waitFwDone(void)
{
	uint32_t message = 0, mail;

	printf("%s\n", __func__);

	while (message != 0x07 && message != 0xff) {
		dwc_get_mailbox(0, &mail);
		message = mail & 0xffff;
	}

	printf("Firmware training process is complete!!!\n");
}

void dwc_ddrphy_phyinit_userCustom_J_enterMissionMode(void)
{
	uint32_t  value;
  //// 1. Set the PHY input clocks to the desired frequency.
  //// 2. Initialize the PHY to mission mode by performing DFI Initialization.
  ////	  Please see the DFI specification for more information. See the DFI frequency bus encoding in section <XXX>.
  //// Note: The PHY training firmware initializes the DRAM state. if skip
  //// training is used, the DRAM state is not initialized.
	writel(0xffffffff, DRAMC_IRQMSK);

	value = readl(DRAMC_IRQSTA);
	while (value) {
		value = readl(DRAMC_IRQSTA);
	};

	writel(0x0, DRAMC_DFICFG); // [16] reset=0
	value = readl(DRAMC_MCTL);
	value = value | 0x1;
	writel(value, DRAMC_MCTL); // [0] init_start

	value = readl(DRAMC_IRQSTA);
	while ((value & 0x1) != 1) {
		value = readl(DRAMC_IRQSTA);
	};
	writel(0x1, DRAMC_IRQCLR);

	value = readl(DRAMC_IRQSTA);
	while (value) {
		value = readl(DRAMC_IRQSTA);
	};
}

int dwc_ddrphy_phyinit_userCustom_D_loadIMEM(const int train2D)
{
	uint32_t i;
	uint32_t imem_base = DWC_PHY_IMEM_OFFSET;
	uint32_t src_base, offset;
	uint32_t *src;
	enum boot_mode_type boot_mode;
	int ret = 0;

	printf("%s\n", __func__);

	boot_mode = boot_mode_selection();
	switch (boot_mode) {
	case BOOT_SPI:
		src_base = DWC_PHY_BIN_BASE_SPI;
		offset = 0;
		break;
	case BOOT_EMMC:
		src_base = DWC_PHY_BIN_BASE_SRAM;
		offset = 131072;
		break;
	case BOOT_UFS:
		break;
	default:
		ret = ERR_INVALID_BOOT_TYPE;
		break;
	}

	src = (uint32_t *)(src_base + bin[train2D].imem_base - offset);

	for (i = 0; i < bin[train2D].imem_len / 4; i++)
		writel(*(src + i), (void *)DRAMC_PHY_BASE + 2 * (imem_base + 2 * i));

	return ret;
}

int dwc_ddrphy_phyinit_userCustom_F_loadDMEM(const int pState, const int train2D)
{
	uint32_t i;
	uint32_t dmem_base = DWC_PHY_DMEM_OFFSET;
	uint32_t src_base, offset;
	uint32_t *src;
	enum boot_mode_type boot_mode;
	int ret = 0;

	printf("%s\n", __func__);

	boot_mode = boot_mode_selection();
	switch (boot_mode) {
	case BOOT_SPI:
		src_base = DWC_PHY_BIN_BASE_SPI;
		offset = 0;
		break;
	case BOOT_EMMC:
		src_base = DWC_PHY_BIN_BASE_SRAM;
		offset = 131072;
		break;
	case BOOT_UFS:
		break;
	default:
		ret = ERR_INVALID_BOOT_TYPE;
		break;
	}

	src = (uint32_t *)(src_base + bin[train2D].dmem_base - offset);

	for (i = 0; i < bin[train2D].dmem_len / 4; i++)
		writel(*(src + i), (void *)DRAMC_PHY_BASE + 2 * (dmem_base + 2 * i));

	return ret;
}

void dwc_phy_init(void)
{
#if defined(CONFIG_DDR_PHY_TRAINING)
#if defined(CONFIG_DDR4_TYPE)
#include "dwc_ddrphy_phyinit_ddr4-3200-nodimm-train2D.c"
#elif defined(CONFIG_DDR5_TYPE)
#include "dwc_ddrphy_phyinit_ddr5-3200-nodimm-train2D.c"
#endif
#else
#if defined(CONFIG_DDR4_TYPE)
#include "dwc_ddrphy_phyinit_ddr4-3200-nodimm-skiptrain.c"
#elif defined(CONFIG_DDR5_TYPE)
#include "dwc_ddrphy_phyinit_ddr5-3200-nodimm-skiptrain.c"
#endif
#endif
}
