#include <iostream>
#include <string>
using namespace std;

class motor {
public:
	static int num;
	motor(string brand_, double fuel_, double speed_)
		: brand(brand_), fuel(fuel_), speed(speed_) {
		num++;
		calKM();
	};
	~motor() { num--; };
	void calKM() {
		km = fuel * 15;
	};
	void show();
private:
	string brand;
	double fuel;
	double speed;
	double km;
};

int motor::num = 0;
void motor::show() {
	cout
		<< "機車品牌: "			<< brand
		<< " 油量: "					<< fuel
		<< " 速度: "					<< speed
		<< " 可行使公里數: "	<< km
		<< endl;
};

int main()
{
	// 建立 A 物件 機車品牌：三陽 油量：10 速度：50
	motor A("三陽", 10, 50);
	// 建立 B 物件 機車品牌：光陽 油量：15 速度：60
	motor B("光陽", 15, 60);
	cout << "已建立機車數: " << motor::num << endl;
	//機車品牌：三陽 油量：10 速度：50 可行駛公里數：150
	A.show();
	return 0;
}