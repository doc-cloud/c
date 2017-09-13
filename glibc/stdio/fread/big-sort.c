#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    srand((unsigned int)time(NULL));
    int i;
    FILE *p = fopen("D:\\temp\\a.txt", "w");
    for(i = 0; i < 100000; i++)
    {
        fprintf(p, "%d\n", (int)rand() % 513);
    }
    //文本文件，每行代表一个整数，整数是从0到512之间一个随机数
    //对这个文件进行排序，不能用堆内存，只能用栈内存
    fclose(p);

    p = fopen("D:\\temp\\a.txt", "r");
    int array[513] = { 0 };
    while (!feof(p))
    {
        char buf[100] = { 0 };
        fgets(buf, sizeof(buf), p);//得到一行
        if (buf[0] != 0)//如果读取的行不是空行，那么就执行代码
        {
            int value = atoi(buf);//将得到的行转化为int
            array[value]++;
        }
    }
    fclose(p);

    p = fopen("D:\\temp\\b.txt", "w");

    int j;
    for(i = 0; i < 513; i++)
    {
        for(j = 0; j < array[i]; j++)
        {
            fprintf(p, "%d\n", i);
        }
    }
    fclose(p);

    printf("end\n");

    return 0;
}

//int main(void)
//{

//    return 0;
//}
