#include <string.h>
#include <stdio.h>

//void split(const char *text, char delim, char arr[10][30], int *count)
//{
//	int cursor = 0;
//	int i = 0;
//	while (*text != '\0') {
//		if (*text != delim)
//			cursor++;
//		else {
//			++*count;
//			strncpy(arr[i], text - cursor, cursor);
//			arr[i][cursor] = '\0';
//			//printf("%s \n", arr[i]);
//			i++;
//			cursor = 0;
//		}
//		text++;
//	}
//	if (text[-1] == delim) {
//		--*count;
//	} else {
//		strncpy(arr[i], text - cursor, cursor);
//		arr[i][cursor] = '\0';
//	}
//}

void split(const char *text, char delim, char arr[10][30], int *count)
{
	const char *prev_ptr, *ptr;
	prev_ptr = ptr = text;
	int local_count = 0;
	//int tmp = 0;
	
	do {
		//ptr = strchrnul(ptr, delim);
		ptr = (char *)(unsigned long)strchrnul(ptr, delim);
		//printf("tmp = %d\n", tmp);
		if (ptr != NULL) {
		//if (NULL != strchrnul(ptr, delim)) {
			if (ptr - prev_ptr > 0) {
				strncpy(arr[local_count], prev_ptr, ptr - prev_ptr);
				arr[local_count++][ptr - prev_ptr] = '\0';
				prev_ptr = ++ptr;
			}
		} else {
			if (ptr[-1] != delim) {
				strncpy(arr[local_count], prev_ptr, ptr - prev_ptr);
				arr[local_count++][ptr - prev_ptr] = '\0';
			}
			break;
		}
	} while (*ptr != '\0');
	*count = local_count;
}

void print_string(char arr[10][30], int count)
{
	int i;
	for (i = 0; i < count; i++)
		printf("%s ", arr[i]);
	printf("\n");
}

void main()
{
	const char *text = "adffasdf,afasdf,fasdfaf,tewr,ffdasf,ar, -----";
	char delim = ',';
	char arr[10][30];
	int count;
	split(text, delim, arr, &count);
	//printf("count = %d\n", count);
	print_string(arr, count);
}
