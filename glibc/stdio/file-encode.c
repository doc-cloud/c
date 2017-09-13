
#include <stdio.h>
#include <string.h>

int main01(void)
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\a.txt", "w");
	while (1) {
		memset(s, 0, sizeof(s));
		//scanf("%s", s);
		gets(s);
		if (strcmp(s, "exit") == 0)
			break;
		int len = strlen(s);
		s[len] = '\n';
		fputs(s, p);
	}
	fclose(p);
	printf("end\n");
	return 0;
}

int main02()
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\main.c", "r");
	while (!feof(p)) {
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);
		printf("%s", s);
	}
	fclose(p);
	return 0;
}

void code(char *s)
{
	while (*s) {
		(*s)++;
		s++;
	}
}

void decode(char *s)
{
	while (*s) {
		(*s)--;
		s++;
	}
}

int main03()
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	FILE *p1 = fopen("D:\\temp\\b.txt", "w");
	while (!feof(p)) {
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);
		code(s);	//
		fputs(s, p1);
	}
	fclose(p);
	fclose(p1);
	return 0;
}

int main()
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\b.txt", "r");
	FILE *p1 = fopen("D:\\temp\\c.txt", "w");
	while (!feof(p)) {
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);
		decode(s);
		fputs(s, p1);
	}
	fclose(p);
	fclose(p1);
	return 0;
}

