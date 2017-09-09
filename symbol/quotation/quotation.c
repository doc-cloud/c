#include <stdio.h>

int main()
{
	char c = " ";
	while("\t" == c || " " == c || "\n" == c)
		scanf("%c", &c);
/*
 		while (!strcmp(&c, "")) {
			scanf("%c", &c);
		}
 */
	return 0;
}
