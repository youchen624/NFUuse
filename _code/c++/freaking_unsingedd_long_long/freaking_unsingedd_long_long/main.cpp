#include <iostream>

int main() {
    unsigned long long l = 1;
    while (l++ != 0) {
        std::cout << l << std::endl;
    }
    std::cout << l << std::endl;
    return 0;
};