#include <stdio.h>
#include <stdlib.h>

void cfunc(int[], int);

int main() {
	int* data = NULL;
	int size = 0, num;
	while (scanf("%d", &num) != EOF) {
		int* dataT = (int*)malloc((size + 1) * sizeof(int));
		for (int i = 0; i < size; i++) dataT[i] = data[i];
		dataT[size] = num;
		free(data);
		data = dataT;
		size++;
	}
	//for (int i = 0; i < size; i++) printf("%d\n", data[i]);
	cfunc(data, size);
	return 0;
}

void cfunc(int array[], int n) {
	int v = 0, w = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2) v++;
		else w++;
	}
	printf("%d個奇數，%d個偶數", v, w);
}