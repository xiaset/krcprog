#include <stdio.h>
#define S1MAXLN 50
#define S2MAXLN 300

int expand(char s1[], char s2[]);

int main()
{


}

int expand(char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] == '-' && i != 0) {
			if (s[i-1] >= 'a' && s[i-1] <= 'z' &&
				s[i+1] >= 'a' && s[i+1] <= 'z' &&
				s[i+1] - s[i-1] > 0) {
					for (k = 0; k < s1[i+1] - s1[i-1]; k++)
						s2[j++] = s1[i-1] + k;
			}
		
		}
		
	}
}
