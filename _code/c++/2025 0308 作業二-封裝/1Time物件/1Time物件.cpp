// 請完成下面具有時鐘功能的 Time 物件
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
class Time
{
public:
	Time();						 // 建構子, 將資料成員時,分,秒初設為 0
	~Time();					 // 解構子, 印出 “時間物件已解構” 訊息
	void setTime(int, int, int); // 由外部設定時,分,秒
	void tick();				 // 每執行一次 tick 函式會將目前時間物件增加一秒
	void Show();				 // 顯示時間物件內的時間
private:
	int hour;		// 時, 0 - 23
	int minute;	// 分, 0 - 59
	int second;	// 秒, 0 - 59
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
void Time::tick()
{
	setTime(hour, minute, ++second);
}
void Time::Show()
{
	cout
		<< "目前時間!：" << setw(2) << setfill('0')
		<< hour	  << ":" << setw(2) << setfill('0')
		<< minute  << ":" << setw(2) << setfill('0')
		<< second;
}
int main()
{
	Time t;				   // 建立時間物件 t
	t.setTime(13, 59, 56); // 設定物件 t 為 13 時 59 分 56 秒
	while (1)
	{				   // 持續執行
		Sleep(1000);   // 延遲 1000 毫秒=1 秒
		system("cls"); // 清除執行畫面
		t.tick();	   // 將物件 t 增加一秒
		t.Show();	   // 顯示 t 的時間
	}
	return 0;
}