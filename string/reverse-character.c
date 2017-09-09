#include <stdio.h>

int main01()
{
	char buf[100] = "你好世界";

	//char buf[100] = "你好";
	int len = 0;
	while (buf[len++]) ;
	len--;

	//printf("%d\n", len);
	int min = 0;
	int max = len - 1;
	while (min < max) {
		char tmp = buf[min];
		buf[min] = buf[max - 1];
		buf[max - 1] = tmp;
		tmp = buf[min + 1];
		buf[min + 1] = buf[max];
		buf[max] = tmp;
		min += 2;
		max -= 2;
	} printf("%s\n", buf);
	return 0;
}

int main()
{
	char buf[100] = "你好abc";
	int len = 0;
	int i = 0;
	while (buf[i]) {
		if (buf[i] < 0)
			i++;
		i++;
		len++;
	}

	//len--;
	printf("%d\n", len);
	return 0;
}
