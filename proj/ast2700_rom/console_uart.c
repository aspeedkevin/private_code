#include <console_uart.h>
#include <drivers/uart.h>
#include <drivers/usb.h>
#include <lib/console.h>

static struct uart_cfg cnsl_uartcfg[1];
static struct uart cnsl_uart[1];

static int console_uart_getch(char *c)
{
	return uart_poll_in(cnsl_uart, c);
}

static int console_uart_putch(char c)
{
	int rc;

	if (c == '\n') {
		rc = uart_poll_out(cnsl_uart, '\r');
		if (rc)
			return rc;
	}

	return uart_poll_out(cnsl_uart, c);
}

static int console_uart_putch_forever(char c)
{
	int rc;

	if (c == '\n') {
		rc = uart_poll_out_forever(cnsl_uart, '\r');
		if (rc)
			return rc;
	}

	return uart_poll_out_forever(cnsl_uart, c);
}

bootstage_t console_uart_init(struct rom_context *rom_ctx)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	struct console cnsl;

	cnsl_uartcfg->divisor = 1,
	cnsl_uartcfg->parity = UART_CFG_PARITY_NONE,
	cnsl_uartcfg->stop_bits = UART_CFG_STOP_BITS_1,
	cnsl_uartcfg->data_bits = UART_CFG_DATA_BITS_8,

	uart_init(rom_ctx->cnsl_base, cnsl_uart);
	uart_configure(cnsl_uart, cnsl_uartcfg);

	cnsl.getch = console_uart_getch;
	if (usb2uart_put_all_msg())
		cnsl.putch = console_uart_putch_forever;
	else
		cnsl.putch = console_uart_putch;
	console_register(&cnsl);

	return sts;
}
