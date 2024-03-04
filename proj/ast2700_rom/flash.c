#include <boot.h>
#include <bootstage.h>
#include <drivers/gpio.h>
#include <drivers/mmc.h>
#include <drivers/wdt.h>
#include <drivers/scu.h>
#include <drivers/spi.h>
#include <flash.h>
#include <flash_mmc.h>
#include <flash_spi.h>
#include <io.h>
#include <lib/string.h>
#include <types.h>

int flash_strap_read(uint16_t fs_val[8])
{
	switch (boot_mode()) {
	case BOOT_EMMC:
		return flash_mmc_strap_read(fs_val);
	case BOOT_SPI:
		return flash_spi_strap_read(fs_val);
	default:
		/* TODO: UFS and error handling */
		break;
	}

	return ERR_STRAP_INVALID_BOOT_TYPE;
}

bootstage_t flash_init_f(void)
{
	bootstage_t sts = { 0, 0 };

	switch (boot_mode()) {
	case BOOT_EMMC:
		flash_mmc_init_f();
		break;
	case BOOT_SPI:
		flash_spi_init_f();
		break;
	default:
		/* TODO: UFS and error handling */
		break;
	}

	return sts;
}

bootstage_t flash_init_r(void)
{
	bootstage_t sts = { 0, 0 };

	switch (boot_mode()) {
	case BOOT_EMMC:
		flash_mmc_init_r();
		break;
	case BOOT_SPI:
		flash_spi_init_r();
		break;
	default:
		/* TODO: UFS and error handling */
		break;
	}

	return sts;
}

bootstage_t flash_image_load(void)
{
	bootstage_t sts = { 0, 0 };

	switch (boot_mode()) {
	case BOOT_EMMC:
		flash_mmc_image_load();
		break;
	case BOOT_SPI:
		flash_spi_image_load();
		break;
	default:
		/* TODO: UFS and error handling */
		break;
	}

	return sts;
}
