#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[] = "Ipsum Dolor";
	char s2[] = "abxa";
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("any(s1): %d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
/*
 *  Function returns the first location in the string s1 where any character 
 *  from the string s2 occurs, or -1 if s1 contains no characters from s2
 *
*/
{
	int i, j, k;
	for (i = 0; s1[i] != '\0'; i++)
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				return i;
	return -1;
}
