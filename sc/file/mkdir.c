
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{
	if (mkdir("./test-dir", S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
		perror("fail to mkdir");
		exit(1);
	}
	printf("successfully make a dir\n");
	return 0;
}

