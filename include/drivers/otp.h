#ifndef __OTP_H__
#define __OTP_H__

#include <types.h>

enum otp_errno {
	OTP_ERR_SUCCESS = 0,
	OTP_ERR_GENERIC,
	OTP_ERR_READ,
	OTP_ERR_PROG,
	OTP_ERR_CMP,
	OTP_ERR_INVAL,
};

int otp_read_data(uint32_t offset, uint16_t *data);

#endif /* __OTP_H__ */
