//TODO: 图形化界面
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "bv-api/bv-api.h"

int main(int argc,char *argv[]) {
	register FILE * fi, * fo, * fe;
	bool file = false;
	if (argc == 2) {
		register char * q;
		register const char * const p = argv[1];
		if (!strcmp("-h", p) || !strcmp("--help", p)) {
			fprintf(stderr,
				"-h, --help\tshow this help.\n"
				"[filename]\tconvert the file and write into [filename].txt .\n"
				"\n"
				"WARNING: this Program will overwrite ./latest.log!\n"
				"\n"
			);
			return 0;
		} else {
			register size_t len = strlen(p)+1;
			q = malloc((len+4)*sizeof(char));
			if (!q) {
				fprintf(stderr,
					"Error while eating memory!\n"
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
						file = true;
					}
				}
			}
			free(q);
		}
	}

	register int stat;
	int64_t num;
	char p[13] = {0};
	
	bvInitialize();
	
	while (stat = scanf("%" SCNd64, &num), true) {
		if (feof(stdin)) {
			break;
		}
		
		if (stat) {
			printf("%s\n",bvEnc(num));
		} else {
			scanf("%s",p);
			printf("av%" PRId64 "\n",bvDec(p));
			p[0] = 0;
		}
	}
	if (file) {
		if (fclose(fi)||fclose(fo)||fclose(fe)) {
			fprintf(stderr,"Error while closing files!\n\n");
		}
	}
	return stat;
}
