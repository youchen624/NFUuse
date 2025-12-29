#include <stdio.h>
#include <stdlib.h>

int main() {
	float a = -0.2, b = -0.3, c = -0.4;
	printf("%f", (c > ((a>b)?a:b))?c: ((a > b) ? a : b));
	return 0;
}