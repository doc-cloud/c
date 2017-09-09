#include <stdio.h>
#include <malloc.h>

typedef struct _soft_array {
	int len;
	int array[];
} SoftArray;

SoftArray *create_soft_array(int size)
{
	SoftArray *ret = NULL;
	if(0 < size) {
		ret = (SoftArray *)malloc(sizeof(*ret) + sizeof(*(ret->array)) * size);
		ret->len = size;
	}
	return ret;
}

void fac(SoftArray *sa)
{
	int len_arr;
	int i;
	if(NULL != sa) {
		len_arr = sa->len;
		if(1 == len_arr)
			sa->array[0] = 1;
		else {
			sa->array[0] = 1;
			sa->array[1] = 1;
			for(i = 2;i < sa->len;i++)
				sa->array[i] = sa->array[i - 1] + sa->array[i - 2];
		}
	}
}

void destroy_soft_array(SoftArray *sa)
{
	free(sa);
}

int main()
{
	int i;
	SoftArray *sa = create_soft_array(10);
	fac(sa);
	for(i = 0; i < 10; i++)
		printf("%d\n", sa->array[i]);
	destroy_soft_array(sa);
	return 0;
}
