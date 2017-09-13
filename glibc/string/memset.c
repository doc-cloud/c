
#include <string.h>
#include <stdio.h>

main()
{
	char s[] = "this is a test";

	memset(s, 'G', 6);
	printf("%s\n",s);

	return 0;
}

