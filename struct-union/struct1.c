#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[100];
	int age;
};

struct A {
	char c;
	char b;
	short a;
	int d;
};

struct B {
	struct A a1;
	int a:4;
	char b:2;
	char c:2;
};

struct C {
	struct B b;
	int a;
};

struct A1 {
	int a;
	char s[10];
};

struct A2 {
	struct A1 a;
	char b;
};

struct A3 {
	struct A2 a;
	char b;
};

int main01(void)
{
	struct A3 a3;
	a3.a.a.a = 100;
	struct A3 *ap = malloc(sizeof(struct A3));
	ap->a.a.a = 20;

	printf("%d\n", sizeof(struct B));
	return 0;
	struct student st = { "tom", 10 };
	struct student st1 = {.name = "mike",.age = 20 };
	struct student *p = malloc(sizeof(struct student));
	memset(p, 0, sizeof(struct student));
	p->age = 30;
	strcpy(p->name, "marry");

	struct student array[3];
	struct student *p1 = malloc(sizeof(struct student) * 3);
	array[0].age = 100;

	struct student *p2 = array;
	p2->age = 30;

	p1[0].age = 300;
	p1->age = 30;

	printf("Hello World!\n");

	free(p1);
	free(p);
	return 0;
}

struct man {
	char *name;
	int age;
};

int main02()
{

	//struct man m = {"tom", 20};
	struct man m;
	m.name = malloc(sizeof(char) * 100);
	m.age = 20;
	strcpy(m.name, "tom");
	printf("name = %s, age = %d\n", m.name, m.age);
	strcpy(m.name, "mike");
	printf("name = %s, age = %d\n", m.name, m.age);

	free(m.name);
	return 0;
}

int main()
{
	struct man *p = malloc(sizeof(struct man));
	p->name = malloc(sizeof(char) * 100);
	strcpy(name, "tom");
	p->age = 30;
	printf("name = %s, age = %d\n", p->name, p->age);

	free(p->name);
	free(p);

	return 0;
}
