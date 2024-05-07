#ifndef __SPI_H__
#define __SPI_H__

//#include <drivers/abr.h>
#include <types.h>
#include <utils.h>
#include <bootdev.h>

#define SNOR_SZ_UNSET		0x0
#define SNOR_SZ_8MB		0x800000
#define SNOR_SZ_16MB		0x1000000
#define SNOR_SZ_32MB		0x2000000
#define SNOR_SZ_64MB		0x4000000
#define SNOR_SZ_128MB		0x8000000
#define SNOR_SZ_256MB		0x10000000
#define SNOR_SZ_512MB		0x20000000


/* FMC REG OFFSET */
#define ADDR_CTRL		(0x04)
#define ADDR_DATA_CTRL		(0x0C)
#define CE0_CTRL		(0x10)
#define   FMC_CLK_FREQ_MASK	(0x0f000f00)
#define   CS_STOP_ACTIVE	(BIT(2))
#define   USER_MODE		(0x3)
#define CE0_ADDR_DECODING	(0x30)
#define CS_SWAP_CRTL		(0xA0)
#define   CS_SWAP_BY_WDT	(BIT(0))
#define FMC_RST_WLOCK1		(0x1f4)
#define   CS_SWAP_CTRL_RST_LOCK	(BIT(31))

/* SPI error code */
#define ERROR_INVALID_FLASH_SZ	0x1
#define ERROR_INVALID_DST_PTR	0x2

#define SNOR_SFDP_MAGIC		0x50444653 /* 0x50444653 is "SFDP" ASCII */

struct decoding_range {
	uint32_t start_addr;
	uint32_t end_addr;
};

void spi_register(struct bootdev *bd);

#endif
