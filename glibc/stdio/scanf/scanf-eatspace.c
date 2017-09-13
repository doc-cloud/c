#include <stdio.h>

void main()
{
 char str[100];
 //scanf("%[^\n]", str);
 //scanf("%[^=]", str);
 //scanf("%[^#]", str);
 //scanf("%[1]", str);
 //scanf("%[0-9]", str);
 scanf("%[^0-9]", str);
 printf("str = %s", str);
}
