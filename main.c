#include <stdio.h>

char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
long long tr[256] = {0};

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
		r += llPow(tr[x[s[i]]]*58,i);
	}
	return (r-add)^xor;
}

int main(void) {
	for (register unsigned int i=0; i<58; i++) {
		tr[table[i]] = i;
	}
	char p[13] = {0};
	scanf("%s",p);
	printf("%I64d",dec(p));
	return 0;
}

/*
table='fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF'
tr={}
for i in range(58):
	tr[table[i]]=i
s=[11,10,3,8,4,6,2,9,5,7]
xor=177451812
add=100618342136696320

def dec(x):
	r=0
	for i in range(10):
		r+=tr[x[s[i]]]*58**i
	return (r-add)^xor

def enc(x):
	x=(x^xor)+add
	r=list('BV          ')
	for i in range(10):
		r[s[i]]=table[x//58**i%58]
	return ''.join(r)

#print(dec('BV17x411w7KC'))
#print(dec('BV1Q541167Qg'))
#print(dec('BV1mK4y1C7Bz'))
#print(enc(170001))
#print(enc(455017605))
#print(enc(882584971))
print('av'+str(dec(input())))
#print(enc(input()))
*/
