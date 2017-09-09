#include <stdio.h>

typedef int(AINT5)[5];

int main()
{
	AINT5 iArr5;
	iArr5[3] = 10;
	printf("%d\n",iArr5[3]);
	return 0;
}
