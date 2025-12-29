#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int x = i; x > 0; x--) printf(" ");
		for (int xx = n - i; xx > 0; xx--) printf("*");
		printf("\n");
	}
	return 0;
}