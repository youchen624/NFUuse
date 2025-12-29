#include <iostream>
#define PI 3.14
using namespace std;
class Circle {
public:
	Circle(double r) : r(r) {};
	double area() {
		return PI * r * r;
	}
	double get_R() {
		return r;
	};
protected:
	double r;
};
class inheritance_cylinder : public Circle {
private:
	double h;
public:
	inheritance_cylinder(double r, double h_) : Circle(r) { h = h_; }
	double area() { return 2 * Circle::area() + (2 * PI * r * h); }
	double vol() { return Circle::area() * h; }
};
class composition_cylinder {
private:
	Circle c;
	double h;
public:
	composition_cylinder(double r, double h_) : c(r) { h = h_; }
	double area() { return 2 * c.area() + (2 * PI * c.get_R() * h); }
	double vol() { return c.area() * h; }
};

int main()
{
	double r, h;
	printf("請輸入圓柱體之半徑與高: ");
	cin >> r >> h; // 設輸入 10 5
	cout << "以繼承方式建立圓柱體物件: \n ";
	inheritance_cylinder a(r, h); // 建立圓柱體物件 a，半徑與高分別為 r 及 h
	cout << "圓柱體物件面積為: ";
	cout << a.area() << endl; // 輸出 942
	cout << "以組合方式建立圓柱體物件: \n ";
	composition_cylinder b(r, h); // 建立圓柱體物件 b，半徑與高分別為 r 及 h
	cout << "圓柱體物件面積為: ";
	cout << b.area() << endl; // 輸出 942
	return 0;
}