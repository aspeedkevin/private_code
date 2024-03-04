#ifndef __SLI_H__
#define __SLI_H__

#include <bootstage.h>
#include <types.h>
#include <utils.h>

#define SLI_INTR_EN		0x10
#define   SLI_INTR_RX_SYNC	BIT(15)
#define   SLI_INTR_RX_TRAIN_PKT	BIT(10)
#define   SLI_INTR_TX_SUSPEND	BIT(4)
#define   SLI_INTR_TX_TRAIN	BIT(3)
#define   SLI_INTR_TX_IDLE	BIT(2)
#define   SLI_INTR_RX_SUSPEND	BIT(1)
#define   SLI_INTR_RX_IDLE	BIT(0)

#define SLI_INTR_STATUS		0x14

#define	SLI_STATUS_PASS		0x00
#define SLI_ERR_UNAVAIL_AST1700	0x01
#define SLI_ERR_UNAVAIL_IO_DIE	0x02
#define SLI_ERR_UNAVAIL_CPU_DIE	0x03

/**
 * @brief initialize the SLI bus for ROM code
 *
 * Since the SLI operates at the default low speed of 25Mhz during ROM
 * execution, this function only needs to check the straps and hardware status.
 * The information is then organized into a private variable, which users can
 * access through the `sli_get_availability` function to obtain this
 * information.
 */
bootstage_t sli_init(void);

/**
 * @brief get the availability of the SLI bus
 * @return the availability. 0: SLI is not unavailable, 1: SLI is available
 */
int sli_get_availability(void);

#endif /* end of "#ifndef __SLI_H__" */
