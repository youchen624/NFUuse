
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
class Time
{
public:
	Time();
	~Time();
	void setTime(int, int, int);
	void setClock(int, int, int);
	void tick();
	bool isClock();
	void Show();
private:
	int ch = 0, cm = 0, cs = 0;
	int hour;		// 0 - 23
	int minute;	// 0 - 59
	int second;	// 0 - 59
};
Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::~Time()
{
	cout << "時間物件已解構";
}
void Time::setTime(int h, int m, int s)
{
	while (s > 59) {
		s -= 60;
		m++;
	}
	while (m > 59) {
		m -= 60;
		h++;
	}
	while (h > 23) {
		h -= 24;
	}
	second = s;
	minute = m;
	hour = h;
}
void Time::setClock(int h, int m, int s)
{
	while (s > 59) {
		s -= 60;
		m++;
	}
	while (m > 59) {
		m -= 60;
		h++;
	}
	while (h > 23) {
		h -= 24;
	}
	cs = s;
	cm = m;
	ch = h;
}
void Time::tick()
{
	setTime(hour, minute, ++second);
}
void Time::Show()
{
	cout
		<< "目前時間!：" << setw(2) << setfill('0')
		<< hour << ":" << setw(2) << setfill('0')
		<< minute << ":" << setw(2) << setfill('0')
		<< second;
}
bool Time::isClock() {
	return (ch == hour) && (cm == minute) && (cs == second);
}
int main()
{
	Time t;
	t.setTime(13, 59, 56);
	t.setClock(14, 0, 2);
	while (true)
	{
		Sleep(1000);
		system("cls");
		t.tick();
		t.Show();
		if (t.isClock()) {
			cout << endl << "時間到" << endl;
			break;
		}
	}
	return 0;
}