#include <io.h>
#include <errno.h>
#include <debug.h>
#include <drivers/uart.h>

#define UART_POLL_MAX	10000

int uart_reset_fifo(struct uart *uart)
{
	uint32_t fcr;

	if (!uart)
		return -EINVAL;

	fcr = readl(uart->base + UART_FCR) |
	      UART_FCR_TX_RST |
	      UART_FCR_RX_RST |
	      UART_FCR_EN;

	writel(fcr, uart->base + UART_FCR);

	return 0;
}

int uart_configure(struct uart *uart, struct uart_cfg *cfg)
{
	uint8_t lcr = 0;
	uint8_t div_l, div_h;

	if (!uart || !cfg)
		return -EINVAL;

	switch (cfg->parity) {
	case UART_CFG_PARITY_EVEN:
		lcr |= UART_LCR_PARITY_MODE;
		/* fallthrough */
	case UART_CFG_PARITY_ODD:
		lcr |= UART_LCR_PARITY_EN;
		break;
	case UART_CFG_PARITY_NONE:
		break;
	default:
		debug("unknown parity config\n");
		return -EINVAL;
	}

	switch (cfg->stop_bits) {
	case UART_CFG_STOP_BITS_1_5:
		lcr |= UART_LCR_STOP;
		/* fallthrough */
	case UART_CFG_STOP_BITS_1:
		break;
	default:
		debug("unknown stop bits config\n");
		return -EINVAL;
	}

	switch (cfg->data_bits) {
	case UART_CFG_DATA_BITS_5:
	case UART_CFG_DATA_BITS_6:
	case UART_CFG_DATA_BITS_7:
	case UART_CFG_DATA_BITS_8:
		lcr |= ((cfg->data_bits) << UART_LCR_CLS_SHIFT) & UART_LCR_CLS_MASK;
		break;
	default:
		debug("unknown data bits config\n");
		break;
	}

	writel(lcr | UART_LCR_DLAB, uart->base + UART_LCR);

	div_l = cfg->divisor & 0xff;
	div_h = (cfg->divisor >> 8) & 0xff;
	writel(div_l, uart->base + UART_DLL);
	writel(div_h, uart->base + UART_DLH);

	writel(lcr, uart->base + UART_LCR);

	return 0;
}

int uart_poll_in(struct uart *uart, uint8_t *byte)
{
	uint32_t poll_cnt = 0;
	uint32_t sts;

	if (!uart || !byte)
		return -EINVAL;

	do {
		if (poll_cnt++ > UART_POLL_MAX)
			return -ETIMEDOUT;

		sts = readl(uart->base + UART_LSR);
	} while (!(sts & UART_LSR_DR));

	*byte = readl(uart->base + UART_RBR);

	return 0;
}

int uart_poll_in_forever(struct uart *uart, uint8_t *byte)
{
	uint32_t sts;

	if (!uart || !byte)
		return -EINVAL;

	do {
		sts = readl(uart->base + UART_LSR);
	} while (!(sts & UART_LSR_DR));

	*byte = readl(uart->base + UART_RBR);

	return 0;
}

int uart_poll_out(struct uart *uart, uint8_t byte)
{
	uint32_t poll_cnt = 0;
	uint32_t sts;

	if (!uart)
		return -EINVAL;

	do {
		if (poll_cnt++ > UART_POLL_MAX)
			return -ETIMEDOUT;

		sts = readl(uart->base + UART_LSR);
	} while (!(sts & UART_LSR_THRE));

	writel(byte, uart->base + UART_THR);

	return 0;
}

int uart_init(uintptr_t base, struct uart *uart)
{
	int rc;

	if (!uart)
		return -EINVAL;

	uart->base = base;

	rc = uart_reset_fifo(uart);
	if (rc)
		return rc;

	return 0;
}
