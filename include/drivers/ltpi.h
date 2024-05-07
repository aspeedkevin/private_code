#ifndef __LTPI_H__
#define __LTPI_H__

#include <bootstage.h>
#include <rom_context.h>
#include <types.h>

/* bootstage_t->errno */
#define LTPI_STATUS_EXIT			BIT(7)	/* 1: exit due to errors */
#define LTPI_STATUS_RESTART			BIT(6)	/* 1: restart LTPI initialization */

#define LTPI_STATUS_HAS_CRC_ERR			BIT(4)
#define LTPI_STATUS_MODE			GENMASK(3, 2)	/* PHY mode */
#define LTPI_STATUS_IDX				BIT(1)	/* 1: LTPI1 */
#define LTPI_STATUS_HPM				BIT(0)	/* 1: LTPI controller is on HPM */

/* bootstage_t->syndrome */
#define LTPI_SYND_OK				0
#define LTPI_SYND_OK_ALREADY_INIT		1
#define LTPI_SYND_NO_COMMOM_SPEED		2
#define LTPI_SYND_WAIT_OP_TO			3
#define LTPI_SYND_EXTRST_LINK_TRAINING		4	/* EXTRST deasserted during link training */
#define LTPI_SYND_EXTRST_LINK_CONFIG		5	/* EXTRST deasserted during link configuration */

/* LTPI wait state return code */
#define LTPI_ERR_NONE				0x00
#define LTPI_ERR_TIMEOUT			0x10
#define LTPI_ERR_DISCON				0x20

/**
 * @brief initialize the LTPI bus according to straps
 */
bootstage_t ltpi_init(struct rom_context *rom_ctx);
#endif	/* #ifndef __LTPI_H__ */
