
#include <stdio.h>

int *address(int (*ptr)[4], int num)
{
	int *p;
	p = *(ptr + num);
	return p;
}

void display(int *ptr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%d\n", *(ptr + i));
}

void main()
{
	int score[3][4] = {
		{76, 87, 56, 89},
		{34, 983, 12, 382},
		{37, 83, 24, 82}
	};
	int row;
	int *ptr;
	int num = 4;
	printf("(1, 2, 3)?");
	scanf("%d", &row);
	while (row) {
		if (row == 1 || row == 2 || row == 3) {
			printf("student %d\n", row);
			ptr = address(score, row - 1);
			display(ptr, num);
			printf("(1, 2, 3)?");
			scanf("%d", &row);
		} else {
			printf("error row, input again\n");
			printf("(1, 2, 3)?");
			scanf("%d", &row);
		}
	}
}

