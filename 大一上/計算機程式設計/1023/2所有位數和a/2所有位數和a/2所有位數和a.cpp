#include <stdio.h>
#include <stdlib.h>

int doMix(int);

int main() {
	int a, size = 0;
	int* data = NULL;
	while (scanf("%d", &a) != EOF) {
		int* temp = (int*)malloc((size + 1) * sizeof(int));//new
		for (int i = 0; i < size; i++) {
			temp[i] = data[i];
		}
		temp[size] = doMix(a);
		free(data);
		data = temp;
		size++;
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", data[i]);
	}
	system("pause");
	return 0;
}

int doMix(int x) {
	int t = 0;
	while (x > 0) {
		t += x % 10;
		x /= 10;
	}
	return t;
}