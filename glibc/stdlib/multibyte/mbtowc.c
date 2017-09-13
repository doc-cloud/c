
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str = "This is yiibai.com";
	wchar_t mb[100];
	int len;

	len = mblen(NULL, MB_CUR_MAX); 

	mbtowc(mb, str, len*strlen(str) );

	wprintf(L"%ls \n", mb );   

	return(0);
}

