#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main() {
	double a = 0 ,b = 0;
	printf("請輸入球體半徑...\n");
	scanf("%lf", &b);
	a = PI * 4 * b * b;
	b = a * b / 3;
	printf("球的表面積= %.2lf\n", a);
	printf("球的體積  = %.2lf\n", b);
	system("pause");
	return 0;
}