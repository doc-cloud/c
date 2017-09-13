#include <stdio.h>

int main()
{
 /* if the size is less than user input, it is overflow */
 char str1[20];
 int num = 0;
 
 scanf("%s", str1);
 scanf("#num = %d", &num);
 
 printf("Entered Name: %s\n", str1);
 printf("num = %d\n", num);
}
