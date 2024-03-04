/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2012-2015, The Regents of the University of California (Regents).
 * All Rights Reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Regents nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
 * SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
 * OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
 * HEREUNDER IS PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE
 * MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

#ifndef RISCV_CSR_ENCODING_H
#define RISCV_CSR_ENCODING_H

#ifndef __ASSEMBLER__

#ifdef __GNUC__

#define read_csr(reg) ({ unsigned long __tmp; \
	__asm__ volatile ("csrr %0, " #reg : "=r"(__tmp)); \
	__tmp; })

#define write_csr(reg, val) ({ \
	__asm__ volatile ("csrw " #reg ", %0" :: "rK"(val)); })

#define swap_csr(reg, val) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "rK"(val)); \
	__tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
	__tmp; })

#define clear_csr(reg, bit) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
	__tmp; })

#define rdtime() read_csr(time)
#define rdcycle() read_csr(cycle)
#define rdinstret() read_csr(instret)

#endif

#endif

#endif
