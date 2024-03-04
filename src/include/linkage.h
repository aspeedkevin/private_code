/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) Aspeed Technology
 */

#ifndef __LINKAGE_H__
#define __LINKAGE_H__

#include <linux/linkage.h>

#define ALIGN			__ALIGN
#define ALIGN_STR		__ALIGN_STR

#define LENTRY(name) \
	ALIGN ASM_NL \
	SYMBOL_NAME_LABEL(name)

#define ENTRY(name) \
	.globl SYMBOL_NAME(name) ASM_NL \
	LENTRY(name)

#define WEAK(name) \
	.weak SYMBOL_NAME(name) ASM_NL \
	LENTRY(name)

#define END(name) \
	.size name, .-name

#define ENDPROC(name) \
	.type name STT_FUNC ASM_NL \
	END(name)

#endif
