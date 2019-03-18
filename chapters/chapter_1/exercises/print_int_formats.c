// exercise 11, pg. 40

// Display the value of an integer in decimal, octal,
// hexademical notation

#include <stdio.h>
int main() {
	int i;
	
	printf("\nEnter an integer : \t");
	scanf("%d", &i);
	printf("\nDecimal value : %d", i);
	printf("\nOctal value : %o", i);
	printf("\nHexademical value : %x", i);
}
