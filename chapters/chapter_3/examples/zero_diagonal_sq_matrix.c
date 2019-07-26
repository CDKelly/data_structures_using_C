// example 24, pgs. 104-105

/* Write a program to fill a square matrix with 0s on the diagonal,
   1s on the upper left corner, and -1s in the lower left corner
*/

#include <stdio.h>
#include <stdlib.h>

int get_dimension();
int* diagonalize_matrix(int dim);
void set_val(int *arr, int cols, int m, int n, int val_to_set);
int get_val(int *arr, int cols, int m, int n);
void print_matrix(int *result, int rows, int cols);

int main() {

	int dim = get_dimension();

	int *sq_matrix = diagonalize_matrix(dim);
	print_matrix(sq_matrix, dim, dim);

	free(sq_matrix);

	return 0;
}

int get_dimension() {
	int dim;

	printf("\nEnter the number of rows and columns in the square matrix : ");
	scanf("%d", &dim);

	return dim;
}

int* diagonalize_matrix(int dim) {
	int *arr = (int *) malloc(dim * dim * sizeof(int));

	for(int i = 0; i < dim; i++) {
		for(int j = 0; j < dim; j++) {
			if (i == j) {
				set_val(arr, dim, i, j, 0);
			} else if (i < j) {
				set_val(arr, dim, i, j, 1);
			} else {
				set_val(arr, dim, i, j, -1);
			}
		}
	}

	return arr;
}

// set int val for a 2d array that is stored in row major order
void set_val(int *arr, int cols, int m, int n, int val_to_set) {
	arr[(cols * m) + n] = val_to_set;
}

// get int val from a 2d array that is stored in row major order
int get_val(int *arr, int cols, int m, int n) {
	return arr[(cols * m) + n];
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
