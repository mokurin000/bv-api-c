#include "bv-api.h"
#include <stddef.h>

static const char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
static int64_t tr[256] = {0};

static char r[] = "BV          ";
static int64_t s[] = {11,10,3,8,4,6,2,9,5,7};
static int64_t xor = INT64_C(177451812);
static int64_t add = INT64_C(100618342136696320);

void bvInitialize(void) {
	for (register uint_fast16_t i=0; i<58; i++) {
		tr[(size_t)table[i]] = i;
	}
}

inline static int64_t bvi64Pow(int64_t x, uint_fast16_t a) {
	register uint_fast16_t aa = a;
	register int64_t s = 1;
	for (register uint_fast16_t i=0; i<aa; i++) {
		s *= x;
	}
	return s;
}

int64_t bvDec(char x[]) {
	register int64_t r = 0;
	for (register uint_fast16_t i=0; i<10; i++) {
		r += tr[(size_t)x[s[i]]*bvi64Pow(58,i)];
	}
	return (r-add)^xor;
}

char * bvEnc(int64_t x) {
	x = (x^xor) + add;
	for (register uint_fast16_t i=0; i<10; i++) {
		r[s[i]] = table[x/bvi64Pow(58,i)%58];
	}
	return r;
}
