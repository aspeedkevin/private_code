.option norvc
.option norelax

.section .vectors, "ax"
.balignl 256, 0x0

/* trap vector table */
.global _vector_table
_vector_table:
.rept 32
j	_exception_handler
.endr
.size _vector_table, .-_vector_table

/* entry point after reset de-assertion */
.global _start
_start:
	/* disable interrupts globally */
	csrci	mstatus, 0x8

	/* setup vector table with vectored mode setting */
	la	t0, (_vector_table + 1)
	csrw	mtvec, t0

	/* do early platform init. */
	jal	lowlevel_init

	/* setup stack */
	li	t0, CONFIG_SYS_INIT_STACK_ADDR
	li	t1, CONFIG_SYS_MALLOC_LEN
	sub	sp, t0, t1

	/* clear .bss */
	la	t0, __bss_start
	la	t1, __bss_end
	beq	t0, t1, clear_bss_done

clear_bss_loop:
	sw	zero, 0(t0)
	addi	t0, t0, 4
	blt	t0, t1, clear_bss_loop

clear_bss_done:
	/* copy .data to writable area */
	la	t0, __data_lma
	la	t1, __data_vma_start
	la	t2, __data_vma_end
	beq	t0, t1, copy_data_done

copy_data_loop:
	lw	t3, 0(t0)
	sw	t3, 0(t1)
	addi	t0, t0, 4
	addi	t1, t1, 4
	blt	t1, t2, copy_data_loop

copy_data_done:
	/* jump to C code */
	jal	main

	/* should never reach */
_exception_handler:
wfi_loop:
	wfi
	j	wfi_loop

.weak lowlevel_init
lowlevel_init:
	/* do nothing */
	ret
