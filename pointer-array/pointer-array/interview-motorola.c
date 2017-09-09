
#include <stdio.h>

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p1 = (int *)(&a + 1); 
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);

	printf("%d, %d, %d\n", p1[-1], p2[0], p3[1]);

	return 0;
}
// A. cannot run
// B. p1[-1] output random, p2[0] output 2, p3[1] output 3
// C. p1[-1] output gibberish, p2[0], p3[1] output 2

