#ifndef _MMC_H
#define _MMC_H

//#include <drivers/abr.h>
#include <bootdev.h>

/* offset 0x04 */
#define MMC_BOOT_DMA_LENGTH_OFFSET	(9)
#define MMC_BOOT_DMA_UPPER_ADDR_OFFSET	(20)

/* offset 0x08 */
#define MMC_BOOT_DMA_DONE	(0x00000001)
#define MMC_BOOT_ERROR		(0x00000002)

/* offset 0x0C */
#define MMC_BOOT_ENABLE		(0x80000000)
#define MMC_BOOT_WP		(0x40000000)
#define MMC_BOOT_MODE		(0x10000000)
#define MMC_BOOT_CMD0_F0	(0x04000000)
#define MMC_BOOT_CMD0_00	(0x02000000)
#define MMC_BOOT_DMA_START	(0x01000000)

#define DEFAULT_CMD6_TIMEOUT_MS		500

enum {
	MMC_SUCCESS = 0,
	MMC_ERROR = 3,
	MMC_ERR_TIMEOUT,
	MMC_ERR_ADDR_ROLL_BACK,
	MMC_ERR_DUMMY_READ,
};

enum bus_mode {
	MMC_LEGACY,
	MMC_HS,
	SD_HS,
	MMC_HS_52,
	MMC_DDR_52,
	UHS_SDR12,
	UHS_SDR25,
	UHS_SDR50,
	UHS_DDR50,
	UHS_SDR104,
	MMC_HS_200,
	MMC_HS_400,
	MMC_HS_400_ES,
	MMC_MODES_END
};

enum mmc_voltage {
	MMC_SIGNAL_VOLTAGE_000 = 0,
	MMC_SIGNAL_VOLTAGE_120 = 1,
	MMC_SIGNAL_VOLTAGE_180 = 2,
	MMC_SIGNAL_VOLTAGE_330 = 4,
};

enum {
	SDHCI_TRANS_PIO = 0,
	SDHCI_TRANS_SDMA,
	SDHCI_TRANS_ADMA1,
	SDHCI_TRANS_ADMA2,
	SDHCI_TRANS_ADMA2_64,
};

struct mmc_regs {
	union {
		u32 sdma_address;
		u32 blk_cnt_v4;
	};
	u32 blk_size;
	u32 argument;
	u32 command;
	u32 resp[4];
	u32 data_port;
	u32 present;
	u32 host_control_0;
	u32 host_control_1;
	u32 intr_status;
	u32 intr_status_en;
	u32 intr_signal_en;
	u16 acmd12_status;
	u16 host_control_2;
	u32 capability_1;
	u32 capability_2;
	u32 max_capability;
	u32 reserved0;
	u32 force_event;
	u32 adma_status;
	u32 adma_address;
	u32 adma_address_hi;
};

struct mmc_cmd {
	uint32_t cmdidx;
	uint32_t resp_type;
	uint32_t cmdarg;
	uint32_t response[4];
	uint32_t done;
	uint32_t error;
} __aligned(16);

struct mmc_data {
	union {
		char *dest;
		const char *src; /* src buffers don't get written to */
	};
	uint32_t flags;
	uint32_t blocks;
	uint32_t blocksize;
	uint32_t sg_cnt;
	uint32_t done;
	uint32_t bytes_xfered;
	uint32_t error;
} __aligned(16);

#define MMC_DATA_READ		1
#define MMC_DATA_WRITE		2

#define MMC_CMD_GO_IDLE_STATE		0
#define MMC_CMD_SEND_OP_COND		1
#define MMC_CMD_ALL_SEND_CID		2
#define MMC_CMD_SET_RELATIVE_ADDR	3
#define MMC_CMD_SET_DSR			4
#define MMC_CMD_SWITCH			6
#define MMC_CMD_SELECT_CARD		7
#define MMC_CMD_SEND_EXT_CSD		8
#define MMC_CMD_SEND_CSD		9
#define MMC_CMD_SEND_CID		10
#define MMC_CMD_STOP_TRANSMISSION	12
#define MMC_CMD_SEND_STATUS		13
#define MMC_CMD_SET_BLOCKLEN		16
#define MMC_CMD_READ_SINGLE_BLOCK	17
#define MMC_CMD_READ_MULTIPLE_BLOCK 18
#define MMC_CMD_SEND_TUNING_BLOCK		19
#define MMC_CMD_SEND_TUNING_BLOCK_HS200 21
#define MMC_CMD_SET_BLOCK_COUNT			23
#define MMC_CMD_WRITE_SINGLE_BLOCK	24
#define MMC_CMD_WRITE_MULTIPLE_BLOCK	25
#define MMC_CMD_ERASE_GROUP_START	35
#define MMC_CMD_ERASE_GROUP_END		36
#define MMC_CMD_ERASE			38
#define MMC_CMD_APP_CMD			55
#define MMC_CMD_SPI_READ_OCR		58
#define MMC_CMD_SPI_CRC_ON_OFF		59
#define MMC_CMD_RES_MAN			62

#define MMC_CMD62_ARG1			0xefac62ec
#define MMC_CMD62_ARG2			0xcbaea7

#define SD_CMD_SEND_RELATIVE_ADDR	3
#define SD_CMD_SWITCH_FUNC		6
#define SD_CMD_SEND_IF_COND		8
#define SD_CMD_SWITCH_UHS18V		11

#define SD_CMD_APP_SET_BUS_WIDTH	6
#define SD_CMD_APP_SD_STATUS		13
#define SD_CMD_ERASE_WR_BLK_START	32
#define SD_CMD_ERASE_WR_BLK_END		33
#define SD_CMD_APP_SEND_OP_COND		41
#define SD_CMD_APP_SEND_SCR		51

#define MMC_RSP_PRESENT			BIT(0)
#define MMC_RSP_136			BIT(1)		/* 136 bit response */
#define MMC_RSP_CRC			BIT(2)		/* expect valid crc */
#define MMC_RSP_BUSY			BIT(3)		/* card may send busy */
#define MMC_RSP_OPCODE			BIT(4)		/* response contains opcode */

#define MMC_RSP_NONE	(0)
#define MMC_RSP_R1	(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
#define MMC_RSP_R1b	(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE | \
			MMC_RSP_BUSY)
#define MMC_RSP_R2	(MMC_RSP_PRESENT | MMC_RSP_136 | MMC_RSP_CRC)
#define MMC_RSP_R3	(MMC_RSP_PRESENT)
#define MMC_RSP_R4	(MMC_RSP_PRESENT)
#define MMC_RSP_R5	(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
#define MMC_RSP_R6	(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)
#define MMC_RSP_R7	(MMC_RSP_PRESENT | MMC_RSP_CRC | MMC_RSP_OPCODE)

#define MMC_CLK_ENABLE		false
#define MMC_CLK_DISABLE		true

/* SCR definitions in different words */
#define SD_HIGHSPEED_BUSY	0x00020000
#define SD_HIGHSPEED_SUPPORTED	0x00020000

#define UHS_SDR12_BUS_SPEED 0
#define HIGH_SPEED_BUS_SPEED	1
#define UHS_SDR25_BUS_SPEED 1
#define UHS_SDR50_BUS_SPEED 2
#define UHS_SDR104_BUS_SPEED	3
#define UHS_DDR50_BUS_SPEED 4

#define SD_MODE_UHS_SDR12	BIT(UHS_SDR12_BUS_SPEED)
#define SD_MODE_UHS_SDR25	BIT(UHS_SDR25_BUS_SPEED)
#define SD_MODE_UHS_SDR50	BIT(UHS_SDR50_BUS_SPEED)
#define SD_MODE_UHS_SDR104	BIT(UHS_SDR104_BUS_SPEED)
#define SD_MODE_UHS_DDR50	BIT(UHS_DDR50_BUS_SPEED)

#define OCR_BUSY		0x80000000
#define OCR_HCS			0x40000000
#define OCR_S18R		0x1000000
#define OCR_VOLTAGE_MASK	0x007FFF80
#define OCR_ACCESS_MODE		0x60000000

#define MMC_ERASE_ARG		0x00000000
#define MMC_SECURE_ERASE_ARG	0x80000000
#define MMC_TRIM_ARG		0x00000001
#define MMC_DISCARD_ARG		0x00000003
#define MMC_SECURE_TRIM1_ARG	0x80000001
#define MMC_SECURE_TRIM2_ARG	0x80008000

#define MMC_STATUS_MASK		(~0x0206BF7F)
#define MMC_STATUS_SWITCH_ERROR BIT(7)
#define MMC_STATUS_RDY_FOR_DATA BIT(8)
#define MMC_STATUS_CURR_STATE	(0xf << 9)
#define MMC_STATUS_ERROR	BIT(19)

#define MMC_STATE_PRG		(7 << 9)
#define MMC_STATE_TRANS		(4 << 9)

#define MMC_MAX_BLOCK_LEN	512

/* SD/MMC version bits; 8 flags, 8 major, 8 minor, 8 change */
#define SD_VERSION_SD		BIT(31)
#define MMC_VERSION_MMC		BIT(30)

#define MAKE_SDMMC_VERSION(a, b, c) \
	((((u32)(a)) << 16) | ((u32)(b) << 8) | (u32)(c))
#define MAKE_SD_VERSION(a, b, c)	\
	(SD_VERSION_SD | MAKE_SDMMC_VERSION(a, b, c))
#define MAKE_MMC_VERSION(a, b, c)	\
	(MMC_VERSION_MMC | MAKE_SDMMC_VERSION(a, b, c))

#define EXTRACT_SDMMC_MAJOR_VERSION(x)	\
	(((u32)(x) >> 16) & 0xff)
#define EXTRACT_SDMMC_MINOR_VERSION(x)	\
	(((u32)(x) >> 8) & 0xff)
#define EXTRACT_SDMMC_CHANGE_VERSION(x) \
	((u32)(x) & 0xff)

#define SD_VERSION_3		MAKE_SD_VERSION(3, 0, 0)
#define SD_VERSION_2		MAKE_SD_VERSION(2, 0, 0)
#define SD_VERSION_1_0		MAKE_SD_VERSION(1, 0, 0)
#define SD_VERSION_1_10		MAKE_SD_VERSION(1, 10, 0)

#define MMC_VERSION_UNKNOWN MAKE_MMC_VERSION(0, 0, 0)
#define MMC_VERSION_1_2		MAKE_MMC_VERSION(1, 2, 0)
#define MMC_VERSION_1_4		MAKE_MMC_VERSION(1, 4, 0)
#define MMC_VERSION_2_2		MAKE_MMC_VERSION(2, 2, 0)
#define MMC_VERSION_3		MAKE_MMC_VERSION(3, 0, 0)
#define MMC_VERSION_4		MAKE_MMC_VERSION(4, 0, 0)
#define MMC_VERSION_4_1		MAKE_MMC_VERSION(4, 1, 0)
#define MMC_VERSION_4_2		MAKE_MMC_VERSION(4, 2, 0)
#define MMC_VERSION_4_3		MAKE_MMC_VERSION(4, 3, 0)
#define MMC_VERSION_4_4		MAKE_MMC_VERSION(4, 4, 0)
#define MMC_VERSION_4_41	MAKE_MMC_VERSION(4, 4, 1)
#define MMC_VERSION_4_5		MAKE_MMC_VERSION(4, 5, 0)
#define MMC_VERSION_5_0		MAKE_MMC_VERSION(5, 0, 0)
#define MMC_VERSION_5_1		MAKE_MMC_VERSION(5, 1, 0)

#define MMC_CAP(mode)		(1 << (mode))
#define MMC_MODE_HS		(MMC_CAP(MMC_HS) | MMC_CAP(SD_HS))
#define MMC_MODE_HS_52MHz	MMC_CAP(MMC_HS_52)
#define MMC_MODE_DDR_52MHz	MMC_CAP(MMC_DDR_52)
#define MMC_MODE_HS200		MMC_CAP(MMC_HS_200)
#define MMC_MODE_HS400		MMC_CAP(MMC_HS_400)

#define MMC_MODE_8BIT		BIT(30)
#define MMC_MODE_4BIT		BIT(29)
#define MMC_MODE_1BIT		BIT(28)
#define MMC_MODE_SPI		BIT(27)

#define SD_DATA_4BIT	0x00040000

#define IS_SD(x)	((x)->version & SD_VERSION_SD)
#define IS_MMC(x)	((x)->version & MMC_VERSION_MMC)

#define MMC_SWITCH_MODE_CMD_SET		0x00 /* Change the command set */
#define MMC_SWITCH_MODE_SET_BITS	0x01 /* Set bits in EXT_CSD byte addressed by index which are 1 in value field */
#define MMC_SWITCH_MODE_CLEAR_BITS	0x02 /* Clear bits in EXT_CSD byte addressed by index, which are 1 in value field */
#define MMC_SWITCH_MODE_WRITE_BYTE	0x03 /* Set target byte to value */

#define SD_SWITCH_CHECK		0
#define SD_SWITCH_SWITCH	1

/*
 * EXT_CSD fields
 */
#define EXT_CSD_ENH_START_ADDR		136 /* R/W */
#define EXT_CSD_ENH_SIZE_MULT		140 /* R/W */
#define EXT_CSD_GP_SIZE_MULT		143 /* R/W */
#define EXT_CSD_PARTITION_SETTING	155 /* R/W */
#define EXT_CSD_PARTITIONS_ATTRIBUTE	156 /* R/W */
#define EXT_CSD_MAX_ENH_SIZE_MULT	157 /* R */
#define EXT_CSD_PARTITIONING_SUPPORT	160 /* RO */
#define EXT_CSD_RST_N_FUNCTION		162 /* R/W */
#define EXT_CSD_BKOPS_EN		163 /* R/W & R/W/E */
#define EXT_CSD_WR_REL_PARAM		166 /* R */
#define EXT_CSD_WR_REL_SET		167 /* R/W */
#define EXT_CSD_RPMB_MULT		168 /* RO */
#define EXT_CSD_ERASE_GROUP_DEF		175 /* R/W */
#define EXT_CSD_BOOT_BUS_WIDTH		177
#define EXT_CSD_PART_CONF		179 /* R/W */
#define EXT_CSD_BUS_WIDTH		183 /* R/W */
#define EXT_CSD_HS_TIMING		185 /* R/W */
#define EXT_CSD_REV			192 /* RO */
#define EXT_CSD_CARD_TYPE		196 /* RO */
#define EXT_CSD_SEC_CNT			212 /* RO, 4 bytes */
#define EXT_CSD_HC_WP_GRP_SIZE		221 /* RO */
#define EXT_CSD_HC_ERASE_GRP_SIZE	224 /* RO */
#define EXT_CSD_BOOT_MULT		226 /* RO */
#define EXT_CSD_BKOPS_SUPPORT		502 /* RO */

/*
 * EXT_CSD field definitions
 */

#define EXT_CSD_CMD_SET_NORMAL		BIT(0)
#define EXT_CSD_CMD_SET_SECURE		BIT(1)
#define EXT_CSD_CMD_SET_CPSECURE	BIT(2)

#define EXT_CSD_CARD_TYPE_26		BIT(0)	/* Card can run at 26MHz */
#define EXT_CSD_CARD_TYPE_52		BIT(1)	/* Card can run at 52MHz */
#define EXT_CSD_CARD_TYPE_DDR_1_8V	BIT(2)
#define EXT_CSD_CARD_TYPE_DDR_1_2V	BIT(3)
#define EXT_CSD_CARD_TYPE_DDR_52	(EXT_CSD_CARD_TYPE_DDR_1_8V \
					| EXT_CSD_CARD_TYPE_DDR_1_2V)

#define EXT_CSD_CARD_TYPE_HS200_1_8V	BIT(4)	/* Card can run at 200MHz */
						/* SDR mode @1.8V I/O */
#define EXT_CSD_CARD_TYPE_HS200_1_2V	BIT(5)	/* Card can run at 200MHz */
						/* SDR mode @1.2V I/O */
#define EXT_CSD_CARD_TYPE_HS200		(EXT_CSD_CARD_TYPE_HS200_1_8V | \
					 EXT_CSD_CARD_TYPE_HS200_1_2V)
#define EXT_CSD_CARD_TYPE_HS400_1_8V	BIT(6)
#define EXT_CSD_CARD_TYPE_HS400_1_2V	BIT(7)
#define EXT_CSD_CARD_TYPE_HS400		(EXT_CSD_CARD_TYPE_HS400_1_8V | \
					 EXT_CSD_CARD_TYPE_HS400_1_2V)

#define EXT_CSD_BUS_WIDTH_1 0	/* Card is in 1 bit mode */
#define EXT_CSD_BUS_WIDTH_4 1	/* Card is in 4 bit mode */
#define EXT_CSD_BUS_WIDTH_8 2	/* Card is in 8 bit mode */
#define EXT_CSD_DDR_BUS_WIDTH_4 5	/* Card is in 4 bit DDR mode */
#define EXT_CSD_DDR_BUS_WIDTH_8 6	/* Card is in 8 bit DDR mode */
#define EXT_CSD_DDR_FLAG	BIT(2)	/* Flag for DDR mode */

#define EXT_CSD_TIMING_LEGACY	0	/* no high speed */
#define EXT_CSD_TIMING_HS	1	/* HS */
#define EXT_CSD_TIMING_HS200	2	/* HS200 */
#define EXT_CSD_TIMING_HS400	3	/* HS400 */

/************************************************************
 *
 * SDHCI Registers
 *
 ************************************************************/
#define SDHCI_DMA_ADDRESS	0x00
#define SDHCI_ARGUMENT2		SDHCI_DMA_ADDRESS
#define SDHCI_32BIT_BLK_CNT SDHCI_DMA_ADDRESS

#define SDHCI_BLOCK_SIZE	0x04
#define  SDHCI_MAKE_BLKSZ(dma, blksz) ((((dma) & 0x7) << 12) | ((blksz) & 0xFFF))

#define SDHCI_BLOCK_COUNT	0x06

#define SDHCI_ARGUMENT		0x08

#define SDHCI_TRANSFER_MODE 0x0C
#define  SDHCI_TRNS_DMA		BIT(0)
#define  SDHCI_TRNS_BLK_CNT_EN	BIT(1)
#define  SDHCI_TRNS_ACMD12	BIT(2)
#define  SDHCI_TRNS_READ	BIT(4)
#define  SDHCI_TRNS_MULTI	BIT(5)

#define SDHCI_COMMAND		0x0E
#define  SDHCI_CMD_RESP_MASK	0x03
#define  SDHCI_CMD_CRC		0x08
#define  SDHCI_CMD_INDEX	0x10
#define  SDHCI_CMD_DATA		0x20
#define  SDHCI_CMD_ABORTCMD 0xC0
#define SDHCI_COMMAND_SHIFT (16)

#define  SDHCI_CMD_RESP_NONE	0x00
#define  SDHCI_CMD_RESP_LONG	0x01
#define  SDHCI_CMD_RESP_SHORT	0x02
#define  SDHCI_CMD_RESP_SHORT_BUSY 0x03

#define SDHCI_MAKE_CMD(c, f) ((((c) & 0xff) << 8) | ((f) & 0xff))
#define SDHCI_GET_CMD(c) (((c) >> 8) & 0x3f)

#define SDHCI_RESPONSE		0x10

#define SDHCI_BUFFER		0x20

#define SDHCI_PRESENT_STATE 0x24
#define  SDHCI_CMD_INHIBIT	0x00000001
#define  SDHCI_DATA_INHIBIT 0x00000002
#define  SDHCI_DOING_WRITE	0x00000100
#define  SDHCI_DOING_READ	0x00000200
#define  SDHCI_SPACE_AVAILABLE	0x00000400
#define  SDHCI_DATA_AVAILABLE	0x00000800
#define  SDHCI_CARD_PRESENT 0x00010000
#define   SDHCI_CARD_PRES_SHIFT 16
#define  SDHCI_CD_STABLE	0x00020000
#define  SDHCI_CD_LVL		0x00040000
#define   SDHCI_CD_LVL_SHIFT	18
#define  SDHCI_WRITE_PROTECT	0x00080000
#define  SDHCI_DATA_LVL_MASK	0x00F00000
#define   SDHCI_DATA_LVL_SHIFT	20
#define   SDHCI_DATA_0_LVL_MASK 0x00100000
#define  SDHCI_CMD_LVL		0x01000000

#define SDHCI_HOST_CONTROL	0x28
#define  SDHCI_CTRL_LED		0x01
#define  SDHCI_CTRL_4BITBUS 0x02
#define  SDHCI_CTRL_HISPD	0x04
#define  SDHCI_CTRL_DMA_MASK	0x18
#define   SDHCI_CTRL_SDMA	0x00
#define   SDHCI_CTRL_ADMA1	0x08
#define   SDHCI_CTRL_ADMA32 0x10
#define   SDHCI_CTRL_ADMA64 0x18
#define   SDHCI_CTRL_ADMA3	0x18
#define  SDHCI_CTRL_8BITBUS 0x20
#define  SDHCI_CTRL_CDTEST_INS	0x40
#define  SDHCI_CTRL_CDTEST_EN	0x80

#define SDHCI_POWER_CONTROL 0x29
#define  SDHCI_POWER_ON		0x01
#define  SDHCI_POWER_180	0x0A
#define  SDHCI_POWER_300	0x0C
#define  SDHCI_POWER_330	0x0E
#define SDHCI_POWER_CONTROL_SHIFT (8)

#define SDHCI_BLOCK_GAP_CONTROL 0x2A

#define SDHCI_CLOCK_CONTROL 0x2C
#define  SDHCI_DIVIDER_SHIFT	8
#define  SDHCI_DIVIDER_HI_SHIFT 6
#define  SDHCI_DIV_MASK 0xFF
#define  SDHCI_DIV_MASK_LEN 8
#define  SDHCI_DIV_HI_MASK	0x300
#define  SDHCI_PROG_CLOCK_MODE	BIT(5)
#define  SDHCI_CLOCK_CARD_EN	BIT(2)
#define  SDHCI_CLOCK_INT_STABLE BIT(1)
#define  SDHCI_CLOCK_INT_EN BIT(0)

#define SDHCI_SOFTWARE_RESET	0x2F
#define  SDHCI_RESET_ALL	0x01
#define  SDHCI_RESET_CMD	0x02
#define  SDHCI_RESET_DATA	0x04
#define SDHCI_RESET_SHIFT	(24)

#define SDHCI_INT_STATUS	0x30
#define SDHCI_INT_ENABLE	0x34
#define SDHCI_SIGNAL_ENABLE 0x38
#define  SDHCI_INT_RESPONSE BIT(0)
#define  SDHCI_INT_DATA_END BIT(1)
#define  SDHCI_INT_DMA_END	BIT(3)
#define  SDHCI_INT_SPACE_AVAIL	BIT(4)
#define  SDHCI_INT_DATA_AVAIL	BIT(5)
#define  SDHCI_INT_CARD_INSERT	BIT(6)
#define  SDHCI_INT_CARD_REMOVE	BIT(7)
#define  SDHCI_INT_CARD_INT BIT(8)
#define  SDHCI_INT_RETUNE	BIT(12)
#define  SDHCI_INT_ERROR	BIT(15)
#define  SDHCI_INT_TIMEOUT	BIT(16)
#define  SDHCI_INT_CRC		BIT(17)
#define  SDHCI_INT_END_BIT	BIT(18)
#define  SDHCI_INT_INDEX	BIT(19)
#define  SDHCI_INT_DATA_TIMEOUT BIT(20)
#define  SDHCI_INT_DATA_CRC BIT(21)
#define  SDHCI_INT_DATA_END_BIT BIT(22)
#define  SDHCI_INT_BUS_POWER	BIT(23)
#define  SDHCI_INT_ACMD12ERR	BIT(24)
#define  SDHCI_INT_ADMA_ERROR	BIT(25)

#define  SDHCI_INT_NORMAL_MASK	0x00007FFF
#define  SDHCI_INT_ERROR_MASK	0xFFFF8000

#define  SDHCI_INT_CMD_MASK (SDHCI_INT_RESPONSE | SDHCI_INT_TIMEOUT | \
		SDHCI_INT_CRC | SDHCI_INT_END_BIT | SDHCI_INT_INDEX)
#define  SDHCI_INT_DATA_MASK	(SDHCI_INT_DATA_END | SDHCI_INT_DMA_END | \
		SDHCI_INT_DATA_AVAIL | SDHCI_INT_SPACE_AVAIL | \
		SDHCI_INT_DATA_TIMEOUT | SDHCI_INT_DATA_CRC | \
		SDHCI_INT_DATA_END_BIT | SDHCI_INT_ADMA_ERROR)
#define SDHCI_INT_ALL_MASK	((unsigned int)-1)

#define SDHCI_AUTO_CMD_STATUS	0x3C
#define  SDHCI_AUTO_CMD_TIMEOUT 0x00000002
#define  SDHCI_AUTO_CMD_CRC 0x00000004
#define  SDHCI_AUTO_CMD_END_BIT 0x00000008
#define  SDHCI_AUTO_CMD_INDEX	0x00000010
#define  SDHCI_AUTO_TUNE_DONE	0x00800000

#define SDHCI_HOST_CONTROL2		0x3E
#define  SDHCI_CTRL_UHS_MASK		0x0007
#define   SDHCI_CTRL_UHS_SDR12		0x0000
#define   SDHCI_CTRL_UHS_SDR25		0x0001
#define   SDHCI_CTRL_UHS_SDR50		0x0002
#define   SDHCI_CTRL_UHS_SDR104		0x0003
#define   SDHCI_CTRL_UHS_DDR50		0x0004
#define   SDHCI_CTRL_HS400		0x0005 /* Non-standard */
#define  SDHCI_CTRL_VDD_180		0x0008
#define  SDHCI_CTRL_DRV_TYPE_MASK	0x0030
#define   SDHCI_CTRL_DRV_TYPE_B		0x0000
#define   SDHCI_CTRL_DRV_TYPE_A		0x0010
#define   SDHCI_CTRL_DRV_TYPE_C		0x0020
#define   SDHCI_CTRL_DRV_TYPE_D		0x0030
#define  SDHCI_CTRL_EXEC_TUNING		0x0040
#define  SDHCI_CTRL_TUNED_CLK		0x0080
#define  SDHCI_CMD23_ENABLE		0x0800
#define  SDHCI_CTRL_V4_MODE		0x1000
#define  SDHCI_CTRL_64BIT_ADDR		0x2000
#define  SDHCI_CTRL_PRESET_VAL_ENABLE	0x8000

#define SDHCI_ADMA_ADDRESS		0x58
#define SDHCI_ADMA_ADDRESS_HI	0x5C

#define CARD_DETECT_CONTROL_OFFSET	0xF0
#define CLK_PHASE_CONTROL_OFFSET	0xF4
#define INT_STATUS					0xFC

/*
 * Host SDMA buffer boundary. Valid values from 4K to 512K in powers of 2.
 */
#define SDHCI_DEFAULT_BOUNDARY_SIZE (512 * 1024)
#define SDHCI_DEFAULT_BOUNDARY_ARG	(7)

#define SDHCI_MAX_DIV_SPEC_300	2046

void mmc_register(struct bootdev *bd);
#endif
