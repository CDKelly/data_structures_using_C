// example 6

/* Determine whether an array contains duplicate
   nums. Print the indices of the last-most duplicate
   if applicable
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

	int dup_1, dup_2, is_duplicate = 0;

	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				is_duplicate = 1;
				dup_1 = i;
				dup_2 = j;
			}
		}
	}

	if(is_duplicate == 0) {
		printf("\nNo duplicates found");
	} else {
		printf("\nDuplicates found at indices %d and %d\n", dup_1, dup_2);
	}

	return 0;
}
