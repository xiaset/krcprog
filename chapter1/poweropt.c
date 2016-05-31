#include <stdio.h>

unsigned long long power(int base, int n) {
	unsigned long long p[2];
	int i;
	p[0] = base;	
	for (i = 1; i < n ; i++) {
		p[1] = p[0] * base;
		p[0] = p[1];
	}
	return p[1];
}

int main() {
	int base, n;
	printf("%llu\n", power(2, 63));
	return 0;
}
