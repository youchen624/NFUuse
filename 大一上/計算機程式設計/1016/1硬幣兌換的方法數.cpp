#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	while (scanf("%d", &n) != EOF) {
		int j = 0;
		if (!n) printf("       0 種\n");
		if ((n % 5 > 0) || !n) continue;
		for (int i = n / 10; i >= 0; i--, j++) { j += (n - i * 10) / 5; }
		printf("%8d 種\n", j);
	}
	system("pause");
	return 0;
}