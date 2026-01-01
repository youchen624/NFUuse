#include "youMisc.h"
#include "youMath.h"
#include <numeric>
#include <string>
#include <iostream>

using namespace youMisc;

namespace youMath
{

    // get GCD
    int getGCD(const int x, const int y)
    {
        int a = std::abs(x);
        int b = std::abs(y);
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    };
    // get LCM
    int getLCM(const int x, const int y)
    {
        return std::abs(x * y) / getGCD(x, y);
    };
};