#include <iostream>
using namespace std;

class motor {
protected:
    string brand;
    double fuel;
    double speed;
    double km = 0;
public:
    static int num;
    motor(string b, double f, double sp) : brand(b), fuel(f), speed(sp) { motor::num++; }
    motor(const motor& m) : motor(m.brand, m.fuel, m.speed) {}
    ~motor() { motor::num--; }
    void calKM() { km = fuel * 15; }
    virtual void show();
};
class electricMotor : public motor {
private:
    int seat;
public:
    electricMotor(string b, double f, double sp, int se) : motor(b, f, sp), seat(se) {}
    void calKM() { km = fuel * 20; }
    void show();
};
class raceMotor : public motor {
private:
    string type;
public:
    raceMotor(string b, double f, double sp, string t) : motor(b, f, sp), type(t) {}
    void calKM() { km = fuel * ((60 < speed) ? 10 : 12); }
    void show();
};

void motor::show() {
    calKM();
    cout
        << "機車品牌：" << brand
        << " 油量：" << fuel
        << " 速度：" << speed
        << " 可行駛公里數：" << km
        << endl;
}
void electricMotor::show() {
    calKM();
    cout
        << "電動車品牌：" << brand
        << " 座位數：" << seat
        << " 油量：" << fuel
        << " 速度：" << speed
        << " 可行駛公里數：" << km
        << endl;
}
void raceMotor::show() {
    calKM();
    cout
        << "機車品牌：" << brand
        << " 型號：" << type
        << " 油量：" << fuel
        << " 速度：" << speed
        << " 可行駛公里數：" << km
        << endl;
}

int motor::num = 0;
/*
int main() {
    electricMotor A("Gogoro", 10, 25, 2);
    raceMotor B("華洋賽車", 15, 150, "TT150");
    A.show();
    B.show();
    cout << "已建立機車數" << motor::num << endl;
    return 0;
}
*/
void output(motor& m) { m.show(); };
int main()
{
    motor A("光陽", 8, 50);//機車品牌：光陽 油量:8 速度：50 可行駛公里數：120
    electricMotor B("Gogoro", 10, 25, 2);//座位數 2
    raceMotor C("華洋賽車", 15, 150, "TT150");//型號 TT 150
    output(A);//輸出 機車品牌：光陽 油量:8 速度：50 可行駛公里數：120
    output(B);//輸出 電動機車品牌：Gogoro 座位數：2 油量:10 速度：25 可行駛公里數：200
    output(C);//輸出 競技機車品牌：華洋賽車 型號： TT150 座位數:2 油量：15 速度：150
    //可行駛公里數：150
    cout << "建立機車數: " << motor::num << endl; // output 建立機車數: 3
    return 0;
}