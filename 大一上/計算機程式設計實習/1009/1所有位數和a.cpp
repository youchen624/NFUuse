#include <stdio.h>
#include <stdlib.h>

int mixNum(int);

int main() {
	int* dataA = NULL; //int* dataA = nullptr;
	int size = 0, intputData = 0;
	printf("請輸入資料...\n");
	while (scanf("%d", &intputData) != EOF) {
		if (intputData <= 0) break;
		int* tempA = (int*)malloc((size + 1) * sizeof(int));//int* tempA = new int[size + 1];
		for (int i = 0; i < size; i++) {
			tempA[i] = dataA[i];
		}
		tempA[size] = intputData;
		free(dataA);//delete[] dataA;
		dataA = tempA;
		size++;
		//scanf("%d", &dataA[]);
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", mixNum(dataA[i]));
	}
	free(dataA);//delete[] dataA;
	system("pause");
	return 0;
}

int mixNum(int x) {
	int y = 0;
	while (x > 0) {
		y += x % 10;
		x /= 10;
	}
	return y;
}