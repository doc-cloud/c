#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char s1[] = {'H', 'e', 'l', 'l', 'o'};
    char s2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char* s3 = "Hello";
    char* s4 = (char*)malloc(100 * sizeof(char));
	memset(s4 + 5,'c',100);
	
    s4[0] = 'H';
    s4[1] = 'e';
    s4[2] = 'l';
    s4[3] = 'l';
    s4[4] = 'o';
 //  s4[5] = 'r';
 //   s4[5] = '\0';

	printf("%s\n",s4);
	
    free(s4);
	
    return 0;
}
