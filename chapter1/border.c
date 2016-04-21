#include <stdio.h>
#define LINELIMIT 2000
#define BORDER 80

int printarray(char text[], int limit);

int main() {
	char line[LINELIMIT];
	int length, i, c, lastblank;

	length = i = lastblank = 0;

	while ((c = getchar()) != EOF && i < LINELIMIT) {
		line[i] = c;
		if (c == ' ' || c == '\t')
			lastblank = i;
		if (c == '\n') 
			length = 0;
//		printf("\n**i=%d, c=%c, lenght=%d, lastblank=%d", i, c, length, lastblank);
		if (length >= BORDER && lastblank > 0) {
			line[lastblank] = '\n';
//			printf("\n***LENGTH before %d***\n", length);
			length = i - lastblank;
			lastblank = 0;
//			printf("\n***LENGTH after %d***\n", length);
		}
		length++;
		i++;
	}
	line[i] = '\0';
//	printarray(line, LINELIMIT);
	printf("\nLine:\n%s\n", line);
	return 0;
}

int printarray(char text[], int limit) {
	int i;
	for (i = 0; i < limit; i++)
		printf("[%2d]= %3c (%3d)\n", i, text[i], text[i]);
	return i;
}
