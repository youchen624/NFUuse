#include <stdio.h>

int isP(int);

int main() {
	int p, q, t = 0;
	while (scanf("%d%d", &p, &q) != EOF) {
		for (int i = p; i <= q; i++) t += isP(i);
		printf("%d\n", t);
		t = 0;
	}
	return 0;
}

int isP(int x) {
	if (x <= 2) return 0;
	for (int i = 3; i < x;i++) if (!(x % i)) return 0;
	return 1;
}