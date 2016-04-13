#include <stdio.h>
#define TEXTLIMIT 50

int gettxt(char text[], int textlimit);
void longestline(char text[], int maxpos[]); 

int main() {
	char text[TEXTLIMIT];
	int i, len;
	int maxpos[2];

	len = gettxt(text, TEXTLIMIT);
	for (i = 0; i < TEXTLIMIT + 10; i++)
		printf("\ni[%d] = %c", i, text[i]);
	longestline(text, maxpos);
	printf("\n\n%s", text);
	printf("\nlongest line starts at %d, length %d\n", maxpos[0], maxpos[1]);
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

void longestline(char text[], int maxpos[]) {
/*	
	Descriprion:
		Function puts start position and length in to array.
		maxpos[start_index, line_length]
	
	Variables:
	i			- index
	startpos	- current line starting position
	curlen		- current line length
*/
	int i, startpos, curlen;

	startpos = 0;
	maxpos[0] = 0;
	maxpos[1] = 0;
	for (i = 0; text[i] != '\0'; i++) {
		if (text[i] == '\n') { 
			curlen = i - startpos;
			if (curlen > maxpos[1]) {
				maxpos[0] = startpos;
				maxpos[1] = curlen;
			}
			startpos = i;
		}
	}
}
