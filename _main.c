#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bv-api/bv-api.h"

int main(int argc,char *argv[]) {
	register FILE * fi, * fo, * fe;
	_Bool file = 0;
	if (argc == 2) {
		register char * q;
		register const char * const p = argv[1];
		if (!strcmp("-h", p) || !strcmp("--help", p)) {
			fprintf(stderr,
				"-h, --help\tshow this help.\n"
				"[filename]\tconvert the file and write into [filename].txt .\n"
				"\n"
			);
			return 0;
		} else {
			register size_t len = strlen(p)+1;
			q = malloc((len+4)*sizeof(char));
			if (!q) {
				fprintf(stderr,
					"Error while mallocing memory!\n"
					"\n"
				);
				return 0;
			}
			memcpy(q, p, len);

			strcat(q, ".txt");
			if (!(fi = freopen(p, "r", stdin))) {
				fprintf(stderr,
					"File redirecting failed!\n"
					"Do you have the permissions needed?\n"
					"\n"
				);
				free(q);
				return 0;
			} else {
				if (!(fo = freopen(q, "w", stdout))) {
					fprintf(stderr,
						"File redirecting failed!\n"
						"Do you have the permissions needed?\n"
						"\n"
					);
					free(q);
					fclose(fi);
					return 0;
				} else {
					if (!(fe = freopen("latest.log", "w", stderr))) {
						fprintf(stderr,
							"File redirecting failed!\n"
							"Do you have the permissions needed?\n"
							"\n"
						);
						free(q);
						fclose(fi);
						fclose(fo);
						return 0;
					} else {
						file = 1;
					}
				}
			}
			free(q);
		}
	}

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
	
	if (file) {
		if (fclose(fi)||fclose(fo)||fclose(fe)) {
			fprintf(stderr,"Error while closing files!\n\n");
		}
	}
	return stat;
}
