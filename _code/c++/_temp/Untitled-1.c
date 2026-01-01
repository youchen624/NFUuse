#include <stdio.h>
#include <stdlib.h>

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
#define lcm(p, q) (p * q / gcd(p, q))

int main() {
	int p, q;
	while (scanf("%d%d", &p, &q) != EOF) {
		printf("%d ㎝%d 程そ计: %d, 程そ计: %d \n", p, q, gcd(p, q), lcm(p, q));
	}
}


