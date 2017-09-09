#include <stdio.h>

#define RESET(p, len) while( len > 0) ((char*)p)[--len] = 0

void reset(void* p, int len)
{
	while(len > 0)
		((char*)p)[--len] = 0;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int len = sizeof(array);

	reset(array, len);
int i;

	for (i = 0; i < 5; ++i)
printf("%d\n", array[i]);

for (i = 0; i < 5; ++i)
 array[i] = i + 1;

	RESET(array, len);

	for (i = 0; i < 5; ++i)
printf("%d\n", array[i]);

	return 0;
}
