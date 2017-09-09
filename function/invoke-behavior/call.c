#include <stdio.h>

void
call(int a, int b)
{
 printf("%d %d\n", a, b);
}

void
main()
{
 int a = 5;
 call(a, a++);
}
