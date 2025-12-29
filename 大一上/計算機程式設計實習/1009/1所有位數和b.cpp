#include <stdio.h>
#include <stdlib.h>

int mixNum(int);

int main() {
	int* dataA = NULL;//int* dataA = nullptr;
	int size = 0, intputData = 0;
	printf("請輸入有幾筆資料...\n");
	while (scanf("%d", &intputData) != EOF) {
		if (intputData <= 0) break;
		if (!size) {
			size = intputData;
			dataA = (int*)malloc(size * sizeof(int));//int* tempA = new int[size + 1];
			for (int i = 0; i < size; i++) {
				printf("請輸入資料...\n");
				if (scanf("%d", &dataA[i]) != 1) while (getchar() != '\n');
			}
		}
		else while (getchar() != '\n');
		printf("資料輸入完成\n");
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", mixNum(dataA[i]));
	}
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