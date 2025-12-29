#include <iostream>
#include <string>
using namespace std;

class motor {
public:
	motor(string b, double f, double s) : brand(b), fuel(f), speed(s) {
		num++;
		calKM();
	};
	motor(motor& m) : motor(m.brand, m.fuel, m.speed) {};
	~motor() { num--; };
	void calKM() {
		km = fuel * 15;
	};
	void show() {
		cout
			<< "機車品牌：" << brand
			<< " 油量：" << fuel
			<< " 速度：" << speed
			<< " 可行駛公里：" << km
		<< endl;
	};
	static int num;
protected:
	string brand;
	double fuel, speed, km;
};
class electricMotor : public motor {
public:
	electricMotor(string b, double f, double sp, int se) : motor(b, f, sp), seat(se) {
		calKM();
	};
	void calKM() {
		km = fuel * 20;
	};
	void show() {
		cout
			<< "電動車品牌：" << brand
			<< " 油量：" << fuel
			<< " 速度：" << speed
			<< " 座位數：" << seat
			<< " 可行駛公里：" << km
		<< endl;
	};
private:
	int seat;
};

int motor::num = 0;
int main()
{
	motor A("三陽", 10, 50); // 建立 A 機車物件
	motor B(A); //建立 B 機車物件, 內容與 A 機車物件相同
	electricMotor C("Gogoro", 10, 25, 2);// 建立 C 電動機車物件, 座位數 2
	B.show(); //output 機車品牌：三陽 油量：10 速度：50 可行駛公里數：150
	C.show();//output 電動機車品牌：Gogoro 座位數：2 油量 10 速度：25 可行駛公里數：200
	cout << "已建立機車數" << motor::num << endl; // output 已建立機車數 3
	return 0;
}