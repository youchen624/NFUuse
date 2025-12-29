#include <stdio.h>
#include <stdlib.h>

int main() {
	int m = 0, n = 0, a = 0, b = 0; //a2 b4
	printf("");
	while (scanf("%d%d", &m, &n) != EOF) {
		a = (4 * m - n) / 2;
		b = m - a;
		printf("雞:%d\n兔:%d\n", a, b);
		m = 0, n = 0, a = 0, b = 0;
	}
	return 0;
}