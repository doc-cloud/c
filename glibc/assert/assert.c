/* once the expression is not true, print info on stderr, call abort */

#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a = 12;
	int b = 24;

	/* a < b, assertion failed, output error info, and call abort to stop program */
	assert(a > b);

	printf("a is larger than b!");
	return 0;
}
