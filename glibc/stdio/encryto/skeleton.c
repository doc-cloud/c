
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

int FileSymEnc(const char *pfile1, const char *pfile2)
{
	int ret = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	unsigned char plain[4096];
	int plainlen = 0;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	int tmplen;

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
		goto END;

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
		goto END;

	while (!feof(fp1)) {
		plainlen = fread(plain, 1, 4096, fp1);
		if (feof(fp1))
			break;
		/* encrypt == 4K data */
		ret = DesDec_raw(plain, plainlen, cryptbuf, &cryptlen);
		if (ret != 0) {
			printf("func DesEnc() err:%d \n", ret);
			goto END;
		}

		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if (tmplen != cryptlen) {
			ret = -3;
			printf("Error occured while writing encrypted file, check the disk\n");
			goto END;
		}
		//if (plainlen == 4096)
	}

	/* smaller than 4K */
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0) {
		printf("func DesEnc() err:%d \n", ret);
		goto END;
	}

	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if (cryptlen != tmplen) {
		ret = -3;
		printf("Error occured while writing encrypted file, check the disk\n");
		goto END;
	}

END:
	if (fp1 != NULL)
		fclose(fp1);
	if (fp2 != NULL)
		fclose(fp2);
	return 0;
}

void main()
{
	int ret = 0;
	const char *file1 = "./source.txt";
	const char *file2 = "./destination.txt";

	ret = FileSymEnc(file1, file2);
	if (ret != 0) {
		printf("func FileSymEnc() err\n ");
		return;
	}

	return;
}

