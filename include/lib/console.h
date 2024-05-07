#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <types.h>

struct console {
	int (*getch)(char *c);
	int (*putch)(char c);
};

int console_getch(char *c);
int console_putch(char c);
int console_register(struct console *cnsl);

#endif
