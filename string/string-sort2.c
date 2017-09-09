#include <stdlib.h>
#include <stdio.h>

char **get_memory(int num)
{
	char **ptr = (char **)malloc(num * sizeof(char *));
	int i;
	if (ptr == NULL)
		return NULL;
	for (i = 0; i < num; i++) {
		ptr[i] = malloc(100 * sizeof(char));
		sprintf(ptr[i], "%d%d%d", 6 - i + 1, 6 - i + 1, 6 - i + 1);
	}
	return ptr;
}

void print_array(char **ptr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%s ", ptr[i]);
	printf("\n");
}

void sort_array(char **ptr, int num)
{
	int i, j;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
		for (j = i + 1; j < num; j++)
			if (strcmp(ptr[i], ptr[j]) > 0) {
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
}

void main()
{
	char **ptr = NULL;
	int num = 5;
	ptr = get_memory(num);
	print_array(ptr, num);
	sort_array(ptr, num);
	print_array(ptr, num);
}
