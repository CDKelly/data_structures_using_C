// example 10, pg. 130

// Alphabetically sort the names of students in an array of strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_num_students();
char* get_student_arr(int num_students);
/* void copy_name_to_arr(char *arr, int idx); */
char* get_student_name(int idx);
char* get_val_in_arr(char *arr, int idx);
void bubble_sort_arr(char *arr, int num_students);
void swap_elements(char *arr, int str1_idx, int str2_idx, char *str1, char *str2);
void clear_element(char *arr, int idx, char *str);

// I know global vars are typically looked down upon
int max_num_of_chars_per_name = 15;

int main() {

	int num_students = get_num_students();

	char *student_names = get_student_arr(num_students);
	bubble_sort_arr(student_names, num_students);

	printf("Sorted students' names : \n");
	for(int i = 0; i < num_students; i++) {
		printf("\nstudent [%d] : %s", i+1, get_val_in_arr(student_names, i));
	}

	free(student_names);
	return 0;
}

int get_num_students() {
	int num;

	printf("How many students' names need sorted : ");
	scanf("%d", &num);
	printf("\n\n");

	return num;
}

char* get_student_arr(int num_of_students) {
	char *arr = (char *) malloc(num_of_students * max_num_of_chars_per_name * sizeof(char));

	printf("Please enter the first names of each student (up to 15 characters)\n");
	for(int i = 0; i < num_of_students; i++) {
		char *student_name = get_student_name(i);
		strcpy(&arr[(i * max_num_of_chars_per_name)], student_name);
		free(student_name);
	}

	return arr;
}

char* get_student_name(int idx) {
	char *student_name = (char *) malloc(max_num_of_chars_per_name * sizeof(char));

	// I have no idea why the first student is skipped all the time (at least on my machine)
	// Maybe something to do with fgets?
	printf("\nFirst name of Student %d : ", idx+1);
	fgets(student_name, max_num_of_chars_per_name, stdin);

	return student_name;
}

// get int val from a 2d array that is stored in row major order
char* get_val_in_arr(char *arr, int idx) {
	char *str = (char *) malloc(max_num_of_chars_per_name * sizeof(char));

	for(int i = 0; i < max_num_of_chars_per_name; i++) {
		str[i] = arr[(idx * max_num_of_chars_per_name) + i];
	}

	return str;
}

void bubble_sort_arr(char *arr, int num_students) {
	for(int i = 0; i < num_students; i++) {
		for(int j = 0; j < num_students-i-1; j++) {
			char *curr_student_name = get_val_in_arr(arr, j);
			char *next_student_name = get_val_in_arr(arr, j+1);

			if(strcmp(curr_student_name, next_student_name) > 0) {
				swap_elements(arr, j, j+1, curr_student_name, next_student_name);
			}

			free(curr_student_name);
			free(next_student_name);
		}
	}
}

void swap_elements(char *arr, int str1_idx, int str2_idx, char *str1, char *str2) {
	clear_element(arr, str1_idx, str1);
	clear_element(arr, str2_idx, str2);

	strcpy(&arr[(str2_idx * max_num_of_chars_per_name)], str1);
	strcpy(&arr[(str1_idx * max_num_of_chars_per_name)], str2);
}

void clear_element(char *arr, int idx, char *str) {
	int str_len = strlen(str);

	// want to delete the null character at the end of str as well
	for(int i = 0; i <= str_len; i++) {
		strcpy(&arr[(idx * max_num_of_chars_per_name) + i], "");
	}
}
