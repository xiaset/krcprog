#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	printf("%d\n", invert(101, 7, 3));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
/*
 * Function invert(x,p,n) returns x with the n bits that begin at position p 
 * inverted (i.e., 1 changed into 0 and vice versa), leaving the others 
 * unchanged.
 *
*/
{
	return x = x ^ (~(~0 << n) << (p - n));
}
