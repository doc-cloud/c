
#include <stdio.h>

/*
"r"	打开一个文件进行读取。该文件必须存在。
"w"	创建一个空的书面文件。如果已经存在具有相同名称的文件，其内容被删除的文件被认为是一个新的空文件。
"a"	附加到文件中。写入操作的数据追加在文件末尾的。该文件被创建，如果它不存在。
"r+"	打开更新文件阅读和写作。该文件必须存在。
"w+"	创建一个空文件，读取和写入。
"a+"	打开一个文件​​读取和追加
*/

int main ()
{
	FILE *fp;

	printf("This text is redirected to stdout\n");

	fp = freopen("file.txt", "w+", stdout);

	printf("This text is redirected to file.txt\n");

	fclose(fp);

	return(0);
}

