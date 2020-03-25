#include <stdio.h>
#define true 1

char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
long long tr[256] = {0};

char r[] = "BV          ";
long long s[] = {11,10,3,8,4,6,2,9,5,7};
long long xor = 177451812;
long long add = 100618342136696320L;

inline static long long llPow(long long x, unsigned int a) {
	register unsigned int aa = a;
	register long long s = 1;
	for (register unsigned int i=0; i<aa; i++) {
		s *= x;
	}
	return s;
}

long long dec(char x[]) {
	register long long r = 0;
	for (register unsigned int i=0; i<10; i++) {
		r += tr[x[s[i]]]*llPow(58,i);
	}
	return (r-add)^xor;
}

char * enc(long long x) {
	x = (x^xor) + add;
	for (register unsigned int i=0; i<10; i++) {
		r[s[i]] = table[x/llPow(58,i)%58];
	}
	return r;
}

int main(void) {
	int stat;
	long long num;
	char p[13] = {0};
	
	//初始化
	for (register unsigned int i=0; i<58; i++) {
		tr[table[i]] = i;
	}
	
	fprintf(stderr,
	"0 enc 1 dec\n");
	scanf("%d",&stat);
	
	switch (stat) {
		case 0:
			while (!feof(stdin)) {
				scanf("%I64d",&num);
				printf("%s\n",enc(num));
			}
			break;
		case 1:
			while (!feof(stdin)) {
				scanf("%s",p);
				printf("%I64d\n",dec(p));
				p[0] = 0;
			}
			break;
		default:
			return stat;
			break;
	};
	
	return stat;
}