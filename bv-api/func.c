#include "bv-api.h"
#include <stddef.h>

static const char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
static int64_t tr[256] = {0};

static char r[] = "BV1  4 1 7  ";
static int64_t s[] = {11,10,3,8,4,6};
static int64_t xor = INT64_C(177451812);
static int64_t add = INT64_C(8728348608);

void bvInitialize(void) {
	for (uint_fast16_t i=0; i<58; i++) {
		tr[(size_t)table[i]] = i;
	}
}

inline static int64_t i64Pow(int64_t x, uint_fast16_t a) {
	int64_t s = 1;
	for (uint_fast16_t i=0; i<a; i++) {
		s *= x;
	}
	return s;
}

int64_t bvDec(char x[]) {
	int64_t r = 0;
	for (uint_fast16_t i=0; i<6; i++) {
		r += tr[(size_t)x[s[i]]]*i64Pow(58,i);
	}
	return (r-add)^xor;
}

char * bvEnc(int64_t x) {
	x = (x^xor) + add;
	for (uint_fast16_t i=0; i<6; i++) {
		r[s[i]] = table[x/i64Pow(58,i)%58];
	}
	return r;
}
