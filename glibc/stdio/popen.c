
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSZ PIPE_BUF

int main(void)
{
	FILE *fp;
	char *cmd = "cat file1";
	char buf[BUFSZ];
	if ((fp = popen(cmd, "r")) == NULL) {
		perror(" failed to popen ");
		exit(1);
	}
	while ((fgets(buf, BUFSZ, fp)) != NULL)
		printf("%s", buf);
	pclose(fp);
	exit(0);
}

