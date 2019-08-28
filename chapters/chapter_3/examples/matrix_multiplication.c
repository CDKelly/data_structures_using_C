// example 23, pgs. 102-103

// Multiply two m x n matrices

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_dimension(bool is_row_dim, bool is_multiplicand);
bool can_mult_arrs(int col1, int row2);
int* read_arr(int rows, int cols, bool is_multiplicand);
int* multiply_arrs(int row1, int col1, int row2, int col2, int *arr1, int *arr2);
int get_val(int *arr, int cols, int m, int n);
void set_val(int *arr, int cols, int m, int n, int val_to_set);
void print_matrix(int *result, int rows, int cols);

int main() {

	int row1 = get_dimension(true, true);
	int col1 = get_dimension(false, true);

	int row2 = get_dimension(true, false);
	int col2 = get_dimension(false, false);

	if (!can_mult_arrs(col1, row2)) {
		printf("\nCannot multiply matrices");
		printf("\nThe number of columns in the first matrix does not equal the number of rows in the second matrix");
		return 0;
	}

	int *arr1 = read_arr(row1, col1, true);
	print_matrix(arr1, row1, col1);
	int *arr2 = read_arr(row2, col2, false);
	print_matrix(arr2, row2, col2);
	int *result = multiply_arrs(row1, col1, row2, col2, arr1, arr2);

	print_matrix(result, row1, col2);

	free(arr1);
	free(arr2);
	free(result);

	return 0;
}

int get_dimension(bool is_row_dim, bool is_multiplicand) {
	int dim_int;

	char *dim_str = is_row_dim ? "rows" : "columns";
	char *which_factor = is_multiplicand ? "first" : "second";

	printf("\nEnter the number of %s in the %s matrix : ", dim_str, which_factor);
	scanf("%d", &dim_int);

	return dim_int;
}

bool can_mult_arrs(int col1, int row2) {
	return col1 == row2;
}

int* read_arr(int rows, int cols, bool is_multiplicand) {
	int *arr = (int *) malloc(rows * cols * sizeof(int));

	char *which_factor = is_multiplicand ? "first" : "second";
	printf("\nEnter the elements of the %s matrix : ", which_factor);

	for(int i = 0; i < rows; i++) {
		printf("\nrow %d", i+1);
		for(int j = 0; j < cols; j++) {
			printf("\ncol %d : ", j+1);
			scanf("%d", &(arr[(cols * i) + j]));
		}
	}
	return arr;
}

int* multiply_arrs(int row1, int col1, int row2, int col2, int *arr1, int *arr2) {
	int *result = (int *) malloc(row1 * col2 * sizeof(int));

	for(int i = 0; i < row1; i++) {
		for(int j = 0; j < col2; j++) {
			set_val(result, col2, i, j, 0);
			for(int k = 0; k < row2; k++) {
				int arr1_val = get_val(arr1, col1, i, k);
				int arr2_val = get_val(arr2, col2, k, j);
				int curr_res_val = get_val(result, col2, i, j);
				int new_res_val = curr_res_val + (arr1_val * arr2_val);

				set_val(result, col2, i, j, new_res_val);
			}
		}
	}
	return result;
}

// get int val from a 2d array that is stored in row major order
int get_val(int *arr, int cols, int m, int n) {
	return arr[(cols * m) + n];
}

void set_val(int *arr, int cols, int m, int n, int val_to_set) {
	arr[(cols * m) + n] = val_to_set;
}

void print_matrix(int *result, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		printf("\n");
		for(int j = 0; j < cols; j++) {
			printf("\t %d", get_val(result, cols, i, j));
		}
	}
	printf("\n====================\n");
}
