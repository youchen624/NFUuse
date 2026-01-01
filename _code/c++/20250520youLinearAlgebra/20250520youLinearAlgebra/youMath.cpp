#include "youMisc.h"
#include "youMath.h"
#include <numeric>
#include <string>
#include <iostream>

using namespace youMisc;

namespace youMath
{
    Number::Fraction::Fraction(std::string s) {
        std::vector<std::string> v = split(s, '/');
        unsigned long long n = std::stoull(v[0]), d = std::stoull(v[1]);
        if (!d)
            throw std::invalid_argument(this->to_string().append(" is undefined"));
        this->num = n;
        this->den = d;
        this->normalize();
    };

    void Number::Fraction::normalize () {
        if(this->den == 0) {
            if(this->num == 0) {
                throw FractionException(FractionException::ErrorType::INDEFINITE_FORM,
                    "Fraction: Result is mathematically undefined (0/0).");
            }
            if(this->is_negative()) {
                throw FractionException(FractionException::ErrorType::OVERFLOW_NEGATIVE,
                    "Fraction: Division by zero, result approaches negative infinity.");
            } else {
                throw FractionException(FractionException::ErrorType::OVERFLOW_POSITIVE,
                    "Fraction: Division by zero, result approaches positive infinity.");
            }
        }
        /*
        if (this->den < 0) {
            this->den *= -1;
            this->num *= -1;
        }
        */ // deleted
        // int gcd = std::gcd(num, den); // some bugs
        unsigned long long gcd = get_gcd(this->num, this->den);
        this->num /= gcd;
        this->den /= gcd;
    };
    /*      // deleted
    double Number::Fraction::to_double() const {
        return (double)this->num / this->den;
    };
    */
    std::string Number::Fraction::to_string() const {
        // if (auto_normalize ) normalize ();
        std::string s = "";
        // if (enable_positive_sign && num >= 0)
            // s.append("+");
        s.append(std::to_string(this->num));
        s.append("/");
        s.append(std::to_string(this->den));
        return s;
    };

    Number::Fraction Number::Fraction::operator-() const {
        return Number::Fraction((-1) * this->num, this->den);
    };
    Number::Fraction Number::Fraction::operator~() const {
        if (!this->num)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        return Number::Fraction(this->den, this->num);
    };
    Number::Fraction Number::Fraction::operator++() {
        this->num += this->den;
        return *this;
    };
    Number::Fraction Number::Fraction::operator++(int) {
        Number::Fraction t(this->num, this->den);
        this->num += this->den;
        return t;
    };
    Number::Fraction Number::Fraction::operator--() {
        this->num -= this->den;
        return *this;
    };
    Number::Fraction Number::Fraction::operator--(int) {
        Number::Fraction t(this->num, this->den);
        this->num -= this->den;
        return t;
    };

    Number::Fraction Number::Fraction::operator+(const Number::Fraction &that) const {
        if (this->den == that.den)
            return Number::Fraction(this->num + that.num, this->den);
        unsigned long long lcm = get_lcm(this->den, that.den);
        return Number::Fraction(this->num * (lcm / this->den) + that.num * (lcm / that.den), lcm);
    };
    Number::Fraction Number::Fraction::operator-(const Number::Fraction &that) const {
        if (this->den == that.den)
            return Number::Fraction(this->num - that.num, this->den);
        unsigned long long lcm = get_lcm(this->den, that.den);
        return Number::Fraction(this->num * (lcm / this->den) - that.num * (lcm / that.den), lcm);
    };
    Number::Fraction Number::Fraction::operator*(const Number::Fraction &that) const {
        return Number::Fraction(this->num * that.num, this->den * that.den);
    };
    Number::Fraction Number::Fraction::operator/(const Number::Fraction &that) const {
        if (!that.num)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        return Number::Fraction(this->num * that.den, this->den * that.num);
    };

    Number::Fraction Number::Fraction::operator+=(const Number::Fraction &that) {
        if (this->den == that.den)
        {
            this->num += that.num;
            return *this;
        }
        unsigned long long lcm = get_lcm(this->den, that.den);
        this->num = this->num * (lcm / this->den) + that.num * (lcm / that.den);
        this->den = lcm;
        this->normalize ();
        return *this;
    };
    Number::Fraction Number::Fraction::operator-=(const Number::Fraction &that) {
        if (this->den == that.den)
        {
            this->num -= that.num;
            return *this;
        }
        unsigned long long lcm = get_lcm(this->den, that.den);
        this->num = this->num * (lcm / this->den) - that.num * (lcm / that.den);
        this->den = lcm;
        this->normalize ();
        return *this;
    };
    Number::Fraction Number::Fraction::operator*=(const Number::Fraction &that) {
        this->num *= that.num;
        this->den *= that.den;
        this->normalize ();
        return *this;
    };
    Number::Fraction Number::Fraction::operator/=(const Number::Fraction &that) {
        if (!that.num)
            throw std::invalid_argument("Cannot take reciprocal of zero.");
        this->num *= that.den;
        this->den *= that.num;
        this->normalize ();
        return *this;
    };

    bool Number::Fraction::operator==(const Number::Fraction &that) const {
        return this->num * that.den == that.num * this->den;
    };
    bool Number::Fraction::operator!=(const Number::Fraction &that) const {
        return !operator==(that);
    };
    bool Number::Fraction::operator>(const Number::Fraction &that) const {
        return this->num * that.den > that.num * this->den;
    };
    bool Number::Fraction::operator<(const Number::Fraction &that) const {
        return this->num * that.den < that.num * this->den;
    };
    bool Number::Fraction::operator>=(const Number::Fraction &that) const {
        return this->num * that.den >= that.num * this->den;
    };
    bool Number::Fraction::operator<=(const Number::Fraction &that) const {
        return this->num * that.den <= that.num * this->den;
    };
    ;

};