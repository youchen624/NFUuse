#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A(int x, int v = 1) { x = x; y = v; }
	void f1(int a, int b) { x = x - a; y = y - b; }
	void f2() { x = a - 2; }
private:
	int x, y;
};
int main() {
	A a(1);
	a.f2();
	return 0;
}
/*
class a {
public:
	void pop(int n) { cout << n; }
};
class b : public a {
public:
	void pop(int n) { cout << n-1; }
	void t(int n) { super pop(n); }
};
int main() {
	a aa;
	b bb;
	return 0;
}
*/
/*
int main() {
	string s;
	int n;
	cout << "輸入數量";
	cin >> n;
	cin.ignore(); //<<<
	cout << "輸入文字";//<< endl;
	getline(cin, s);
	for(int i = 0; i < n; i++)
		cout << s << endl;
	return 0;
}
*/