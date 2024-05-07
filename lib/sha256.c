#include <lib/sha256.h>
#include <lib/string.h>
#include <utils.h>

static uint8_t sha256_padding[SHA256_BLK_SIZE] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

#define SHR(x,n) ((x & 0xFFFFFFFF) >> n)
#define ROTR(x,n) (SHR(x,n) | (x << (32 - n)))

#define S0(x) (ROTR(x, 7) ^ ROTR(x,18) ^ SHR(x, 3))
#define S1(x) (ROTR(x,17) ^ ROTR(x,19) ^ SHR(x,10))

#define S2(x) (ROTR(x, 2) ^ ROTR(x,13) ^ ROTR(x,22))
#define S3(x) (ROTR(x, 6) ^ ROTR(x,11) ^ ROTR(x,25))

#define F0(x,y,z) ((x & y) | (z & (x | y)))
#define F1(x,y,z) (z ^ (x & (y ^ z)))

static uint32_t R(uint32_t t, uint32_t W[64])
{
	W[t] = S1(W[t - 2]) + W[t - 7] + S0(W[t - 15]) + W[t - 16];

	return W[t];
}

static void P(uint32_t a, uint32_t b, uint32_t c, uint32_t *d,
	      uint32_t e, uint32_t f, uint32_t g, uint32_t *h,
	      uint32_t x, uint32_t K)
{
	uint32_t temp1, temp2;

	temp1 = *h + S3(e) + F1(e, f, g) + K + x;
	temp2 = S2(a) + F0(a, b, c);

	*d = *d + temp1;
	*h = temp1 + temp2;
}

static void sha256_process_block(struct sha256_context *ctx, const uint8_t data[SHA256_BLK_SIZE])
{
	uint32_t A, B, C, D, E, F, G, H;
	uint32_t temp1;
	uint32_t W[64];
	int i;

	for (i = 0; i < 16; ++i) {
		temp1 = *(uint32_t *)(data + (i << 2));
		W[i] = BSWAP_32(temp1);
	}

	A = ctx->state[0];
	B = ctx->state[1];
	C = ctx->state[2];
	D = ctx->state[3];
	E = ctx->state[4];
	F = ctx->state[5];
	G = ctx->state[6];
	H = ctx->state[7];

	P(A, B, C, &D, E, F, G, &H, W[0], 0x428A2F98);
	P(H, A, B, &C, D, E, F, &G, W[1], 0x71374491);
	P(G, H, A, &B, C, D, E, &F, W[2], 0xB5C0FBCF);
	P(F, G, H, &A, B, C, D, &E, W[3], 0xE9B5DBA5);
	P(E, F, G, &H, A, B, C, &D, W[4], 0x3956C25B);
	P(D, E, F, &G, H, A, B, &C, W[5], 0x59F111F1);
	P(C, D, E, &F, G, H, A, &B, W[6], 0x923F82A4);
	P(B, C, D, &E, F, G, H, &A, W[7], 0xAB1C5ED5);
	P(A, B, C, &D, E, F, G, &H, W[8], 0xD807AA98);
	P(H, A, B, &C, D, E, F, &G, W[9], 0x12835B01);
	P(G, H, A, &B, C, D, E, &F, W[10], 0x243185BE);
	P(F, G, H, &A, B, C, D, &E, W[11], 0x550C7DC3);
	P(E, F, G, &H, A, B, C, &D, W[12], 0x72BE5D74);
	P(D, E, F, &G, H, A, B, &C, W[13], 0x80DEB1FE);
	P(C, D, E, &F, G, H, A, &B, W[14], 0x9BDC06A7);
	P(B, C, D, &E, F, G, H, &A, W[15], 0xC19BF174);
	P(A, B, C, &D, E, F, G, &H, R(16, W), 0xE49B69C1);
	P(H, A, B, &C, D, E, F, &G, R(17, W), 0xEFBE4786);
	P(G, H, A, &B, C, D, E, &F, R(18, W), 0x0FC19DC6);
	P(F, G, H, &A, B, C, D, &E, R(19, W), 0x240CA1CC);
	P(E, F, G, &H, A, B, C, &D, R(20, W), 0x2DE92C6F);
	P(D, E, F, &G, H, A, B, &C, R(21, W), 0x4A7484AA);
	P(C, D, E, &F, G, H, A, &B, R(22, W), 0x5CB0A9DC);
	P(B, C, D, &E, F, G, H, &A, R(23, W), 0x76F988DA);
	P(A, B, C, &D, E, F, G, &H, R(24, W), 0x983E5152);
	P(H, A, B, &C, D, E, F, &G, R(25, W), 0xA831C66D);
	P(G, H, A, &B, C, D, E, &F, R(26, W), 0xB00327C8);
	P(F, G, H, &A, B, C, D, &E, R(27, W), 0xBF597FC7);
	P(E, F, G, &H, A, B, C, &D, R(28, W), 0xC6E00BF3);
	P(D, E, F, &G, H, A, B, &C, R(29, W), 0xD5A79147);
	P(C, D, E, &F, G, H, A, &B, R(30, W), 0x06CA6351);
	P(B, C, D, &E, F, G, H, &A, R(31, W), 0x14292967);
	P(A, B, C, &D, E, F, G, &H, R(32, W), 0x27B70A85);
	P(H, A, B, &C, D, E, F, &G, R(33, W), 0x2E1B2138);
	P(G, H, A, &B, C, D, E, &F, R(34, W), 0x4D2C6DFC);
	P(F, G, H, &A, B, C, D, &E, R(35, W), 0x53380D13);
	P(E, F, G, &H, A, B, C, &D, R(36, W), 0x650A7354);
	P(D, E, F, &G, H, A, B, &C, R(37, W), 0x766A0ABB);
	P(C, D, E, &F, G, H, A, &B, R(38, W), 0x81C2C92E);
	P(B, C, D, &E, F, G, H, &A, R(39, W), 0x92722C85);
	P(A, B, C, &D, E, F, G, &H, R(40, W), 0xA2BFE8A1);
	P(H, A, B, &C, D, E, F, &G, R(41, W), 0xA81A664B);
	P(G, H, A, &B, C, D, E, &F, R(42, W), 0xC24B8B70);
	P(F, G, H, &A, B, C, D, &E, R(43, W), 0xC76C51A3);
	P(E, F, G, &H, A, B, C, &D, R(44, W), 0xD192E819);
	P(D, E, F, &G, H, A, B, &C, R(45, W), 0xD6990624);
	P(C, D, E, &F, G, H, A, &B, R(46, W), 0xF40E3585);
	P(B, C, D, &E, F, G, H, &A, R(47, W), 0x106AA070);
	P(A, B, C, &D, E, F, G, &H, R(48, W), 0x19A4C116);
	P(H, A, B, &C, D, E, F, &G, R(49, W), 0x1E376C08);
	P(G, H, A, &B, C, D, E, &F, R(50, W), 0x2748774C);
	P(F, G, H, &A, B, C, D, &E, R(51, W), 0x34B0BCB5);
	P(E, F, G, &H, A, B, C, &D, R(52, W), 0x391C0CB3);
	P(D, E, F, &G, H, A, B, &C, R(53, W), 0x4ED8AA4A);
	P(C, D, E, &F, G, H, A, &B, R(54, W), 0x5B9CCA4F);
	P(B, C, D, &E, F, G, H, &A, R(55, W), 0x682E6FF3);
	P(A, B, C, &D, E, F, G, &H, R(56, W), 0x748F82EE);
	P(H, A, B, &C, D, E, F, &G, R(57, W), 0x78A5636F);
	P(G, H, A, &B, C, D, E, &F, R(58, W), 0x84C87814);
	P(F, G, H, &A, B, C, D, &E, R(59, W), 0x8CC70208);
	P(E, F, G, &H, A, B, C, &D, R(60, W), 0x90BEFFFA);
	P(D, E, F, &G, H, A, B, &C, R(61, W), 0xA4506CEB);
	P(C, D, E, &F, G, H, A, &B, R(62, W), 0xBEF9A3F7);
	P(B, C, D, &E, F, G, H, &A, R(63, W), 0xC67178F2);

	ctx->state[0] += A;
	ctx->state[1] += B;
	ctx->state[2] += C;
	ctx->state[3] += D;
	ctx->state[4] += E;
	ctx->state[5] += F;
	ctx->state[6] += G;
	ctx->state[7] += H;
}

void sha256_init(struct sha256_context *ctx)
{
	ctx->total[0] = 0;
	ctx->total[1] = 0;

	ctx->state[0] = 0x6A09E667;
	ctx->state[1] = 0xBB67AE85;
	ctx->state[2] = 0x3C6EF372;
	ctx->state[3] = 0xA54FF53A;
	ctx->state[4] = 0x510E527F;
	ctx->state[5] = 0x9B05688C;
	ctx->state[6] = 0x1F83D9AB;
	ctx->state[7] = 0x5BE0CD19;
}

void sha256_update(struct sha256_context *ctx, const uint8_t *input, uint32_t length)
{
	uint32_t left, fill;

	if (!length)
		return;

	left = ctx->total[0] & 0x3F;
	fill = SHA256_BLK_SIZE - left;

	ctx->total[0] += length;
	ctx->total[0] &= 0xFFFFFFFF;

	if (ctx->total[0] < length)
		ctx->total[1]++;

	if (left && length >= fill) {
		memcpy((void *)(ctx->buffer + left), (void *)input, fill);
		sha256_process_block(ctx, ctx->buffer);
		length -= fill;
		input += fill;
		left = 0;
	}

	while (length >= SHA256_BLK_SIZE) {
		sha256_process_block(ctx, input);
		input += SHA256_BLK_SIZE;
		length -= SHA256_BLK_SIZE;
	}

	if (length)
		memcpy((void *)(ctx->buffer + left), (void *)input, length);
}

void sha256_finish(struct sha256_context *ctx, uint8_t digest[SHA256_SUM_SIZE])
{
	uint32_t last, padn;
	uint32_t high, low;
	uint32_t msglen[2];
	uint32_t i, *p32;

	high = ((ctx->total[0] >> 29)
		| (ctx->total[1] << 3));
	low = (ctx->total[0] << 3);

	msglen[0] = BSWAP_32(high);
	msglen[1] = BSWAP_32(low);

	last = ctx->total[0] & 0x3F;
	padn = (last < 56) ? (56 - last) : (120 - last);

	sha256_update(ctx, sha256_padding, padn);
	sha256_update(ctx, (uint8_t *)msglen, sizeof(msglen));

	for (i = 0, p32 = (uint32_t *)digest; i < 8; ++i, p32++)
		*p32 = BSWAP_32(ctx->state[i]);
}
