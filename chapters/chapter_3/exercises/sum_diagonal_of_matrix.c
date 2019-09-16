// exercises 15-17, pg. 113

/* Write a program that reads a matrix and sums the elements
   above, along, and below its main diagonal
 */

#include <stdio.h>
#include <stdlib.h>

int get_dim();
int* read_arr(int dim);
int get_val(int *arr, int cols, int m, int n);
void print_matrix(int *arr, int rows, int cols);
void print_sum_of_upper_tri(int *arr, int rows, int cols);
void print_sum_of_diagonal(int *arr, int rows, int cols);
void print_sum_of_lower_tri(int *arr, int rows, int cols);
int calc_sum_of_upper_tri(int *arr, int rows, int cols);
int calc_sum_of_diagonal(int *arr, int rows, int cols);
int calc_sum_of_lower_tri(int *arr, int rows, int cols);

int main() {
	int dim = get_dim();
	int *arr = read_arr(dim);
	print_matrix(arr, dim, dim);

	print_sum_of_upper_tri(arr, dim, dim);
	print_sum_of_diagonal(arr, dim, dim);
	print_sum_of_lower_tri(arr, dim, dim);

	free(arr);

	return 0;
}

int get_dim() {
	int dim;

	printf("\nEnter the number of rows and columns in the matrix : ");
	scanf("%d", &dim);

	return dim;
}

int* read_arr(int dim) {
	int *arr = (int *) malloc(dim * dim * sizeof(int));

	printf("\nFor each row and column, enter an integer");
	for(int i = 0; i < dim; i++) {
		printf("\nrow %d", i+1);
		for(int j = 0; j < dim; j++) {
			printf("\ncolumn %d : ", j+1);
			scanf("%d", &(arr[(dim * i) + j]));
		}
	}
	return arr;
}

int get_val(int *arr, int cols, int m, int n) {
	return arr[(cols * m) + n];
}

void print_matrix(int *arr, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		printf("\n");
		for(int j = 0; j < cols; j++) {
			printf("\t %d", get_val(arr, cols, i, j));
		}
	}
	printf("\n====================\n");
}

void print_sum_of_upper_tri(int *arr, int rows, int cols) {
	int sum = calc_sum_of_upper_tri(arr, rows, cols);

	printf("Sum of upper triangle of matrix : %d\n", sum);
}

void print_sum_of_diagonal(int *arr, int rows, int cols) {
	int sum = calc_sum_of_diagonal(arr, rows, cols);

	printf("Sum of diagonal of matrix : %d\n", sum);
}

void print_sum_of_lower_tri(int *arr, int rows, int cols) {
	int sum = calc_sum_of_lower_tri(arr, rows, cols);

	printf("Sum of lower triangle of matrix : %d\n", sum);
}

int calc_sum_of_upper_tri(int *arr, int rows, int cols) {
	int sum = 0;

	for(int i = 0; i < rows - 1; i++) {
		int starting_col = i + 1;
		for(int j = starting_col; j < cols; j++) {
			int curr_int = get_val(arr, cols, i, j);
			sum += curr_int;
		}
	}

	return sum;
}

int calc_sum_of_diagonal(int *arr, int rows, int cols) {
	int sum = 0;

	for(int i = 0; i < rows; i++) {
		int curr_int = get_val(arr, cols, i, i);
		sum += curr_int;
	}

	return sum;
}

int calc_sum_of_lower_tri(int *arr, int rows, int cols) {
	int sum = 0;

	for(int i = 1; i < rows; i++) {
		int ending_col = i - 1;
		for(int j = 0; j <= ending_col; j++) {
			int curr_int = get_val(arr, cols, i, j);
			sum += curr_int;
		}
	}

	return sum;
}

