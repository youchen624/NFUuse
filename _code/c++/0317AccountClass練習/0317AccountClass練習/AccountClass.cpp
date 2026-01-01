#include "AccountClass.h"

// -- 設定 static 變數初始值 --------------------------
double Account::Rate = 5.8;
int Account::Count = 0;
//-- 定義預設建構函式 Account() ------------ ----------
Account::Account()
{
	cout << "設定銀行帳戶" << endl;
	Balance = 0;
	Account::Count++;
	cout << "目前尚未輸入帳戶名稱.\n";
}
//-- 定義建構函式 Account() ----------------------------
Account::Account(string Name) : Account::Account(Name, 0) {}
// -- 定義建構函式 Account() (可設定初值) --------------
Account::Account(string Name, int N)
{
	Id = Name;//
	cout << "設定 " << left << setw(8) << Id
		<< " 的銀行帳戶" << endl;
	Balance = N;
	Account::Count++;
	cout << "目前 " << setw(8) << Id << " 帳戶餘額是 "
		<< Balance << " 元\n";
}
//-- 定義解構函式 ~Account() -------------------------
Account::~Account()
{
	cout << "撤銷 " << setw(8) << Id << " 的銀行帳戶" << endl;
	Account::Count--;
}
// -- 定義函式成員 WithDraw() ------------------------
void Account::WithDraw(int Cash)
{
	Balance -= Cash;
}
