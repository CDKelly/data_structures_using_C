// exercise 2, pg. 40

// Print the count and sum of even nums between two given nums (inclusive)

#include <stdio.h>
int is_even(int num) {
	return num % 2 == 0;
}

int sum_two_nums(int a, int b) {
	return a + b;
}

int count_even_nums(int greater_num, int lesser_num) {
	int diff = greater_num - lesser_num;
	if (is_even(greater_num) || is_even(lesser_num)) {
		return = diff / 2 + 1;
	} else {
		return = diff / 2;
	}
}

int main() {

}
