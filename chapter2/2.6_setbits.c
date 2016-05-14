#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	printf("%u\n", setbits(255, 7, 4, 13));
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
/*
 * Function setbits(x,p,n,y) that returns x with the n bits that begin at 
 * position p set to the rightmost n bits of y, leaving the other bits 
 * unchanged.
 *
*/
{
	x = x & ~(~(~0 << n) << (p - n)); // zeroing specified bits
	y &= ~(~0 << n); // taking n bits
	y = y << (p - n); // and moving in position
	return x | y;
}

