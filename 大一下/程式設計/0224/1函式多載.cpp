#include <iostream>
#include <span>

double getmin(double a, double b) {
	return a > b ? b : a;
}

template <size_t n>
double getmin(double (&a)[n]) {
	double t = a[0];
	for (double b : a)
		if (t > b) t = b;
	return t;
}

int main() {
	double ar[] = {0.1, 0.2, 0.3, 0.2, 0.01};
	std::cout << getmin(ar) << std::endl;
	std::cout << getmin(ar[1],ar[2]) << std::endl;
	return 0;
}