// examples 2 and 3

/* Given an array of integers find the
   min, max, and mean of the array
   as well as the indices of the min and
   max
 */

#include <stdio.h>
int main() {
	int n, sum = 0;

	printf("\nEnter the number of elements you'd like in the array : ");
	scanf("%d", &n);

	int arr[n];

	for(int i = 0; i < n; i++) {
		printf("\narr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	int min = arr[0];
	int max = arr[0];
	int min_pos = 0;
	int max_pos = 0;
	for(int i = 0; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
			min_pos = i;
		} else if (max < arr[i]) {
			max = arr[i];
			max_pos = i;
		}
		sum += arr[i];
	}

	float mean = (float) sum / n;

	printf("\nThe min of arr = %d. It's index in arr = %d", min, min_pos);
	printf("\nThe max of arr = %d. It's index in arr = %d", max, max_pos);
	printf("\nThe mean of arr = %.2f\n", mean);

	return 0;
}
