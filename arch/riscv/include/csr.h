#ifndef __RISCV_CSR_H__
#define __RISCV_CSR_H__

/* mstatus */
#define MSTATUS_MIE	BIT(3)

/*
 * mcause[31]: 0 -> synchronus exception
 *             1 -> asynchronous exception, aka interrupt
 * mcause[0:31]: exception code
 */
#define MCAUSE_INTERRUPT	BIT(31)
#define MCAUSE_CODE		GENMASK(30, 0)
#define   MCAUSE_CODE_MTI	7

/* mie */
#define MIE_MEI	BIT(11)
#define MIE_MTI	BIT(7)
#define MIE_MSI	BIT(3)

/* mip */
#define MIP_MEI	BIT(11)
#define MIP_MTI	BIT(7)
#define MIP_MSI	BIT(3)

/* convenient macro to access CSR */
#define csr_read(reg) ({ unsigned long __tmp; \
	__asm__ volatile ("csrr %0, " #reg : "=r"(__tmp)); \
	__tmp; })

#define csr_write(reg, val) ({ \
	__asm__ volatile ("csrw " #reg ", %0" :: "rK"(val)); })

#define csr_swap(reg, val) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "rK"(val)); \
	__tmp; })

#define csr_set(reg, bit) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
	__tmp; })

#define csr_clear(reg, bit) ({ unsigned long __tmp; \
	__asm__ volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
	__tmp; })

#endif
