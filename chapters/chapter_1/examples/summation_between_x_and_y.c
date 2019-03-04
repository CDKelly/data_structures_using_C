// example 5, pg. 23

// Calculate the sum of number from x to y

#include <stdio.h>
int main() {
	int x, y, i, sum = 0;
	printf("\nEnter a number x : \t");
	scanf("%d", &x);
	i=x;
	printf("\nEnter a number y : \t");
	scanf("%d", &y);

	while(i<=y) {
		sum += i;
		i++;
	}
	printf("\nThe sum of numbers from %d to %d = %d\n", x, y, sum);
	return 0;
}
