#include <iostream>
#include <math.h>
using namespace std;

class Mortgage {
public:
	Mortgage() {
		loan = 0, rate = 0, year = 0, num++;
	}
	~Mortgage() {
		num--;
	}
	void set(double l, double r, int y) {
		loan = l;
		rate = r;
		year = y;
	};
	void get();
	double tern();
	double payment();
	static int num;
private:
	double loan, rate;
	int year;
};
int Mortgage::num = 0;
void Mortgage::get() {};
double Mortgage::tern() {
	return pow((1 + rate / 12), 12 * year);
};
double Mortgage::payment() {
	return (loan * (rate / 12) * tern()) / (tern() - 1);
};

int main()
{
	Mortgage mg;
	double ll, rr;
	int yy;
	cout << "輸入貸款額、利率、年數：";
	cin >> ll >> rr >> yy; //輸入 1000000 0.02 20
	mg.set(ll, rr, yy);
	//mg.get();
	cout << "月付額 = " << mg.payment() << endl;// 輸出 5058.83
	{
		Mortgage mg2;
		cout << "目前房屋貸款物件數為: " << Mortgage::num << endl; //目前房屋貸款物件數為: 2
	}
	cout << "目前房屋貸款物件數為: " << mg.num << endl; //目前房屋貸款物件數為: 1
	system("pause");
}
