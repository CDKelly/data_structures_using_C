// exercise 2, pg. 40

// Print the count and sum of even nums between two given nums (inclusive)
// where the first given num < second given num

#include <stdio.h>
#include <stdlib.h>
int is_even(int num) {
	return num % 2 == 0;
}

int count_even_nums(int a, int b) {
	int diff = abs(a - b);
	if (is_even(a) || is_even(b)) {
		return diff / 2 + 1;
	} else {
		return diff / 2;
	}
}

int main() {
	int l_num, g_num, i, sum = 0;

	printf("\nEnter the lesser number l_num : \t");
	scanf("%d", &l_num);
	printf("\nEnter the greater number g_num : \t");
	scanf("%d", &g_num);

	for(i=l_num; i <= g_num; i++) {
		if (i % 2 == 0) {
			sum += i;
		}
	}

	int count = count_even_nums(g_num, l_num);

	printf("\nThe are %d even numbers between %d and %d (inclusive)", count, l_num, g_num);
	printf("\nThe sum of even numbers between %d and %d = %d", l_num, g_num, sum);
}
