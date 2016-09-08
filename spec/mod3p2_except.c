#include <stdio.h>
#define BIN_LEN 8

void printbin (int x, char bin[]);
void printchararr(char arr[], int limit);

int main()
{
	char bin[BIN_LEN];
	unsigned char a=1;
	a = 129;
	printbin(a, bin);
	a = ~a;
	printbin(a, bin);
	return 0;
}

void printbin(int x, char bin[])
{

/*
 * printbin(int number, char binary_representaion[]) return array with 1 and 0 that represents integer number
 * 
*/
	int j, i=0;
	char buf;
	printf("a = %d\n", x);
	for (i = 0; i < BIN_LEN; i++)
		bin[i] = 0;
	i = 0;
	while (x > 0) {
		bin[i] = x % 2;
		x /= 2;
		i++;
	}
	for (i = BIN_LEN-1; i >= 0; i--) {
		printf("%d", bin[i]);
		i % 4 == 0 && printf(" ");
	}
	printf("\n");
}
