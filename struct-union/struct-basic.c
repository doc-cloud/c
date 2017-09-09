#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher {
	char name[64];
	int age;
	int id;
} Teacher;

struct Student {
	char name[64];
	int aga;
} s1, s2;

struct {
	char name[64];
	int aga;
} s3, s4;

Teacher t3 = { "aaaa", 31, 01 };

struct Student2 {
	char name[64];
	int aga;
} s5 = {"names", 21};

struct {
	char name[64];
	int aga;
} s6 = {"names", 21};

void main()
{
	//struct Teacher  t1;

	Teacher t1;
	Teacher t2 = { "aaaa", 32, 02 };

	t1.age = 31;
	{
		Teacher *p = NULL;
		p = &t2;
		printf("p->age:%d \n", p->age);
		printf("p->name:%s \n", p->name);
	}
	strcpy(t1.name, "t1name");

	printf("t1.name:%s \n", t1.name);

	return;
}

void copyTeacher(Teacher to, Teacher from)
{
	to = from;
}

void copyTeacher02(Teacher * to, Teacher * from)
{
	//(*to) = (*from);
	*to = *from;
}

void main0()
{

	Teacher t1 = {"aaaa", 32, 02};
	Teacher t2;
	Teacher t3;
	memset(&t3, 0, sizeof(t3));

	t2 = t1;

	printf("t2.name:%s \n", t2.name);
	printf("t2.age:%d \n", t2.age);

	copyTeacher(t3, t1);
	printf("copyTeacher() after \n");
	printf("t3.name:%s \n", t3.name);
	printf("t3.age:%d \n", t3.age);
	printf("hello...\n");

	copyTeacher02(&t3, &t1);
	printf("copyTeacher02() after \n");
	printf("t3.name:%s \n", t3.name);
	printf("t3.age:%d \n", t3.age);

	return;
}
