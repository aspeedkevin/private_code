#!/bin/sh

# switch to the right working path
TOP_DIR=`cd ../../; pwd`
cd $TOP_DIR

# check if ROM build has been configured
if [ ! -f .config ]; then
	echo "Cannot find $TOP_DIR/.config. Please run through defconfig first"
	exit -1
fi

# build ROM
make -j`nproc`

# ROM binary post-process to add the golden SHA256 digest at the image end
ROM_NAME=`grep CONFIG_BINARY_NAME .config | sed -n -e 's/.*"\(.*\)".*/\1/p'`

ROM_BIN=$ROM_NAME.bin
ROM_MAP=$ROM_NAME.map

ROM_BASE=`grep -s CONFIG_SYS_TEXT_BASE .config | sed -n -e 's/.*0x\(.*\)/0x\1/p'`

ROM_DGST=$ROM_NAME.dgst
ROM_DGST_LMA=`grep -s "rom_dgst_golden" $ROM_MAP | awk '{print $1}'`
ROM_DGST_OFST=$((ROM_DGST_LMA - ROM_BASE))
ROM_DGST_SIZE=32

dd if=$ROM_BIN bs=1 count=$ROM_DGST_OFST 2>/dev/null | sha256sum -b | awk -e '{ print $1 }' | xxd -r -p > $ROM_DGST

# overwrite the digest at the image end
dd if=$ROM_DGST of=$ROM_BIN bs=1 seek=$ROM_DGST_OFST 2>/dev/null

# in last line of build_rom.sh
cp $ROM_BIN ~/ast27xx_sdk/spl/board/aspeed/ibex_ast2700/prebuilt/
