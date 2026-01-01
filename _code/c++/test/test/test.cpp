#include <iostream>
using namespace std;
int* a() {
    static int value = 10;  // 靜態變數，存活於整個程序
    return &value;
}
int& getStaticVar() {
    static int value = 10;  // 靜態變數，存活於整個程序
    return value;
}

int main() {
    int& ref = getStaticVar();
    int* refA = a();
    getStaticVar() = 43;
    *refA = 42;
    *a() = 2;
    ref = 42;
    cout << "靜態變數的值: " << getStaticVar() << "\nref: " << ref << endl;
    cout << "指標變數的值: " << *a() << "\nrefA: " << *refA << endl;
    return 0;
}
