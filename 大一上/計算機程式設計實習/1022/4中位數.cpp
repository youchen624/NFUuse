#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* p;
	int v;
} pv;

void swap(int*, int*);//void swap(int&, int&);
void sort(int*, int);
void pvSet(pv*, int*);
int* findMin(int*, int);

int main() {
	int times = 0, n = 0;
	scanf("%d", &times);
	for (int i = 0; i < times; i++) {
		scanf("%d", &n);
		int* data = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) scanf("%d", &data[i]);// 1 2 3 4  |  0 1 2 3
		sort(data, n);
		//for (int i = 0; i < n; i++) printf("%d ", data[i]); printf("\n\n");
		if (n % 2)	printf("中位數= %d\n", data[n / 2]);
		else printf("中位數= %.1lf\n", (data[n / 2] + data[n / 2 - 1]) / (double)2);
		free(data);
	}
	return 0;
}

void swap(int* a, int* b) {
	if (*a == *b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void sort(int* ptrAr, int size) {// ptrAr[size]
	for (int i = 0; i < size; i++) swap(&ptrAr[i], findMin(&ptrAr[i], size - i));
}

void pvSet(pv* ap, int* p) {
	ap->p = p;
	ap->v = *p;
}

int* findMin(int* s, int n) {
	pv min = { s, *s };
	for (int i = 1; i < n; i++) if (s[i] < min.v) pvSet(&min, &s[i]);
	return min.p;
}