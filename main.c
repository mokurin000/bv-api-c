#include <stdio.h>
#include <string.h>

#include "bv-api/bv-api.h"

#define true 1

int main(int argc,char *argv[]) {
	if (argv == 2) {
		register const char * const p = argv[1];
		if (!strcmp("-h",p)||!strcmp("--help",p)) {
			fprintf(stderr,
				"-h, --help\tshow this help.\n"
				"[filename]\tconvert the file and write into [filename].txt .\n"
				"\n"
			);
			return 0;
		} else {
			register size_t len = strlen(p)+1;
			register char * const q = memcpy(malloc((len+4)*sizeof(char)), p, len);
			if (!q) {
				fprintf(stderr,
					"Error while malloc memory!\n"
					"\n"
				);
				return 0;
			}

			strcat(q, ".txt");
			if (freopen(p, "r", stdin) || freopen(p, "r", stdout)) {
				fprintf(stderr,
					"File redirecting failed!\n"
					"Do you have the permissions needed?\n"
					"\n"
				);
				return 0;
			}
		}
	}

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