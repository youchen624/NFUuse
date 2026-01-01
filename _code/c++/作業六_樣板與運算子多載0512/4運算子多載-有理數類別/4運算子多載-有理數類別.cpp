#include <iostream>
#include <string>
using namespace std;

class RationalNumber
{
public:
	RationalNumber(int n = 0, int d = 1) : numerator(n), denominator(d) { this->reduction(); };
	RationalNumber operator+(RationalNumber& that) {
		RationalNumber t(this->numerator * that.denominator + that.numerator * this->denominator, that.denominator * this->denominator);
		t.reduction();
		return t;
	};
	RationalNumber operator++(int) {
		RationalNumber t = *this;
		this->numerator++;
		this->denominator++;
		//this->numerator += this->denominator;
		this->reduction();
		return t;
	}; //多載後加運算子，設後加會先以目前值運算，再將分子與分母各加一
	RationalNumber operator++() {
		this->numerator++;
		this->denominator++;
		//this->numerator += this->denominator;
		this->reduction();
		return *this;
	}; // 多載前加運算子，設後加會先將分子與分母各加一，再傳出運算
	bool operator==(RationalNumber &that) const {
		return ((long long)this->numerator * that.denominator) == ((long long)that.numerator * this->denominator);
	}; // 多載 == 運算子
	bool operator!=(RationalNumber &that) const {
		return !operator==(that);
		//((long long)this->numerator * that.denominator) != ((long long)that.numerator * this->denominator);
	}; // 多載 != 運算子
	void reduction() {
		int hcf = 1, h = (numerator > denominator) ? denominator : numerator;
		// 找公因數
		for (h; h > 1; h--) {
			if (!(numerator % h || denominator % h)) {
				hcf = h;
				break;
			}
		}
		// 化簡
		numerator /= hcf;
		denominator /= hcf;
	}; // 找分子與分母的最大公因數以對分子與分母進行化簡
private:
	int numerator; // 分子
	int denominator; // 分母
	friend ostream& operator<<(ostream& output, RationalNumber& number) {
		output << to_string(number.numerator) << '/' << to_string(number.denominator);
		return output;
	};
	friend istream& operator>>(istream& input, RationalNumber& number) {
		char sym; // not using
		input >> number.numerator >> sym >> number.denominator;
		return input;
	};
	friend bool operator>(double a, const RationalNumber& number) {
		return (a > ((double)number.numerator / number.denominator));
	};
};

int main()
{
	RationalNumber c, d, x, y;
	printf("請輸入一有理數，格式如: 19/3\n");
	cin >> c; //設輸入 19/3
	printf("請輸入一有理數，輸入格式如: 2/3\n");
	cin >> d; //設輸入 2/3
	x = c + d;
	y = (++c) + d;
	cout << "x= " << x << endl; //輸出 x=7/1
	cout << "y= " << y << endl; //輸出 y=17/3
	x++;
	cout << x << endl; // 輸出分數格式如: 4/1
	if (7.2 > c) cout << "larger than\n"; // 輸出 larger than
	else cout << "less or equal to\n";
	x = y;
	if (x == y) cout << "equal \n"; // 輸出 equal
	else cout << "not equal \n";
	return 0;
};