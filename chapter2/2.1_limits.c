#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("Data type limits:            Unsigned       Signed\n");
	printf("Char:            %20d       %d .. %d\n", UCHAR_MAX, SCHAR_MIN, SCHAR_MAX);
	printf("Short:           %20d       %d .. %d\n", USHRT_MAX, SHRT_MIN, SHRT_MAX);
	printf("Int:             %20u       %d .. %d\n", UINT_MAX, INT_MIN, INT_MAX);
	printf("Long:            %20lu       %ld .. %ld\n", ULONG_MAX, LONG_MIN, LONG_MAX);
	return 0;
}
