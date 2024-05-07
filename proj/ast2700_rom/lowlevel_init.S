#include <csr.h>
#include <drivers/scu.h>
#include <platform.h>

.global lowlevel_init
lowlevel_init:
	li	t0, SRAM_REG
	li	t1, 0xffff
	sw	t1, 0(t0)

	/* check Dis_ROM by SCU1_010[22] */
	li	t0, SCU1_HWSTRAP1
	lw	t0, (t0)
	li	t1, SCU1_HWSTRAP1_DIS_ROM
	and	t0, t0, t1
	beqz	t0, 1f

	/* copy SRAM code */
	li	t0, FMC_MEM_L
	li	t1, CONFIG_FMC_LOAD_ADDR
	li	t2, CONFIG_FMC_LOAD_SIZE
	add	t2, t2, t1

copy_sram_loop:
	lw	t3, 0(t0)
	sw	t3, 0(t1)
	addi	t0, t0, 4
	addi	t1, t1, 4
	blt	t1, t2, copy_sram_loop

copy_sram_done:
	/* jump to SRAM code */
	li	t0, CONFIG_FMC_ENTRY_ADDR
	jr	0(t0)

1:
	li	t0,	SCU1_HWSTRAP1
	lw	t0, (t0)
	li	t1, SCU1_HWSTRAP1_EN_ROM_INT
	and	t0, t0, t1
	beqz	t0, 2f

	/* clear & disable enable machine interrupts */
	li	t0, MIE_MEI | MIE_MTI | MIE_MSI
	csrc	mie, t0

	li	t0, MIP_MEI | MIP_MTI | MIP_MSI
	csrc	mip, t0

	/* enable machine global interrupt */
	csrsi	mstatus, MSTATUS_MIE

2:
	ret
