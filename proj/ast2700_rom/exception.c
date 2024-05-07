#include <csr.h>
#include <drivers/rv_timer.h>
#include <errno.h>
#include <exception.h>
#include <lib/printf.h>
#include <panic.h>

#define MIE_MTI	BIT(7)
#define MIP_MTI	BIT(7)

static struct exception_callback except_cbs[32];

int exception_callback_register(uint32_t code, int (*cb)(void *cb_arg, uint32_t *epc), void *cb_arg)
{
	uint32_t mie_mask = 0x0;
	uint32_t mip_mask = 0x0;

	switch (code) {
	case MCAUSE_CODE_MTI:
		mie_mask = MIE_MTI;
		mip_mask = MIP_MTI;
		break;
	default:
		return -EINVAL;
	}

	if (except_cbs[code].cb)
		return -EBUSY;

	except_cbs[code].cb_arg = cb_arg;
	except_cbs[code].cb = cb;

	csr_clear(mip, mip_mask);
	csr_set(mie, mie_mask);

	return 0;
}

int exception_callback_deregister(uint32_t code)
{
	uint32_t bit;

	switch (code) {
	case MCAUSE_CODE_MTI:
		bit = 7;
		break;
	default:
		return -EINVAL;
	}

	csr_clear(mie, bit);
	csr_clear(mip, bit);

	except_cbs[code].cb = NULL;
	except_cbs[code].cb_arg = NULL;

	return 0;
}

uint32_t do_exception(uint32_t mcause, uint32_t mepc)
{
	uint32_t code = FIELD_GET(MCAUSE_CODE, mcause);

	/* synchronous exceptions are NOT expected */
	if (!(mcause & MCAUSE_INTERRUPT))
		panic(NULL);

	/* nobody care? panic though */
	if (!except_cbs[code].cb)
		panic(NULL);

	except_cbs[code].cb(except_cbs[code].cb_arg, &mepc);

	return mepc;
}
