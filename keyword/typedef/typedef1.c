#include <stdio.h>
#include <string.h>

typedef char BYTE;
#define BYTE1 char
#define MAX 10
typedef int INT;
typedef unsigned int UINT;
typedef char CHAR;
typedef unsigned char UCHAR;
//typedef w_char TCHAR;
//typedef 10 AAA;

struct abc {
	int a;
	char b;
};

typedef struct abc A;

typedef struct {
	int a;
} A2;

int main01(void)
{
	int a1;
	int a2;
	int a3;
	int a4;

	//A2 a;

	//BYTE1 a;
	//a = MAX;
	//printf("%d\n", a);
	return 0;
}

char *mystrcat(char *s1, char *s2)
{
	strcat(s1, s2);
	return s1;
}

typedef char *(*STRCAT) (char *, char *);

char *test(STRCAT p, char *s1, char *s2)
{
	return p(s1, s2);
}

STRCAT get_mystrcat()
{
	return mystrcat;
}

int main()
{
	char *(*p) (char *s1, char *s2);
	p = get_mystrcat();

	//char *(*p[10])(char *s1, char *s2);
	STRCAT array[10];

	char s1[100] = "hello";
	char s2[100] = "world";
	p(s1, s2);
	char *s = test(mystrcat, s1, s2);
	printf("s = %s\n", s);
	return 0;
}
