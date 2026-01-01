#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//---- 宣告類別 Account -----------------------------
class Account
{
private:
	static double Rate; // 利率
	static int Count; // 帳戶數
	int Balance; // 存款餘額
	string Id; // 帳戶名稱
public:
	Account(); // 預設建構函式
	Account(string); // 建構函式-1
	Account(string, int); // 建構函式-2
	~Account(); // 解構函式
	void Deposit(int); // 存款函式
	void WithDraw(int); // 提款函式
	void CheckBalance(); // 查詢餘額
	void CheckRate() // 查詢目前利率
	{
		cout << "目前存款利率是: " << Rate << '%' << endl;
	}
	void CheckCount();
};
// -- 定義 inline 函式成員 Deposit() ------------------
inline void Account::Deposit(int CashInput)
{
	Balance += CashInput;
}
// -- 定義 inline 函式成員 CheckBalance() -------------
inline void Account::CheckBalance()
{
	cout << "目前 " << setw(8) << Id
		<< " 的帳戶餘額是 " << Balance << " 元\n";
	return;
}
// -- 定義 inline 函式成員 CheckCount() ----------------
inline void Account::CheckCount()
{
	cout << "目前銀行共有 " << Count << " 個帳戶.\n";
	return;
}