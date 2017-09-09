#include <stdio.h>
#include <time.h>

#define SIZE 100000

int main()
{
	clock_t start;
	clock_t end;
	int a[SIZE];
	int b[SIZE];
	int* pEnd = &a[SIZE];
	int* pa = NULL;
	int* pb = NULL;
	int i = 0;
	int k = 0;

	start = clock();

	for(k = 0; k < SIZE; k++)
		for(i = 0; i < SIZE; i++)
			b[i] = a[i];

	end = clock();

	printf("Index Timing: %d\n", (int)(end - start));

	start = clock();

	for(k = 0; k < SIZE; k++)
		for(pa = a, pb = b; pa < pEnd;)
			*pb++ = *pa++;

	end = clock();

	printf("Pointer Timing: %d\n", (int)(end - start));

	return 0;
}
