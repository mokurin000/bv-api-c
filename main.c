#include <stdio.h>

char table[] = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
char tr[256] = {0};

long long s[] = {11,10,3,8,4,6,2,9,5,7};
long long xor = 177451812;
long long add = 100618342136696320;

int main(void) {
	for (register char i=0; i<58; i++)
		tr[table[i]] = i;
}


//---------
/*
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

print(dec('BV17x411w7KC'))
print(dec('BV1Q541167Qg'))
print(dec('BV1mK4y1C7Bz'))
print(enc(170001))
print(enc(455017605))
print(enc(882584971))
*/
