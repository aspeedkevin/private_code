#include <platform.h>

.global lowlevel_init
lowlevel_init:
	li	t0, SRAM_REG
	li	t1, 0xffff
	sw	t1, 0(t0)

	/* check Dis_ROM by SCU1_010[22] */
	li	t0, SCU1_REG
	lw	t0, 16(t0)
	li	t1, (0x1 << 22)
	and	t0, t0, t1
	beqz	t0, 1f

	/* copy SRAM code */
	li	t0, FMC_MEM_L
	li	t1, CONFIG_RAM_CODE_LOAD_ADDR
	li	t2, CONFIG_RAM_CODE_LOAD_SIZE
	add	t2, t2, t1

copy_sram_loop:
	lw	t3, 0(t0)
	sw	t3, 0(t1)
	addi	t0, t0, 4
	addi	t1, t1, 4
	blt	t1, t2, copy_sram_loop

copy_sram_done:
	/* jump to SRAM code */
	li	t0, CONFIG_RAM_CODE_ENTRY_ADDR
	jr	0(t0)

1:
	ret
