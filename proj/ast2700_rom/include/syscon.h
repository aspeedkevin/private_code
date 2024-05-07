#ifndef __SYSCON_INIT_H__
#define __SYSCON_INIT_H__

#include <rom_context.h>

#define SCU_INIT_ERR_SUCCESS	0
#define SCU_INIT_ERR_FAILED	1

bootstage_t scu_rstlog_init(struct rom_context *rom_ctx);

/**
 * @brief Get EXTRSTN status
 * @return 0 if EXTRSTN de-asserted. Else EXTRSTN is asserted
 */
int scu_rstlog_get_extrstn(void);

#define SCU_PLL_ID_IO_HPLL	0
#define SCU_PLL_ID_IO_APLL	1
#define SCU_PLL_ID_IO_L0PLL	2
#define SCU_PLL_ID_IO_L1PLL	3
#define SCU_PLL_ID_MAX		SCU_PLL_ID_IO_L1PLL
/**
 * @brief Get PLL frequency in Hz
 * @param pll_id - SCU_PLL_ID_*
 * @return PLL frequency in Hz
 */
int scu_get_pll_freq(int pll_id);

/**
 * @brief Set PLL frequency
 * @param pll_id - SCU_PLL_ID_*
 * @param freq - PLL frequency in Hz
 * @return Non-zero value if not successfully set
 */
int scu_set_pll_freq(int pll_id, int freq);

#endif
