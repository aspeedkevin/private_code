#ifndef __I2C_H__
#define __I2C_H__

#include <types.h>
#include <utils.h>
#include <bootdev.h>

struct i2c_hci {
	u32 index;
	u16 slave_addr_disable;
	u16 slave_addr_enable;
	void *global_regs;
	void *base_regs;
	u32 irq_status;
};

/* global register */
#define I2CG_MIRQ		0x00
#define I2CG_SIRQ		0x04
#define I2CG_CTRL		0x0C

#define I2CG_CTRL_NEW_REG	BIT(2)
#define I2CG_CTRL_NEW_CLK_DIV	BIT(1)

#define I2CG_AC_CTRL		0x10
#define I2CG_FIFO_CFG0		0x14
#define I2CG_FIFO_CFG1		0x18
#define I2C_FIFO_DEFAULT	0x66666666

#define I2C_MULTI_FUN1		0x11
#define I2C_MULTI_FUN2		0x22

/* 0x00 : I2CC Master/Slave Function Control Register  */
#define I2CC_FUN_CTRL		0x00
#define I2CC_SLAVE_EN		BIT(1)

/* 0x04 : I2CC Master/Slave Clock and AC Timing Control Register #1 */
#define I2CC_AC_TIMING		0x04
#define I2CC_AC_VAL		0x344063 /* Real */

/* 0x20 : I2CS Slave Interrupt Control Register   */
#define I2CS_IER			0x20
/* 0x24 : I2CS Slave Interrupt Status Register	 */
#define I2CS_ISR			0x24

#define I2CS_WAIT_TX		BIT(25)
#define I2CS_RX_STOP		BIT(4)
#define I2CS_RX_DONE		BIT(2)

/* 0x28 : I2CS Slave CMD/Status Register   */
#define I2CS_CMD_STS		0x28
#define I2CS_PKT_MODE_EN	BIT(16)
#define I2CS_RX_DMA_EN		BIT(9)
#define I2CS_AUTO_NAK	(BIT(24) | BIT(25))
#define I2CS_FIRE_CMD (I2CS_AUTO_NAK | I2CS_PKT_MODE_EN | I2CS_RX_DMA_EN)

/* 0x2C : I2CS DMA Length   */
#define I2CS_DMA_LEN		0x2C
#define I2CS_DMA_RX_LEN_SET		0x1030000

/* I2CS Slave DMA Rx Buffer Register   */
#define I2CS_RX_DMA			0x3C
/* I2CS Slave DMA Rx Buffer Register   */
#define I2CS_RX_DMA_H		0x6C

/* 0x40 : I2CS Address 1  */
#define I2CS_ADDR_1		0x40
#define I2CS_EN_ADDR		0xEAE9
#define I2CS_DIS_ADDR		0x6A69
#define I2CS_ENABLE_ADDR0	0x80

/* 0x40 : I2CS Address 2  */
#define I2CS_ADDR_2		0x44

/* 0x4C : I2CS lebgth   */
#define I2CS_LENGTH		0x4C

#define I2C_BUFFER_SIZE 260 /* over 255 for one single interrupt */

#define I2C_REG(x)      (0x14c0f000 + 0x100 * (x))

#define i2c_reg_read(r)		readl(hci->base_regs + (r))
#define i2c_reg_write(r, v)		writel(v, hci->base_regs + (r))
#define i2c_g_reg_write(r, v)		writel(v, hci->global_regs + (r))

void i2c_register(struct bootdev *bd);
#endif
