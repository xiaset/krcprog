#include <stdio.h>
#define S1MAXLN 50
#define S2MAXLN 150

int expand(char s1[], char s2[]);
int gettxt(char text[], int textlimit);
int printarray(char text[], int limit);


int main()
{
	char s1[S1MAXLN];
	char s2[S2MAXLN];
	gettxt(s1, S1MAXLN);
	expand(s1, s2);
	printf("\ns1:\n");
	printarray(s1, S2MAXLN);
	printf("\ns2:\n");
	printarray(s2, S2MAXLN);
	printf("\n\n");
	return 0;
	

}

int expand(char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; i++) {
		if ((s1[i] == '-' && i != 0 && (s1[i+1] - s1[i-1]) > 0) &&
			((s1[i-1] >= 'a' && s1[i-1] <= 'z' &&
			s1[i+1] >= 'a' && s1[i+1] <= 'z') ||
			(s1[i-1] >= 'A' && s1[i-1] <= 'Z' &&
			s1[i+1] >= 'A' && s1[i+1] <= 'Z') ||
			(s1[i-1] >= '0' && s1[i-1] <= '9' &&
			s1[i+1] >= '0' && s1[i+1] <= '9'))) {
			for (k = 1; k <= s1[i+1] - s1[i-1]; k++) {
				s2[j++] = s1[i-1] + k;
			}
			i++;
		} else
		s2[j++] = s1[i];
	}
	s2[j] = '\0';
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

