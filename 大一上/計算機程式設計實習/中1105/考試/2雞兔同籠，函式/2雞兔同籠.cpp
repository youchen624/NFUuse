#include <stdio.h>

void ¨ç¦¡(int, int);

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	¨ç¦¡(m, n);
	return 0;
}

void ¨ç¦¡(int m, int n) {
	int a = (4 * m - n) / 2;
	printf("Âû: %d ¨ß: %d", a, m - a);
}