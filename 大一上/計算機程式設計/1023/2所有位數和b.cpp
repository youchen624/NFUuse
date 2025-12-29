#include <stdio.h>
#include <stdlib.h>

int doMix(int);

int main() {
	int t, n;
	scanf("%d", &t);
	int* data = (int*)malloc((t) * sizeof(int));//new
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		data[i] = doMix(n);
	}
	for (int i = 0; i < t; i++) {
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