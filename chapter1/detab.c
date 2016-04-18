#include <stdio.h>
#define TEXTLIMIT 80
#define TABSIZE 4

int main()
{
	int i, j, c;
	char text[TEXTLIMIT];
	i = 0;
	while ((c = getchar()) != EOF && i < TEXTLIMIT) {
		if (c == '\t') {
			for (j = (i / 4) * 4 + TABSIZE; i < j; i++)
				text[i] = ' ';
		} else {
			text[i] = c;
			i++;
		}
	}
	text[i] = '\0';
	
	for (i = 0; i < TEXTLIMIT - 50; i++) {
		printf(" %3d ", text[i]);
	}
	printf("\n");
	for (i = 0; i < TEXTLIMIT - 50; i++) {
		printf(" %3c ", text[i]);
	}
	printf("\n");
	for (i = 0; i < TEXTLIMIT - 50; i++) {
		printf(" %3d ", i);
	}
	printf("\n");
	return 0;
}
		
				
