#include <sys/time.h>
#include <sys/resource.h>

#include <stdio.h>

int main()
{
	struct rlimit rlim;
	if(0 == getrlimit(RLIMIT_STACK, &rlim)) {

		printf("%-15s", "RLIMIT_STACK");

		if (RLIM_INFINITY == rlim.rlim_cur)
			printf("(infinite)");
		else
			printf("%-15ld", rlim.rlim_cur);

		if (RLIM_INFINITY == rlim.rlim_max)
			printf("(infinite)");
		else
			printf("%-15ld", rlim.rlim_max);

		rlim.rlim_cur = rlim.rlim_max;
		setrlimit(RLIMIT_STACK, &rlim);
	}

	printf("\n");

	if(0 == getrlimit(RLIMIT_STACK, &rlim)) {

		printf("%-15s", "RLIMIT_STACK");

		if (RLIM_INFINITY == rlim.rlim_cur)
			printf("(infinite)");
		else
			printf("%-15ld", rlim.rlim_cur);

		if (RLIM_INFINITY == rlim.rlim_max)
			printf("(infinite)");
		else
			printf("%-15ld", rlim.rlim_max);
	}
	printf("\n");

	return 0;
}
