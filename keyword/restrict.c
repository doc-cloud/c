#include <stdio.h>

/*
int
foo(int * x, int * y)
{
 *x = 0;
 *y = 1;
 return *x;
}

int
foo(int * x, int * y)
{
 *x = 0;
 *y = 1;
 return 0;
}

//less operations about memory,
//error occur when both y and x point to the same address.
*/

int
foo(int * a, int * b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}
 
int
rfoo(int * restrict a, int * restrict b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}

int
main()
{
    int a = 1, b = 2;
    int * ptr_a, * ptr_b;
    ptr_a = &a, ptr_b = &b;
    printf("%d\n", foo(ptr_a, ptr_b));
    printf("%d\n", rfoo(ptr_a, ptr_b));
}
