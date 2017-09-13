
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

int main()
{
	int ret = 0;
	char *plain = "1232343444";
	int plainlen = strlen(plain);

	char plain2[4096] = { 0 };
	int plainlen2 = 0;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	/* user used function */
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0) {
		printf("func DesEnc() err:%d \n");
		return ret;
	}

	/* decrypt by des */
	ret = DesDec(cryptbuf, cryptlen, plain2, &plainlen2);
	if (ret != 0) {
		printf("func DesDec() err:%d \n");
		return ret;
	}

	if (plainlen != plainlen2) {
		ret = -2;
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ�� \n");
		return ret;
	}

	if (memcmp(plain2, plain, plainlen) == 0)
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� һ�� ok \n");
	else
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ�� err \n");

	return ret;
}

