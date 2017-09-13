#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(void)
{
	char buf[MAX_LINE];
	FILE *fp;
	int len;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		perror("fail to read");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp) != NULL) {
		len = strlen(buf);
		/* get rid of '\n', other string function can handle it */
		buf[len - 1] = '\0';
		printf("%s %d\n", buf, len - 1);
	}
	return 0;
}
