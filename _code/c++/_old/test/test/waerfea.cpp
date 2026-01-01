#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c = 0, d = 1, time = 0;
	scanf("%d", &time);
	for (int i = 0; i < time; i++) {
		scanf("%d%d", &a, &b);
		if (b > a) {
			int t = b;
			b = a;
			a = t;
		}
		for (int i = b; i <= a; i++) {
			if (i % 2) c += i;
		}
		printf("Case %d: %d\n", d, c);
		d++;
		c = 0;
	}
	return 0;
}