// example 15, pg. 92

/* Display the first half of a given array
   using pointers
*/

#include <stdio.h>
#include <stdlib.h>

int* read_arr(int s);
void display_half_arr(int *arr, int *half_ptr);

int main() {
	int s;

	printf("\nEnter the number of elements you'd like in the array : ");
	scanf("%d", &s);

	int *arr = read_arr(s);

	int half = s / 2;
	half = s % 2 == 0 ? half - 1 : half;

	display_half_arr(arr, &arr[half]);

	free(arr);
	return 0;
}

int* read_arr(int size_of_arr) {
	int *arr = (int *) malloc(size_of_arr * sizeof(int));

	for(int i = 0; i < size_of_arr; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	return arr;
}

void display_half_arr(int *arr, int *half_ptr) {
	printf("\nThe first half of the array : ");
	int *ptr = arr;

	while(ptr <= half_ptr) {
		printf("%d ", *ptr);
		ptr++;
	}
}
