/*
 * 0.from the undefined identifier in innermost bracket,
 * 1.look forward to right at first, and turn to left,
 * 2.round bracket or square bracket confirm a part of types, and turn the direction
 * 3.repeat 1 and 2
 */

#include <stdio.h>

int main()
{
	int (*p2)(int *, int (*f)(int *));
	//pointer to function .
	//return integer .
	//parameter1:
	//				pointer to integer
	//parameter2:
	//				pointer to function
	//				return integer
	//				parameter1:
	//							pointer to integer

	int (*p3[5])(int *);
	//array for 5 function pointer .
	//				function type:
	//				return integer .
	//				parameter1:
	//							pointer to integer

	int (*(*p4)[5])(int *);
	//pointer to array
	//				array for 5 function pointer
	//							return integer
	//							parameter1:
	//										pointer to integer

	int (*(*p5)(int *))[5];
	//pointer to function
	//				return an array
	//							array for 5 integer
	//				parameter1:
	//						pointer to integer
}
