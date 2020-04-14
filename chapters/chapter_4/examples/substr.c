// example 8, pgs. 127 - 128

/* Write a program to retrieve a substring from a string
   given a starting and ending index (exclusive; does not
   edit the original string)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* read_str();
int get_start_idx(int str_len);
bool is_val_start_idx(int str_len, int start_idx);
int get_end_idx(int str_len, int start_idx);
bool is_val_end_idx(int str_len, int start_idx, int end_idx);
char* get_substr(char *orig_str, int start_idx, int end_idx);

int main() {
	char *orig_str = read_str();

	int start_idx = get_start_idx(strlen(orig_str));
	int end_idx = get_end_idx(strlen(orig_str), start_idx);

	char *substr = get_substr(orig_str, start_idx, end_idx);
	printf("\nSubstring : %s", substr);

	free(substr);
	return 0;
}

char* read_str() {
	char *str = (char *) malloc(100 * sizeof(char));

	char *input_prompt = "Enter the string from which a substring will be"
	       " removed (no more than 100 characters) : \n";

	printf("%s", input_prompt);
	fgets(str, 100, stdin);

	return str;
}

int get_start_idx(int str_len) {
	int start_idx = -1;

	while(!is_val_start_idx(str_len, start_idx)) {
		char *input_prompt = "\nEnter starting index of the substring"
			"\n(must >= 0 and <= the length of your string) : ";
		printf("%s", input_prompt);
		scanf("%d", &start_idx);
	}

	return start_idx;
}

bool is_val_start_idx(int str_len, int start_idx) {
	return start_idx >= 0 && start_idx <= str_len-1;
}

int get_end_idx(int str_len, int start_idx) {
	int end_idx = -1;

	while(!is_val_end_idx(str_len, start_idx, end_idx)) {
		char *input_prompt = "\nEnter ending index of the substring"
			"\n(must be <= the length of your string"
			" and >= the starting index) : ";
		printf("%s", input_prompt);
		scanf("%d", &end_idx);
	}

	return end_idx;
}

bool is_val_end_idx(int str_len, int start_idx, int end_idx) {
	return end_idx <= str_len-1 && end_idx >= start_idx;
}

char* get_substr(char *orig_str, int start_idx, int end_idx) {
	int substr_len = end_idx - start_idx;
	char *substr = (char *) malloc(substr_len * sizeof(char));

	if (substr_len == 0) {
		substr[0] = '\0';
	}

	int j = 0;
	for(int i = start_idx; i < end_idx; i++) {
		substr[j] = orig_str[i];
		j++;
	}

	return substr;
}
