#include <stdio.h>
#define TEXTLIMIT 80
#define TABSIZE 4

int main()
{
	int blank, i, j, c, tabs, spaces;
	char text[TEXTLIMIT];
	i = 0;
	blank = 0; // Spaces counter and blank string indicator
	while ((c = getchar()) != EOF && i < TEXTLIMIT) {
		if (c == ' ' && blank >= 0) // increase value of "blank" if not negative
			blank++;
		if (c != ' ' && c != '\n') {	// a negative value indicates that
			blank = -1;					// the string contains characters 
			putchar(c);					// other than spaces
		}
		if (c == '\n') {
			putchar(c);
			if (blank > 0) {
				printf("Blank string, %d symbols\n", blank);
				printf("Spaces: %d\nTabs: %d\n", blank % TABSIZE, blank / TABSIZE);
			}
			blank = 0;
		}
	}
/*
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
*/
	printf("\n");
	return 0;
}
		
				
