// example 9, pg. 81

/* Delete a number from a given location
   in an array
*/

#include <stdio.h>
int main() {
	int n;

	printf("\nEnter the number of elements you'd like in the array : ");
	scanf("%d", &n);

	int arr[n];

	for(int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	int idx;
	printf("\nEnter the index from which the number has to be deleted : ");
	scanf("%d", &idx);

	if (idx < n - 1) {
		for(int i = idx; i < n - 1; i++) {
			arr[i] = arr[i+1];
		}
	}

	n--;
	printf("\nThe array after deleting the value from index %d : ", idx);
	for(int i = 0; i < n; i++) {
		printf("\narr[%d] = %d", i, arr[i]);
	}
	return 0;
}
