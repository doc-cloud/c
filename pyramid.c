#include <stdio.h>

void main()
{
	char tail;
	char base = 'A';
	int i = 0;
	scanf("%c", &tail);
	int num = tail - base;
	while (i < num) {
		char end = base + i;
		int j = 0;
		while (j++ < num - i - 1)
			printf(" ");
		while (base < end)
			printf("%c", base++);
		printf("%c", end);
		base -= i;
		end--;
		while (base <= end)
			printf("%c", end--);
		printf("\n");
		i++;
	}
}
