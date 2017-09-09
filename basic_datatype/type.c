#include <stdio.h>

int
main()
{
 printf("signed = %ld\n", sizeof(signed));
 printf("short = %ld\n", sizeof(short));
 printf("int = %ld\n", sizeof(int));
 printf("long = %ld\n", sizeof(long));
 printf("long long = %ld\n", sizeof(long long));

 printf("unsigned = %ld\n", sizeof(unsigned));
 printf("unsigned short = %ld\n", sizeof(unsigned short));
 printf("unsigned int = %ld\n", sizeof(unsigned int));
 printf("unsigned long = %ld\n", sizeof(unsigned long));
 printf("unsigned long long = %ld\n", sizeof(unsigned long long));

 unsigned short abc = 0xffff;
 abc += 1;
 printf("abc = %d\n", abc);

 short abc1 = -2;
 int i = abc1;
 printf("i = %x\n", i);
 abc1 = 2;
 i = abc1;
 printf("i = %x", i);
 char c = 'c';
 printf("\b\b\b\b\b");
 printf("%c", c);
}
