#include <stdio.h>
#define SMAXLENGTH	50
#define TMAXLENGTH	100

int escape(char s[], char t[]);
int gettxt(char text[], int textlimit);
int printarray(char text[], int limit);

int main()
{
	char s[SMAXLENGTH];
	char t[TMAXLENGTH];
	gettxt(s, SMAXLENGTH);
	escape(s, t);
	printf("\ns:\n");
	printarray(s, TMAXLENGTH);
	printf("\nt:\n");
	printarray(t, TMAXLENGTH);
	printf("\n\n");
	return 0;
}

int escape(char s[], char t[])
/*
 *
 * Function escape(s,t) converts characters like newline and tab into 
 * visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch . Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 *
*/
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case 'n':
			if (s[i-1] == '\\') {
				t[--j] = '\n';
				j++;
			}
			break;
		case 't':
			if (s[i-1] == '\\') {
                t[--j] = '\t';
                j++;
            }

			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
	return 0;
}

int gettxt(char text[], int textlimit)
{
	int i;
	int c;
	for (i = 0; ((i < textlimit) && (c = getchar()) != EOF); i++)
		text[i] = c;
	text[i] = '\0';
	return i;
}

int printarray(char text[], int limit)
{
	int i;
	for (i = 0; i < limit && text[i] != '\0'; i++)
		printf("%c", text[i]);
//		printf("[%2d]= %3c (%3d)\n", i, text[i], text[i]);
	return i;
}

