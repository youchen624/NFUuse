#include <iostream>
using namespace std;

class motor {
protected:
	string brand;
	double fuel;
	double speed;
	double km = 0;
public:
	static int num;
	motor(string b, double f, double sp) : brand(b), fuel(f), speed(sp) { motor::num++; }
	motor(const motor& m) : motor(m.brand, m.fuel, m.speed) {}
	~motor() { motor::num--; }
	void calKM() { km = fuel * 15; }
	void show();
};
class electricMotor : private motor {
private:
	int seat;
public:
	electricMotor(string b, double f, double sp, int se) : motor(b, f, sp), seat(se) {}
	void calKM() { km = fuel * 20; }
	void show();
};
class raceMotor : private motor {
private:
	string type;
public:
	raceMotor(string b, double f, double sp, string t) : motor(b, f, sp), type(t) {}
	void calKM() { km = fuel * ((60 < speed) ? 10 : 12); }
	void show();
};

void motor::show() {
	calKM();
	cout
		<< "诀ó珇礟" << brand
		<< " 猳秖" << fuel
		<< " 硉" << speed
		<< " ︽緋そń计" << km
	<< endl;
}
void electricMotor::show() {
	calKM();
	cout
		<< "筿笆ó珇礟" << brand
		<< " 畒计" << seat
		<< " 猳秖" << fuel
		<< " 硉" << speed
		<< " ︽緋そń计" << km
	<< endl;
}
void raceMotor::show() {
	calKM();
	cout
		<< "诀ó珇礟" << brand
		<< " 腹" << type
		<< " 猳秖" << fuel
		<< " 硉" << speed
		<< " ︽緋そń计" << km
	<< endl;
}

int motor::num = 0;
int main() {
	electricMotor A("Gogoro", 10, 25, 2);
	raceMotor B("地瑅辽ó", 15, 150, "TT150");
	A.show();
	B.show();
	cout << "ミ诀ó计" << motor::num << endl;
	return 0;
}