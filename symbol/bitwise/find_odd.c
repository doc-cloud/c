#include <stdio.h>

/*
 * there is an array,
 * every natural number is take the form of an even number in this array,
 * one natural number, show up odd times, find it
 */
void main()
{
	int i;
	int xor_base = 0;
	int arr[] = {43, 43, 23, 23,23,23,54,54,54};
	int len_arr = sizeof(arr) / sizeof(*arr);
	
	for(i = 0;i < len_arr;i++)
		xor_base ^= arr[i];
	
	printf("%d\n",xor_base);
}
