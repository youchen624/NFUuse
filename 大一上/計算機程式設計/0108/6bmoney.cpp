#include <stdio.h>
#define a1 1
#define a2 5
#define ak 100
int money(int n) {
	if (n >= ak) return (n / ak) + money(n % ak);
	if (n >= a2) return (n / a2) + money(n % a2);
	if (n >= a1) return (n / a1) + money(n % a1);
	return n;
}

int main() {
	int a = 0;
	while (scanf("%d", &a) != EOF) {
		printf("%d\n", money(a));
	}
	return 0;
}