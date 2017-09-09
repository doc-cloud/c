#include <stdio.h>

void main()
{
 "test" == "test1" ? putchar('1') : putchar('0');

 char *p0 = "test";
 char *p1 = "test1";

 p0 == p1 ? putchar('1') : putchar('0');
 p0 == "test" ? putchar('1') : putchar('0');
 printf("%p, %p\n", p0, "test");

 char str0[] = "test";
 char str1[] = "test";
 printf("%p, %p\n", str0, str1);
}
