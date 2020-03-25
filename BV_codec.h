#ifndef BV_CODEC


#define BV_CODEC

#include <stdio.h>

void bvInitialize(void);
// 初始化BV_codec。
// 可以多次调用。

long long bvDec(char x[]);
// 把BV号转换为av号。
// eg bvDec("BV1xx411c7XW")

char * bvEnc(long long x);
// 把av号转换为BV号。
// eg bvEnc(314LL)

#endif