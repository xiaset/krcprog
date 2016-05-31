#include <stdio.h>

unsigned long long power(int base, int n) {
	unsigned long long p;
	int i;
	p = 1;	
	for (i = 0; i < n; i++)
		p = p * base;
	return p;
}

int main() {
	int base, n;
	printf("%llu\n", power(2, 63));
	return 0;
}
