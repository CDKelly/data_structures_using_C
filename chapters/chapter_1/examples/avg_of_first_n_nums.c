// example 6, pgs. 24-25

// Calculate the average of the first n positive numbers

#include <stdio.h>
int main() {
	int n, i = 0, sum = 0;
	float avg;

	printf("\nEnter a positive number n : \t");
	scanf("%d", &n);

	do {
		sum += i;
		++i;
	} while(i<=n);

	avg = (float) sum/n;
	printf("\nThe sum of the first %d positive numbers = %d", n, sum);
	printf("\nThe average of the first %d positive numbers = %.2f\n", n, avg);

	return 0;
}
