#include <stdio.h>
#include <stdlib.h>

int gcdd(int);
void doFind(int*);

int main() {
	int inputData = 0, size = 0;
	int* data = NULL;//int* data = nullptr;
	while (scanf("%d", &inputData) != EOF) {
		if (inputData <= 0) break;
		int* tempA = (int*)malloc((size + 1) * sizeof(int));//int* tempA = new int[size + 1];
		for (int i = 0; i < size; i++) { tempA[i] = data[i]; }
		doFind(&inputData);
		tempA[size] = inputData;
		free(data);//delete[] data;
		data = tempA;
		size++;
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", data[i]);
	}
	free(data);//delete[] data;
	system("pause");
	return 0;
}


int gcdd(int p) {
	for (int i = p -1; i > 0; i--) {
		if (p % i == 0) { return i; }
	}
	return 1;
}
void doFind(int* n) {
	while (gcdd(*n) != 1) (*n)++;
}