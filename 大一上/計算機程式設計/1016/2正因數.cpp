#include <stdio.h>
#include <stdlib.h>

void factor(int);

int main() {
	int x;
	while (scanf("%d", &x) != EOF) factor(x);
	system("pause");
	return 0;
}

void factor(int n) {
	if (n <= 0) return;
	printf("1");
	for (int i = 2; i <= n; i++) if (n % i == 0) printf(", %d", i);
	printf("\n");
}