#include <stdio.h>
#define TEXTLIMIT 100

int gettxt(char text[], int textlimit);

int main() {
	char text[TEXTLIMIT];
	int i, len;

	len = gettxt(text, TEXTLIMIT);
	for (i = 0; i < TEXTLIMIT; i++)
		printf("%d x ", text[i]);
	printf("\n\n%s", text);
	return 0;

}

int gettxt(char text[], int textlimit) {
	int i;
	int c;
	for (i = 0; ((i < textlimit) && (c = getchar()) != EOF); i++)
		text[i] = c;
	text[i] = '\0';
	return i;
}
