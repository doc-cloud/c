#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

struct student
{
	char name[100];
	int age;
};

struct student_a
{
	char *name;
	int age;
};

int main()
{
	struct student_a st = {NULL, 0};
	st.age = 30;
	st.name = malloc(100);
	strcpy(st.name, "ΑυµΒ»ª");

	struct student_a st1 = st;
	free(st.name);

	printf("%d, %s\n", st1.age, st1.name);

	return 0;
}
