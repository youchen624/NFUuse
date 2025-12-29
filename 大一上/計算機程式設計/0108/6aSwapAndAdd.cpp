#include <stdio.h>

int* SwapAndAdd(int*, int*);

int main() {
	int a = 3, b = 5;
	printf("%d, %d,%d", *SwapAndAdd(&a,&b), a, b);
	return 0;
}

int* SwapAndAdd(int* a, int* b) {
	static int data; data = *a + *b;
	int t = *a;
	*a = *b;
	*b = t;
	return &data;
}