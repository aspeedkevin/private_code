#ifndef __UART_H__
#define __UART_H__

#include <types.h>
#include <utils.h>

/* UART registers */
#define UART_THR	0x00
#define UART_RBR	0x00
#define UART_DLL	0x00
#define UART_DLH	0x04
#define UART_IER	0x04
#define UART_IIR	0x08
#define UART_FCR	0x08
#define UART_LCR	0x0c
#define UART_MCR	0x10
#define UART_LSR	0x14
#define UART_MSR	0x18

/* UART_FCR */
#define UART_FCR_TX_RST		BIT(2)
#define UART_FCR_RX_RST		BIT(1)
#define UART_FCR_EN		BIT(0)

/* UART_LCR */
#define UART_LCR_DLAB		BIT(7)
#define UART_LCR_PARITY_MODE	BIT(4)
#define UART_LCR_PARITY_EN	BIT(3)
#define UART_LCR_STOP		BIT(2)
#define UART_LCR_CLS_MASK	GENMASK(1, 0)
#define UART_LCR_CLS_SHIFT	0

/* UART_LSR */
#define UART_LSR_TEMT		BIT(6)
#define UART_LSR_THRE		BIT(5)
#define UART_LSR_BI		BIT(4)
#define UART_LSR_FE		BIT(3)
#define UART_LSR_PE		BIT(2)
#define UART_LSR_OE		BIT(1)
#define UART_LSR_DR		BIT(0)

enum uart_cfg_parity {
	UART_CFG_PARITY_NONE,
	UART_CFG_PARITY_ODD,
	UART_CFG_PARITY_EVEN,
};

enum uart_cfg_stop_bits {
	UART_CFG_STOP_BITS_1,
	UART_CFG_STOP_BITS_1_5,
};

enum uart_cfg_data_bits {
	UART_CFG_DATA_BITS_5,
	UART_CFG_DATA_BITS_6,
	UART_CFG_DATA_BITS_7,
	UART_CFG_DATA_BITS_8,
};

struct uart_cfg {
	uint16_t divisor;
	uint8_t parity;
	uint8_t stop_bits;
	uint8_t data_bits;
};

struct uart {
	uintptr_t base;
};

int uart_reset_fifo(struct uart *uart);
int uart_configure(struct uart *uart, struct uart_cfg *cfg);
int uart_poll_in(struct uart *uart, uint8_t *byte);
int uart_poll_in_forever(struct uart *uart, uint8_t *byte);
int uart_poll_out(struct uart *uart, uint8_t byte);
int uart_init(uintptr_t base, struct uart *uart);

#endif
