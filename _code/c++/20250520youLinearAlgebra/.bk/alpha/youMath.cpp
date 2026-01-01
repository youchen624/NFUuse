#include "youMisc.h"
#include "youMath.h"
#include <numeric>
#include <string>
#include <iostream>

using namespace youMisc;

namespace youMath
{

    class Fraction;
    Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
    {
        if (!d)
            throw std::invalid_argument(this->to_string().append(" is undefined"));
        if (auto_reduction)
            reduction();
    };
    Fraction::Fraction(std::string s)
    {
        std::vector<std::string> v = split(s, '/');
        int n = std::stoi(v[0]), d = std::stoi(v[1]);
        if (!d)
            throw std::invalid_argument(this->to_string().append(" is undefined"));
        numerator = n;
        denominator = d;
        if (auto_reduction)
            reduction();
    };

    void Fraction::reduction()
    {
        if (!denominator)
            throw std::invalid_argument(this->to_string().append(" is undefined"));
        if (denominator < 0)
        {
            denominator *= -1;
            numerator *= -1;
        }
        // int gcd = std::gcd(numerator, denominator);
        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    };
    double Fraction::to_double() const
    {
        return (double)numerator / denominator;
    };
    std::string Fraction::to_string() const
    {
        // if (auto_reduction) reduction();
        std::string s = "";
        if (enable_positive_sign && numerator >= 0)
            s.append("+");
        s.append(std::to_string(this->numerator));
        s.append("/");
        s.append(std::to_string(this->denominator));
        return s;
    };

    Fraction Fraction::operator-() const
    {
        return Fraction((-1) * this->numerator, this->denominator);
    };
    Fraction Fraction::operator~() const
    {
        if (!this->numerator)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        return Fraction(this->denominator, this->numerator);
    };
    Fraction Fraction::operator++()
    {
        this->numerator += this->denominator;
        return *this;
    };
    Fraction Fraction::operator++(int)
    {
        Fraction t(this->numerator, this->denominator);
        this->numerator += this->denominator;
        return t;
    };
    Fraction Fraction::operator--()
    {
        this->numerator -= this->denominator;
        return *this;
    };
    Fraction Fraction::operator--(int)
    {
        Fraction t(this->numerator, this->denominator);
        this->numerator -= this->denominator;
        return t;
    };

    Fraction Fraction::operator+(const Fraction &that) const
    {
        if (this->denominator == that.denominator)
            return Fraction(this->numerator + that.numerator, this->denominator);
        int lcm = getLCM(this->denominator, that.denominator);
        return Fraction(this->numerator * (lcm / this->denominator) + that.numerator * (lcm / that.denominator), lcm);
    };
    Fraction Fraction::operator-(const Fraction &that) const
    {
        if (this->denominator == that.denominator)
            return Fraction(this->numerator - that.numerator, this->denominator);
        int lcm = getLCM(this->denominator, that.denominator);
        return Fraction(this->numerator * (lcm / this->denominator) - that.numerator * (lcm / that.denominator), lcm);
    };
    Fraction Fraction::operator*(const Fraction &that) const
    {
        return Fraction(this->numerator * that.numerator, this->denominator * that.denominator);
    };
    Fraction Fraction::operator/(const Fraction &that) const
    {
        if (!that.numerator)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        return Fraction(this->numerator * that.denominator, this->denominator * that.numerator);
    };

    Fraction Fraction::operator+=(const Fraction &that)
    {
        if (this->denominator == that.denominator)
        {
            this->numerator += that.numerator;
            return *this;
        }
        int lcm = getLCM(this->denominator, that.denominator);
        this->numerator = this->numerator * (lcm / this->denominator) + that.numerator * (lcm / that.denominator);
        this->denominator = lcm;
        if (auto_reduction)
            this->reduction();
        return *this;
    };
    Fraction Fraction::operator-=(const Fraction &that)
    {
        if (this->denominator == that.denominator)
        {
            this->numerator -= that.numerator;
            return *this;
        }
        int lcm = getLCM(this->denominator, that.denominator);
        this->numerator = this->numerator * (lcm / this->denominator) - that.numerator * (lcm / that.denominator);
        this->denominator = lcm;
        if (auto_reduction)
            this->reduction();
        return *this;
    };
    Fraction Fraction::operator*=(const Fraction &that)
    {
        this->numerator *= that.numerator;
        this->denominator *= that.denominator;
        if (auto_reduction)
            this->reduction();
        return *this;
    };
    Fraction Fraction::operator/=(const Fraction &that)
    {
        if (!that.numerator)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        this->numerator *= that.denominator;
        this->denominator *= that.numerator;
        if (auto_reduction)
            this->reduction();
        return *this;
    };

    bool Fraction::operator==(const Fraction &that) const
    {
        return this->numerator * that.denominator == that.numerator * this->denominator;
    };
    bool Fraction::operator!=(const Fraction &that) const
    {
        return !operator==(that);
    };
    bool Fraction::operator>(const Fraction &that) const
    {
        return this->numerator * that.denominator > that.numerator * this->denominator;
    };
    bool Fraction::operator<(const Fraction &that) const
    {
        return this->numerator * that.denominator < that.numerator * this->denominator;
    };
    bool Fraction::operator>=(const Fraction &that) const
    {
        return this->numerator * that.denominator >= that.numerator * this->denominator;
    };
    bool Fraction::operator<=(const Fraction &that) const
    {
        return this->numerator * that.denominator <= that.numerator * this->denominator;
    };
    //
    std::ostream &operator<<(std::ostream &out, const Fraction &fraction)
    {
        return out << fraction.to_string();
    }
    std::istream &operator>>(std::istream &in, Fraction &fraction)
    {
        int n, d = 1; // char c;
        in >> n;
        if (in >> std::ws && in.peek() == '/')
        {
            in.get();
            if (!(in >> d) || d == 0)
            {
                in.setstate(std::ios::failbit);
                return in;
            };
        };
        fraction = Fraction(n, d);
        return in;
    }





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