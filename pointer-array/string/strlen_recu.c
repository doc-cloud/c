#include <stdio.h>
#include <assert.h>

#include <string.h>

size_t
__t_strlen(const char* s)
{
 return assert(s), (*s ? (strlen(s + 1) + 1) : 0);
}

int main()
{
 printf("%ld\n", __t_strlen("test"));
 printf("%ld\n", strlen("test"));

 //printf("%ld\n", __t_strlen(NULL));
 //printf("%ld\n", strlen(NULL));
}
