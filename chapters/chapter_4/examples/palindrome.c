// example 12, pg. 131

// Determine if a given string is a palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* get_string(int size);
bool is_palindrome(char *string);

int main() {
    // don't wanna do > 1000
    char *input = get_string(1000);

    bool yes_or_no = is_palindrome(input);

    if(yes_or_no) {
        printf("%s IS a palindrome", input);
    } else {
        printf("%s is NOT a palindrome", input);
    }

    free(input);
    return 0;
}

char* get_string(int size) {
    char *result = (char *) malloc(size * sizeof(char));

    printf("\nPlease enter string to check for palindromeness (max size = %d; does not work with spaces) : ", size);
    scanf("%s", result);

    return result;
}

bool is_palindrome(char *string) {
    int str_len = strlen(string);
    bool result = true;
    int i = 0;
    int j = str_len-1;

    while(i <= j) {
        if(string[i] == string[j]) {
            i++;
            j--;
        } else {
            result = false;
            break;
        }
    }

    return result;
}
