#include <iostream>
#include <string>
using namespace std;

int main() {
	string input, goal;
	cout << "請輸入文本字串: ";
	getline(cin, input);
	cout << "請輸入目標字串: ";
	cin >> goal;
	int pos = 0, i = 0;
	cout << "字串中出現 " << goal << " 的位置是 ";
	do {
		pos = input.find(goal, pos);
		if (pos == string::npos) break;
		cout << (i++>0 ? ", " : "") << pos;
		pos += goal.length();
	} while (true);
	cout << endl;
	return 0;
}