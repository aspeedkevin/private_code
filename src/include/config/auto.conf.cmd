deps_config := \
	drivers/sli/Kconfig \
	drivers/spi/Kconfig \
	drivers/uart/Kconfig \
	drivers/dram/Kconfig \
	drivers/Kconfig \
	proj/ast2700_rom/Kconfig \
	proj/Kconfig \
	arch/riscv/Kconfig \
	arch/Kconfig \
	Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
