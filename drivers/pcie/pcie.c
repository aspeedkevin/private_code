// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */

#include <io.h>
#include <debug.h>
#include <printf.h>
#include <platform.h>
#include <util_macro.h>
#include <drivers/scu.h>

// for SCU_CPU_VGAx_SAR0
 //[4:0] Frame buffer decode size
 // 0 would not decode
 // 1 decode 4KB
 // 2 decode 8KB
 // ...
 // E decode 32MB (Framebuffer support size)
 // F decode 64MB (Framebuffer support size)
#define VGA_FB_SIZE	GENMASK(4, 0)
 //[31:8] memory base [35:12]
#define VGA_FB_BASE	GENMASK(31, 8)

#define SCU_PCI_MISC70			(SCU_CPU_REG + 0xa70)
#define SCU_PCI_MISCF0			(SCU_CPU_REG + 0xaf0)

#if defined(CONFIG_FPGA)
#define DRAM_SIZE	0x20000000
#else
#if defined(CONFIG_DDR4_16G)
#define DRAM_SIZE	0x400000000
#elif defined(CONFIG_DDR4_8G)
#define DRAM_SIZE	0x200000000
#elif defined(CONFIG_DDR4_4G)
#define DRAM_SIZE	0x100000000
#else
#define DRAM_SIZE	0x80000000
#endif	// CONFIG_DDR4_xxG
#endif	// CONFIG_FPGA

int pcie_init(void)
{
	uint32_t val;
	uint64_t vram_base;
	uint32_t vram_size;
	bool is_pcie0_enable = !(readl(SCU_PCI_MISC70) & BIT(0));
	bool is_pcie1_enable = !(readl(SCU_PCI_MISCF0) & BIT(0));

	//printf("PCIE_ENABLE(%d %d) a70(%#x) af0(%#x)\n", is_pcie0_enable, is_pcie1_enable);
	//printf("macro DRAM size(%#x) VRAM size(%#x)\n",
	//	DRAM_SIZE, VRAM_SIZE);
	vram_base = DRAM_SIZE;

	if (is_pcie0_enable || is_pcie1_enable)
		clrbits(SCU_CPU_CLK_CTRL, SCU_CPU_CLK_CTRL_BCLK);

	if (is_pcie0_enable) {
		writel(0x800254, PCIE0_CPU_REG + 0x60);
		writel(0x11501a02, PCIE0_CPU_REG);

		// A0: Fix 32MB
		// TODO: A1 Check OTP to decide 32 or 64MB
		val = 0xe;
		vram_size = 2 << (val + 10);

		vram_base -= vram_size;
		val = (vram_base >> 4) | FIELD_PREP(VGA_FB_SIZE, val);
		//printf("pcie0 debug reg(%#x)\n", val);
		writel(val, E2M_CPU_REG + 0x100);
		writel(val, SCU_CPU_VGA0_SAR0);
	}

	if (is_pcie1_enable) {
		writel(0x800254, PCIE1_CPU_REG + 0x60);
		writel(0x11501a02, PCIE1_CPU_REG);

		// A0: Fix 32MB
		// TODO: A1 Check OTP to decide 32 or 64MB
		val = 0xe;
		vram_size = 2 << (val + 10);

		vram_base -= vram_size;
		val = (vram_base >> 4) | FIELD_PREP(VGA_FB_SIZE, val);
		//printf("pcie1 debug reg(%#x)\n", val);
		writel(val, E2M_CPU_REG + 0x104);
		writel(val, SCU_CPU_VGA1_SAR0);
	}

	return 0;
}
