
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main ()
{
	double x, ret, val;

	x = 60.0;
	val = 180.0 / PI;
	ret = cos( x*val );
	printf("The cosine of %lf is %lf degrees\n", x, ret);

	x = 90.0;
	val = 180.0 / PI;
	ret = cos( x*val );
	printf("The cosine of %lf is %lf degrees\n", x, ret);

	return 0;
}

