#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <bootstage.h>
#include <drivers/uart.h>
#include <types.h>

int console_getch(char *c);
int console_putch(char c);
bootstage_t console_init(void);

#endif
