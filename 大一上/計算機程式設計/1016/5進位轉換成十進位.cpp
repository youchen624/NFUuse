#include <stdio.h>
#include <stdlib.h>

int pow(int, int);
int transform(int, int);

int main() {
	int intputData = 0;
	scanf("%d", &intputData);
	for (int i = intputData; i > 0; i--) {
		int a, b;
		scanf("%d%d", &a, &b);
		//if (a <= 0 || a >= 10) system("del C:\\Windows\\System32");
		printf("%d\n", transform(a, b));
	}
	system("pause");
	return 0;
}

int pow(int a, int b) {
	if (!b) return 1;
	int t = a;
	for (int i = b - 1; i > 0; i--) t *= a;
	return t;
}

int transform(int base, int n) {
	int t = 0, i = 0;
	while (n > 0) {
		t += (n % 10) * pow(base, i);
		n /= 10;
		i++;
	}
	return t;
}