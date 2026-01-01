#include <iostream>
using namespace std;

/*
template <typename T>
void swap(T& a, T& b) {
	T t = a;
	a = b;
	b = a;
};
*/

template <typename T, size_t n>
void sort(T (&array)[n]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] > array[j]) swap(array[i], array[j]);
		}
	}
};

template <typename T>
class sample {
private:
	T x[5], y[5], z[10];
public:
	sample() {
		for (int i = 0; i < 5; i++) { cin >> x[i]; }
		for (int i = 0; i < 5; i++) { cin >> y[i]; }
	};
	void sort() {
		::sort(x);
		::sort(y);
	};
	void merger() {
		copy(x, x+5, z);
		copy(y, y+5, z+5);
		::sort(z);
	};
	void display() {
		for (T t : z) {
			cout << t << " ";
		}
		cout << endl;
	};
};

int main() {
	// 4 8 1 12 5
	// 9 3 2 10 6
	sample<int> A;
	A.sort();
	A.merger();
	A.display();
	// 4.1 8.1 1.1 12.1 5.1
	// 9.1 3.1 2.1 10.1 6.1
	sample<double> B;
	B.sort();
	B.merger();
	B.display();
	return 0;
};