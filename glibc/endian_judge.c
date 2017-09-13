#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 1;

	if(*(char *)&a == 1)
		printf("little endian\n");

	return 0;
}
