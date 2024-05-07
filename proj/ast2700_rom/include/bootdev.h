#ifndef __BOOTDEV_H_
#define __BOOTDEV_H_

#include <bootstage.h>
#include <rom_context.h>
#include <types.h>
#include <boot.h>

#define ERR_STRAP_INVALID_BOOT_TYPE	0x01
#define ERR_STRAP_INVALID_PTR		0x02
#define ERR_STRAP_READ_OTP_FAILED	0x03
#define ERR_STRAP_INCORRECT_MAGIC	0x04
#define ERR_STRAP_INCORRECT_SZ		0x05
#define ERR_STRAP_INCORRECT_ALG		0x06
#define ERR_STRAP_INVALID_CHECKSUM	0x07

#define FLASH_STRAP_MAGIC		0x50415254	/* "PART" */
#define FLASH_STRAP_OFFSET		0x1f000		/* 124KB */
#define FLASH_STRAP_SZ			0x18
#define FLASH_STRAP_ALG_TYPE		0x01

struct flash_strap {
	uint32_t magic;
	uint16_t size;		/* checksum is not included */
	uint16_t algo;
	uint16_t fs_val[8];
	uint32_t csum;		/* checksum of fs_val[8] */
};

struct bootdev_ops {
	int (*init)(void);
	void (*deinit)(void);
	int (*read)(u32 from, u32 *dst, u32 len);
};

struct bootdev {
	int id;

	struct rom_context *parent;
	struct bootdev_ops *ops;
	struct abr *abr;
	int (*fmc_load)(u8 *errno);
	void *this;

	uint8_t info;
};

bootstage_t bootdev_init(struct rom_context *rom_ctx);
bootstage_t bootdev_deinit(struct rom_context *rc);
int bootdev_read(struct rom_context *rom_ctx, u32 from, u32 *dst, u32 len);
int bootdev_load(struct rom_context *rc, u8 *errno);

#endif
