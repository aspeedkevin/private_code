cmd_ast2700_rom.bin ?= riscv32-unknown-elf-objcopy --gap-fill 0x00 -O binary ast2700_rom.elf ast2700_rom.bin
