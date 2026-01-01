#include <iostream>
#include <string>
using namespace std;

class PhoneNumber {
private:
	//char ac[3], ec[3], lc[4];
	string num;
public:
	friend istream& operator>>(istream& that, PhoneNumber& phone);
	friend ostream& operator<<(ostream& that, PhoneNumber& phone);
};
istream& operator>>(istream& that, PhoneNumber& phone) {
	//string t; // 15
	getline(that, phone.num);
	return that;
};
ostream& operator<<(ostream& that, PhoneNumber& phone) {
	that << phone.num;//"(" + to_string(phone.num[0]) + ") " + to_string(phone.num[1]) + "-" + to_string(phone.num[2]);
	return that;
};

int main() {
	PhoneNumber phone;
	cout << "ENter phone number in the form (123) 456-7890:" << endl;
	// cin >> phone invokes operator >> by implicitly issuing
	// the global function call operator>>(cin, phone)
	cin >> phone; // (800) 555-1212
	cout << "The phone number entered was:";
	// cout << phone invokes operator<< by implicitly issuing
	// the global function call operator<<(cout, phone)
	cout << phone << endl;
	return 0;
};