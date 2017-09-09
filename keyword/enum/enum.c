#include <stdio.h>

enum Color
{
	GREEN,
	RED = 2,
	BLUE
};

void main()
{
	printf("%d\n", GREEN);
	printf("%d\n", RED);
	printf("%d\n", BLUE);
}
