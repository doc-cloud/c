#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int *get_mymax();

void print_mymax();

int main()
{
	int *p1 = calloc(sizeof(int), 100);
	if (p1 == NULL)//û�ж��ڴ����ʹ���ˣ����ʱ��Ĵ���������������
	{
		exit(0);
	}
	p1[2] = 8;
	int *p2 = realloc(p1, sizeof(int) * 200);

	memset(p2 + 100, 0, sizeof(int) * 100);

	//int set[1000000];//ջ���
	int *set = malloc(sizeof(int)* 100000);//�ڶ��м䴴����������

	int i = 0;
	scanf("%d", &i);
	//int array[i];//��̬����
	int *array = malloc(sizeof(int) * i);//�ڶ��д���һ����̬����

	//�����û���������ʹ�ö�̬������

	free(array);

	return 0;



	int *p = get_mymax();
	*p = 300;
	print_mymax();
	return 0;
}