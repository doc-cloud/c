
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(void)
{
	DIR *dir;
	struct dirent *d_ptr;
	dir = opendir("./");
	if (dir == NULL) {
		perror("fail to open dir");
		exit(1);
	}
	/* according telldir output, "." && ".." occupy 24 bytes */
	seekdir(dir, 1117558374);
	while ((d_ptr = readdir(dir)) != NULL)
		printf("dir name is :%s \n", d_ptr->d_name);
	closedir(dir);
	return 0;
}

