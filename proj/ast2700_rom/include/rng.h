#ifndef __RNG_H__
#define __RNG_H__

#include <rom_context.h>

/* rng init errno */
#define RNG_SUCCESS			0
#define RNG_ERR_INIT			1
#define RNG_ERR_REGISTER		2
#define RNG_ERR_SELF_TEST		4

/* rng init syndrome */
#define RNG_NIST			0
#define RNG_SCU				1

bootstage_t rng_init(struct rom_context *rom_ctx);
bool is_rng_ready(void);
bool is_nisttrng_ready(void);

#endif /* __RNG_H__ */
