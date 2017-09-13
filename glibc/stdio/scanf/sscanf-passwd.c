#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
 char str[150] = "43488257----chenvay13";
 int long qid;
 char passwd[32];
 
 sscanf(str, "%ld----%s", &qid, passwd);
 
 printf("passwd of QQ %ld is %s\n", qid, passwd);
}
