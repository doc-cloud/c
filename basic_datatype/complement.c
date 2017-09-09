#include <stdio.h>

int main()
{
	printf("-10 %s == %x\n", "%x", -10);
	int i = 10;
	printf("sizeof(int) %s == %ld\n", "%ld", sizeof(i));

	printf("-7 %s == %x\n", "%x", -7);
	printf("-7 %s == %u\n", "%u", -7);

	printf("-24 %s == %u\n", "%u", -24);
	printf("-24 %s == %x\n", "%x", -24);
	printf("-24 %s == %X\n", "%X", -24);
	printf("-24 %s == %o\n", "%o", -24);

	return 0;
}
