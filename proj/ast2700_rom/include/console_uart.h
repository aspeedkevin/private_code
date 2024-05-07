#ifndef __CONSOLE_UART_H__
#define __CONSOLE_UART_H__

#include <bootstage.h>
#include <rom_context.h>

bootstage_t console_uart_init(struct rom_context *rom_ctx);

#endif
