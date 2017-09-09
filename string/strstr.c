#include <string.h>
#include <stdio.h>

int str_count0(const char *text, const char *sub)
{
	int ret = 0;
	int sub_len = strlen(sub);
	if (text == NULL || sub == NULL) {
		ret = -1;
		fprintf(stderr, "str_count get NULL pointer\n");
		return ret;
	}
	do {
		text = strstr(text, sub);
		if (text != NULL) {
			ret++;
			text = text + sub_len;
		} else
			break;
	} while (*text != '\0');

	return ret;
}

int str_count(const char *text, const char *sub)
{
	int ret = 0;
	int sub_len = strlen(sub);
	if (text == NULL || sub == NULL) {
		ret = -1;
		fprintf(stderr, "str_count get NULL pointer\n");
		return ret;
	}

	while (*text != '\0') {
		text = strstr(text, sub);
		if (text != NULL) {
			ret++;
			text = text + sub_len;
		} else
			break;
	}

	return ret;
}

void main()
{
	const char *text = "abcdasdfafasdfacjjjjjjjjjjjjcanndnnn";
	const char *sub = "abcd";
	printf("ret = %d\n", str_count(text, sub));
}
