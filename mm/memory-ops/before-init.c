#include <stdio.h>
#include <string.h>

struct Student {
    char* name;
    int number;
};

int main()
{
	struct Student s;
	/* oops. */
	strcpy(s.name, "Linkerist Heracles");
	s.number = 99;
	return 0;
}
