#include <stdio.h>
#include <string.h>

struct student
{
	char name[16];//姓名
	unsigned char age;//年龄
	unsigned char score;//成绩
	char classes[100];//班级
};

struct A
{
	char array[10];
};

void swap(struct student *a, struct student *b)
{
	struct student tmp = *a;
	*a = *b;
	*b = tmp;
}

int main01()
{
	//struct A a1 = { "hello" };//如果结构体的成员是数组，通过结构可以变相的实现数组的赋值
	//struct A a2 = { 0 };
	//a2 = a1;
	//printf("a2.array = %s\n", a2.array);
	//return 0;


	struct student st[5] = { {"周永康", 70, 59, "C++基础班"}, {"徐才厚",60, 30, "JAVA班"}, {"薄熙来", 70, 40, "PHP班"}, {"令计划", 50, 32, "平面设计"}, {"金三胖", 60, 28, "C++基础班"} };
	
	//struct student tmp = st[0];
	//st[0] = st[1];
	//st[1] = tmp;

	int i;
	int j;
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j < 5 - i; j++)
		{
			if (st[j].age < st[j - 1].age)
			{
				swap(&st[j], &st[j - 1]);
			}
			else if (st[j].age == st[j - 1].age)
			{
				if (st[j].score < st[j - 1].score)
				{
					swap(&st[j], &st[j - 1]);
				}
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("姓名=%s,年龄=%d, 成绩=%d, 班级=%s\n", st[i].name, st[i].age, st[i].score, st[i].classes);
	}
	
	return 0;
}

int main()
{
	struct student st[5] = { { "周永康", 70, 59, "C++基础班" }, { "徐才厚", 60, 30, "JAVA班" }, { "薄熙来", 70, 40, "PHP班" }, { "令计划", 50, 32, "平面设计" }, { "金三胖", 60, 28, "C++基础班" } };
	
	int i;
	int j;
	for (i = 0; i < 5; i++)
	{
		for (j = 1; j < 5 - i; j++)
		{
			if (strcmp(st[j].classes, st[j - 1].classes) > 0)
			{
				swap(&st[j], &st[j - 1]);
			}
		}
	}


	for (i = 0; i < 5; i++)
	{
		printf("姓名=%s,年龄=%d, 成绩=%d, 班级=%s\n", st[i].name, st[i].age, st[i].score, st[i].classes);
	}
}