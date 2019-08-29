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
int get_subject_to_avg();
int get_student_to_avg();
double calc_avg_by_subject(double *arr, int rows, int cols, int subj_to_avg);
double calc_avg_by_student(double *arr, int rows, int cols, int stud_to_avg);

int main() {
	int num_of_students = get_num_of_students();
	int num_of_subjects = get_num_of_subjects();

	double *arr = read_arr(num_of_students, num_of_subjects);

	print_matrix(arr, num_of_students, num_of_subjects);
	print_avg_by_subject(arr, num_of_students, num_of_subjects);
	print_avg_by_student(arr, num_of_students, num_of_subjects);

	free(arr);
	return 0;
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
		printf("\nStudent %d", i+1);
		for(int j = 0; j < cols; j++) {
			printf("\t%7.3f", get_val(result, cols, i, j));
		}
	}
	printf("\n====================\n");
}

void print_avg_by_subject(double *arr, int rows, int cols) {
	int subj_to_avg = get_subject_to_avg();

	double avg_by_subject = calc_avg_by_subject(arr, rows, cols, subj_to_avg);

	printf("\nThe average mark for Subject %d across all students : %7.3f", subj_to_avg, avg_by_subject);
}

void print_avg_by_student(double *arr, int rows, int cols) {
	int stud_to_avg = get_student_to_avg();

	double avg_by_student = calc_avg_by_student(arr, rows, cols, stud_to_avg);

	printf("\nThe average mark for Student %d across all subjects : %7.3f", stud_to_avg, avg_by_student);
}

int get_subject_to_avg() {
	int subj_to_avg;

	printf("\nWhich subject would you like find the average of : ");
	scanf("%d", &subj_to_avg);

	return subj_to_avg;
}

int get_student_to_avg() {
	int stud_to_avg;

	printf("\nWhich student's marks would you to average : ");
	scanf("%d", &stud_to_avg);

	return stud_to_avg;
}

double calc_avg_by_subject(double *arr, int rows, int cols, int subj_to_avg) {
	double sum_of_marks = 0.0;

	for(int i = 0; i < rows; i++) {
		double curr_mark = get_val(arr, cols, i, subj_to_avg-1);
		sum_of_marks += curr_mark;
	}

	return sum_of_marks / rows;
}

double calc_avg_by_student(double *arr, int rows, int cols, int stud_to_avg) {
	double sum_of_marks = 0.0;

	for(int j = 0; j < cols; j++) {
		double curr_mark = get_val(arr, cols, stud_to_avg-1, j);
		sum_of_marks += curr_mark;
	}

	return sum_of_marks / cols;
}
