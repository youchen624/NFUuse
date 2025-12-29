#include <stdio.h>
#include <stdlib.h>

double cell(int);
double testFor(int);
double testWhile(int);
double testDoWhile(int);

int main() {
	int n = 0;
	printf("請輸入n..\n");
	scanf("%d", &n);
	printf("for迴圈       S=%.3lf\n", testFor(n));
	printf("while迴圈     S=%.3lf\n", testWhile(n));
	printf("do..while迴圈 S=%.3lf\n", testDoWhile(n));
	system("pause");
	return 0;
}

double cell(int n) { return n ? (double)(n * n - 1) / (n * n) : 0; }

double testFor(int n) {
	int u = 1;
	double s = 1;
	for (int i = 2; i <= n; i++) {
		s += cell(i) * u;
		u *= -1;
	}
	return s;
}

double testWhile(int n) {
	int u = 1, i = 2;
	double s = 1;
	while (i <= n) {
		s += cell(i) * u;
		u *= -1;
		i++;
	}
	return s;
}

double testDoWhile(int n) {
	int u = -1, i = 1;
	double s = 1;
	do
	{
		s += cell(i) * u;
		u *= -1;
		i++;
	} while (i <= n);
	return s;
}