#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//---- 宣告類別 Account -----------------------------
class Account
{
private:
	static double Rate;    // 利率
	static int   Count;   // 帳戶數	
	int          Balance; // 存款餘額
	string         Id; // 帳戶名稱 
public:
	Account();                  // 預設建構函式
	Account(string);        // 建構函式-1
	Account(string, int);  // 建構函式-2
	~Account();   	    // 解構函式
	void Deposit(int); // 存款函式
	void WithDraw(int); // 提款函式
	void CheckBalance();
	void CheckRate()
	{
		cout << "目前存款利率是: " << Rate << '%' << endl;
	}
	void CheckCount();
};

// -- 定義 inline 函式成員 Deposit() ------------------
inline void Account::Deposit(int CashInput)
{
	Balance += CashInput;
	cout << setw(8) << Id << " 存款 " << CashInput
		<< " 元後 " << "目前帳戶餘額是 "
		<< Balance << " 元\n";
	return;
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
// -- 設定 static 變數初始值 --------------------------
double Account::Rate = 5.8;
int   Account::Count = 0;
//-- 定義預設建構函式 Account() ------------ ----------
Account::Account()
{
	cout << "設定銀行帳戶" << endl;
	Balance = 0;
	Account::Count++;
	cout << "目前尚未輸入帳戶名稱.\n";
}
//-- 定義建構函式 Account() ----------------------------
Account::Account(string Name)
{
	Id = Name;//
	cout << "設定 " << left << setw(8) << Id
		<< " 的銀行帳戶" << endl;
	Balance = 0;
	Account::Count++;
	cout << "目前 " << setw(8) << Id << " 帳戶餘額是 "
		<< Balance << " 元\n";
}
// -- 定義建構函式 Account() (可設定初值) --------------
Account::Account(string Name, int N)
{
	Id = Name;
	cout << "設定 " << setw(8) << Id << " 的銀行帳戶" << endl;
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
	if (Cash > Balance)
	{
		cout << "存款不足! " << setw(8) << Id
			<< " 這次提款不成." << endl;
		return;
	}
	Balance -= Cash;
	cout << setw(8) << Id << " 提款 " << Cash << " 元後，"
		<< "目前帳戶餘額是 " << Balance << " 元\n";
}

