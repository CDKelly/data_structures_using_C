// exercise 4, pg. 135

// Trim leading and trailing whitespace from a string
// Creates new string, leaves original intact
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_str();
char* trim_str(const char *str, int first_nonwhitespace);
int get_first_idx_of_nonwhitespace(const char *str);
int get_last_idx_of_nonwhitespace(const char *str);

int main() {
    char *orig_str = get_str();

    int first_nonwhitespace = get_first_idx_of_nonwhitespace(orig_str);
    if (strlen(orig_str) == 0 || first_nonwhitespace == -1) {
        printf("Trimmed string is : ''");
        return 0;
    }

    char *trimmed_str = trim_str(orig_str, first_nonwhitespace);
    printf("Trimmed string is : '%s'", trimmed_str);

    free(orig_str);
    free(trimmed_str);
    return 0;
}

char* get_str() {
    char *str = (char *) malloc(100 * sizeof(char));

    char *input_prompt = "Enter the string whose whitespace we need to trim"
           " (no more than 100 characters) : \n";

    printf("%s", input_prompt);
    gets(str);

    return str;
}

char* trim_str(const char *str, int first_nonwhitespace) {
    int last_nonwhitespace = get_last_idx_of_nonwhitespace(str);

    int substr_len = last_nonwhitespace - first_nonwhitespace;

    char *trimmed_str = (char *) malloc(substr_len * sizeof(char));

    int j = 0;
    for(int i = first_nonwhitespace; i <= last_nonwhitespace; i++) {
        trimmed_str[j] = str[i];
        j++;
    }

    printf("\ntrimmed str = '%s'\n", trimmed_str);

    return trimmed_str;
}

// return -1 if all whitespace
int get_first_idx_of_nonwhitespace(const char *str) {
    if (strlen(str) == 0) {
        return 0;
    }

    int i = -1;
    for(int j = 0; j < strlen(str); j++) {
        if (str[j] != ' ') {
            i = j;
            break;
        }
    }

    return i;
}

// return -1 if all whitespace
int get_last_idx_of_nonwhitespace(const char *str) {
    if (strlen(str) == 0) {
        return 0;
    }

    int i = -1;
    for(int j = strlen(str)-1; j >= 0; j--) {
        if (str[j] != ' ') {
            i = j;
            break;
        }
    }

    return i;
}
