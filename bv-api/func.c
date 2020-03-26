#include "bv-api.h"

static const char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
static long long tr[256] = {0};

static char r[] = "BV          ";
static long long s[] = {11,10,3,8,4,6,2,9,5,7};
static long long xor = 177451812LL;
static long long add = 100618342136696320LL;

void bvInitialize(void) {
	for (register unsigned int i=0; i<58; i++) {
		tr[(size_t)table[i]] = i;
	}
}

inline static long long bvllPow(long long x, unsigned int a) {
	register unsigned int aa = a;
	register long long s = 1;
	for (register unsigned int i=0; i<aa; i++) {
		s *= x;
	}
	return s;
}

long long bvDec(char x[]) {
	register long long r = 0;
	for (register unsigned int i=0; i<10; i++) {
		r += tr[x[s[i]]]*bvllPow(58,i);
	}
	return (r-add)^xor;
}

char * bvEnc(long long x) {
	x = (x^xor) + add;
	for (register unsigned int i=0; i<10; i++) {
		r[s[i]] = table[x/bvllPow(58,i)%58];
	}
	return r;
}