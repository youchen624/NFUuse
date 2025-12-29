#include <stdio.h>
#include <stdlib.h>

#define C(x) ((x)*(x))
#define D() (C(a) + C(b))

int main() {
	int m = 0, a = 0, b = 0;
	while (scanf("%d%d%d", &m, &a, &b) != EOF) {
		int x = m;
		if (m < a) {
			m = a;
			a = x;
		}
		x = m;
		if (m < b) {
			m = b;
			b = x;
		}
		if (m >= a + b) {
			printf("非三角形\n");
			continue;
		}
		if (C(m) < D())
			printf("銳角三角形\n");
		if (C(m) == D())
			printf("直角三角形\n");
		if (C(m) > D())
			printf("鈍角三角形\n");
	}
	return 0;
}
