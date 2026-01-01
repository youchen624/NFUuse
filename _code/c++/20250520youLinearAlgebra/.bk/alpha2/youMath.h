#pragma once
#include <map>
#include <vector>

namespace youMath
{
    // Fraction getGCD(const Fraction&, const Fraction&);
    //  #TODO make all in namespace::youMath

    class Number {
    protected:
        // nothing here
    public:
        // using Value = std::variant<Complex, Infinity, Variable, Undefined>;
        enum class Type {
            Infinity = -1,
            Undefined = 0,
            Fraction,
            Complex,
            Variable,
        };

        std::string type_name() const;

        std::string to_string() const;
        double to_double() const;

        // determine whether it is a Real Number
        bool is_real() const;
        // determine whether it is Zero
        bool is_zero() const;
        // determine whether it is Defined
        bool is_defined() const;
        // determine whether it is Undefined
        bool is_undefined() const;
        // determine whether it is a Complex Number
        bool is_complex() const;

        // determine whether the Number is Negative
        bool is_negative() const;
        // determine whether the Number is Positive
        bool is_positive() const;
        // determine whether the Number is Infinity
        bool is_infinity() const;
        // determine whether the Number is Integer
        bool is_integer() const;
        // auto is_();
    private:
        // as Real
        class Fraction {
        private:
            long long num, den;
        public:
            Fraction ();
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
        };

        // Real + Imaginary-Number
        class Complex {
            Fraction real, imag;
        };

        // Infinity
        class Infinity {
            bool positive;
        };

        // Variable
        class Variable {
        public:
        private:
            static std::map<std::string, Number> VariableValueMap;
            std::string name;
        };

        // Undefined
        class Undefined { };

        // Value a ptr union
        union Value {
            Fraction* fraction;
            Complex* complex;
            Infinity* infinity;
            Variable* variable;
            Undefined* undefined;
        };

        //

        // Number Type
        Type type;
        // positive/negative
        bool sign;
        // Number Value
        // Value value;
        std::vector<unsigned long long> value;
    };

    int getGCD(const int, const int);
    int getLCM(const int, const int);

    class Array {
    protected:
        long long length;
    public:
    private:
    };

    class Matrix {
    protected:
        long long m, n;
    public:
    private:
    };
};