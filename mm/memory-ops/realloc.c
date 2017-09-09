#include <stdlib.h>
#include <stdio.h>

int
realloc_rewrite(char **ptr,int size,int new_size)
{
 int ret = 1;
 int i = 0;
 int len;

 char *pptr = NULL;
 char *tmp = NULL;
 char *ptr_src = *ptr;

 if(NULL != ptr && 0 < new_size){
  pptr = (char *)malloc(new_size);
  tmp = pptr;
  len = (size < new_size) ? size : new_size;
  for(i = 0; i < len; i++)
   *tmp++ = *ptr_src++;
  free(*ptr);
  *ptr = pptr;
 } else
  ret = 0;

 return ret;
}

int
main()
{
 char *ptr = NULL;
 ptr = (char *)malloc(10);
 ptr[0] = 1;
 ptr[1] = 2;

 printf("%d %d\n", ptr[1], sizeof(ptr));

 if(realloc_rewrite(&ptr, 10, 100))
  printf("%d %d\n", ptr[1], sizeof(ptr));

 return 0;
}
