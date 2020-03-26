#include <stdio.h>

#include "bv-api/bv-api.h"

int main(void) {
	int stat;
	long long num;
	char p[13] = {0};
	
	bvInitialize();
	
	fprintf(stderr,
	"0 enc 1 dec\n");
	scanf("%d",&stat);
	
	switch (stat) {
		case 0:
			while (!feof(stdin)) {
				scanf("%I64d",&num);
				printf("%s\n",bvEnc(num));
			}
			break;
		case 1:
			while (!feof(stdin)) {
				scanf("%s",p);
				printf("av%I64d\n",bvDec(p));
				p[0] = 0;
			}
			break;
		default:
			return stat;
			break;
	};
	
	return stat;
}
