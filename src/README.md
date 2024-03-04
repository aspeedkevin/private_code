## BootMCU
BootMCU is designated to load the first, verified image for the main processor (e.g. ARM CA35). The image verification is achieved in the collaboration with the RoT Caliptra. It is also responsible for device recovery by the boot-from-USB/UART capabilities.

This repo contains the baremetal code to build BootMCU code in terms of the project selected.

## Quick Start (AST2700 BootMCU ROM code for example)
1. Download lowrisc toolchain
```
wget https://github.com/lowRISC/lowrisc-toolchains/releases/download/20220524-1/lowrisc-toolchain-gcc-rv32imcb-20220524-1.tar.xz
```

2. Extract lowrisc toolchain
```
tar xvf lowrisc-toolchain-gcc-rv32imcb-20220524-1.tar.xz
```

3. Export cross compiler prefix
```
export CROSS_COMPILE=<TOOLCHAIN_FOLDER>/bin/riscv32-unknown-elf-
```

4. Build AST2700 ROM project
```
cd <BOOTMCU_FOLDER>
make ast2700-rom_defconfig
make
```
