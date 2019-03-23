#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* usage: rotate <length> <shift> <array>
 * 	shifts the elements of an array to the right.
 * 	rotate 7 3 [1,2,3,4,5,6,7]
 * 	[5,6,7,1,2,3,4]
 */

void shift_right(int arr[], int length);


int main(int argc, char *argv[])
{
	int length, shift, n;
	int *arr;
	char c;

	/* Parse inputs */
	length = atoi(argv[1]);
	shift = atoi(argv[2]);
	arr = (int *) malloc(length * sizeof(int));

	n = 0;
	while ((c = *argv[3]++) != '\0')
		if (c != ',' && c != '[' && c != ']')
			arr[n++] = atoi(&c);

	printf("Inputs:\n");
	printf("length is %d\n", length);
	printf("shift is %d\n", shift);
	printf("array is ");
	for (int i = 0; i < length - 1; i++)
		printf("%d,", arr[i]);
	printf("%d\n", arr[length - 1]);

	/* Rotation */
	for (int i = 0; i < shift; i++) {
		shift_right(arr, length);
	}

	printf("Output:\n");
	for (int i = 0; i < length - 1; i++)
		printf("%d,", arr[i]);
	printf("%d\n", arr[length - 1]);

	free(arr);

	return 0;	
}


void shift_right(int arr[], int length)
{
	int swap, temp;

	swap = arr[length - 1];
	for (int i = 0; i < length; i++) {
		temp = arr[i];
		arr[i] = swap;
		swap = temp;
	}
}
