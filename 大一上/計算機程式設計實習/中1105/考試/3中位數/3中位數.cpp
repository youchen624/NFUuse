#include <stdio.h>
#include <stdlib.h>

void sort(int*, int);
void swap(int*, int*);

int main() {
	int n, x;
	int* data = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		data = (int*)malloc(x * sizeof(int));
		for (int j = 0; j < x; j++) scanf("%d", &data[j]);
		sort(data, x);
		//printf("%d", x);
		if (x % 2) {
			printf("%d", data[x / 2]);
		}
		else {
			printf("%.1lf", (data[x / 2] + data[x / 2 - 1]) / (double)2);
		}
		printf("\n");
		//for (int j = 0; j < x; j++) printf("%d ", data[j]);
		free(data);
	}
	return 0;
}

void sort(int* d, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (d[i] > d[j]) swap(&d[i], &d[j]); //printf("!!!");
		}
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}