#include <iostream>
#include <iomanip>
#define PI 3.14
using namespace std;

class Ball {
private:
	double r;
public:
	Ball(double r_ = 1) {
		r = r_;
	}
	double area() {
		return (double)4 * PI * r * r;
	}
	double volume() {
		return (double)4 * PI * r * r * r / 3;
	}
	void set(double k) {
		r = k;
	}
	void print() {
		cout << "半徑:" << r << endl;
	}
};
int main()
{
	double radius;
	cout << "請輸入球半徑: ";
	cin >> radius;
	Ball ball_1(radius), ball_2; //建立兩球類別物件 ball_1 及 ball_2, ball_1 的半徑為 radius
	cout << "ball_1 之面積為: " << ball_1.area() << endl;
	cout << "ball_1 之體積為: " << setprecision(1) << fixed << ball_1.volume() << endl;
	ball_2.set(100);
	ball_2.print();
	return 0;
}