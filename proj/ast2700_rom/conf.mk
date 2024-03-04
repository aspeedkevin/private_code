# locate read/write-able space for .bss and .data sections
LDPPFLAGS += -DBSS_DATA_BASE=$(CONFIG_BSS_DATA_ADDR)
LDPPFLAGS += -DBSS_DATA_SIZE=$(CONFIG_BSS_DATA_SIZE)
