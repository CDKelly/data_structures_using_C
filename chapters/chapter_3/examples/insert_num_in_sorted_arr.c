// example 8, pgs. 78-79

/* Insert a number in an array that can be
   sorted in ascending or descending order.
   The number the user inserts must be present
   in the array.
*/

#include<stdio.h>
int asc_or_desc_comparison(int is_asc, int arr_num, int user_num) {
	int result = 0;

	if (is_asc && user_num <= arr_num) {
		result = 1;
	} else if (!is_asc && user_num >= arr_num) {
		result = 1;
	}

	return result;
}


int main() {
	int is_asc, n;

	printf("\nWill the numbers you enter be in ascending or descending order? (Enter 1 for ascending or 0 for descending) : ");
	scanf("%d", &is_asc);
	printf("\nEnter the number of elements you'd like in the array : ");
	scanf("%d", &n);

	int arr[n];

	for(int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	int user_num;

	printf("\nEnter the number to be inserted into the array : ");
	scanf("%d", &user_num);

	for(int i = 0; i < n; i++) {
		if ((*asc_or_desc_comparison)(is_asc, arr[i], user_num)) {
			for(int j = n - 1; j >= i; j--) {
				arr[j+1] = arr[j];
			}
			arr[i] = user_num;
			break;
		}
	}
	n++;
	printf("\nThe array after inserting %d : ", user_num);

	for(int i = 0; i < n; i++) {
		printf("\narr[%d] = %d", i, arr[i]);
	}
	return 0;
}
