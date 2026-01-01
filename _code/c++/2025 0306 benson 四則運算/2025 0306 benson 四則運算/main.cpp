#include <iostream>
//#include <string>
using namespace std;


// 四捨五入進位
int DB(int i) {
    //cout << "[DB()]: " << i << endl;
    return (int)((i < 10) && (i >= 5)) + (int)((i >= 10) && (bool)DB(i / 10 + (i%10 >= 5)));
}

// 取符號
double getSign(double x) {
    return (1 - 2 * (x < 0));
}

int main() {
    double x = 0, y = 0, resultDouble, sign;
    while (cin >> x >> y) {
        resultDouble = x / y;                                                   //相除結果 小數
        sign = getSign(resultDouble);                                    //取符號(正負)
        resultDouble = abs(resultDouble);                     //絕對值
        int resultInt = (int)abs(resultDouble);                 //相除結果 整數
        cout << "x/y= " << sign * resultDouble << endl;
        double resultDoublePart = resultDouble - resultInt;   //相除結果 小數部分
        cout << "A: " << sign * resultDoublePart << endl;
        // A. 輸出兩數相除結果之小數部分。 (10%)

        int i = resultDoublePart * 10000;
        while (i >= 10) {
            i = (i / 10) + (int)(i % 10 >= 5);
        }
        cout << "B: " << sign *(resultInt + (int)(i % 10 >= 5)) << endl;
        // B. 輸出兩數相除之結果 (四捨五入至整數)。 (10%)

        cout << "C: " << sign * (resultInt + (int)(resultDoublePart != 0)) << endl;
        // C. 輸出兩數相除之結果 (無條件進位至整數)。 (10%)

        // 如果B的while不能
        cout << "DB: " << sign * (resultInt + DB(resultDoublePart * 10000)) << endl;
        // D. 同B小題，但限制不得使用判斷式 (如if、switch、?: 等，由老師判定)，
        // 僅使用CH04所學得之運算式與型態轉換技術。 (10%) PS: 此題正確則是為B小題正確。

        cout << "E: " << sign * (resultInt + (int)(resultDoublePart != 0)) << endl;
        // E. 同C小題，但限制不得使用判斷式 (如if、switch、?: 等，由老師判定)，
        // 僅使用CH04所學得之運算式與型態轉換技術。 (10%) PS: 此題正確則是為C小題正確。

        // <>
        // F. 輸出座標 (x, y) 位於第幾象限、原點、X軸上或Y軸上。(10%) 

        int m = abs((int)x) % 12 + 1;
        cout << m;
        switch (m)
        {
        case 3: case 4: case 5:
            cout << "春" << endl;
            break;
        case 6: case 7: case 8:
            cout << "夏" << endl;
            break;
        case 9: case 10: case 11:
            cout << "秋" << endl;
            break;
        case 12: case 1: case 2:
            cout << "冬" << endl;
            break;
        default:
            break;
        }
        // G. 利用switch的fall through特性，判斷月份 m = |x| % 12 + 1的季節並輸出，
        // 其中3-5月: 春、6-8月: 夏、9-11月: 秋、12-2月: 冬。(10%) 

        int n = abs((int)x * (int)y);   // | x * y |
        int t = (n / 100) % 10;         //百位數
        int tt = (n / 10) % 10;          //十位數
        if (n > 1000) {
            cout << n / 1000 << "千";
        }
        if (n > 100) {
            if (t)
                cout << t << "百";
            else
                cout << "零";
        }
        if (n > 10) {
            if (tt)
                cout << tt << "十";
            else if(t)
                cout << "零";
        }
        if (n % 10 != 0)
            cout << n % 10 << endl;
        // H. 輸出 n = |x * y| 之中文念法，例如n = 1234，輸出1千2百3十4、n = 6005，輸出6千零5。(10%)
    }
    system("pause");
    return 0;
}