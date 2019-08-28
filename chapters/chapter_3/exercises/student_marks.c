// exercise 1, pg. 113

/* Consider a two-dimensional array marks[students][subjects]
   a: find the average marks obtained in each subject
   b: find the average marks obtained by every student
   c: display the scores obtained by every student
 */

#include <stdio.h>
#include <stdlib.h>

int get_num_of_students();
int get_num_of_subjects();
double* read_arr(int rows, int cols);
void set_val(double *arr, int cols, int m, int n, double val_to_set);
double get_val(double *arr, int cols, int m, int n);
void print_matrix(double *result, int rows, int cols);
void print_avg_by_subject(double *arr, int rows, int cols);
void print_avg_by_student(double *arr, int rows, int cols);

int main() {
	int num_of_students = get_num_of_students();
	int num_of_subjects = get_num_of_subjects();

	double *arr = read_arr(num_of_students, num_of_subjects);

	print_matrix(arr, num_of_students, num_of_subjects);

	print_avg_by_subject(arr, num_of_students, num_of_subjects);
	print_avg_by_student(arr, num_of_students, num_of_subjects);
}

int get_num_of_students() {
	int num_of_students;

	printf("\nEnter the number of students : ");
	scanf("%d", &num_of_students);

	return num_of_students;
}

int get_num_of_subjects() {
	int num_of_subjects;

	printf("\nEnter the number of subjects taken by each student : ");
	scanf("%d", &num_of_subjects);

	return num_of_subjects;
}

double* read_arr(int num_of_students, int num_of_subjects) {
	double *arr = (double *) malloc(num_of_students * num_of_subjects * sizeof(double));

	printf("\nFor each student, enter the percentage grade they received");
	for(int i = 0; i < num_of_students; i++) {
		printf("\nStudent %d", i+1);
		for(int j = 0; j < num_of_subjects; j++) {
			printf("\nSubject %d : ", j+1);
			scanf("%lf", &(arr[(num_of_subjects * i) + j]));
		}
	}
	return arr;
}

// set double val for a 2d array that is stored in row major order
void set_val(double *arr, int cols, int m, int n, double val_to_set) {
	arr[(cols * m) + n] = val_to_set;
}

double get_val(double *arr, int cols, int m, int n) {
	return arr[(cols * m) + n];
}

void print_matrix(double *result, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		printf("\n");
		for(int j = 0; j < cols; j++) {
			printf("\t %7.3f", get_val(result, cols, i, j));
		}
	}
	printf("\n====================\n");
}

void print_avg_by_subject(double *arr, int rows, int cols) {

}

void print_avg_by_student(double *arr, int rows, int cols) {

}
