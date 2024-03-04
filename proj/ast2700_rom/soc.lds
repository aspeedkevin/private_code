OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
	rom : ORIGIN = IMAGE_TEXT_BASE
	      LENGTH = IMAGE_MAX_SIZE

	bss_data_ram : ORIGIN = BSS_DATA_BASE
		       LENGTH = BSS_DATA_SIZE
}

SECTIONS
{
	. = 0x0;

	. = ALIGN(4);
	.text :
	{
		*(.vectors*)
		*(.text*)
	} > rom

	. = ALIGN(4);
	.rodata :
	{
		*(.rodata*)
	} > rom

	. = ALIGN(4);
	__data_lma = .;
	.data : AT(__data_lma)
	{
		__data_vma_start = .;
		*(.data*)
		__data_vma_end = .;
	} > bss_data_ram

	. = ALIGN(4);
	.bss :
	{
		__bss_start = .;
		*(.bss*)
		__bss_end = .;
	} > bss_data_ram
}
