#include <stdio.h>
int pow(int, int);
int powU(int, int);

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("»¼°j%d^%d=%d, «D»¼°j%d^%d=%d\n", x, y, pow(x, y), x, y, powU(x, y));
	return 0;
}

int pow(int x, int y) {
	return (y > 0) ? x * pow(x, y - 1) : 1;
}
int powU(int x, int y) {
	int t = 1;
	while (y > 0) {
		t *= x;
		y--;
	}
	return t;
}
