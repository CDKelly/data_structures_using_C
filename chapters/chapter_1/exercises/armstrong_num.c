// exercise 23, pg. 41

/* Determine if a given 3-digit number is an Armstrong number.
   An Armstrong number is a number such that the sum
   of its digits raised to the third power is equal
   to the number itself
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int is_armstrong_num(char user_str[]) {
	char *ptr;
	int str_len = strlen(user_str);
	long sum = 0;

	for(int i = 0; i < str_len; i++) {
		char curr_char = user_str[i];
		long curr_long = strtol(&curr_char, &ptr, 10);
		sum += pow(curr_long, 3);
	}
	return sum == strtol(user_str, &ptr, 10);
}

int main() {
	char user_str[5];

	printf("\nEnter a 3-digit number : \t");
	scanf("%s", user_str);

	int is_armstrong_number = is_armstrong_num(user_str);

	printf("%s is %san Armstrong number", user_str, (is_armstrong_number == 1 ? "" : "not "));
}
