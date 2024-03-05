#!/bin/sh
BOOT_DVT=drivers/loader/soc_loader.bin
DRAM_UBOOT_DVT=soc.bin
#DRAM_UBOOT_DVT=bin/u-boot.bin
OUTPUT=bootloader.bin

#
# 0. Check the binary file exist or not
#
if [ ! -f "$BOOT_DVT" ]
then
	echo "$BOOT_DVT does not exist."
	exit
fi
if [ ! -f "$DRAM_UBOOT_DVT" ]
then
	echo "$DRAM_UBOOT_DVT does not exist."
	exit
fi


#
# 1. Get the code size by wc
#
socdvt_size=$(wc -c "$BOOT_DVT" | awk '{print $1}')
dram_uboot_dvt_size=$(wc -c "$DRAM_UBOOT_DVT" | awk '{print $1}')
echo "$BOOT_DVT size is $socdvt_size, $DRAM_UBOOT_DVT size is $dram_uboot_dvt_size"


#
# 2. Get the load address/size from parameter
#
load_address_hex="$1"
load_address=$(printf "%d" "$load_address_hex")
if test "$load_address" -eq 0; then
	load_address_hex=0x20000
fi
echo "load address in Flash is $load_address_hex"
#echo "load address in Flash is $load_address_hex, load address is $load_address"

load_size_hex="$2"
load_size=$(printf "%d" "$load_size_hex")
#Size from Flash offset(128KB)=1MB
if test "$load_size" -eq 0; then
	load_size_hex=0x100000
fi
echo "load size hex is $load_size_hex"
#echo "load size hex is $load_size_hex, load size is $load_size"


#
# 3.Check file size with load address and load size
#
if [ "$socdvt_size" -gt "$load_address" ]; then
	echo "Error: $BOOT_DVT is greater than CONFIG_SYS_LOAD_ADDR, $BOOT_DVT in Flash will be covered."
	exit
fi

if [ "$dram_uboot_dvt_size" -gt "$load_size" ]; then
	echo "Error: $DRAM_UBOOT_DVT is greater than CONFIG_SYS_LOAD_SIZE,  $DARM_DRAM_UBOOT_DVT in Flash will not be copied."
	exit
fi


#
# 4. Create output file
#
echo "=============================================================================="
echo "Create $OUTPUT"
echo "by $BOOT_DVT in 0x0 and $DRAM_UBOOT_DVT in $load_address_hex with $load_size_hex size"
echo "=============================================================================="
#Copying the soc loader to boot, offset=0
dd if=$BOOT_DVT of=$OUTPUT bs=1
#Copying the u-Boot or Second dvt
dd if=$DRAM_UBOOT_DVT of=$OUTPUT bs=1 seek="$load_address"

