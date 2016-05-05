#include <stdio.h>

int squeeze(char s1[], char s2[]);

int main()
{
	char s1[] = "Ipsum Dolor";
	char s2[] = "po";
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	squeeze(s1, s2);
	printf("squeze(s1): %s\n", s1);
	return 0;
}

int squeeze(char s1[], char s2[])
/*
 *  Alternate version of squeeze(s1,s2) that deletes each character 
 *  in the string s1 that matches any character in the string s2.
 *
*/
{
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; k >= 0 && s2[k] != '\0'; k++) {
			if (s1[i] == s2[k])
				k = -2;
		}
		if (k > 0)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
	return j-1;
}
