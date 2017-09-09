#include <stdlib.h>
#include <stdio.h>

int
get_memory (char ***ptr, int num)
{
 char **tmp = NULL;
 int i;

 if (ptr == NULL)
  return -1;

 tmp = (char **) malloc (num * sizeof (char *));
 if (tmp == NULL) {
  perror ("malloc");
  exit (1);
 }

 for (i = 0; i < num; i++) {
  tmp[i] = (char *) malloc (10 * sizeof (char));
  sprintf (tmp[i], "%d%d%d", i + 1, i + 1, i + 1);
 }

 *ptr = tmp;
}

void
free_memory (char ***ptr, int num)
{
 char **tmp = NULL;
 int i;

 if (ptr == NULL)
  return;

 tmp = *ptr;

 for (i = 0; i < num; i++)
  free (tmp[i]);

 free (tmp);
 *ptr = NULL;
}

void
main ()
{
 char **ptr = NULL;
 int num = 5;
 int i;

 get_memory (&ptr, num);

 for (i = 0; i < num; i++)
  printf ("%s\n", ptr[i]);

 free_memory (&ptr, num);
}
