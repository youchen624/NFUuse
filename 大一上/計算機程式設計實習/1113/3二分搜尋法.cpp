#include <stdio.h>
#include <stdlib.h>

void sort(int[], int);
int binSearchSSS(int ar[], int from, int to, int key, int* isThere);//return times----- [ from, mid, to ] -----

int main() {
	int data[15];
	int target, t = 0;
	for (int i = 0; i < 15; i++)
		scanf("%d", &data[i]);
	scanf("%d", &target);
	sort(data, 15);
	for (int i = 0; i < 15; i++) printf("%d ", data[i]);
	printf("\n%d\n", binSearchSSS(data, 0, 14, target, &t));
	if (t) printf("%d\n", target);
	else printf("查無此數字");
	return 0;
}

void sort(int ar[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int ii = i + 1; ii < size; ii++) {
			if (ar[i] > ar[ii]) {
				int t = ar[i];
				ar[i] = ar[ii];
				ar[ii] = t;
			}
		}
	}
}

int binSearchSSS(int ar[], int from, int to, int key, int* isThere) {
	int mid = (from + to) / 2;
	/*
	for (int i = from; i <= to; i++) printf("%d ", ar[i]);
	printf("\nfr: %d, to: %d, mid:%d\n", from, to, mid);
	printf("fr: %d, to: %d, mid:%d\n\n", ar[from], ar[to], ar[mid]);
	*/
	if (ar[mid] == key) {
		*isThere = 1;
		return 1;
	}
	if (from == to) {
		*isThere = 0;
		return 1;
	}
	if (ar[mid] > key) return 1 + binSearchSSS(ar, from, mid - 1, key, isThere);
	else if (ar[mid] < key) return 1 + binSearchSSS(ar, mid + 1, to, key, isThere);
	return 0;
}