// exercise 3, pg. 40

// Count the numbers of vowels in a string

#include <stdio.h>
#include <regex.h>
#include <string.h>

/* return 1 for match, 0 for no match or errors */
int match(const char *string, const char *pattern) {
	regex_t re;

	if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB|REG_ICASE) != 0) {
		return 0; // check for compilation error
	}

	int status = regexec(&re, string, 0, NULL, 0);
	regfree(&re); // free up memory

	if (status != 0) {
		return 0; // check for no match or error
	}

	return 1;
}

int main() {
	char user_str[60];
	int count;
	const char *pattern = "[aeiou]";

	printf("\nEnter a string (less than 60 characters) : \t");
	scanf("%s", user_str);

	int str_len = strlen(user_str);
	const char *user_char = user_str;

	printf("\ndoes match: %d\n", match(user_char, pattern));

	if (strchr(user_char, 'a')) {
		printf("\nstrchr line reached");
	}

	for(int i=0; i<str_len; i++) {
		char curr_char = user_str[i];
		printf("\ncurr char %c\n", user_str[i]);
		printf("\npattern pointer: %c\n", pattern[i]);
		if (match(&curr_char, pattern)) {
			printf("\nthis line reached\n");
			printf("\n=======\n");
		}
	}
}
