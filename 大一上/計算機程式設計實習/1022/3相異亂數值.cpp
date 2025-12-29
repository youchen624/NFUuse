#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*, int*);//void swap(int&, int&);
int randomPro(int, int);

int main() {
	srand(time(0));
	int data[5] = { 0 };
	for (int i = 0, j = 0; i < 5; i++) {
		do {
			data[i] = randomPro(1, 10);
			for (j = 0; j < i; j++) j += (data[j] == data[i]);
		} while (j!=i);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	system("pause");
	return 0;
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int randomPro(int min, int max) {
	if (min > max) swap(&min, &max);
	return rand() % (max - min + 1) + min;
}