#include <boot.h>
#include <bootstage.h>
#include <drivers/gpio.h>
#include <drivers/mmc.h>
#include <drivers/ufs.h>
#include <drivers/usb.h>
#include <drivers/wdt.h>
#include <drivers/scu.h>
#include <drivers/spi.h>
#include <drivers/abr.h>
#include <drivers/i2c.h>
#include <drivers/i3c.h>
#include <recovery.h>
#include <bootdev.h>
#include <io.h>
#include <lib/printf.h>
#include <lib/string.h>
#include <types.h>
#include <fmc_verify.h>
#include <fw_load.h>

#define BOOTID_SHIFT	4

enum {
	STATUS_SUCCESS,
	STATUS_IO_ERROR,
	STATUS_TIMEOUT_ERROR,
	STATUS_BOOT_DEVICE_NO_INIT,
	STATUS_BOOT_DEVICE_NO_READ,
	STATUS_BOOT_DEVICE_NO_OPS,
	STATUS_BOOT_DEVICE_CREATE_ERROR,
	STATUS_LOAD_CPTRA_ERROR,
	STATUS_LOAD_SOC_HEADER_ERROR,
};

static struct bootdev g_bd;

int bootdev_load(struct rom_context *rc, u8 *errno)
{
	struct bootdev *bd = rc->bd;
	int ret = 0;

	if (bd && bd->fmc_load)
		ret = bd->fmc_load(errno);
	else
		*errno = FWLD_ERR_BOOTDEV;

	return ret;
}

int bootdev_read(struct rom_context *rc, u32 from, u32 *dst, u32 len)
{
	struct bootdev *bd = rc->bd;
	int ret = STATUS_BOOT_DEVICE_NO_OPS;

	if (!bd->ops)
		return STATUS_BOOT_DEVICE_NO_OPS;

	if (!bd->ops->read)
		return STATUS_BOOT_DEVICE_NO_READ;

	ret = bd->ops->read(from, dst, len);

	return ret;
}

static int bootdev_load_fmc(u8 *errno)
{
	struct rom_context *rc = g_bd.parent;
	u32 from = rc->cptra_lds;
	u32 *dst = (u32 *)rc->fmc_lda;
	u32 len;
	struct ast_fmc_header *hdr = (struct ast_fmc_header *)dst;
	int ret = 0;

	/* load soc image header*/
	len = sizeof(struct ast_fmc_header);
	ret = bootdev_read(rc, from, dst, len);
	if (ret) {
		*errno = FWLD_ERR_READ_HEADER;
		return ret;
	}

	/* check magic */
	if (!is_ast_hdr(hdr)) {
		*errno = FWLD_ERR_WRONG_MAGIC;
		return ret;
	}

	/* move input and output pointer */
	dst = (u32 *)((u8 *)dst + len);
	from += len;

	len = hdr->body.size;

	/* load soc image according the size in the header */
	if (len && len <= rc->fmc_lds) {
		ret = bootdev_read(rc, from, dst, len);
		if (ret)
			*errno = FWLD_ERR_READ_FMC;
	} else {
		*errno = FWLD_ERR_ILLEGAL_SIZE;
	}

	return ret;
}

static int recovery_load_fmc(u8 *errno)
{
	struct rom_context *rc = g_bd.parent;
	u32 *dst = (u32 *)rc->fmc_lda;
	u32 len = rc->fmc_lds;
	int ret = 0;

	/* The 'from' parameter is meaningless for recovery */
	ret = bootdev_read(rc, 0, dst, len);
	if (ret)
		*errno = FWLD_ERR_RECOVERY;

	return ret;
}

static struct bootdev *bootdev_create(struct rom_context *rc)
{
	struct bootdev *bd = &g_bd;

	rc->bootstrap = boot_mode();

	if (rc->bootstrap == BOOT_SPI)
		spi_register(bd);
	else if (rc->bootstrap == BOOT_EMMC)
		mmc_register(bd);
	else if (rc->bootstrap == BOOT_UFS)
		ufs_register(bd);
	else
		return NULL;

	bd->parent = rc;
	bd->abr = abr_create(rc);
	bd->fmc_load = bootdev_load_fmc;
	bd->info = (bd->id << BOOTID_SHIFT);
	if (bd->abr) {
		bd->info |= ((bd->abr->wdta_triggered & 0x1) << 0) |
			    ((bd->abr->boot_indicator & 0x1) << 1);
	}

	rc->bd = bd;

	return bd;
}

/* When boot into recovery mode, GPIO_P4 must output low signal. */
static void recovery_signal_output(void)
{
	uint32_t multi_func;
	uint32_t reg;

	/* Change to GPIO_P4 */
	multi_func = readl(SCU1_PINMUX_GRP_P);
	multi_func &= ~(SCU1_PINMUX_PIN4);
	writel(multi_func, SCU1_PINMUX_GRP_P);

	reg = readl(GPIO1_REG + GPIO(P, 4));
	/* Output direction with low signal */
	reg |= GPIO_DIRECT;
	reg &= ~(GPIO_DATA);
	writel(reg, GPIO1_REG + GPIO(P, 4));
}

static struct bootdev *recovery_create(struct rom_context *rc)
{
	struct bootdev *bd = &g_bd;

	if (rc->bootstrap == BOOT_USB)
		usb_register(bd);
	else if (rc->bootstrap == BOOT_I2C)
		i2c_register(bd);
	else if (rc->bootstrap == BOOT_I3C)
		i3c_register(bd);
	else if (rc->bootstrap == BOOT_UART)
		uart_register(bd);
	else
		return NULL;

	bd->parent = rc;
	bd->abr = NULL;
	bd->fmc_load = recovery_load_fmc;
	bd->info = (bd->id << BOOTID_SHIFT);

	rc->bd = bd;

	recovery_signal_output();

	return bd;
}

bootstage_t bootdev_init(struct rom_context *rc)
{
	bootstage_t sts = { 0, 0 };
	struct bootdev *bd;
	int ret = STATUS_BOOT_DEVICE_NO_INIT;

	bd = bootdev_create(rc);
	if (!bd) {
		bd = recovery_create(rc);
		if (!bd) {
			sts.errno = STATUS_BOOT_DEVICE_CREATE_ERROR;
			return sts;
		}
	}

	if (bd->ops && bd->ops->init)
		ret = bd->ops->init();

	sts.errno = bd->info;
	sts.syndrome = ret;

	return sts;
}

bootstage_t bootdev_deinit(struct rom_context *rc)
{
	bootstage_t sts = { 0, 0 };
	struct bootdev *bd = rc->bd;

	if (bd->ops && bd->ops->deinit)
		bd->ops->deinit();

	return sts;
}
