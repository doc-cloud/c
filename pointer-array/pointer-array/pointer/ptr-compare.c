#include <stdio.h>
#include <malloc.h>

#define DIM(a) (sizeof(a) / sizeof(*a))

int main()
{
	char s[] = {'H', 'e', 'l', 'l', 'o'};
	char *pBegin = s;
	char *pEnd = s + DIM(s);
	char *p = NULL;

	for(p = pBegin; p < pEnd; p++)
		printf("%c", *p);

	printf("\n");

	return 0;
}

/*
int main(){
	int s[] = {'H','e','l','l','o'};
	int *pBegin = s;
	int *pEnd = s + DIM(s);
	int *ptr = NULL;
	
	for(p = pBegin;p < pEnd;p++)
		printf("%c",(char *)(*(unsigned int *)p));
	
	printf("\n");
	return 0;
}
*/

