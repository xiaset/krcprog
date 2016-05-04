#include <stdio.h>
#include <string.h>

#define STR "0x7c5"

int htoi(char s[]);
int power(int base, int n);

int main() {
	char s[] = "0x7c5";
	printf("%x\n", htoi(s));
	return 0;
}

int htoi(char s[]) {
	int i, n, q;
	n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else
		i = 0;
	q = strlen(s) - i - 1;
	while (i < strlen(s)) {
		if (s[i] >= '0' && s[i] <= '9')
			n = n + (s[i] - '0') * power(0x10, q);
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = n + (s[i] - 'a' + 0xa) * power(0x10, q);
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n + (s[i] - 'A' + 0xa) * power(0x10, q);
		else
			return -1;
		i++;
		q--;
	}
	return n;
}

int power(int base, int n) {
        int p;
        int i;
        p = 1;
        for (i = 0; i < n; i++)
                p = p * base;
        return p;
}
