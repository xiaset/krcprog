#include <stdio.h>
#define S1MAXLN 50
#define S2MAXLN 50

int getlinex(char line[], int limit);
int strindex(char s[], char t[]);
int printarray(char text[], int limit);

int main()
{
	char s1[S1MAXLN];
	char s2[S2MAXLN];

	printf("\npattern: ");
	getlinex(s2, S2MAXLN);
	printf("\ntext:\n");
	while (getlinex(s1, S1MAXLN) > 0)
		if (strindex(s1, s2) >= 0)
			printf("%s", s1);
	return 0;
}

int getlinex(char line[],int limit)
{
	int c, i;

	i = 0;
	while (--limit > 0 && (c=getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (k = i, j = 0; 
			s[k] == t[j] && t[j] != '\0' && s[k] != '\0';
			k++, j++)
			;
		if (t[++j] == '\0' && j > 0)
			return i;
	}
	return -1;
}
