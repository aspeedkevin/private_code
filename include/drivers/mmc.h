/* SPDX-License-Identifier: GPL-2.0+  */
#ifndef _MMC_H
#define _MMC_H

#include <drivers/abr.h>

/* offset 0x04 */
#define MMC_BOOT_DMA_LENGTH_OFFSET		(9)
#define MMC_BOOT_DMA_UPPER_ADDR_OFFSET	(20)

/* offset 0x08 */
#define MMC_BOOT_DMA_DONE	(0x00000001)
#define MMC_BOOT_ERROR		(0x00000002)

/* offset 0x0C */
#define MMC_BOOT_ENABLE		(0x80000000)
#define MMC_BOOT_WP			(0x40000000)
#define MMC_BOOT_MODE		(0x10000000)
#define MMC_BOOT_CMD0_F0	(0x04000000)
#define MMC_BOOT_CMD0_00	(0x02000000)
#define MMC_BOOT_DMA_START	(0x01000000)

struct mmc_boot_regs {
	uint32_t dma_address;
	uint32_t dma_length;
	uint32_t intr;
	uint32_t control;
};

struct mmc {
	struct mmc_boot_regs *boot_regs;
};

int mmc_boot_start(uint32_t wdta_triggered, uint32_t boot_indicator);
void mmc_bring_to_default(void);
int mmc_boot_read(uint64_t dma_addr, uint32_t dma_len);
void mmc_boot_copy(void);
#endif
