
#include <iostream>
#include <string>
using namespace std;

/*
// '0' = 48
// '9' = 57
// '9' + '9' = 57 + 57 = 114 => 66 => 56;
char charNum_add(char a, char b, int& c) {
	char t = a + b - '0';
	if (t > '9') c = 1;
	return t - 1;
};
*/

//template <typename T>
class BNumber {
protected:
	class Node {
	public:
		Node(char v = {}, Node* L = nullptr, Node* R = nullptr) :
		value(v), left(L), right(R) {};
		~Node() {};
	
		char value;
		Node* left;
		Node* right;
	};
	
	Node* _search_p(size_t index) const {		// const
		if(index >= size) throw "out of range";
		Node* ptr = head;
		if (index <= size / 2) {
			// index >< size/2 ?? if..else
			for (size_t i = 0; i < index; ++i) {
				ptr = ptr->left;
			}
			return ptr;
		} else {
			ptr = ptr->right;
			for (size_t i = size - 1; i != index; --i) {
				ptr = ptr->right;
			}
			return ptr;
		}
	};
	char& _search(size_t index) {
		return _search_p(index)->value;
		/*
		if(index >= size) throw "out of range";
		Node* ptr = head;
		if (index <= size / 2) {
			// index >< size/2 ?? if..else
			for (size_t i = 0; i < index; ++i) {
				ptr = ptr->left;
			}
			return ptr->value;
		} else {
			ptr = ptr->right;
			for (size_t i = size - 1; i != index; --i) {
				ptr = ptr->right;
			}
			return ptr->value;
		}
		*/
	};
	char _search_n(size_t index) const {
		return _search_p(index)->value;
		/*
		if(index >= size) throw "out of range";
		Node* ptr = head;
		if (index <= size / 2) {
			// index >< size/2 ?? if..else
			for (size_t i = 0; i < index; ++i) {
				ptr = ptr->left;
			}
			return ptr->value;
		} else {
			ptr = ptr->right;
			for (size_t i = size - 1; i != index; --i) {
				ptr = ptr->right;
			}
			return ptr->value;
		}
		*/
	};
	
	void _push_left(char c, size_t dup = 0) {
		// dup 額外次數
		for (size_t i = 0; i <= dup; ++i) {
			if(empty()) {
				head = new Node(c);
				head->right = head;
				head->left = head;
				++size;
				return;
			}
			Node* ptr = new Node(c, head, head->right);
			head->right = head->right->left = ptr;
			++size;
		}
	};
	void _push_right(char c, size_t dup = 0) {
		// dup 額外次數
		for (size_t i = 0; i <= dup; ++i) {
			if(empty()) return _push_left(c, dup);
			Node* ptr = new Node(c, head, head->right);
			head = head->right = head->right->left = ptr;
			++size;
		}
	};
private:
	// string value;
	Node* head;	// 個位數
	// Node* nmax;	// 最高位元
	size_t size;
public:
	BNumber() {
		size = 0;
		head = nullptr;
	};
	BNumber(int v) {
		size = 0;
		_push_left(v%10);
		//Node* ptr = head = new Node((v%10), head, head);
		v /= 10;
		//++size;
		for (;v > 0;v /= 10) {
			_push_left(v%10);
			/*
			ptr->left = new Node((v%10), head, ptr);
			ptr = ptr->left;
			head->right = ptr;
			++size;
			*/
		}
	};
	BNumber(const BNumber& that) {
		this->size = 0;
		for (size_t i = 0; i < that.length(); ++i) {
			this->_push_left(that._search_n(i));
		}
	};
	BNumber(string str) {
		size = 0;
		_push_left(str[str.length()-1] - '0');
		//Node* ptr = head = new Node((str[str.length()-1] - '0'), head, head);
		//++size;
		for(size_t i = 1; i < str.length(); ++i) {
			_push_left(str[str.length()-1 - i] - '0');
			/*
			ptr->left = new Node(str[str.length()-i-1] - '0', head, ptr);
			ptr = ptr->left;
			head->right = ptr;
			++size;
			*/
		}
	};
	
	~BNumber() {
		this->clear();
	};
	
	void clear() {
		if (empty()) return;
		Node* ptr = head->left;
		for (size_t i = 0; i < size; ++i) {
			if (head) delete head;
			head = ptr;
			if (ptr) ptr = ptr->left;
		}
		size = 0;
	};
	bool empty() const { return !size; };
	size_t length() const { return size; };
	
	// [0] = 0001 // [1] == 0010
	char& operator[](size_t index) { return _search(index); };

	/*
	void t() {
		_push_right(0, 1);
	};
	*/
	BNumber& operator=(const BNumber& that) {
		this->clear();
		for (size_t i = 0; i < that.length(); ++i) {
			this->_push_left(that._search_n(i));
		}
		return *this;
	}
	
	BNumber operator+(const BNumber& that) const {
		const BNumber* nLess = (that.length() > this->length() ? this : &that);
		const BNumber* nMore = (that.length() > this->length() ? &that : this);
		BNumber nTemp;
		char c = 0;
		size_t i = 0;
		for (;i < nLess->length(); ++i) {
			char t = nLess->_search_n(i) + nMore->_search_n(i) + c;
			if (t >= 10) {
				c = 1;
				t -= 10;
			} else c = 0;
			nTemp._push_left(t);
		}
		for (;i < nMore->length(); ++i) {
			char t = nMore->_search_n(i) + c;
			if (t >= 10) {
				c = 1;
				t -= 10;
			} else c = 0;
			nTemp._push_left(t);
		}
		if (c) nTemp._push_left(c);
		return nTemp;
	};
	BNumber& operator+=(const BNumber& that) {
		BNumber t = (*this) + that;
		this->operator=(t);
		return *this;
	}
	BNumber operator*(const BNumber& that) const {
		const BNumber* nLess = (that.length() > this->length() ? this : &that);
		const BNumber* nMore = (that.length() > this->length() ? &that : this);
		BNumber NTemp;
		char c = 0;
		for (size_t i = 0; i < nLess->length(); ++i) {
			BNumber tn;
			for (size_t ii = 0; ii < nMore->length(); ++ii) {
				char tc = nMore->_search_n(ii) * nLess->_search_n(i) + c;
				if (tc >= 10) {
					c = tc/10;
					tc %= 10;
				} else c = 0;
				tn._push_left(tc);
			}
			if (c) tn._push_left(c);
			c = 0;
			if (i) tn._push_right(0, i - 1);
			NTemp += tn;
			// debug
			// cout << tn.to_string() << endl;
		}
		return NTemp;
	};
	BNumber& operator*=(const BNumber& that) {
		BNumber t = (*this) * that;
		this->operator=(t);
		return *this;
	}
	
	string to_string() const {
		string str = "";
		Node* ptr = head->right;
		for (size_t i = 0; i < size; ++i) {
			//cout << i <<"debug:" << (int)ptr->value << endl;
			str += (char)(ptr->value + '0');
			ptr = ptr->right;
		}
		/*
		while (ptr != head) {
			str += (char)(ptr->value + '0');
			ptr = ptr->right;
		}
		str += (char)(ptr->value + '0');
		*/
		return str;
	};
	
	void debug() {
		cout
			<< "#debug>\n"
			<< "size=" << size << endl
			//<< ", "
			<< "<debugEND#"
		<< endl;
	};
};

//// CLASS END ####

int main() {
	//cout << (int)'0';
	//cout << (char)58;
	// BNumber bn("123");
	// BNumber bn2("567");
	// cout << (bn+bn2).to_string() << endl;
	// cout << charNum_add('6', '3');
	/*
	BNumber bn(123);
	BNumber bn2("456");
	cout << bn.to_string() << endl;
	cout << bn2.to_string() << endl;
	cout << (char)(bn[2] + '0') << endl;
	cout << (char)(bn2[2] + '0') << endl;
	cout << (bn+bn).to_string() << endl;
	cout << (bn+bn2).to_string() << endl;
	cout << (BNumber(999) + BNumber(999)).to_string() << endl;
	BNumber bn3(bn2);
	cout << bn3.to_string() << endl;
	bn3.t();
	cout << bn3.to_string() << endl;
	bn3 += bn;
	cout << bn3.to_string() << endl;
	*/
	// cout << "*===>" << endl << (BNumber(12) * BNumber(12)).to_string() << endl;
	//cout << (BNumber(12) + BNumber(13)).to_string() << endl;
	// BNumber t(50);
	// BNumber t1(12);
	// t *= t1;
	// cout << "tt=>>" << t.to_string() << endl;
	
	int n;
	while (cin >> n) {
		BNumber bn(1), tn;
		for (int i = 1; i <= n; ++i) {
			tn = BNumber(i);
			//cout << tn.to_string() << endl;
			bn *= tn;
		}
		// cout << bn.to_string() << endl;
		int tt = 0;
		for (size_t i = 0; i < bn.length(); ++i) {
			tt += (int)(bn[i]);
			//cout << (int)(bn[i]) << endl;
		}
		cout << tt << endl;
	}
	return 0;
};
