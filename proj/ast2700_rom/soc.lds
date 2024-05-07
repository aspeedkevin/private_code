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
		*(.srdata*)
	} > rom

	. = ALIGN(4);
	__data_lma = .;
	.data :
	{
		__data_vma_start = .;
		*(.sdata*)
		*(.data*)
		__data_vma_end = .;
	} > bss_data_ram AT > rom

	.rom_digest :
	{
		. = ALIGN(32);
		*(.rom_digest*)
	} > rom

	.bss :
	{
		__bss_start = .;
		*(.sbss*)
		*(.bss*)
		__bss_end = .;
	} > bss_data_ram
}
