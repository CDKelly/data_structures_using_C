// example 12, pgs. 84-85

/* Merge two arrays that are sorted in
   ascending or descending order.
*/

#include <stdio.h>
int asc_or_desc_comparison(int *is_asc, int *num1, int *num2) {
	int result = 0;

	if (*is_asc && *num1 <= *num2) {
		result = 1;
	} else if (!*is_asc && *num1 >= *num2) {
		result = 1;
	}

	return result;
}

int main() {
	int is_asc, n1, n2;

	printf("\nWill the numbers you enter be in ascending or descending order? (Enter 1 for ascending or 0 for descending) : ");
	scanf("%d", &is_asc);

	printf("\nEnter the number of elements you'd like in the first array : ");
	scanf("%d", &n1);
	int arr1[n1];
	for(int i = 0; i < n1; i++) {
		printf("\narr1[%d] = ", i);
		scanf("%d", &arr1[i]);
	}

	printf("\nEnter the number of elements you'd like in the second array : ");
	scanf("%d", &n2);
	int arr2[n2];
	for(int i = 0; i < n2; i++) {
		printf("\narr2[%d] = ", i);
		scanf("%d", &arr2[i]);
	}

	int n3 = n1 + n2;
	int arr3[n3];
	int idx1 = 0, idx2 = 0, idx3 = 0;

	while(idx1 < n1 && idx2 < n2) {
		if ((*asc_or_desc_comparison)(&is_asc, &arr1[idx1], &arr2[idx2])) {
			arr3[idx3] = arr1[idx1];
			idx1++;
		} else {
			arr3[idx3] = arr1[idx2];
			idx2++;
		}
	}
	// if arr2 still has elements in it
	if (idx1 == n1) {
		while(idx2 < n2) {
			arr3[idx3] = arr2[idx2];
			idx2++;
			idx3++;
		}
	} else if (idx2 == n2) {
		while(idx1 < n1) {
			arr3[idx3] = arr1[idx1];;
			idx1++;
			idx3++;
		}
	}

	printf("\nThe merged array : ");
	for(int i = 0; i < n3; i++) {
		printf("\narr3[%d] = %d", i, arr3[i]);
	}

	return 0;
}
