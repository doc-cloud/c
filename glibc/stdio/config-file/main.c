
#define KEY_LEN 1024
#define CONFIG_FNAME "./config.txt"
#define LINE_SIZE 2048

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void)
{
	printf("======================\n");
	printf("1.write configure file\n");
	printf("2.read configure file\n");
	printf("3.exit\n");
	printf("======================\n");
}

int item_write(const char *cfg_fname, const char *key, const char *value, int len)
{
	int ret = 0;
	FILE *fp = NULL;
	long file_len;
	char linebuf[LINE_SIZE];
	const char *ptmp = NULL;
	char filebuf[1024 * 8] = {0};
	int itag = 0;

	if (cfg_fname == NULL || key == NULL || value == NULL) {
		ret = -1;
		printf("item_write error, param error\n");
		goto out;
	}

	fp = fopen(cfg_fname, "r+");
	if (fp == NULL) {
		ret = -2;
		printf("item_write error, param error\n");
		//goto out;
	}

	if (fp == NULL) {
		fp = fopen(cfg_fname, "w+t");
		if (fp == NULL) {
			ret = -3;
			printf("item_write error, param error\n");
			goto out;
		} else
			ret = 0;
	}

	fseek(fp, 0, SEEK_END);
	file_len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (file_len > 1024 * 8) {
		ret = -3;
		printf("over 1024 * 8, not supported\n");
		goto out;
	}

	while (!feof(fp)) {
		memset(linebuf, 0, LINE_SIZE);
		ptmp = fgets(linebuf, LINE_SIZE, fp);
		if (ptmp == NULL)
			break;
		ptmp = strstr(ptmp, key);
		if (ptmp == NULL) {
			strcat(filebuf, linebuf);
			continue;
		} else {
			sprintf(linebuf, "%s = %s\n", key, value);
			strcat(filebuf, linebuf);
			itag = 1;
		}
	}

	if (itag == 0)
		fprintf(fp, "%s = %s\n", key, value);
	else {
		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(cfg_fname, "w+t");
		if (fp == NULL) {
			ret = -4;
			printf("fopen error\n");
			goto out;
		}
		fputs(filebuf, fp);
	}
out:
	if (fp != NULL)
		fclose(fp);
	return ret;
}

int config_write(void)
{
	char key[KEY_LEN] = {0};
	char value[KEY_LEN] = {0};
	int ret = 0;
	printf("input key:");
	scanf("%s", key);
	printf("input value:");
	scanf("%s", value);
	ret = item_write(CONFIG_FNAME, key, value, strlen(value));
	if (ret != 0) {
		printf("func write configure file err:%d\n", ret);
		return ret;
	}
	printf("your write item is:%s = %s\n", key, value);
	return ret;
}

int item_read(const char *cfg_fname, const char *key, char *value, int *len)
{
	int ret = 0;
	FILE *fp = NULL;
	char linebuf[LINE_SIZE];
	char *ptmp, *pbegin;

	if (cfg_fname == NULL || key == NULL || value == NULL) {
		ret = -1;
		printf("item_read error, param error\n");
	}

	fp = fopen(cfg_fname, "r");
	if (fp == NULL) {
		ret = -2;
		printf("item_read error, param error\n");
	}

	while (!feof(fp)) {
		memset(linebuf, 0, LINE_SIZE);
		fgets(linebuf, LINE_SIZE, fp);
		ptmp = strstr(linebuf, key);
		if (ptmp == NULL)
			continue;
		ptmp = strchr(linebuf, '=');
		if (ptmp == NULL)
			continue;
		while (*++ptmp == ' ');
		pbegin = ptmp;
		if (*pbegin == '\n')
			goto out;
		while (*ptmp != ' ' && *ptmp != '\n')
			ptmp++;

		*len = ptmp - pbegin;
		memcpy(value, pbegin, *len);
	}
out:
	if (fp != NULL)
		fclose(fp);
	return ret;
}

int config_read(void)
{
	int ret = 0;
	char key[KEY_LEN] = {0};
	char value[KEY_LEN] = {0};
	int len = 0;
	printf("input key:");
	scanf("%s", key);
	ret = item_read(CONFIG_FNAME, key, value, &len);
	if (ret != 0) {
		printf("func read configure file err:%d\n", ret);
		return ret;
	}
	printf("your read item is:%s = %s\n", key, value);
	return ret;
}

void main()
{
	int choice;
	for (;;) {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			config_write();
			break;
		case 2:
			config_read();
			break;
		case 3:
			exit(0);
		default:
			exit(0);
		}
	}
}

