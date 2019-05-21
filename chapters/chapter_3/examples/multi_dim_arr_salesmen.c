// example 18, pgs. 97-98

/* Write a program that takes in a number of salesmen and products to sell.
   The program should print out the total sales by each salesman and the
   total sales by each product.
*/

#include <stdio.h>
#include <stdlib.h>

int get_num_of_salesmen();
int get_num_of_prods();
int* read_arr(int s, int p);
/* void print_arr(int *arr, int s, int p); */
void print_total_by_salesmen(int *arr, int s, int p);
void print_total_by_products(int *arr, int s, int p);

int main() {

	int num_of_salesmen = get_num_of_salesmen();
	int num_of_prods = get_num_of_prods();

	int *arr = read_arr(num_of_salesmen, num_of_prods);

	print_arr(arr, num_of_salesmen, num_of_prods);
	print_total_by_salesmen(arr, num_of_salesmen, num_of_prods);
	print_total_by_products(arr, num_of_salesmen, num_of_prods);

	free(arr);
	return 0;
}

int get_num_of_salesmen() {
	int num_of_salesmen;

	printf("\nEnter the number of salesmen in your company : ");
	scanf("%d", &num_of_salesmen);

	return num_of_salesmen;
}

int get_num_of_prods() {
	int num_of_prods;

	printf("\nEnter the number of products each salesman must sell : ");
	scanf("%d", &num_of_prods);

	return num_of_prods;
}

int* read_arr(int num_of_salesmen, int num_of_prods) {
	int *arr = (int *) malloc(num_of_salesmen * num_of_prods * sizeof(int));

	for(int i = 0; i < num_of_salesmen; i++) {
		printf("\nFor each product, enter the number of products sold by salesmen %d", i+1);
		for(int j = 0; j < num_of_prods; j++) {
			printf("\nproduct %d : ", j+1);
			scanf("%d", &(arr[(num_of_prods * i) + j]));
		}
	}
	return arr;
}

/* void print_arr(int *arr, int num_of_salesmen, int num_of_prods) { */
/* 	for(int i = 0; i < num_of_salesmen; i++) { */
/* 		for(int j = 0; j < num_of_prods; j++) { */
/* 			printf("\narr[%d][%d] = %d", i, j, arr[(num_of_prods * i) + j]); */
/* 		} */
/* 	} */
/* } */

void print_total_by_salesmen(int *arr, int num_of_salesmen, int num_of_prods) {
	int total;

	for(int i = 0; i < num_of_salesmen; i++) {
		total = 0;
		for(int j = 0; j < num_of_prods; j++) {
			total += arr[(num_of_prods * i) + j];
			printf("\nCURR TOTAL = %d", total);
		}
		printf("\nTotal sales by salesman %d = %d", i+1, total);
	}
}

void print_total_by_products(int *arr, int num_of_salesmen, int num_of_prods) {
	int total;

	for(int j = 0; j < num_of_prods; j++) {
		total = 0;
		for(int i = 0; j < num_of_salesmen; i++) {
			total += arr[(num_of_prods * i) + j];
		}
		printf("\nTotal sales for product %d = %d", j+1, total);
	}
}
