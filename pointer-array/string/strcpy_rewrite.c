#include <stdio.h>
#include <assert.h>

char *strcpy_rewrite(char *dst,const char *src){
	char *ret = dst;
	assert(dst && src);
	while('\0' != (*dst++ = *src++))
		;
	return ret;
}

int main(){
	char dst[20];
	printf("%s\n",strcpy_rewrite(dst,"fasdfsdfsdfsfasdfgdfgfdsffsfsdfsddffa!"));
	return 0;
}
