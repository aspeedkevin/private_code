#ifndef __ABR_H__
#define __ABR_H__

#include <rom_context.h>
#include <types.h>
#include <utils.h>

#define ABR_FMC_CS_SWAP		BIT(0)
#define ABR_INDICATOR		BIT(1)
#define ABR_EXT_SIGNAL_EN	BIT(2)
#define ABR_INFO_CLR		0xea000000

struct abr {
	/* common */
	uint32_t enabled;
	uint32_t boot_indicator;
	uint32_t wdta_triggered;
	uint32_t abr_rc_dis;

	/* spi dedicate */
	uint32_t single;
	uint32_t auxpin_enabled;
	uint32_t auxpin_val;
	uint32_t boot_cs;
	uint32_t cs_swap;
};

struct abr *abr_create(struct rom_context *rc);
#endif
