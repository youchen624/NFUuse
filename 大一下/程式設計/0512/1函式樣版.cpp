#include <iostream>
using namespace std;

template <typename T>
void exchange(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
};

int main() {
	int a = 2, b = 3;
	exchange(a, b);
	cout << "after exchange: a=" << a << ",b=" << b << endl;
	double c = 3.5, d = 6.34;
	exchange(c, d);
	cout << "after exchange: c=" << c << ",d=" << d << endl;
	return 0;
};