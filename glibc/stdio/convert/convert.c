
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FILE_LEN 64
#define MAX_LINE 128
#define LINE 28

int main(int argc, char *argv[])
{
	FILE *in, *out;
	char file_name[FILE_LEN];
	char buf[MAX_LINE];
	char outbuf[MAX_LINE];
	char head[LINE];
	char *p;
	int len;

	if (argc != 2) {
		printf("wrong usage\n");
		exit(1);
	}
	len = strlen(argv[1]);

	/* the extension is "ini" ? */
	if (strcmp(&argv[1][len - 3], "ini") != 0) {
		printf("source file error\n");
		exit(1);
	}

	/* open configure file */
	in = fopen(argv[1], "r");
	if (in == NULL) {
		perror("fail to open");
		exit(1);
	}
	/* change the configure file extension to "xml" */
	strcpy(file_name, argv[1]);
	strcpy(&file_name[len - 3], "xml");

	/* open ".xml" file, the filename is same as the original */
	out = fopen(file_name, "w");
	if (out == NULL) {
		perror("fail to open");
		exit(1);
	}

	/* read lines one by one */
	while (fgets(buf, MAX_LINE, in) != NULL) {
		/* remove the last '\n' */
		len = strlen(buf);
		printf("%d\n", len);
		buf[len - 1] = '\0';

		/* write configure info header */
		if (buf[0] == '#')
			sprintf(outbuf, "<!-- %s -->\n", buf);
		/* write configure info header */
		else if (buf[0] == '!') {
			sprintf(outbuf, "<%s>\n", &buf[1]);
			/* make a copy, for the </head> output latter */
			strcpy(head, buf);
		/* encounter to empty line, a configure info is done, output it */
		} else if (buf[0] == '\0')
			sprintf(outbuf, "</%s>\n\n", &head[1]);
		else {
			/* split a line into configure options and configure content */
			p = strtok(buf, "=");
			sprintf(outbuf, "\t<%s>%s</%s>\n", buf, p, buf);
		}

		/* output the ready info, one time for every line */
		if (fputs(outbuf, out) == -1) {
			perror("fail to write");
			exit(1);
		}
	}
	if (errno != 0) {
		perror("fail to read");
		exit(1);
	}
	fclose(in);
	fclose(out);
	return 0;
}

