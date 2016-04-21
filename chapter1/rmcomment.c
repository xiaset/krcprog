#include <stdio.h>
#define UEOL 2
#define IN 1
#define OUT 0
#define BACKSPACE 8
#define MAXLENGTH 900

int main() {
	int i, c, pre, state, prestate;
	pre = prestate = i = state = 0;
	while ((c = getchar()) != EOF) {
		if (pre == '/' && c == '/') {
			state = UEOL;
			putchar(BACKSPACE);
		}
		if (pre == '/' && c == '*') {
			state = IN;
			putchar(BACKSPACE);
		} 
		if (pre == '*' && c == '/')
			state = OUT;
		if (c == '\n' && state == UEOL)
			state = OUT;
		if (state == OUT && prestate == OUT)
			putchar(c);
		pre = c;
		prestate = state;
	}
	return 0;
}
