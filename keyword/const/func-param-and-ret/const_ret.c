#include <stdio.h>

const int *
const_ret_func()
{
 static int count = 0;
 count++;
 return &count;
}

int
main()
{
 int i = 0;
 int ptr_tmp = 2;
 const int *p = const_ret_func();
 //int *p = const_ret_func();

 printf("%d\n", *p);
 //*p = const_ret_func();
 p = &ptr_tmp;
 printf("%d\n", *p);

 return 0;
}
