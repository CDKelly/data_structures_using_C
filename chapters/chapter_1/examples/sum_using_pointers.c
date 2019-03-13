// example 9, pg. 37

// Add two integers using pointers and functions

#include <stdio.h>
void sum(int *a, int *b, int *t) {
	*t = *a + *b;
}

int main() {
	int num1, num2, total;

	printf("\n Enter the first number num1 : \t");
	scanf("%d", &num1);
	printf("\n Enter the second number num2 : \t");
	scanf("%d", &num2);

	sum(&num1, &num2, &total);

	printf("\n Total = %d\n", total);
	return 0;
}

