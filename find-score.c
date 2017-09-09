#include <stdio.h>

int *find_addr(int (*ptrscore)[4], int n)
{
	return *(ptrscore + n);
}

void display(int num, int *pos)
{
	int col;
	for (col = 0; col < num; col++)
	      printf("%4d", *(pos + col));
	printf("\n");
}

void main()
{
	int row = 0;
	int num = 4;
	int *pos;
	int score[3][4] = {
		{76, 87, 85, 81},
		{67, 61, 71, 60},
		{81, 89, 82, 78}
	};
	scanf("%d", &row);
	while (row) {
		if (row == 1 || row == 2 || row == 3) {
			printf("no.row student's score:\n");
			pos = find_addr(score, row - 1);
			display(num, pos);
			printf("input (1, 2, or 3), 0 indicates exit\n");
			scanf("%d", &row);
		} else {
			printf("input illegal, input (1, 2, or 3), 0 indicates exit\n");
			scanf("%d", &row);
		}
	}
}
