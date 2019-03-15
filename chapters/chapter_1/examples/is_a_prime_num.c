// example 7, pg. 26

// Determine whether a given number is a prime or a composite number

#include <stdio.h>
int main() {
	int is_prime = 0, num;

	printf("\nEnter a positive number : \t");
	scanf("%d", &num);

	for(int i=2; i < num/2; i++) {
		if (num%i == 0) {
			is_prime = 1;
			break;
		}
	}

 	if (is_prime == 1) {
		printf("\n%d is a composite number", num);
	} else {
		printf("\n%d is a prime number\n", num);
	}

	return 0;
}
