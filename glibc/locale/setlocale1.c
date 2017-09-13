#ifdef __GNUC__

#define CSET_GBK    "GBK"
#define CSET_UTF8   "UTF-8"

#define LC_NAME_zh_CN   "zh_CN"

// ifdef __GNUC__
#elif defined(_MSC_VER)

#define CSET_GBK    "936"
#define CSET_UTF8   "65001"

#define LC_NAME_zh_CN   "Chinese_People's Republic of China"

// ifdef _MSC_VER
#endif

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LC_NAME_zh_CN_GBK       LC_NAME_zh_CN "." CSET_GBK
#define LC_NAME_zh_CN_UTF8      LC_NAME_zh_CN "." CSET_UTF8
#define LC_NAME_zh_CN_DEFAULT   LC_NAME_zh_CN_GBK

void print_current_loc();

int main(int argc, char *argv[])
{
	char *locname = NULL;
	const wchar_t *strzh = L"中文字符串";

	print_current_loc();

	/* use assigned locale */
	locname = setlocale(LC_ALL, LC_NAME_zh_CN_DEFAULT);
	if (NULL == locname)
		printf("setlocale() with %s failed.\n", LC_NAME_zh_CN_DEFAULT);
	else
		printf("setlocale() with %s succeed.\n", LC_NAME_zh_CN_DEFAULT);

	print_current_loc();

	wprintf(L"Zhong text is: %ls\n", strzh);

	/* use locale settings in run time environment */
	locname = setlocale(LC_ALL, "");
	if (NULL == locname)
		printf("setlocale() from environment failed.\n");
	else
		printf("setlocale() from environment succeed.\n");

	print_current_loc();

	wprintf(L"Zhong text is: %ls\n", strzh);

	puts("End of program.");
	return 0;
}

void print_current_loc()
{
	char *locname = setlocale(LC_ALL, NULL);
	printf("Current locale is: %s\n", locname);
}
