// exercise 17, pg. 41

/* Convert a given string to all uppercase
   and all lowercase
 */

#include <stdio.h>
void lower_case(char str[]) {
	int c = 0;

	while (str[c] != '\0') {
		if (str[c] >= 'A' && str[c] <= 'Z') {
			str[c] += 32;
		}
		c++;
	}
}

void upper_case(char str[]) {
	int c = 0;

	while (str[c] != '\0') {
		if (str[c] >= 'a' && str[c] <= 'z') {
			str[c] -= 32;
		}
		c++;
	}
}

int main() {
	char user_str[60];

	printf("\nEnter a string (less than 60 characters) : ");
	scanf("%s", user_str);

	lower_case(user_str);
	printf("\nLower cased string : %s", user_str);
	upper_case(user_str);
	printf("\nUpper cased string : %s", user_str);
}
