
#include <stdio.h>

int main01(void)
{
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	if (p == NULL) {
		printf("file open fail\n");
	} else {
		printf("file open success\n");
		fclose(p);
	}
	printf("end\n");
	return 0;
}

int main02()
{
	/* open file in append mode */
	FILE *p = fopen("D:\\temp\\a.txt", "a");
	if (p == NULL) {
		printf("file open fail\n");
	} else {
		fputs("hello", p);
		fclose(p);
	}
	printf("end\n");
	return 0;
}

int main()
{
//    char c = '\r';
//    printf("%x\n", c);
//    return 0;

	/* write file in text mode */
	FILE *p = fopen("D:\\temp\\a.txt", "w");
	//“a"的含义是，如果文件不存在，那么就创建这个文件，如果文件存在，就在文件结尾处开始追加
	if (p == NULL) {
		printf("file open fail\n");
	} else {
		fputs("hell\n", p);
		fputs("world\n", p);
		fclose(p);
	}

	printf("end\n");
	return 0;
}

