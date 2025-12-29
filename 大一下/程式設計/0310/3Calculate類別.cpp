#include <iostream>
#include <iomanip>
using namespace std;
/*
template <typename T>
void swap(T &a, T &b) {
	T t = a;
	b = a;
	a = t;
}
*/

class Calculate {
public:
	Calculate(int size_) : n(size_) {
		ptr = new double[n];
	};
	void get_data(int i, double value) {
		ptr[i] = value;
	};
	double total();
	double average() {
		return total() / n;
	};
	double median();
	double sd();
private:
	double* ptr;
	int n;
};
double Calculate::total() {
	double t = 0;
	for (int i = 0; i < n; i++) {
		t += ptr[i];
	}
	return t;
};
double Calculate::median() {
	double *t = new double[n];
	memcpy(t, ptr, n*sizeof(double));
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (t[i] > t[j])
				swap(t[i], t[j]);
		}
	}
	if (n % 2)
		return t[n / 2];
	else
		return (double)(t[n / 2] + t[n / 2 - 1]) / 2;
};
double Calculate::sd() {
	double t = 0;
	for (int i = 0; i < n; i++) {
		t += (ptr[i] - average()) * (ptr[i] - average());
	}
	return sqrt(t / n);
};

int main() {
	int size, i, value;
	cout << "Input size of the array:" << endl;
	cin >> size;
	Calculate cal(size);
	// 11 1 5 2 8 7 12 4 -6 -10 1 5
	cout << "Input values of the array:" << endl;
	for (i = 0; i < size; i++) {
		cin >> value;
		cal.get_data(i, value);
	}
	cout << "總  和（sum）       =" << setprecision(2) << fixed << cal.total() << endl;
	cout << "平均值（mean）      =" << setprecision(2) << fixed << cal.average() << endl;
	cout << "中位數（median）    =" << setprecision(2) << fixed << cal.median() << endl;
	cout << "標準差（standard deviation） =" << cal.sd() << endl;
	return 0;
}