#include <stdio.h>
#define BIN_LEN 32

void printbin (int x, char bin[]);
void printchararr(char arr[], int limit);

int main()
{
	char bin[BIN_LEN];
	int a=1, b=1;
	a > 0 || b++;
	printf("\nb = %d\n", b);
	a = 5683;
	printbin(a, bin);
	return 0;
}

void printbin(int x, char bin[])
{
	int j, i=0;
	char buf;
	printf("\nx = %d\n", x);
	while (x > 0) {
		bin[i] = x % 2;
		x /= 2;
		i++;
	}
	for (j = 0; j < i; j++) {
		buf = bin[j];
		bin[j] = bin[i];
		bin[i] = buf;
		i--;
	}
	printchararr(bin, BIN_LEN);
}

void printchararr(char arr[], int limit)
{
	int i;
	printf("\n");
	for (i = 0; i < limit; i++)
		printf("%d", arr[i]);
	printf("\n");
}
