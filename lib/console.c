#include <errno.h>
#include <bootstage.h>
#include <lib/console.h>

static struct console sys_cnsl;

int console_getch(char *c)
{
	if (!sys_cnsl.getch)
		return -ENODEV;

	return sys_cnsl.getch(c);
}

int console_putch(char c)
{
	if (!sys_cnsl.putch)
		return -ENODEV;

	return sys_cnsl.putch(c);
}

int console_register(struct console *cnsl)
{
	if (!cnsl)
		return -EINVAL;

	if (sys_cnsl.getch || sys_cnsl.putch)
		return -EBUSY;

	sys_cnsl.getch = cnsl->getch;
	sys_cnsl.putch = cnsl->putch;

	return 0;
}
