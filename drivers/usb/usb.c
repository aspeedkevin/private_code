// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2023 Aspeed Technology Inc.
 */

#include <bootstage.h>
#include <drivers/ch9.h>
#include <drivers/sli.h>
#include <drivers/usb_dfu.h>
#include <drivers/usb.h>
#include <io.h>
#include <lib/string.h>
#include <platform.h>
#include <types.h>
#include <utils.h>

/*****************************
 *                           *
 * VHUB register definitions *
 *                           *
 *****************************/
#define VHUB_BASE				USB_VHUB_REG

#define	VHUB_CTRL				0x00	/* Root Function Control & Status Register */
#define	VHUB_CONF				0x04	/* Root Configuration Setting Register */
#define	VHUB_IER				0x08	/* Interrupt Ctrl Register */
#define	VHUB_ISR				0x0C	/* Interrupt Status Register */
#define	VHUB_EP_ACK_IER				0x10	/* Programmable Endpoint Pool ACK Interrupt Enable Register */
#define	VHUB_EP_NACK_IER			0x14	/* Programmable Endpoint Pool NACK Interrupt Enable Register  */
#define VHUB_EP_ACK_ISR				0x18	/* Programmable Endpoint Pool ACK Interrupt Status Register  */
#define VHUB_EP_NACK_ISR			0x1C	/* Programmable Endpoint Pool NACK Interrupt Status Register  */
#define VHUB_SW_RESET				0x20	/* Device Controller Soft Reset Enable Register */
#define VHUB_USBSTS				0x24	/* USB Status Register */
#define VHUB_EP_TOGGLE				0x28	/* Programmable Endpoint Pool Data Toggle Value Set */
#define VHUB_ISO_FAIL_ACC			0x2C	/* Isochronous Transaction Fail Accumulator */
#define VHUB_EP0_CTRL				0x30	/* Endpoint 0 Contrl/Status Register */
#define VHUB_EP0_DATA				0x34	/* Base Address of Endpoint 0 In/OUT Data Buffer Register */
#define VHUB_EP1_CTRL				0x38	/* Endpoint 1 Contrl/Status Register */
#define VHUB_EP1_STS_CHG			0x3C	/* Endpoint 1 Status Change Bitmap Data */
#define VHUB_SETUP0				0x80	/* Root Device Setup Data Buffer0 */
#define VHUB_SETUP1				0x84	/* Root Device Setup Data Buffer1 */

/* Main control reg */
#define VHUB_CTRL_PHY_CLK			BIT(31)
#define VHUB_CTRL_PHY_LOOP_TEST			BIT(25)
#define VHUB_CTRL_DN_PWN			BIT(24)
#define VHUB_CTRL_DP_PWN			BIT(23)
#define VHUB_CTRL_LONG_DESC			BIT(18)
#define VHUB_CTRL_ISO_RSP_CTRL			BIT(17)
#define VHUB_CTRL_SPLIT_IN			BIT(16)
#define VHUB_CTRL_LOOP_T_RESULT			BIT(15)
#define VHUB_CTRL_LOOP_T_STS			BIT(14)
#define VHUB_CTRL_PHY_BIST_RESULT		BIT(13)
#define VHUB_CTRL_PHY_BIST_CTRL			BIT(12)
#define VHUB_CTRL_PHY_RESET_DIS			BIT(11)
#define VHUB_CTRL_SET_TEST_MODE(x)		((x) << 8)
#define VHUB_CTRL_MANUAL_REMOTE_WAKEUP		BIT(4)
#define VHUB_CTRL_AUTO_REMOTE_WAKEUP		BIT(3)
#define VHUB_CTRL_CLK_STOP_SUSPEND		BIT(2)
#define VHUB_CTRL_FULL_SPEED_ONLY		BIT(1)
#define VHUB_CTRL_UPSTREAM_CONNECT		BIT(0)

/* IER & ISR */
#define VHUB_IRQ_DEV1_BIT			9
#define VHUB_IRQ_USB_CMD_DEADLOCK		BIT(18)
#define VHUB_IRQ_EP_POOL_NAK			BIT(17)
#define VHUB_IRQ_EP_POOL_ACK_STALL		BIT(16)
#define VHUB_IRQ_DEVICE1			BIT(VHUB_IRQ_DEV1_BIT)
#define VHUB_IRQ_BUS_RESUME			BIT(8)
#define VHUB_IRQ_BUS_SUSPEND			BIT(7)
#define VHUB_IRQ_BUS_RESET			BIT(6)
#define VHUB_IRQ_HUB_EP1_IN_DATA_ACK		BIT(5)
#define VHUB_IRQ_HUB_EP0_IN_DATA_NAK		BIT(4)
#define VHUB_IRQ_HUB_EP0_IN_ACK_STALL		BIT(3)
#define VHUB_IRQ_HUB_EP0_OUT_NAK		BIT(2)
#define VHUB_IRQ_HUB_EP0_OUT_ACK_STALL		BIT(1)
#define VHUB_IRQ_HUB_EP0_SETUP			BIT(0)
#define VHUB_IRQ_ACK_ALL			0x1ff

/* Downstream device IRQ mask. */
#define VHUB_DEV_IRQ(n)				(VHUB_IRQ_DEVICE1 << (n))

/* SW reset reg */
#define VHUB_SW_RESET_ROOT_HUB			BIT(0)

/* HUB EP0 control */
#define VHUB_EP0_CTRL_STALL			BIT(0)
#define VHUB_EP0_TX_BUFF_RDY			BIT(1)
#define VHUB_EP0_RX_BUFF_RDY			BIT(2)
#define VHUB_EP0_RX_LEN(x)			(((x) >> 16) & 0x7f)
#define VHUB_EP0_SET_TX_LEN(x)			(((x) & 0x7f) << 8)
#define VHUB_EP0_SET_HIGH_ADDR(x)		(((x) & 0x3) << 30)

/* SCU ctrl */
#define SCU_USB_MULTI_CTRL			0x410
#define SCU_RST_CTRL				0x220

const char *usb_strings[] = {
	"",
	USB_DEVICE_MANUFACTURER,
	USB_DEVICE_PRODUCT,
	USB_DEVICE_SN,
	FIRMWARE_IMAGE_0_LABEL,
};

static uint8_t *ep0_ctrl_buf = (uint8_t *)CONFIG_USB_DMA_BUF_ADDR;

enum usbd_req_rc {
	USBD_REQ_HANDLED = 0,
	USBD_REQ_NOTSUPP,
};

struct request_ctx {
	struct usb_ctrlrequest crq;
	uint32_t length;
	uint32_t actual;
	uint32_t block_nr;
};

static struct request_ctx usb_req_ctx;

/* DFU mode device descriptor */
struct dev_dfu_mode_descriptor {
	struct usb_device_descriptor device_desc;
	struct usb_config_descriptor cfg_desc;
	struct usb_dfu_config {
		/* sram */
		struct usb_interface_descriptor if0;
		struct dfu_runtime_descriptor dfu_run_desc;
	} dfu_cfg;
};

static struct dev_dfu_mode_descriptor dfu_mode_desc = {
	/* Device descriptor */
	.device_desc = {
		.bLength = sizeof(struct usb_device_descriptor),
		.bDescriptorType = USB_DT_DEVICE,
		.bcdUSB = cpu_to_le16(0x0200),
		.bDeviceClass = 0,
		.bDeviceSubClass = 0,
		.bDeviceProtocol = 0,
		.bMaxPacketSize0 = USB_MAX_CTRL_MPS,
		.idVendor = cpu_to_le16((uint16_t)USB_DEVICE_VID),
		.idProduct = cpu_to_le16((uint16_t)USB_DEVICE_DFU_PID),
		.iManufacturer = 1,
		.iProduct = 2,
		.iSerialNumber = 3,
		.bNumConfigurations = 1,
	},
	/* Configuration descriptor */
	.cfg_desc = {
		.bLength = sizeof(struct usb_config_descriptor),
		.bDescriptorType = USB_DT_CONFIG,
		.wTotalLength = sizeof(dfu_mode_desc.cfg_desc) +
				sizeof(dfu_mode_desc.dfu_cfg),
		.bNumInterfaces = 1,
		.bConfigurationValue = 1,
		.iConfiguration = 0,
		.bmAttributes = USB_CONFIG_ATT_ONE |
				USB_CONFIG_ATT_SELFPOWER,
		.bMaxPower = 0x32,
	},
	.dfu_cfg = {
		/* Interface descriptor */
		.if0 = {
			.bLength = sizeof(struct usb_interface_descriptor),
			.bDescriptorType = USB_DT_INTERFACE,
			.bInterfaceNumber = 0,
			.bAlternateSetting = 0,
			.bNumEndpoints = 0,
			.bInterfaceClass = USB_CLASS_APP_SPEC,
			.bInterfaceSubClass = DFU_SUBCLASS,
			.bInterfaceProtocol = DFU_MODE_PROTOCOL,
			.iInterface = 4,
		},
		.dfu_run_desc = {
			.bLength = sizeof(struct dfu_runtime_descriptor),
			.bDescriptorType = DFU_FUNC_DESC,
			.bmAttributes = DFU_ATTR_CAN_DNLOAD |
					DFU_ATTR_MANIFESTATION_TOLERANT,
			.wDetachTimeOut =
				cpu_to_le16(USB_DFU_DETACH_TIMEOUT),
			.wTransferSize =
				cpu_to_le16(USB_DFU_MAX_XFER_SIZE),
			.bcdDFUVersion =
				cpu_to_le16(DFU_VERSION),
		},
	},
};

#define VENDOR_REQ_MS_OS_DESC             0x12
#define WINDEX_OS_FEATURE_EXT_COMPAT_ID   4
#define WINDEX_OS_FEATURE_EXT_PROPERTIES  5

#define OS_STRING_IDX			       0xEE

struct usb_os_string {
	uint8_t	bLength;
	uint8_t	bDescriptorType;
	uint8_t	qwSignature[14];
	uint8_t	bMS_VendorCode;
	uint8_t	bPad;
} __packed;

struct usb_os_compat_id_desc {
	// Header
	uint32_t dwLength;
	uint16_t bcdVersion;
	uint16_t wIndex;
	uint8_t  bCount;
	uint8_t  bReserved1[7];
	// Function Section 1
	uint8_t  bFirstInterfaceNumber;
	uint8_t  bReserved2;
	uint8_t  bCompatibleID[8];
	uint8_t  bSubCompatibleID[8];
	uint8_t  bReserved3[6];
} __packed;

struct usb_os_ext_properties_desc {
	// Header
	uint32_t dwLength;
	uint16_t bcdVersion;
	uint16_t wIndex;
	uint16_t wCount;
	// Custom Property Section 1
	uint32_t dwSize;
	uint32_t dwPropertyDataType;
	uint16_t wPropertyNameLength;
	uint8_t  bPropertyName[40];
	uint32_t dwPropertyDataLength;
	uint8_t  bPropertyData[78];
} __packed;

struct usb_os_string const desc_string_ms_10 =
{
	.bLength = sizeof (struct usb_os_string),
	.bDescriptorType = USB_DT_STRING,
	.qwSignature = {'M',0,'S',0,'F',0,'T',0,'1',0,'0',0,'0',0,},
	.bMS_VendorCode = VENDOR_REQ_MS_OS_DESC,
	.bPad = 0
};

struct usb_os_compat_id_desc const desc_compat_id_ms =
{
	// Header
	.dwLength = cpu_to_le32(sizeof (struct usb_os_compat_id_desc)),
	.bcdVersion = cpu_to_le16(0x0100),
	.wIndex = cpu_to_le16(0x0004), // The index for Extended compat ID descriptor
	.bCount = 0x01,
	.bReserved1 = {0},
	// Function Section 1
	.bFirstInterfaceNumber = 0x00, //ITF_NUM_DFU_RT
	.bReserved2 = 1,
	.bCompatibleID = "WINUSB",
	.bSubCompatibleID = {0},
	.bReserved3 = {0}
};

struct usb_os_ext_properties_desc const desc_ext_properties_ms =
{
	// Header
	.dwLength = cpu_to_le32(sizeof (struct usb_os_ext_properties_desc)),
	.bcdVersion = cpu_to_le16(0x0100),
	.wIndex = cpu_to_le16(0x0005), // The index for extended property OS descriptors.
	.wCount = cpu_to_le16(0x0001), // Only 1 Custom Property Section
	// Custom Property Section 1
	.dwSize = cpu_to_le32(0x00000084),
	.dwPropertyDataType = cpu_to_le32(0x00000001), //Property Data Type: A NULL-terminated Unicode String (REG_SZ)
	.wPropertyNameLength = cpu_to_le16(0x0028),
	.bPropertyName = {'D', 0x00, 'e', 0x00, 'v', 0x00, 'i', 0x00, 'c', 0x00, 'e', 0x00, 'I', 0x00,
					'n', 0x00, 't', 0x00, 'e', 0x00, 'r', 0x00, 'f', 0x00, 'a', 0x00, 'c', 0x00,
					'e', 0x00, 'G', 0x00, 'U', 0x00, 'I', 0x00, 'D', 0x00, 0x00, 0x00},
	.dwPropertyDataLength = cpu_to_le32(0x0000004E),
	// {AA536045-0A1E-4782-A559-2E1ACA555AAE}
	.bPropertyData = {'{', 0x00, 'A', 0x00, 'A', 0x00, '5', 0x00, '3', 0x00, '6', 0x00, '0', 0x00,
					'4', 0x00, '5', 0x00, '-', 0x00, '0', 0x00, 'A', 0x00, '1', 0x00, 'E', 0x00,
					'-', 0x00, '4', 0x00, '7', 0x00, '8', 0x00, '2', 0x00, '-', 0x00, 'A', 0x00,
					'5', 0x00, '5', 0x00, '9', 0x00, '-', 0x00, '2', 0x00, 'E', 0x00, '1', 0x00,
					'A', 0x00, 'C', 0x00, 'A', 0x00, '5', 0x00, '5', 0x00, '5', 0x00, 'A', 0x00,
					'A', 0x00, 'E', 0x00, '}', 0x00, 0x00, 0x00}
};

/*
 * The USB Unicode bString is encoded in UTF16LE, which means it takes up
 * twice the amount of bytes than the same string encoded in ASCII7.
 * Use this macro to determine the length of the bString array.
 *
 * bString length without null character:
 *   bString_length = (sizeof(initializer_string) - 1) * 2
 * or:
 *   bString_length = sizeof(initializer_string) * 2 - 2
 */
#define USB_BSTRING_LENGTH(s)		(sizeof(s) * 2 - 2)

/*
 * The length of the string descriptor (bLength) is calculated from the
 * size of the two octets bLength and bDescriptorType plus the
 * length of the UTF16LE string:
 *
 *   bLength = 2 + bString_length
 *   bLength = 2 + sizeof(initializer_string) * 2 - 2
 *   bLength = sizeof(initializer_string) * 2
 * Use this macro to determine the bLength of the string descriptor.
 */
#define USB_STRING_DESCRIPTOR_LENGTH(s)	(sizeof(s) * 2)

struct usb_string_desription {
	struct usb_string_descriptor lang_desc;
	struct usb_mfr_descriptor {
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bString[USB_BSTRING_LENGTH(USB_DEVICE_MANUFACTURER) / 2];
	} utf16le_mfr;

	struct usb_product_descriptor {
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bString[USB_BSTRING_LENGTH(USB_DEVICE_PRODUCT) / 2];
	} utf16le_product;

	struct usb_sn_descriptor {
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bString[USB_BSTRING_LENGTH(USB_DEVICE_SN) / 2];
	} utf16le_sn;

	struct image_0_descriptor {
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint16_t bString[USB_BSTRING_LENGTH(FIRMWARE_IMAGE_0_LABEL) / 2];
	} utf16le_image0;
};

static struct usb_string_desription string_desc = {
	.lang_desc = {
		.bLength = sizeof(struct usb_string_descriptor),
		.bDescriptorType = USB_DT_STRING,
		.wData[0] = cpu_to_le16(0x0409),
	},
	/* Manufacturer String Descriptor */
	.utf16le_mfr = {
		.bLength = USB_STRING_DESCRIPTOR_LENGTH(USB_DEVICE_MANUFACTURER),
		.bDescriptorType = USB_DT_STRING,
	},
	/* Product String Descriptor */
	.utf16le_product = {
		.bLength = USB_STRING_DESCRIPTOR_LENGTH(USB_DEVICE_PRODUCT),
		.bDescriptorType = USB_DT_STRING,
	},
	/* Serial Number String Descriptor */
	.utf16le_sn = {
		.bLength = USB_STRING_DESCRIPTOR_LENGTH(USB_DEVICE_SN),
		.bDescriptorType = USB_DT_STRING,
	},
	/* Image 0 String Descriptor */
	.utf16le_image0 = {
		.bLength = USB_STRING_DESCRIPTOR_LENGTH(FIRMWARE_IMAGE_0_LABEL),
		.bDescriptorType = USB_DT_STRING,
	},
};

/* Device data structure */
struct dfu_data_t {
	uint32_t alt_setting;              /* DFU alternate setting */
	enum dfu_state state;              /* State of the DFU device */
	enum dfu_status status;            /* Status of the DFU device */
	uint16_t block_nr;                 /* DFU block number */
	uint16_t bwPollTimeout;
};

static struct dfu_data_t dfu_data = {
	.state = dfuIDLE,
	.status = statusOK,
	.bwPollTimeout = USB_DFU_DEFAULT_POLLTIMEOUT,
};

enum usb_state {
	IDLE,
	STALL,
	DATA_IN,
	LAST_DATA_IN,
	STATUS_IN,
	DATA_OUT,
	LAST_DATA_OUT,
	STATUS_OUT,
};

enum usb_state usb_fsm_state;

static bool is_dnload_done;

static void vhub_ep0_tx(u64 addr, int size)
{
	uint8_t high_addr = addr >> 32;

	/* low addr */
	writel(addr, VHUB_BASE + VHUB_EP0_DATA);

	/* high addr/tx len/tx ready */
	writel(VHUB_EP0_SET_HIGH_ADDR(high_addr) |
	       VHUB_EP0_SET_TX_LEN(size) |
	       VHUB_EP0_TX_BUFF_RDY,
	       VHUB_BASE + VHUB_EP0_CTRL);
}

static void vhub_ep0_rx(u64 addr)
{
	uint8_t high_addr = addr >> 32;

	/* low addr */
	writel(addr, VHUB_BASE + VHUB_EP0_DATA);

	/* high addr/rx ready */
	writel(VHUB_EP0_SET_HIGH_ADDR(high_addr) |
	       VHUB_EP0_RX_BUFF_RDY,
	       VHUB_BASE + VHUB_EP0_CTRL);
}

static void vhub_req_cleanup(void)
{
	usb_req_ctx.length = 0;
	usb_req_ctx.actual = 0;
}

static uint8_t vhub_ep0_in(void)
{
	uint32_t mps, data_size_max;
	uint32_t chunk;
	u64 tx_buff_addr;

	switch (usb_fsm_state) {
	case DATA_IN:
		mps = dfu_mode_desc.device_desc.bMaxPacketSize0;
		chunk = usb_req_ctx.length - usb_req_ctx.actual;
		if (chunk > mps)
			chunk = mps;
		tx_buff_addr = (uintptr_t)ep0_ctrl_buf + usb_req_ctx.actual;
		vhub_ep0_tx(tx_buff_addr, chunk);
		usb_req_ctx.actual += chunk;

		data_size_max = le16_to_cpu(usb_req_ctx.crq.wLength);
		/* Go to status stage if payload size is less than MPS or has transferred exactly
		   the amount of data specified during the Setup stage (data_size_max).
		   Otherwise, go to DATA stage again for more data or a ZLP (short transfer). */
		if (chunk < mps || usb_req_ctx.actual == data_size_max)
			usb_fsm_state = LAST_DATA_IN;
		else
			usb_fsm_state = DATA_IN;
		break;
	case LAST_DATA_IN:
		vhub_ep0_rx(0);
		usb_fsm_state = STATUS_OUT;
		break;
	case STATUS_IN:
		usb_fsm_state = IDLE;
		if (dfu_data.state == dfuDNLOAD_IDLE) {
			memcpy((uint8_t *)DFU_OUTPUT_BASE +
			       usb_req_ctx.block_nr * DRAM_BLOCK_SIZE,
			       ep0_ctrl_buf,
			       DRAM_BLOCK_SIZE);

			vhub_req_cleanup();
		}
		break;
	default:
		return (STS_IN_WRONG_STATE << 4 | usb_fsm_state);
	}

	return 0;
}

static uint8_t vhub_ep0_out(void)
{
	uint32_t val;

	switch (usb_fsm_state) {
	case DATA_OUT:
		val = readl(VHUB_BASE + VHUB_EP0_CTRL);
		usb_req_ctx.actual += VHUB_EP0_RX_LEN(val);

		if (usb_req_ctx.length == usb_req_ctx.actual) {
			dfu_data.state = dfuDNLOAD_IDLE;
			vhub_ep0_tx(0, 0);
			usb_fsm_state = STATUS_IN;

		} else {
			vhub_ep0_rx((uintptr_t)ep0_ctrl_buf + usb_req_ctx.actual);
		}
		break;
	case STATUS_OUT:
		/* Download complete */
		if (dfu_data.state == dfuIDLE && usb_req_ctx.block_nr != -1)
			is_dnload_done = true;

		/* Download size exceeds RAM code size */
		if (dfu_data.state == dfuDNLOAD_IDLE &&
		    usb_req_ctx.block_nr != -1 &&
		    ((usb_req_ctx.block_nr + 1) * DRAM_BLOCK_SIZE >= CONFIG_RAM_CODE_LOAD_SIZE)) {
			is_dnload_done = true;
		}
		break;
	default:
		return (STS_OUT_WRONG_STATE << 4 | usb_fsm_state);
	}

	return 0;
}

static int vhub_std_request(struct usb_ctrlrequest *crq)
{
	uint16_t wValue = le16_to_cpu(crq->wValue);
	int desc_idx, desc_type;
	int len;

	desc_idx = wValue & 0xff;
	desc_type = wValue >> 8;

	switch (crq->bRequest) {
	case USB_REQ_SET_ADDRESS:
		writel(wValue, VHUB_BASE + VHUB_CONF);
		vhub_ep0_tx(0, 0);
		return USBD_REQ_HANDLED;

	case USB_REQ_GET_DESCRIPTOR:
		is_dnload_done = false;
		usb_req_ctx.block_nr = -1;
		switch (wValue >> 8) {
		case USB_DT_DEVICE:
			/* copy device descriptor */
			memcpy(ep0_ctrl_buf, &dfu_mode_desc.device_desc,
			       sizeof(dfu_mode_desc.device_desc));
			usb_req_ctx.length = sizeof(dfu_mode_desc.device_desc);
			return USBD_REQ_HANDLED;

		case USB_DT_CONFIG:
			/* copy config descriptor */
			memcpy(ep0_ctrl_buf, &dfu_mode_desc.cfg_desc,
			       sizeof(dfu_mode_desc.cfg_desc) +
			       sizeof(dfu_mode_desc.dfu_cfg));
			usb_req_ctx.length = sizeof(dfu_mode_desc.cfg_desc) +
				sizeof(dfu_mode_desc.dfu_cfg);
			return USBD_REQ_HANDLED;

		case USB_DT_STRING:
			/* copy string descriptor */
			len = strlen(usb_strings[desc_idx]);
			switch (desc_idx) {
			case 0x0:
				/* Send Language ID descriptor */
				memcpy(ep0_ctrl_buf, &string_desc.lang_desc,
				       sizeof(string_desc.lang_desc));
				usb_req_ctx.length = sizeof(string_desc.lang_desc);
				break;
			case 0x1:
				for (int i = 0; i < len; i++)
					string_desc.utf16le_mfr.bString[i] = usb_strings[desc_idx][i];
				/* Send manufacturer descriptor */
				memcpy(ep0_ctrl_buf, &string_desc.utf16le_mfr,
				       sizeof(string_desc.utf16le_mfr));
				usb_req_ctx.length = sizeof(string_desc.utf16le_mfr);
				break;
			case 0x2:
				for (int i = 0; i < len; i++)
					string_desc.utf16le_product.bString[i] = usb_strings[desc_idx][i];
				/* Send product descriptor */
				memcpy(ep0_ctrl_buf, &string_desc.utf16le_product,
				       sizeof(string_desc.utf16le_product));
				usb_req_ctx.length = sizeof(string_desc.utf16le_product);
				break;
			case 0x3:
				for (int i = 0; i < len; i++)
					string_desc.utf16le_sn.bString[i] = usb_strings[desc_idx][i];
				/* Send serial number descriptor */
				memcpy(ep0_ctrl_buf, &string_desc.utf16le_sn,
				       sizeof(string_desc.utf16le_sn));
				usb_req_ctx.length = sizeof(string_desc.utf16le_sn);
				break;
			case 0x4:
				for (int i = 0; i < len; i++)
					string_desc.utf16le_image0.bString[i] = usb_strings[desc_idx][i];
				/* Send if0 string descriptor */
				memcpy(ep0_ctrl_buf, &string_desc.utf16le_image0,
				       sizeof(string_desc.utf16le_image0));
				usb_req_ctx.length = sizeof(string_desc.utf16le_image0);
				break;
			case OS_STRING_IDX:
				/* Send Microsoft OS String Descriptor */
				memcpy(ep0_ctrl_buf, &desc_string_ms_10,
				       sizeof(desc_string_ms_10));
				usb_req_ctx.length = sizeof(desc_string_ms_10);
				break;
			}
			return USBD_REQ_HANDLED;
		}
		break;
	case USB_REQ_GET_CONFIGURATION:
		ep0_ctrl_buf[0] = 1;
		usb_req_ctx.length = 1;
		return USBD_REQ_HANDLED;
	case USB_REQ_SET_CONFIGURATION:
		return USBD_REQ_HANDLED;
	case USB_REQ_GET_STATUS:
		if ((crq->bRequestType & USB_RECIP_MASK) == USB_RECIP_DEVICE)
		{
			uint8_t status[2];
			status[0] = 1 << USB_DEVICE_SELF_POWERED;
			status[0] |= 0 << USB_DEVICE_REMOTE_WAKEUP;
			memcpy(ep0_ctrl_buf, status, sizeof(status));
			usb_req_ctx.length = sizeof(status);
			return USBD_REQ_HANDLED;
		}
		break;
	case USB_REQ_SET_INTERFACE:
		return USBD_REQ_HANDLED;
	default:
		break;
	}

	return USBD_REQ_NOTSUPP;
}

static int vhub_class_request(struct usb_ctrlrequest *crq)
{
	uint8_t *data = ep0_ctrl_buf;

	switch (crq->bRequest) {
	case DFU_DNLOAD:
		usb_req_ctx.block_nr = crq->wValue;

		switch (dfu_data.state) {
		case dfuIDLE:
			dfu_data.state = dfuDNBUSY;
			usb_req_ctx.length = crq->wLength;
			break;
		case dfuDNLOAD_IDLE:
			if (crq->wLength == 0) {
				/* download complete */
				dfu_data.state = dfuMANIFEST_SYNC;
				break;
			}
			dfu_data.state = dfuDNBUSY;
			usb_req_ctx.length = crq->wLength;
			break;
		default:
			dfu_data.state = dfuERROR;
			dfu_data.status = errUNKNOWN;
			return -1;
		}
		return USBD_REQ_HANDLED;
	case DFU_CLRSTATUS:
		return USBD_REQ_HANDLED;
	case DFU_ABORT:
		return USBD_REQ_HANDLED;
	case DFU_DETACH:
		return USBD_REQ_HANDLED;
	case DFU_GETSTATUS:
		if (dfu_data.state == dfuMANIFEST_SYNC)
			dfu_data.state = dfuIDLE;

		/* bStatus */
		data[0] = dfu_data.status;
		/* bwPollTimeout */
		data[1] = dfu_data.bwPollTimeout;
		data[3] = 0U;
		data[2] = 0U;
		/* bState */
		data[4] = dfu_data.state;
		/* iString */
		data[5] = 0U;
		usb_req_ctx.length = 6;

		return USBD_REQ_HANDLED;
	case DFU_GETSTATE:
		return USBD_REQ_HANDLED;
	}

	return USBD_REQ_NOTSUPP;
}

static int vhub_vendor_request(struct usb_ctrlrequest *crq)
{
	switch (crq->bRequest) {
	case VENDOR_REQ_MS_OS_DESC:
		if (crq->wIndex == WINDEX_OS_FEATURE_EXT_COMPAT_ID) {
			memcpy(ep0_ctrl_buf, &desc_compat_id_ms,
				       sizeof(desc_compat_id_ms));
			usb_req_ctx.length = sizeof(desc_compat_id_ms);
			return USBD_REQ_HANDLED;
		} else if (crq->wIndex == WINDEX_OS_FEATURE_EXT_PROPERTIES) {
			memcpy(ep0_ctrl_buf, &desc_ext_properties_ms,
				       sizeof(desc_ext_properties_ms));
			usb_req_ctx.length = sizeof(desc_ext_properties_ms);
			return USBD_REQ_HANDLED;
		}
	}
	return USBD_REQ_NOTSUPP;
}

static uint8_t vhub_ep0_setup(void)
{
	struct usb_ctrlrequest crq = usb_req_ctx.crq;
	uint32_t data_size_max, mps;
	uint32_t len, act, chunk;
	bool diection_in;
	u64 tx_buff_addr;
	int ret;

	vhub_req_cleanup();

	memcpy(&crq, (void *)(VHUB_BASE + VHUB_SETUP0), sizeof(struct usb_ctrlrequest));

	if ((crq.bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD)
		ret = vhub_std_request(&crq);
	else if ((crq.bRequestType & USB_TYPE_MASK) == USB_TYPE_CLASS)
		ret = vhub_class_request(&crq);
	else if ((crq.bRequestType & USB_TYPE_MASK) == USB_TYPE_VENDOR)
		ret = vhub_vendor_request(&crq);
	else
		ret = USBD_REQ_NOTSUPP;

	if (ret)
		return STS_CRQ_NOT_SUPPORT;

	data_size_max = le16_to_cpu(crq.wLength);

	if (data_size_max) {
		/* data stage */
		diection_in = !!(crq.bRequestType & USB_DIR_IN);
		mps = dfu_mode_desc.device_desc.bMaxPacketSize0;
		len = usb_req_ctx.length;
		act = usb_req_ctx.actual;
		chunk = len - act;

		if (data_size_max < chunk) {
			chunk = data_size_max;
			if (diection_in) {
				/* Data more than host expected, only return wLength (setup) size of data */
				usb_req_ctx.length = data_size_max;
			}
		}

		if (mps < chunk) {
			/* normal transmission */
			if (diection_in) {
				chunk = mps;
				tx_buff_addr = (uintptr_t)ep0_ctrl_buf + act;
				vhub_ep0_tx(tx_buff_addr, chunk);
				usb_req_ctx.actual += chunk;
				usb_fsm_state = DATA_IN;
			} else {
				vhub_ep0_rx((uintptr_t)ep0_ctrl_buf);
				usb_fsm_state = DATA_OUT;
			}

		} else {
			/* end of transmission */
			tx_buff_addr = (uintptr_t)ep0_ctrl_buf + act;
			vhub_ep0_tx(tx_buff_addr, chunk);
			usb_req_ctx.actual += chunk;

			/* Go to status stage if payload size is less than MPS or has transferred exactly
			   the amount of data specified during the Setup stage (data_size_max).
			   Otherwise, go to DATA stage again for more data or a ZLP (short transfer). */
			if (chunk < mps || usb_req_ctx.actual == data_size_max)
				usb_fsm_state = LAST_DATA_IN;
			else
				usb_fsm_state = DATA_IN;
		}

	} else {
		/* status stage: send 0 packet */
		vhub_ep0_tx(0, 0);
		usb_fsm_state = STATUS_IN;
	}

	return STS_OKAY;
}

bool usb_is_dnload_done(void)
{
	return is_dnload_done;
}

uint8_t usb_poll(void)
{
	uint32_t istat;
	uint8_t ret;

	istat = readl(VHUB_BASE + VHUB_ISR);
	if (!istat)
		return 0;

	/* Ack interrupts */
	writel(istat, VHUB_BASE + VHUB_ISR);

	if (istat & VHUB_IRQ_HUB_EP0_IN_ACK_STALL) {
		ret = vhub_ep0_in();
		if (ret)
			return ret;
	}

	if (istat & VHUB_IRQ_HUB_EP0_OUT_ACK_STALL) {
		ret = vhub_ep0_out();
		if (ret)
			return ret;
	}

	if (istat & VHUB_IRQ_HUB_EP0_SETUP) {
		ret = vhub_ep0_setup();
		if (ret)
			return ret;
	}

	return 0;
}

void usb_enable(void)
{
	uint32_t val;

	/* Clear USB mode status */
	val = readl(SCU0_REG + SCU_USB_MULTI_CTRL);
	val = val & ~GENMASK(25, 24);
	val = val & ~GENMASK(3, 2);

	/* Select USB2.0 Hub1 as device */
	writel(val | BIT(2), SCU0_REG + SCU_USB_MULTI_CTRL);

	/* Enable vhub reset */
	val = readl(SCU0_REG + SCU_RST_CTRL);
	writel(val | BIT(0), SCU0_REG + SCU_RST_CTRL);

	mdelay(10);

	/* disable vhub reset */
	writel(BIT(0), SCU0_REG + SCU_RST_CTRL + 0x4);

	udelay(1);

	/* Set 16 bits UTMI */
	val = readl(VHUB_BASE + 0x800);
	writel(val & ~BIT(8), VHUB_BASE + 0x800);

	/* Enable SRAM access */
	val = readl(VHUB_BASE + 0x800);
	writel(val | BIT(4), VHUB_BASE + 0x800);

	/* Disable PHY reset */
	val = VHUB_CTRL_PHY_CLK |
	      VHUB_CTRL_PHY_RESET_DIS;

	/* Enable upstream port connection */
	val |= VHUB_CTRL_UPSTREAM_CONNECT;
	writel(val, VHUB_BASE + VHUB_CTRL);

	/* SW reset device controller */
	writel(VHUB_SW_RESET_ROOT_HUB, VHUB_BASE + VHUB_SW_RESET);
	udelay(1);
	writel(0, VHUB_BASE + VHUB_SW_RESET);

	/* enable interrupts */
	writel(VHUB_IRQ_HUB_EP0_IN_ACK_STALL |
	       VHUB_IRQ_HUB_EP0_OUT_ACK_STALL |
	       VHUB_IRQ_HUB_EP0_SETUP |
	       VHUB_IRQ_BUS_RESUME |
	       VHUB_IRQ_BUS_SUSPEND |
	       VHUB_IRQ_BUS_RESET, VHUB_BASE + VHUB_IER);
}
