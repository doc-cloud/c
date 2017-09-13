
#include <stdio.h> 

int main(void) 
{ 
	FILE *in, *out; 

	if ((in = fopen("test.txt", "rt")) == NULL) {
		fprintf(stderr, "Cannot open input file.\n"); 
		return 1; 
	} 

	if ((out = fopen("test.txt.bak", "wt")) == NULL) {
		fprintf(stderr, "Cannot open output file.\n"); 
		return 1; 
	} 

	while (!feof(in)) 
		fputc(fgetc(in), out); 

	fclose(in); 
	fclose(out); 
	return 0; 
}

