#include <iostream>

inline bool primeQ(int n) {
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; i++) {
		if (!(n % i)) return false;
	}
	return true;
}
int main() {
	int m, n;
	while (std::cin >> m >> n) {
		int i = 0;
		for (; m <= n; m++) {
			if (primeQ(m)) i++;
		}
		std::cout << i << std::endl;
	}
	system("pause");
	return 0;
}