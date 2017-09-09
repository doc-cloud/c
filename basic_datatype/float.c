#include <stdio.h>

int main()
{
	int i = 5;
	/* 2.5 truncate to 2 */
	i = 5 / 2;


	printf("%d\n", i);

	/* low efficient on float, avoid float if you can use int */
	double f = 4;
	f = f / 2;
	printf("%f\n", f);

	printf("%lu\n", sizeof(double));

	f = 3.5;

	i = f + 0.5;
	printf("%d\n", i);
	return 0;
}
