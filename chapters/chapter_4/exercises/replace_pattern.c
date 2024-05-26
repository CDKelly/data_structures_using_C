// derived from exercise 5, chapter 4, pg. 135

// Replace all matches in a given string with another pattern
// Creates new string, leaves original intact
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* read_text();
char* read_find_patt(char *text);
char* read_replace_patt();
bool are_val_inputs(char *text, char *patt);
char* find_and_replace_patt(char *text, const char *find_patt, const char *replace_patt);
int find_patt_starting_at_idx(const char *text, const char *patt, int starting_idx);
bool is_match(int matching_idx);
void replace_patt(const char *text, char *new_str, const char *replacement, int curr_starting_idx, int curr_is_match);

int main() {
    char *text = read_text();
    char *find_patt = read_find_patt(text);
    char *replace_patt = read_replace_patt();

    char *new_str = find_and_replace_patt(text, find_patt, replace_patt);

    printf("New string with pattern replaced : %s\n", new_str);

    free(text);
    free(find_patt);
    free(replace_patt);
    free(new_str);
    return 0;
}

char* read_text() {
    char *text = (char *) malloc(100 * sizeof(char));

    printf("Please enter a string to match against\n"
           "(no more than 100 characters) : ");
    gets(text);

    return text;
}

char* read_find_patt(char *text) {
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

char* read_replace_patt() {
    char *patt = (char *) malloc(100 * sizeof(char));

    printf("Please enter a string to replace the above pattern\n"
           "(standard 128 ASCII character set) : ");
    gets(patt);

    return patt;
}

bool are_val_inputs(char *text, char *patt) {
    return strlen(patt) <= strlen(text);
}

char* find_and_replace_patt(char *text, const char *find_patt, const char *replacement) {
    char *new_str = (char *) malloc(300 * sizeof(char));
    int curr_starting_idx = 0;
    int max_starting_idx = strlen(text) - strlen(find_patt);

    while(curr_starting_idx <= max_starting_idx) {

        int curr_is_match = find_patt_starting_at_idx(text, find_patt, curr_starting_idx);

        replace_patt(text, new_str, replacement, curr_starting_idx, curr_is_match);

        if (is_match(curr_is_match)) {
            curr_starting_idx = curr_is_match + strlen(find_patt);
        } else {
            break;
        }
    }

    return new_str;
}

int find_patt_starting_at_idx(const char *text, const char *patt, int starting_idx) {
    int matching_idx = -1;
    int max_idx = strlen(text) - strlen(patt);

    if (starting_idx > max_idx) {
        printf("Finding pattern starting index is PAST (greater than) maximum index we can look at! Returning no match (-1)\n");
        return matching_idx;
    }

    for(int i = starting_idx; i <= max_idx; i++) {
        for (int j = 0; j < strlen(patt); j++) {
            if (text[i+j] != patt[j]) {
                break;
            }
            if (j == strlen(patt) - 1) { // has a full match occurred
                matching_idx = i;
            }
        }
        if (is_match(matching_idx)) {
            break;
        }
    }

    return matching_idx;
}

bool is_match(int matching_idx) {
    return matching_idx > -1;
}

void replace_patt(const char *text, char *new_str, const char *replacement, int curr_starting_idx, int curr_is_match) {

    if (is_match(curr_is_match)) {
        // copy the non-matching part of the original text to the new str
        strncpy(new_str+strlen(new_str), text+curr_starting_idx, curr_is_match - curr_starting_idx);

        // copy the replacement pattern to new str
        strncpy(new_str+strlen(new_str), replacement, strlen(replacement));
    } else {
        // copy the non-matching part of the original text to the new str
        strncpy(new_str+strlen(new_str), text+curr_starting_idx, strlen(text)-curr_starting_idx);
    }
}
