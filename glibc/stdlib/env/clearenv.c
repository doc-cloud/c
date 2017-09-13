
/* The clearenv() function clears the environment of all name-value pairs and sets the value of the external variable environ to NULL. */

#include <stdio.h>
#include <stdlib.h>

extern **environ;

int main(void)
{
	if(clearenv() == -1){
		perror("fail to clear env");
		exit(1);
	}
	if(NULL == environ)
		printf("done\n");
	return 0;
}

