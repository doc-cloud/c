
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void pupple(int *p, int n)
{
	int i;
	int j;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (p[j - 1] > p[j]) {
				swap(&p[j - 1], &p[j]);
			}
		}
	}
}

/* sort in stack */
int main01(void)
{
	int index = 0;
	int array[100] = { 0 };
	char buf[100];
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), p);
		array[index] = atoi(buf);
		index++;
	}
	fclose(p);
	pupple(array, index);
	p = fopen("D:\\temp\\b.txt", "w");
	int i;
	for (i = 0; i < index; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d\n", array[i]);
		fputs(buf, p);
	}
	fclose(p);
	return 0;
}

/* sort in heap */
int main(void)
{
	int index = 0;
	char buf[100];

	FILE *p = fopen("D:\\temp\\a.txt", "r");
	/* statistic line number only */
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), p);
		index++;
	}
	fclose(p);

	int *array = calloc(sizeof(int), index);

	p = fopen("D:\\temp\\a.txt", "r");
	index = 0;
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), p);
		array[index] = atoi(buf);
		index++;
	}
	fclose(p);
	pupple(array, index);
	p = fopen("D:\\temp\\b.txt", "w");
	int i;
	for (i = 0; i < index; i++) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d\n", array[i]);
		fputs(buf, p);
	}
	fclose(p);
	return 0;
}

