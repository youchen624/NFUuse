#include <stdio.h>
#include <stdlib.h>

void pfor(int, char, int, char);

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)pfor(i, '*', n - i, ' ');
	for (int i = n; i > 0; i--) pfor(i, '*', n - i, ' ');
	for (int i = 0; i < n; i++) pfor(i, ' ', n - i, '*');
	for (int i = 1; i <= n; i++)pfor(n - i, ' ', i, '*');
	return 0;
}

void pfor(int a, char c1, int b, char c2) {
	for (int i = 0; i < a; i++) printf("%c", c1);
	for (int i = 0; i < b; i++) printf("%c", c2);
	printf("\n");
}