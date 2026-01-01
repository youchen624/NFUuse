#pragma once
#include <string>
namespace youMath {
    //Fraction getGCD(const Fraction&, const Fraction&);
    // #TODO make all in namespace::youMath




    // fraction, like "2/3"
    /**
     * @class Fraction
     */
    class Fraction {
    protected:
        // nothing here
    public:
        // Config about whether auto reduction
        static constexpr bool auto_reduction = true;
        // Config about whether enable positive sign when using method <std::string>asString()
        static constexpr bool enable_positive_sign = false;
        // Constructor
        Fraction(int n = 0, int d = 1);
        Fraction(std::string s = "0/1");

        // Simplify the fraction
        void reduction();
        // Gets value as double
        double to_double() const;
        // Gets value as string
        std::string to_string() const;

        Fraction operator-() const;
        // Take the reciprocal
        Fraction operator~() const;
        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        Fraction operator+=(const Fraction&);
        Fraction operator-=(const Fraction&);
        Fraction operator*=(const Fraction&);
        Fraction operator/=(const Fraction&);

        // auto operator<=>(Fraction&) const; // V20

        bool operator==(const Fraction&) const;
        bool operator!=(const Fraction&) const;
        bool operator>(const Fraction&) const;
        bool operator<(const Fraction&) const;
        bool operator>=(const Fraction&) const;
        bool operator<=(const Fraction&) const;
    private:
        int numerator;        // numerator/d
        int denominator;    // n/denominator
    };

    // ostream operator
    std::ostream& operator<<(std::ostream&, const Fraction&);
    // istream operator
    std::istream& operator>>(std::istream&, Fraction&);



    int getGCD(const int, const int);
    int getLCM(const int, const int);


    // Number
    class Number {
    public:
        Number() {};
    };


    class Array {
    public:
    private:
    };

    class Matrix {};
};