#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[1000];
	int age;
};

void print_student(const struct student *s)
{
	printf("name = %s, age = %d\n", s->name, s->age);
}

void set_student(struct student *s, const char *name, int age)
{
	strcpy(s->name, name);
	s->age = age;
}

int main(void)
{
	struct student st = { "tom", 20 };
	set_student(&st, "mike", 100);
	print_student(&st);

	return 0;
}
