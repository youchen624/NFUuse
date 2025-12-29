#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*, int*);
void sort(int[], int);
int randomP(int, int);

int main() {
	srand(time(NULL));
	int pool[9], num[6], gus[5];
	int t = 0, s = 0;
	for (int i = 0; i < 9; i++) pool[i] = i + 1;
	for (int i = 0; i < 5; i++) scanf("%d", &gus[i]);
	for (int i = 0; i < 9; i++) swap(&pool[randomP(0, 8)], &pool[randomP(0, 8)]);
	sort(gus, 5);
	sort(pool, 5);
	for (int i = 0; i < 5; i++) {
		if (gus[i] == pool[i]) t++;
		if (gus[i] == pool[5]) s = 1;
	}
	// ######## ######## ######## ########
	for (int i = 0; i < 9; i++) printf("%d ", pool[i]); printf("\n");
	for (int i = 0; i < 5; i++) printf("%d ", gus[i]); printf("\n");
	// ######## ######## ######## ########
	switch (t) {
	case 5:
		printf("頭獎\n"); break;
	case 3:
		printf("四獎\n"); break;
	case 4:
		if (s) printf("二獎\n");
		else printf("三獎\n");
		break;
	default:
		printf("未中獎\n"); break;
	}
	return 0;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void sort(int a[], int s) {
	for (int i = 0; i < s - 1; i++)
		for (int j = i + 1; j < s; j++)
			if (a[i] > a[j]) swap(&a[i], &a[j]);
}

int randomP(int min, int max) {
	if (min > max) swap(&min, &max);
	return rand() % (max - min + 1) + min;
}