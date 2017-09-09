#include <stdio.h>
#include <string.h>

//void sort_array(char **strs, int num)
//{
//	int i, j;
//	char tmpbuf[32];
//	for (i = 0; i < num; i++)
//		for (j = i + 1; j < num; j++)
//			if (strcmp(strs[i], strs[j]) > 0) {
//				printf("tmpbuf = %s, strs[i] = %s, strs[j] = %s\n", tmpbuf, strs[i], strs[j]);
//				strcpy(tmpbuf, strs[i]);
//				strcpy(strs[i], strs[j]);
//				strcpy(strs[j], tmpbuf);
//			}
//}

void sort_array(char strs[10][30], int num)
{
	int i, j;
	char tmpbuf[32];
	for (i = 0; i < num; i++)
		for (j = i + 1; j < num; j++)
			if (strcmp(strs[i], strs[j]) > 0) {
				//printf("tmpbuf = %s, strs[i] = %s, strs[j] = %s\n", tmpbuf, strs[i], strs[j]);
				strcpy(tmpbuf, strs[i]);
				strcpy(strs[i], strs[j]);
				strcpy(strs[j], tmpbuf);
			}
}

void print_array(char strs[10][30], int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%s ", strs[i]);
	printf("\n");
}

void main()
{
	char strs[10][30] = {"aaaa", "bbbbb", "eeeeeeeeeeee", "dddddddddddd"};
	//char *strs[] = {"aaaa", "bbbbb", "eeeeeeeeeeee", "dddddddddddd"};
	int num = sizeof(strs) / sizeof(strs[0]);
	num = 4;
	//printf("num = %d\n", num);
	print_array(strs, num);
	sort_array(strs, num);
	print_array(strs, num);
}
