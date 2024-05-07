#ifndef __SHA256_H__
#define __SHA256_H__

#include <types.h>

#define SHA256_SUM_SIZE	32
#define SHA256_BLK_SIZE	64

struct sha256_context {
	uint32_t total[2];
	uint32_t state[8];
	uint8_t buffer[SHA256_BLK_SIZE];
};

void sha256_init(struct sha256_context *ctx);
void sha256_update(struct sha256_context *ctx, const uint8_t *input, uint32_t length);
void sha256_finish(struct sha256_context *ctx, uint8_t digest[SHA256_SUM_SIZE]);

#endif
