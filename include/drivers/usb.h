#ifndef __USB_H__
#define __USB_H__

#include <types.h>
#include <bootdev.h>
#include <bootstage.h>
#include <rom_context.h>

enum usb_status_code {
	STS_OKAY = 0,
	STS_IN_WRONG_STATE,
	STS_OUT_WRONG_STATE,
	STS_CRQ_NOT_SUPPORT,
	STS_SLI_UNAVAIL,
};

/*************************************************************************
 * USB configuration
 ************************************************************************/
#define USB_MAX_CTRL_MPS			64	/* maximum packet size (MPS) for EP0 */
#define USB_DEVICE_VID				0x2245
#define USB_DEVICE_DFU_PID			0x2700
#define USB_DFU_DETACH_TIMEOUT			1000
#define USB_DFU_MAX_XFER_SIZE			4096
#define USB_DFU_DEFAULT_POLLTIMEOUT		40

#define USB_DEVICE_MANUFACTURER			"ASPEED"
#define USB_DEVICE_PRODUCT			"AST2700"
#define USB_DEVICE_SN				"8000000080000000"
#define FIRMWARE_IMAGE_0_LABEL			"ram-code"

#define CONFIG_CPU_SRAM_BASE			0x10000000
#define CONFIG_CPU_SRAM_SIZE			0x20000
#define CONFIG_USB_DMA_BUF_ADDR			CONFIG_CPU_SRAM_BASE
#define USB_DMA_BUF_SIZE			CONFIG_CPU_SRAM_SIZE
#define DFU_OUTPUT_BASE				CONFIG_FMC_LOAD_ADDR
#define DRAM_BLOCK_SIZE				USB_DFU_MAX_XFER_SIZE

void usb_register(struct bootdev *bd);
bootstage_t usb2uart_init(struct rom_context *rom_ctx);
bool usb2uart_put_all_msg(void);
#endif /* __USB_H__ */
