#ifndef __SLI_H__
#define __SLI_H__

#include <bootstage.h>
#include <rom_context.h>
#include <types.h>
#include <utils.h>

#define SLI_CTRL_I			0x0
#define   SLI_ALL_IN_SUSPEND		BIT(28)
#define   SLI_AUTO_CLR_OFF_DAT		BIT(23)	/* No auto-clear when changing data pad delay */
#define   SLI_AUTO_CLR_OFF_CLK		BIT(22)	/* No auto-clear when changing clock pad delay */
#define   SLI_SP_DOWN_PERIOD		GENMASK(21, 20)
#define   SLI_NO_RST_TXCLK_CHG		BIT(17)	/* No reset when changing TX clock */
#define   SLI_PHY_LAH_SEL_REV		BIT(13)	/* Reverse latch clock */
#define   SLI_PHY_LAH_SEL_SWAP		BIT(12)	/* postive/negative data swapping */
#define   SLI_AUTO_SP_DOWN_OFF		BIT(11)
#define   SLI_ERR_HANDLER_OFF		BIT(10)
#define   SLI_AUTO_SEND_ACK_OFF		BIT(9)
#define   SLI_AUTO_SEND_TRN_OFF		BIT(8)
#define   SLI_CLEAR_BUS			BIT(6)
#define   SLI_SW_RESET			BIT(4)
#define   SLI_P_RESET			BIT(3)
#define   SLI_CLEAR_RX			BIT(2)
#define   SLI_CLEAR_TX			BIT(1)
#define   SLI_RESET			BIT(0)

#define SLI_CTRL_II			0x4
#define   SLIV_TX_ENT_SUSPEND		GENMASK(15, 14)
#define SLI_CTRL_III			0x8
#define   SLI_CLK_SEL			GENMASK(31, 28)	/* Controller core clock */
#define     SLI_CLK_SEL_25M		0x0
#define     SLI_CLK_SEL_800M		0x1
#define     SLI_CLK_SEL_400M		0x2
#define     SLI_CLK_SEL_200M		0x3
#define     SLI_CLK_SEL_2G		0x4
#define     SLI_CLK_SEL_1G		0x5
#define     SLI_CLK_SEL_500M		0x6
#define     SLI_CLK_SEL_250M		0x7
#define   SLI_PHY_CLK_SEL		GENMASK(27, 24)	/* PHY clock */
#define     SLI_PHY_CLK_SEL_25M		0x0
#define     SLI_PHY_CLK_SEL_800M	0x1
#define     SLI_PHY_CLK_SEL_400M	0x2
#define     SLI_PHY_CLK_SEL_200M	0x3
#define     SLI_PHY_CLK_SEL_1G		0x5
#define     SLI_PHY_CLK_SEL_500M	0x6
#define     SLI_PHY_CLK_SEL_250M	0x7
#define   SLIH_PAD_DLY_TX1		GENMASK(23, 18)
#define   SLIH_PAD_DLY_TX0		GENMASK(17, 12)
#define   SLIH_PAD_DLY_RX1		GENMASK(11, 6)
#define   SLIH_PAD_DLY_RX0		GENMASK(5, 0)

#define   SLIM_PAD_DLY_RX3		GENMASK(23, 18)
#define   SLIM_PAD_DLY_RX2		GENMASK(17, 12)
#define   SLIM_PAD_DLY_RX1		GENMASK(11, 6)
#define   SLIM_PAD_DLY_RX0		GENMASK(5, 0)

#define   SLIV_PAD_DLY_TX1		GENMASK(23, 18)
#define   SLIV_PAD_DLY_TX0		GENMASK(17, 12)
#define   SLIV_PAD_DLY_RX1		GENMASK(11, 6)
#define   SLIV_PAD_DLY_RX0		GENMASK(5, 0)

#define SLI_CTRL_IV			0xc
#define   SLIH_CLK_INV_TX		BIT(11)
#define   SLIH_CLK_DLY_TX		GENMASK(10, 6)
#define   SLIH_CLK_INV_RX		BIT(5)
#define   SLIH_CLK_DLY_RX		GENMASK(4, 0)

#define   SLIM_PAD_DLY_TX3		GENMASK(23, 18)
#define   SLIM_PAD_DLY_TX2		GENMASK(17, 12)
#define   SLIM_PAD_DLY_TX1		GENMASK(11, 6)
#define   SLIM_PAD_DLY_TX0		GENMASK(5, 0)

#define SLI_INTR_EN			0x10
#define SLI_INTR_STATUS			0x14
#define   SLI_INTR_RX_SYNC		BIT(15)
#define   SLI_INTR_RX_TRAIN_PKT		BIT(10)
#define   SLI_INTR_TX_SUSPEND		BIT(4)
#define   SLI_INTR_TX_TRAIN		BIT(3)
#define   SLI_INTR_TX_IDLE		BIT(2)
#define   SLI_INTR_RX_SUSPEND		BIT(1)
#define   SLI_INTR_RX_IDLE		BIT(0)

/* bootstage_t->errno */
#define	SLI_STATUS_OK			0x00
#define	SLI_STATUS_ERR			BIT(7)
#define	SLI_STATUS_NA			BIT(6)	/* Not Applicable */
#define SLI_SPEED_HI_IO			BIT(5)
#define SLI_SPEED_HI_CPU		BIT(4)

#define SLI_BUS_ID			GENMASK(2, 0)
#define   SLI_BUS_ID_GENERIC		0
#define   SLI_BUS_ID_AHB_IO		1
#define   SLI_BUS_ID_AHB_CPU		2
#define   SLI_BUS_ID_MEM_IO		3
#define   SLI_BUS_ID_MEM_CPU		4
#define   SLI_BUS_ID_VDO_IO		5
#define   SLI_BUS_ID_VDO_CPU		6

/* bootstage_t->syndrome */
#define SLI_WAIT_SUSPEND_TIMEOUT	0
#define SLI_READ_OTP_FAIL		1
#define SLI_WAIT_TRAIN_PKT_TIMEOUT	2
#define SLI_WAIT_BUS_CLEAR_TIMEOUT	3
#define SLI_WAIT_BUS_RESET_TIMEOUT	4

/**
 * @brief initialize the SLI bus for ROM code
 *
 * Since the SLI operates at the default low speed of 25Mhz during ROM
 * execution, this function only needs to check the straps and hardware status.
 * The information is then organized into a private variable, which users can
 * access through the `sli_get_availability` function to obtain this
 * information.
 */
bootstage_t sli_init(struct rom_context *rom_ctx);

/**
 * @brief get the availability of the SLI bus
 * @return the availability. 0: SLI is not available, 1: SLI is available
 */
int sli_get_availability(void);

#endif /* end of "#ifndef __SLI_H__" */
