#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <types.h>

struct exception_callback {
	int (*cb)(void *cb_arg, uint32_t *mepc);
	void *cb_arg;
};

int exception_callback_register(uint32_t code, int (*cb)(void *cb_arg, uint32_t *epc), void *cb_arg);
int exception_callback_deregister(uint32_t code);

#endif
