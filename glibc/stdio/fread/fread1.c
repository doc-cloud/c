
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main01(void)
{
	FILE *p = fopen("D:\\temp\\bin-file.exe", "rb");
	//    char buf[1024] = { 0 };
	//    size_t res = fread(buf, sizeof(char), sizeof(buf), p);//第一个参数是缓冲区，第二个参数是读取的时候最小单位大小，第三个参数是一次读几个单位，第四个参数是打开的文件指针
	//    //fread返回值代表读取了多少记录数
	//    printf("res = %u\n", res);

	//    res = fread(buf, sizeof(char), sizeof(buf), p);//第一个参数是缓冲区，第二个参数是读取的时候最小单位大小，第三个参数是一次读几个单位，第四个参数是打开的文件指针
	//    //fread返回值代表读取了多少记录数
	//    printf("res = %u\n", res);
	while (!feof(p)) {
		char buf[1024] = { 0 };
		int res = fread(buf, sizeof(char), sizeof(buf), p);	//第一个参数是缓冲区，第二个参数是读取的时候最小单位大小，第三个参数是一次读几个单位，第四个参数是打开的文件指针
		int i;
		for (i = 0; i < res; i++) {
			printf("buf[%d] = %x\n", i, buf[i]);
		}
	}
	fclose(p);
	return 0;
}

int main02()
{
	FILE *p = fopen("D:\\temp\\a.dat", "wb");

	//    char buf[1024] = { 0 };
	//    buf[0] = 'a';
	//    buf[1] = 'b';
	//    buf[2] = 'c';
	//    buf[3] = 'd';
	//    fwrite(buf, sizeof(char), sizeof(buf), p);
	int a = 0x12345678;
	fwrite(&a, 0, 4, p);
	fclose(p);
	return 0;
}

void code(char *p, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++) {
		p[i] += 3;
	}
}

void decode(char *p, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++) {
		p[i] -= 3;
	}
}

int main03()			//二进制加密
{
	FILE *p = fopen("D:\\temp\\a.wmv", "rb");
	FILE *p1 = fopen("D:\\temp\\b.wmv", "wb");

	//    FILE *p = fopen("D:\\temp\\a.txt", "rb");
	//    FILE *p1 = fopen("D:\\temp\\b.txt", "wb");
	char buf[1024 * 4];	//4k
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		size_t res = fread(buf, sizeof(char), sizeof(buf), p);	//返回从源文件中读取的字节数
		code(buf, res);
		fwrite(buf, sizeof(char), res, p1);	//从源文件中读取多少字节，那么就往目标文件中写入多少字节
	} fclose(p);
	fclose(p1);
	printf("end\n");
	return 0;
}

int main()			//二进制解密
{
	clock_t c1 = clock();
	FILE *p = fopen("D:\\temp\\b.wmv", "rb");
	FILE *p1 = fopen("D:\\temp\\c.wmv", "wb");

	//    FILE *p = fopen("D:\\temp\\b.txt", "rb");
	//    FILE *p1 = fopen("D:\\temp\\c.txt", "wb");
	char buf[1024 * 4];
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		size_t res = fread(buf, sizeof(char), sizeof(buf), p);	//返回从源文件中读取的字节数

		//decode(buf, res);
		fwrite(buf, sizeof(char), res, p1);	//从源文件中读取多少字节，那么就往目标文件中写入多少字节
	} fclose(p);
	fclose(p1);
	clock_t c2 = clock();
	printf("end , %u\n", c2 - c1);
	return 0;
}
