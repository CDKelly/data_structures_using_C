// example 3

// Write a program to append a string to another string

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* read_str(bool is_dest_str);
char* append_str(char *dest_str, char *src_str);

int main() {
	char *dest_str = read_str(true);
	char *src_str = read_str(false);

	char *new_dest_str = append_str(dest_str, src_str);

	printf("After appending, the destination string is : %s", new_dest_str);

	free(dest_str);
	free(src_str);
	return 0;
}

char* read_str(bool is_dest_str) {
	char *str = (char *) malloc(100 * sizeof(char));
	char *which_str = is_dest_str ? "destination" : "source";

	printf("Enter the %s string (no more than 100 characters) : \n", which_str);
	gets(str);

	return str;
}

char* append_str(char *dest_str, char *src_str) {
	int dest_str_len = strlen(dest_str);
	int src_str_len = strlen(src_str);

	int curr_idx = dest_str_len;
	for(int i = 0; i < src_str_len; i++) {
		dest_str[curr_idx] = src_str[i];
		++curr_idx;
	}

	return dest_str;
}

