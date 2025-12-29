#include <stdio.h>
#include <stdlib.h>

int total(int[], int, int);
int max(int, int);
int f(int[], int, int);
int ff(int[], int, int);

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int nn = 0; scanf("%d", &nn);
		int* nums = (int*)malloc(sizeof(int) * nn);
		//printf("enter...\n");
		for (int ii = 0; ii < nn; ii++) scanf("%d", &nums[ii]);
		// ==== <> ==== ;
		printf("%d\n", ff(nums, 0, nn));
	}
	return 0;
}

int total(int n[], int a, int b) {
	int t = 0;
	for (int i = a; i <= b; i++) t += n[i];
	return t;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}

int f(int ar[], int a, int b) {
	if (a >= b) return ar[a];
	return max(total(ar, a, b), f(ar, a + 1, b));
}
int ff(int ar[], int a, int b) {
	//printf("ff%d,%d.\n", a, b);
	if (a >= b) return f(ar, a, b);
	return max(f(ar, a, b), ff(ar, a, b -1));
}