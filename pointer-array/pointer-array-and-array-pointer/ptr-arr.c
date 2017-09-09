#include <stdio.h>

void main()
{
	char *books[4] = {
		"C Programming Language",
		"Assembly Language",
		"Java Language",
		"Natural Language"
	};
	int num = 4;
	char *ptr;
	int row;
	for (row = 0; row < num; row++)
		printf("string %d = %s\n", row + 1, books[row]);
	printf("\n");
	for (row = 0, ptr = *books; row < num; ptr = books[row]) {
		printf("string %d = %s\n", row + 1, ptr);
		row++;
	}
}
