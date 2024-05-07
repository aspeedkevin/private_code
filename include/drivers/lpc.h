#ifndef __LPC_H__
#define __LPC_H__

#include <platform.h>
#include <utils.h>

#define LPC0_HICR9	(LPC0_REG + 0x098)
#define LPC1_HICR9	(LPC1_REG + 0x098)
#define	  LPC_UART12_TX_ROUTE	BIT(24)

#endif
