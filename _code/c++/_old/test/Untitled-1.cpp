#include <iostream>

enum Mode { MODE, APPLE };

class MyClass {
public:
  void test() { std::cout << "test方法"; }
  void test2(Mode theMode) {
    switch (theMode) {
    case MODE:
      std::cout << "MODE"
                << "\n";
      break;
    case APPLE:
      std::cout << "APPLE"
                << "\n";
      break;
    default:
      break;
    }
  }

private:
  int value;
};
MyClass myClass;
int main() {
  
  std::cout << "Hello World!\n";
}