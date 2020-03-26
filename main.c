#include <stdio.h>

#include "BV_API/BV_API.h"

#define true 1

int main(void) {
	register int stat;
	long long num;
	char p[13] = {0};
	
	bvInitialize();
	
	while (stat = scanf("%I64d", &num), true) {
		if (feof(stdin)) {
			break;
		}
		
		if (stat) {
			printf("%s\n",bvEnc(num));
		} else {
			scanf("%s",p);
			printf("av%I64d\n",bvDec(p));
			p[0] = 0;
		}
	}
	return stat;
}