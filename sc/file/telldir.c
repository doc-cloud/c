
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	DIR *dir;
	struct dirent *d_ptr;
	off_t offset;
	dir = opendir("./");
	if (dir == NULL) {
		perror("fail to open dir");
		exit(1);
	}
	/* output filename and directory item offset in directory */
	while ((d_ptr = readdir(dir)) != NULL) {
		offset = telldir(dir);
		if (offset == -1) {
			perror("fail to get offset");
			exit(1);
		}
		printf("dir name is : %s offset is :%d\n", d_ptr->d_name, (int)offset);
	}
	closedir(dir);
}

