#include<iostream>
using namespace std;
class CBox
{
public: //以下設定為公開
	double L, W, H; //資料成員,宣告 存放長,寬,高的欄位名稱
	double Volume() //函式成員, 提供計算物件體積(長*寬*高)的方法
	{
		return L * W * H;
	}
	double area() {
		return (L * W + W * H + H * L) * 2;
	}
	// CBox() {} // 預設建構子, 不須傳參數, 此處可寫可不寫
	void print() //函式成員, 提供印出物件屬性的方法
	{
		cout << "長= " << L << ",寬= " << W << ",高= " << H << endl;
	}
};
int main()
{
	CBox box1; //建立長方體物件box1, 自動呼叫CBox類別的預設建構子
	cout << "請輸入物件之長,寬,高\n";
	cin >> box1.L >> box1.W >> box1.H; //設定 box1 物件 的 長,寬,高
	box1.print(); //呼叫 box1物件的print方法
	cout << "volume of box1=" << box1.Volume() << endl;
	cout << "area of box1=" << box1.area() << endl;
	//CBox *ptr; //建立物件指標
	//ptr=&box1;
	//cout<<"volume of box1="<<ptr->Volume()<<endl;
	//cout<<"volume of box1="<<(*ptr).Volume()<<endl;
	return 0;
}