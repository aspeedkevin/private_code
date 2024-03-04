#ifndef __USB_H__
#define __USB_H__

#include <types.h>

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
#define CONFIG_USB_DMA_BUF_ADDR			CONFIG_CPU_SRAM_BASE
#define DFU_OUTPUT_BASE				CONFIG_RAM_CODE_LOAD_ADDR
#define DRAM_BLOCK_SIZE				USB_DFU_MAX_XFER_SIZE

bool usb_is_dnload_done(void);
uint8_t usb_poll(void);
void usb_enable(void);

#endif /* __USB_H__ */
