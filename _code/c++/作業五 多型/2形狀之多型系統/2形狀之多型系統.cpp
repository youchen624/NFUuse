#include <iostream>
//#include <math.h>
#define PI 3.14
using namespace std;

class Shape {
protected:
    string name;
    double r, h, a;
    Shape(string name_, double r_, double h_, double a_) : name(name_), r(r_), h(h_), a(a_) {};
public:
    virtual double area() = 0;
    virtual double volume() = 0;
    void printname() { cout << name << endl; };
};
class Cylinder : public Shape {
public:
    Cylinder(string n, double r, double h) : Shape(n, r, h, 0) {};
    double area() { return (PI * r * r) + (2 * PI * r * h); };
    double volume() { return (PI * r * r * h); };
};
class Ball : public Shape {
public:
    Ball(string n, double r) : Shape(n, r, 0, 0) {};
    double area() { return (4 * PI * r * r); };
    double volume() { return (area() * r / 3); };
};
class Pyramid : public Shape {
public:
    Pyramid(string n, double a, double h) : Shape(n, 0, h, a) {};
    double area() { return (pow(a, 2) + 2 * a * sqrt(pow(a / 2, 2) + pow(h, 2))); };
    double volume() { return (a * a * h / 3); };
};
class Cube : public Shape {
public:
    Cube(string n, double a) : Shape(n, 0, 0, a) {};
    double area() { return (6 * pow(a, 2)); };
    double volume() { return (pow(a, 3)); };
};

int main() {
    Shape* ptr[4]; int i;
    Ball a_ball("a_ball", 10);
    Cylinder a_cylinder("a_cylinder", 10, 5);
    Cube a_cube("a_cube", 10);
    Pyramid a_pyramid("a_pyramid", 10, 5);
    ptr[0] = &a_ball;
    ptr[1] = &a_cylinder;
    ptr[2] = &a_cube;
    ptr[3] = &a_pyramid;
    for (i = 0; i < 4; i++) {
        ptr[i]->printname();
        cout << ptr[i]->area() << endl;
        cout << ptr[i]->volume() << endl;
        cout << endl;
    }
    return 0;
};