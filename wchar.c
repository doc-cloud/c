//-finput-charset=gbk -fwide-exec-charset=utf-16le
#include <stdio.h>
#include <wchar.h>

void main()
{
 wchar_t ch = L'ܳ';
 printf("%ld\n", sizeof("1��"));
 printf("%ld\n", sizeof(L"1��"));
 printf("%ld, %ld\n", sizeof(ch), sizeof(wchar_t));
}
