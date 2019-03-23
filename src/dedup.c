#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* usage: dedup <length> <array>
 * 	removes duplicates from a sorted array.
 * 	dedup 7 [1,1,3,4,4,4,7]
 * 	4 [1,3,4,7]
 */

void shift_right(int arr[], int length);


int main(int argc, char *argv[])
{
	int length, n;
	int *arr;
	char c;

	/* Parse inputs */
	length = atoi(argv[1]);
	arr = (int *) malloc(length * sizeof(int));

	n = 0;
	while ((c = *argv[2]++) != '\0')
		if (c != ',' && c != '[' && c != ']')
			arr[n++] = atoi(&c);

	printf("Inputs:\n");
	printf("length is %d\n", length);
	printf("array is ");
	for (int i = 0; i < length - 1; i++)
		printf("%d,", arr[i]);
	printf("%d\n", arr[length - 1]);

	/* Dedup in place */
	n = 0;
	for (int j = 0; j < length; j++) {
		if (arr[j] != arr[n]) {
			arr[++n] = arr[j];
		}
	}

	printf("Output:\n");
	for (int i = 0; i < n; i++)
		printf("%d,", arr[i]);
	printf("%d\n", arr[n]);

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
