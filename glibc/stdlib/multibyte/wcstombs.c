
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

int main()
{
	size_t ret;
	char *MB = (char *)malloc( BUFFER_SIZE );
	wchar_t *WC = L"http://www.yiibai.com/html";

	/* converting wide-character string */
	ret = wcstombs(MB, WC, BUFFER_SIZE);

	printf("Characters converted = %u\n", ret);
	printf("Multibyte character = %s\n", MB);

	return(0);
}

