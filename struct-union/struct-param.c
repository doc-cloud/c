#include <stdio.h>

typedef struct {
	char name[64];
	int age;
	int id;
} Teacher;

void print_array(Teacher *arr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("age = %d\n", arr[i].age);
}

void sort_array(Teacher *arr, int num)
{
	int i, j;
	Teacher tmp;
	for (i = 0; i < num; i++)
		for (j = i + 1; j < num; j++)
			if (arr[i].age > arr[j].age) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}

void main()
{
	int i;
	Teacher arr[3];
	int num = 3;
	for (i = 0; i < num; i++)
		scanf("%d", &arr[i].age);

	print_array(arr, num);
	sort_array(arr, num);
	print_array(arr, num);
}
