/* Not an actual coding example - the book just mentions pattern 
   matching. Goal: return the first index at which a pattern occurs
   within a given block of text. Otherwise, return -1.
   pgs. 127 - 128
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* read_text();
char* read_patt(char *text);
bool are_val_inputs(char *text, char *patt);
int find_patt(char *text, char *patt);
void print_result(int matching_idx, char *patt);
bool is_match(int matching_idx);

int main() {
	char *text = read_text();
	char *patt = read_patt(text);

	int matching_idx = find_patt(text, patt);

	print_result(matching_idx, patt);
	
	free(text);
	free(patt);
	return 0;
}

char* read_text() {
	char *text = (char *) malloc(100 * sizeof(char));

	printf("Please enter a string to match against\n"
	       "(no more than 100 characters) : ");
	gets(text);

	return text;
}

char* read_patt(char *text) {
	char *patt = (char *) malloc(100 * sizeof(char));

	printf("Please enter a pattern to use for matching\n"
	       "(standard 128 ASCII character set) : ");
	gets(patt);

	while(!are_val_inputs(text, patt)) {
		printf("Please enter a pattern that is <= the length of text to match against : ");
		gets(patt);
	}

	return patt;
}

bool are_val_inputs(char *text, char *patt) {
	return strlen(patt) <= strlen(text);
}

int find_patt(char *text, char *patt) {
	int idx = -1;
	int max_len = strlen(text) - strlen(patt);

	for(int i = 0; i <= max_len; i++) {
		for (int j = 0; j < strlen(patt); j++) {
			if (text[i+j] != patt[j]) {
				break;
			}
			if (j == strlen(patt) - 1) { // has a full match occurred
				idx = i;
			}
		}
		if (is_match(idx)) {
			break;
		}
	}
	return idx;
}

bool is_match(int matching_idx) {
	return matching_idx > -1;
}

void print_result(int matching_idx, char *patt) {
	if (is_match(matching_idx)) {
		printf("The first index at which a matching pattern\n"
		       "occurs is : %d", matching_idx);
	} else {
		printf("The given text does not contain the pattern '%s'", patt);
	}
}

