// example 5

// Write a program to reverse a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_str();
char* str_rev(char *str);

int main() {
	char *str = read_str();

	str_rev(str);

	printf("The reversed string : %s", str);

	free(str);
	return 0;
}

char* read_str() {
	char *str = (char *) malloc(100 * sizeof(char));

	printf("Enter the string to be reversed (no more than 100 characters) : \n");
	fgets(str, 100, stdin);

	return str;
}

char* str_rev(char *str) {
	if (!str || ! *str) {
		return str;
	}

	int i = 0, j = strlen(str) - 1;
	char temp;

	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	return str;
}

