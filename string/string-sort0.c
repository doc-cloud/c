
#include <stdio.h>

void sort_array(char **strs, int num)
{
	int i, j;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
		for (j = i; j < num; j++)
			if (strcmp(strs[i], strs[j]) > 0) {
				tmp = strs[i];
				strs[i] = strs[j];
				strs[j] = tmp;
			}
}

void print_array(char **strs, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%s ", strs[i]);
	printf("\n");
}

void main()
{
	char *strs[] = {"aaaa", "bbbb", "eeee", "dddd"};
	int num = sizeof(strs) / sizeof(strs[0]);
	print_array(strs, num);
	sort_array(strs, num);
	print_array(strs, num);
}

