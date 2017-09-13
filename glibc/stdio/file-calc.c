#include <stdio.h>
#include <string.h>

int calc_string(const char *s)
{
	char buf1[100] = { 0 };
	char oper1 = 0;
	char buf2[100] = { 0 };

	int len = strlen(s);

	int i;
	for (i = 0; i < len; i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			strncpy(buf1, s, i);
			oper1 = s[i];
			break;
		}
	}

	int start = i + 1;
	for (; i < len; i++) {
		if (s[i] == '=') {
			strncpy(buf2, &s[start], i - start);
		}
	}

	//printf("buf1 = %s, oper1 = %c, buf2 = %s\n", buf1, oper1, buf2);

	switch (oper1) {
	case '+':
		return atoi(buf1) + atoi(buf2);
	case '-':
		return atoi(buf1) - atoi(buf2);
	case '*':
		return atoi(buf1) * atoi(buf2);
	case '/':
		{
			int a = atoi(buf2);
			if (a)
				return atoi(buf1) / atoi(buf2);
			else
				return 0;
		}

	}

}

/* eat the return carriage */
void cutereturn(char *s)
{
	int len = strlen(s);
	/* if it is a return carriage, replace it with 0 */
	if (s[len - 1] == '\n')
		s[len - 1] = 0;
}

int main(void)
{
	//const char *s = "6 / 0  =";
	//printf("%d\n", calc_string(s));
	FILE *p = fopen("D:\\temp\\a.txt", "r");
	FILE *p1 = fopen("D:\\temp\\b.txt", "w");
	char buf[1024];
	char buf1[1024];
	while (!feof(p)) {
		memset(buf, 0, sizeof(buf));
		/* read a record line, it is terminated with '\n' */
		fgets(buf, sizeof(buf), p);
		cutereturn(buf);
		int value = calc_string(buf);
		memset(buf1, 0, sizeof(buf1));
		/* rearrange buf and the result of buf to a string */
		sprintf(buf1, "%s%d\n", buf, value);
		//printf("buf1 = %s\n", buf1);
		/* write the rearanged string to new file */
		fputs(buf1, p1);
	}
	fclose(p);
	fclose(p1);
	return 0;
}
