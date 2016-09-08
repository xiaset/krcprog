#include <stdio.h>

int main()
{
	int d1, m1, y1, d2, m2, y2;
	int date1, date2;
	char c;
	printf("Date 1 (dd.mm.yyyy): ");
	scanf("%2d.%2d.%4d", &d1, &m1, &y1);
	printf("Date 2 (dd.mm.yyyy): ");
	scanf("%2d.%2d.%4d", &d2, &m2, &y2);

	date1 = y1*10000 + m1*100 + d1;
	date2 = y2*10000 + m2*100 + d2;
	printf("\ndate 1: %d", date1);
	printf("\ndate 2: %d", date2);
	c =  y1 > y2 ? '>' : y1 < y2 ? '<' :
             m1 > m2 ? '>' : m1 < m2 ? '<' :
             d1 > d2 ? '>' : d1 < d2 ? '<' : '=';

	printf("\n%02d.%02d.%4d %c %02d.%02d.%4d\n", d1,m1,y1,c,d2,m2,y2);
	return 0;
}
