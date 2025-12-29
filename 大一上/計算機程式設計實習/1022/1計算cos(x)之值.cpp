#include <stdio.h>
#include <stdlib.h>

#define X 3.14
//double x 3.14

int n;
int fac(int);
double pow(double, int);
double cos(double);//int n; essential

int main() {
	while (scanf("%d", &n) != EOF) {
		//printf("%.3lf\n", cos(*(&::x)));
		printf("%.3lf\n", cos(X));
	}
	system("pause");
	return 0;
}

int fac(int a) { return (a < 2) ? 1 : a * fac(a - 1); }

double cos(double x) {
	double t = 1;
	int u = -1;
	for (int i = 2; i < n; i += 2) {
		t += (double) pow(x, i) / fac(i) * u;
		u *= -1;
	}
	return t;
}

double pow(double a, int b) {
	double t = a;
	for (int i = b - 1; i > 0; i--) t *= a;
	return b ? t : 1;
}