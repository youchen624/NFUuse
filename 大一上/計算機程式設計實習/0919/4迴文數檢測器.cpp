#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0;//AaaA
	while (scanf("%d", &a) != EOF) {
		b = a % 10 * 10;
		b += (a/=10) % 10;
		a /= 10;
		//printf("%d\n%d\n", a, b);
		printf((a == b) ? "是迴文\n" : "不是迴文\n");
	}
	return 0;
}