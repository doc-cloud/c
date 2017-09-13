#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
main()
{
 char * ptr;
 int ptr_len;
 printf("Got a %s pointer.\n", (ptr = (char *)malloc(0)) == NULL ? "null" : "valid");
 printf("Got a %s pointer.\n", (ptr_len = strlen(ptr = (char *)malloc(0))) == 0 ? "null" : "valid");
 printf("Got a %s pointer.\n", (ptr_len = sizeof(ptr = (char *)malloc(0))) == 8 ? "null" : "valid");
}
