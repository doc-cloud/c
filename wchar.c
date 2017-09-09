//-finput-charset=gbk -fwide-exec-charset=utf-16le
#include <stdio.h>
#include <wchar.h>

void main()
{
 wchar_t ch = L'‹≥';
 printf("%ld\n", sizeof("1Œ“"));
 printf("%ld\n", sizeof(L"1Œ“"));
 printf("%ld, %ld\n", sizeof(ch), sizeof(wchar_t));
}
