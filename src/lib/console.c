#include <errno.h>
#include <bootstage.h>
#include <lib/console.h>

struct uart cnsl_uart[1];
struct uart_cfg cnsl_uartcfg;
uint32_t cnsl_init;

int console_getch(char *c)
{
	if (!cnsl_init)
		return -ENODEV;

	return uart_poll_in(cnsl_uart, c);
}

int console_putch(char c)
{
	int rc;

	if (!cnsl_init)
		return -ENODEV;

	if (c == '\n') {
		rc = uart_poll_out(cnsl_uart, '\r');
		if (rc)
			return rc;
	}

	return uart_poll_out(cnsl_uart, c);
}

bootstage_t console_init(void)
{
	bootstage_t sts = { BOOTSTAGE_ERR_SUCCESS, 0 };

	cnsl_uartcfg.divisor = 1,
	cnsl_uartcfg.parity = UART_CFG_PARITY_NONE,
	cnsl_uartcfg.stop_bits = UART_CFG_STOP_BITS_1,
	cnsl_uartcfg.data_bits = UART_CFG_DATA_BITS_8,

	uart_init(CONFIG_SYS_CONSOLE_BASE, cnsl_uart);
	uart_configure(cnsl_uart, &cnsl_uartcfg);

	cnsl_init = 1;

	return sts;
}
