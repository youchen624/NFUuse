#include <stdio.h>
#include <stdlib.h>

#define lcm(p, q) (p * q / gcd(p, q))//int lcm(int, int);
int gcd(int, int);

int main() {
	int p, q, n = 0;
	while (scanf("%d", &n) != EOF) {
		for (n; n > 0; n--) {
			scanf("%d%d", &p, &q);
			printf("%d 和%d 的最大公因數為: %d, 最小公倍數為: %d \n", p, q, gcd(p, q), lcm(p, q));
		}
	}
	system("pause");
	return 0;
}

int gcd(int p, int q) {
	for (int i = (p > q ? p : q); i > 0; i--) {
		if ((p % i == 0) && (q % i == 0)) { return i; }
	}
	return 1;
}
/*int lcm(int p, int q) {
	for (int i = 1; i > 0; i++) {
		if ((i % p == 0) && (i % q == 0)) {
			return i;
		}
	}
}*/

