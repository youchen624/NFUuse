#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);//void swap(int&, int&);

int main() {
	int t = 0, lt = 0, c = 0;
	int p[2] = { 0, 0 }, a[2] = { 0, 10 };
	while (c != 3) {
		//printf("請輸入時間\n");
		scanf("%d", &t);
		p[0] += a[0] * (t - lt);
		p[1] += a[1] * (t - lt);
		lt = t;
		//printf("請輸入命令\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
		case 2:
			swap(&a[0], &a[1]);
			a[c - 1] *= -1;
			break;
		case 3:
			printf("%d\n%d\n", p[0], p[1]);
			break;
		}
	}
	system("pause");
	return 0;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
/*void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}*/