
#include <stddef.h>
#include <stdio.h>

struct address {
	char name[50];
	char street[50];
	int phone;
};
   
int main()
{
	printf("name offset = %ld byte in address structure.\n", offsetof(struct address, name));

	printf("street offset = %ld byte in address structure.\n", offsetof(struct address, street));

	printf("phone offset = %ld byte in address structure.\n", offsetof(struct address, phone));

	return(0);
} 

