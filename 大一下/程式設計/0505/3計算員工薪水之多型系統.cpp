#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int salary;
    Employee(string n, int p) : name(n), salary(p) { num++; };
public:
    static int num;
    void const getName() { cout << name; };
    int const getSalary() { return salary; };
};
class Manager : public Employee {
public:
    Manager(string n) : Employee(n, 40000) {};
};
class Engineer : public Employee {
public:
    Engineer(string n) : Employee(n, 35000) {};
};

int Employee::num = 0;
int main()
{
    Employee* array[10];
    Manager A("Terry");
    Engineer B("Sam");
    Engineer C("Mary");
    Engineer D("Helen");
    Manager E("John");
    array[0] = &A;
    array[1] = &B;
    array[2] = &C;
        array[3] = &D;
    array[4] = &E;
    for (int i = 0; i < Employee::num; i++)
    {
        array[i]->getName();
        cout << "\t";
        cout << array[i]->getSalary();
        cout << endl;
    }
    return 0;
}