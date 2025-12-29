#include <stdio.h>
#include <stdlib.h>

int a(int);
int b(int, int);
int main() {
	int i, j;
	while (scanf("%d%d", &i, &j) != EOF) {

		printf("%d %d %d\n", i, j, b(i, j));
	}
	return 0;
}

int a(int n) {
	int t = 0;
	do {
		//printf("%d", n);
		t++;
		if (n == 1) break;
		if (n % 2) n = 3 * n + 1;
		else n /= 2;
	} while (1);
	return t;
}

int b(int min, int max) {
	int temp = 0;
	for (int i = min; i <= max; i++) {
		int t = a(i);
		if (temp < t) temp = t;
	}
	return temp;
}