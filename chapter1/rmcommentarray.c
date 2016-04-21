#include <stdio.h>
#define UEOL 2
#define IN 1
#define OUT 0
#define BACKSPACE 8
#define MAXLENGTH 2000

int printarray(char text[], int limit);

int main() {
	int i, c, pre, state, prestate;
	char text[MAXLENGTH];
	pre = prestate = i = state = 0;
	while ((c = getchar()) != EOF) {
		if (pre == '/' && c == '/') {
			state = UEOL;
			i--;
		}
		if (pre == '/' && c == '*') {
			state = IN;
			i--;
		} 
		if (pre == '*' && c == '/')
			state = OUT;
		if (c == '\n' && state == UEOL)
			state = OUT;
		if (state == OUT && (prestate == OUT || prestate == UEOL)) {
			text[i] = c;
			i++;
		}
		pre = c;
		prestate = state;
	}
	text[i] = '\0';
	printf("\n%s\n", text);
	//printarray(text, MAXLENGTH);
	return 0;
}

int printarray(char text[], int limit) {
	int i;
	for (i = 0; i < limit; i++)
		printf("%c", text[i]);
//		printf("[%2d]= %3c (%3d)\n", i, text[i], text[i]);
	return i;
}
