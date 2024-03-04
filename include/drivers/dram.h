#ifndef __DRAM_H__
#define __DRAM_H__

#include <io.h>
#include <debug.h>
#include <printf.h>
#include <platform.h>
#include <util_macro.h>

#define dwc_ddrphy_apb_wr(addr, value)		(*(volatile unsigned short *)(DRAMC_PHY_BASE + 2 * (addr)) = (unsigned short)value)
#define dwc_ddrphy_apb_rd(addr)			(*(volatile unsigned short *)(DRAMC_PHY_BASE + 2 * (addr)))

#define dwc_ddrphy_apb_wr_32b(addr, value)	(*((volatile unsigned int *)(DRAMC_PHY_BASE + 2 * (addr))) = (unsigned int)value)
#define dwc_ddrphy_apb_rd_32b(addr)		(*(volatile unsigned int *)(DRAMC_PHY_BASE + 2 * (addr)))

void dramc_ecc_enable(uint32_t prot_size);
void dramc_ecc_disable(void);
void dramc_aes_enable(uint32_t addr, uint32_t size);
void dramc_aes_disable(void);
int dramc_bist(uintptr_t addr, uint32_t size, uint32_t cfg, uint32_t timeout);
int dram_init(void);
void dwc_phy_init(void);

#endif
