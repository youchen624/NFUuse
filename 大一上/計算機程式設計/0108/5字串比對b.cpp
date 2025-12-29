#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char[][31], int);

int main() {
	char a[100][31], b[100][31];
	int as = 0, bs = 0;
	for (int i = 0; i < 100; i++) {
		for (int ii = 0; ii < 30; ii++) {
			a[i][ii] = getchar();
			if (a[i][ii] == '\n') {
				a[i][ii] = '\0';
				if (ii == 0) i = 100;
				break;
			}
		}
	}
	for (int i = 0; i < 100; i++, bs++) {
		for (int ii = 0; ii < 30; ii++) {
			b[i][ii] = getchar();
			if (b[i][ii] == '\n') {
				b[i][ii] = '\0';
				if (ii == 0) i = 100;
				break;
			}
		}
	}
	// ^ 讀取輸入 <<<<<<<<<<<<<<
	for (int i = 0; i < 5; i++) {
		printf("%s, %s\n", a[i], b[i]);
	}
	printf("as:%d, bs:%d\n", as, bs);
	/*
	*/
	//^<<<<<<<<<<< X

	// ^ #TODO排序

	// ^ #TODO判斷相似度
	return 0;
}

void sort(char ch[][31], int n) {
	;
}