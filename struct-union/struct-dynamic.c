#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char name[64];
	char *aliasname;
	char **stutab;
	int age;
	int id;
} Teacher;

int teacher_create(Teacher **parr, int num)
{
	Teacher *tmp = NULL;
	int i, j;
	tmp = (Teacher *)malloc(num * sizeof(Teacher));
	if (tmp == NULL)
		return -1;
	memset(tmp, 0, num * sizeof(Teacher));
	for (i = 0; i < num; i++) {
		char **tmp_tab = NULL;
		tmp[i].aliasname = (char *)malloc(64);
		tmp_tab = (char **)malloc(num * sizeof(char *));
		for (j = 0; j < num; j++)
			tmp_tab[j] = (char *)malloc(128);
		tmp[i].stutab = tmp_tab;
	}
	*parr = tmp;
	return 0;
}

void teacher_print(Teacher *parr, int num)
{
	int i;
	for (i = 0; i < num; i++) {
		printf("name : %s\n", parr[i].name);
		printf("alias : %s\n", parr[i].aliasname);
		printf("age : %d\n", parr[i].age);
	}
}

void teacher_sort(Teacher *parr, int num)
{
	int i, j;
	Teacher tmp;
	for (i = 0; i < num; i++)
		for (j = i + 1; j < num; j++)
			if (parr[i].age > parr[j].age) {
				tmp = parr[i];
				parr[i] = parr[j];
				parr[j] = tmp;
			}
}

void teacher_free(Teacher *parr, int num)
{
	int i, j;
	if (parr == NULL)
		return ;
	for (i = 0; i < num; i++) {
		if (parr[i].aliasname != NULL)
			free(parr[i].aliasname);
		if (parr[i].stutab != NULL) {
			char **tmp = parr[i].stutab;
			for (j = 0; j < num; j++)
				if (tmp[j] != NULL)
					free(tmp[j]);
			free(tmp);
			parr[i].stutab = NULL;
		}
	}
	free(parr);
}

void main()
{
	Teacher *parr = NULL;
	int num = 3;
	int i, j;
	teacher_create(&parr, num);

	for (i = 0; i < num; i++) {
		printf("name :");
		scanf("%s", parr[i].name);
		printf("alias :");
		scanf("%s", parr[i].aliasname);
		printf("age :");
		scanf("%d", &parr[i].age);
		for (j = 0; j < num; j++) {
			printf("student's name:");
			scanf("%s", parr[i].stutab[j]);
		}
	}
	teacher_print(parr, num);
	teacher_sort(parr, num);
	teacher_print(parr, num);
	teacher_free(parr, num);
}
