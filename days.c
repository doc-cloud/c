#include <stdio.h>

void main()
{
        int days;
	int ret;
	while (1) {
		int ret_getchar = 0;
       		ret = scanf("%d", &days);
		if (ret == 1 && (ret_getchar = getchar()) == '\n' && days >= 0)
			break;
		printf("input invalid.\n");
		if (ret != 1 || ret_getchar != '\n')
			while (getchar() != '\n');
	}
        printf("week = %d, ", days / 7);
        printf("days = %d\n", days % 7);
}
