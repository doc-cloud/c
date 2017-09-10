#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	if (rmdir("./test-dir") == -1) {
		perror("fail to rmkdir");
		exit(1);
	}
	printf("successfully remove a dir\n");
	return 0;
}
