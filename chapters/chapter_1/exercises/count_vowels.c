// exercise 3, pg. 40

// Count the numbers of vowels in a string

#include <stdio.h>
#include <regex.h>


/* return 1 for match, 0 for no match or errors */
int match(const char *string, const char *pattern) {
	regex_t re;

	if (regcomp(&re, pattern, REG_EXTENDED|REGNOSUB) != 0) {
		return 0; // check for compilation error
	}

	int status = regexec(&re, string, 0, NULL, 0);
	regfree(&re); // free up memory

	if (status != 0) {
		return 0; // check for no match or error
	}

	return 1;
}
