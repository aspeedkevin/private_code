#ifndef __RECOVERY_H__
#define __RECOVERY_H__

#include <bootstage.h>
#include <rom_context.h>
#include <types.h>
#include <utils.h>
#include <bootdev.h>

enum recovery_errno {
	REC_ERR_SUCCESS,
	REC_ERR_UART_INIT,
	REC_ERR_UART_PORT,
	REC_ERR_UART_CONF,
	REC_ERR_I3C_INIT,
	REC_ERR_RECEIVE_IMG_SZ,
	REC_ERR_ZERO_IMG_SZ,
	REC_ERR_LARGE_IMG_SZ,
	REC_ERR_RECEIVE_DATA,

	REC_ERRNO,
};

/* Bootrom only supoort this two command*/
enum ocp_recovery_command {
	OCP_REC_CTRL = 0x26,
	OCP_INDIRECT_DATA = 0x2B,
};

#define OCP_REC_CTRL_BYTES 3
#define OCP_REC_CTRL_CMS_BYTE 0
#define OCP_REC_CTRL_IMG_SEL_BYTE 1
#define   OCP_REC_CTRL_IMG_SEL_CMS 0x1
#define   OCP_REC_CTRL_IMG_SEL_CIMAGE 0x2
#define OCP_REC_CTRL_ACTIVATE_BYTE 2
#define   OCP_REC_CTRL_ACTIVATE_REC_IMG 0xF

struct i2c_recovey_packet {
	u8 command;
	u8 len;
	u8 payload[255];
};

struct i3c_recovey_packet {
	u8 command;
	u8 len_hi;
	u8 len_lo;
	u8 payload[125];
};

enum recovery_syndrome {
	REC_SYN_SKIP,

	REC_SYNDROME,
};

enum recovery_status {
	REC_PASS,
	REC_FAIL,
	REC_NO_NEED,
};

bootstage_t recovery_boot(struct rom_context *ctx);

void uart_register(struct bootdev *bd);
#endif
