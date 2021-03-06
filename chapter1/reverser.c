#include <stdio.h>
#define TEXTLIMIT 50
#define LINELIMIT 20

int getliner(char line[], int limit);
int gettxt(char text[], int limit);
int getstripedline(char line[], int limit);
void longestline(char text[], int maxpos[]); 
void reverse(char text[]);

int main() {
	char text[TEXTLIMIT];
	char line[LINELIMIT];
	int i, len;
	int maxpos[2];
	len = 2;
	while (len >= 2) {
		len = getstripedline(line, LINELIMIT);
		reverse(line);
		printf("\nReversed line: %s\n", line);
	}
	return 0;

}

int getstripedline(char line[], int limit) {
	int i, c, pre, stripsz;
	pre = ' ';
	stripsz = 0;
	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
		// counts the continuous number of spaces and tabs
		if ((c == ' ' || c == '\t') && (pre == ' ' || pre == '\t'))
			stripsz++;
		else
			stripsz = 0;
	}
	i -= stripsz;	// reduce the length of the string to the number of spaces
	if (c == '\n' && i != 0) {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	
	printf("\nStripe size: %d\n", stripsz);
	return i;
}

int getliner(char line[],int limit) {
	int i, c;
	for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
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

void reverse(char text[]) {
	int length, i, tmpc;
	for (length = 0; text[length] != '\n'; length++)
		;
	if (text[length] == '\n')
		length--;
	for (i = 0; i <= length  / 2; i++) {
		tmpc = text[length - i];
		text[length - i] = text[i];
		text[i] = tmpc;
	}
}
