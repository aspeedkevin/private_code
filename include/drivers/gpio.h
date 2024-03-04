/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2023 ASPEED Technology Inc.
 */
#ifndef __GPIO_H__
#define __GPIO_H__

#define GPIO_PORT_A		0
#define GPIO_PORT_B		1
#define GPIO_PORT_C		2
#define GPIO_PORT_D		3
#define GPIO_PORT_E		4
#define GPIO_PORT_F		5
#define GPIO_PORT_G		6
#define GPIO_PORT_H		7
#define GPIO_PORT_I		8
#define GPIO_PORT_J		9
#define GPIO_PORT_K		10
#define GPIO_PORT_L		11
#define GPIO_PORT_M		12
#define GPIO_PORT_N		13
#define GPIO_PORT_O		14
#define GPIO_PORT_P		15
#define GPIO_PORT_Q		16
#define GPIO_PORT_R		17
#define GPIO_PORT_S		18
#define GPIO_PORT_T		19
#define GPIO_PORT_U		20
#define GPIO_PORT_V		21
#define GPIO_PORT_W		22
#define GPIO_PORT_X		23
#define GPIO_PORT_Y		24
#define GPIO_PORT_Z		25
#define GPIO_PORT_AA		26
#define GPIO_PORT_AB		27
#define GPIO_PORT_AC		28

/* number of pins in a port */
#define N_PINS			8
/* size of a pin register in bytes */
#define PIN_REG_SZ		4
/* size of the global control registers in bytes */
#define GPIO_GLOBAL_SZ		0x180

/*
 * This macro returns the address offset of a specific pin. The actual address
 * of the pin control register is "gpio_reg_base + offset".
 *
 * For example, assuming gpio_reg_base is 0x14c0b000, the actual register
 * address of GPIOA5 would be (0x14c0b000 + GPIO(A, 5)).
 */
#define GPIO(port, pin_index)	\
	(GPIO_GLOBAL_SZ + (PIN_REG_SZ * ((GPIO_PORT_##port * N_PINS) + (pin_index))))

/* bitfield of the pin register */
#define GPIO_DATA_IN		BIT(13)	/* data in */
#define GPIO_BLINK_2		BIT(11)
#define GPIO_BLINK_1		BIT(10)
#define GPIO_IN_MASK		BIT(9)
#define GPIO_DEB2		BIT(8)
#define GPIO_DEB1		BIT(7)
#define GPIO_RST_TOL		BIT(6)
#define GPIO_INT_T2		BIT(5)
#define GPIO_INT_T1		BIT(4)
#define GPIO_INT_T0		BIT(3)
#define GPIO_INT_EN		BIT(2)
#define GPIO_DIRECT		BIT(1)
#define   GPIO_DIRECT_IN	0b0
#define   GPIO_DIRECT_OUT	0b1
#define GPIO_DATA		BIT(0)	/* data out */

#endif /* end of "ifndef __GPIO_H__" */
