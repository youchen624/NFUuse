#pragma once
#include <map>
#include <vector>
#include <cmath>
#include <type_traits> // template used
#include <complex>
#include <stdexcept>

namespace youMath
{
    // Fraction get_gcd(const Fraction&, const Fraction&);
    //  #TODO make all in namespace::youMath

    /**
     * Number class
     * @class Number
     */
    class Number {
    public:
        // Number Types
        enum class Type {
            Infinity = -1,
            Undefined = 0,
            Fraction,
            Complex,
            Variable,
        };

        std::string type_name() const;

        std::string to_string() const;
        // double to_double() const; // deleted



        // determines

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


        // operators

        Number operator-() const;
        // Take the reciprocal of Fraction                  // deleting
        // Take the complex conjugate of Complex // deleting
        // Number operator~() const;

        Number operator++();
        Number operator++(int);
        Number operator--();
        Number operator--(int);

        Number operator+(const Number&) const;
        Number operator-(const Number&) const;
        Number operator*(const Number&) const;
        Number operator/(const Number&) const;

        Number operator+=(const Number&);
        Number operator-=(const Number&);
        Number operator*=(const Number&);
        Number operator/=(const Number&);

        // auto operator<=>(Number&) const; // V20

        bool operator==(const Number&) const;
        bool operator!=(const Number&) const;
        bool operator>(const Number&) const;
        bool operator<(const Number&) const;
        bool operator>=(const Number&) const;
        bool operator<=(const Number&) const;
    private:
        Type type;                 // Number Type
        // bool sign;                  // Negative sign


        // Fraction Exception
        class FractionException : public std::runtime_error {
        public:
            enum class ErrorType {
                // Indicates that the result of an arithmetic operation is numerically
                // too large to be represented as a finite fraction in the positive direction.
                // This typically occurs due to an overflow in underlying unsigned long long
                // arithmetic (e.g., ULLONG_MAX + 1) or signed arithmetic positive overflow.
                // Should be interpreted as Positive Infinity (+Inf).
                OVERFLOW_POSITIVE,

                // Indicates that the result of an arithmetic operation is numerically
                // too large (i.e., too negative) to be represented as a finite fraction.
                // This typically occurs due to an underflow in unsigned long long arithmetic
                // (e.g., 0 - 1) or signed arithmetic negative overflow.
                // Should be interpreted as Negative Infinity (-Inf).
                OVERFLOW_NEGATIVE,

                // Indicates a division operation where the denominator is zero but the numerator is non-zero (n/0).
                // Should be interpreted as Infinity (sign determined by numerator's sign).
                DIVIDE_BY_ZERO,

                // Indicates an indeterminate form, typically 0/0.
                // Should be interpreted as Not a Number (NaN) or Undefined.
                INDEFINITE_FORM

                // enum class ErrorType descriptions wrote by Google-Gemini
            };
            ErrorType type;
            FractionException(ErrorType t, const std::string& msg) : std::runtime_error(msg), type(t) {}
        };
        // Number value as Fraction
        // 18,446,744,073,709,551,615
        class Fraction {
        private:
            bool sign;                                  // negative sign
            unsigned long long num, den;  // value num/den

        public:

            template <typename N_TYPE, typename D_TYPE, typename = std::enable_if_t<std::is_integral_v<N_TYPE> && std::is_integral_v<D_TYPE>>>
            // Constructor
            Fraction(N_TYPE n = 0, D_TYPE d = 1) {
                // determine the negative sign
                this->sign = ((n < 0) != (d < 0));

                //
                unsigned long long t_num_abs, t_den_abs;
                if constexpr (std::is_signed_v<N_TYPE>) {
                    t_num_abs = static_case<unsigned long long>(std::abs(static_cast<long long>(n)));
                } else {
                    t_num_abs = static_case<unsigned long long>(n);
                }
                if constexpr (std::is_signed_v<D_TYPE>) {
                    t_den_abs = static_case<unsigned long long>(std::abs(static_cast<long long>(d)));
                } else {
                    t_den_abs = static_case<unsigned long long>(d);
                }

                this->num = t_num_abs;
                this->den = t_den_abs;

                this->normalize();
            };


            // Constructor using std::string
            // sample: "1/3"
            Fraction(std::string s = "0/1");

            // double to_double() const; // deleted
            std::string to_string() const;

            // determine whether the Number is Negative
            bool is_negative() const { return this->sign; };

            // Simplify the fraction
            void normalize();
            Fraction operator-() const;

            // Take the reciprocal                  // deleting...
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

        /**
         * Number Value
         * <Fraction>Real + <Fraction>Imaginary
         */
        std::complex<Fraction> values;
    };

    // get GCD
    template <typename T>
    T get_gcd(const T x, const T y) {
        static_assert(std::is_integral_v<T>, "get_gcd can only be used with integral types.");
        T a, b;
        if constexpr (std::is_signed_v<T>) {
            a = std::abs(x);
            b = std::abs(y);
        } else {
            a = x;
            b = y;
        }
        while (b != 0)
        {
            T r = a % b;
            a = b;
            b = r;
        }
        return a;
    };
    // get LCM
    template <typename T>
    T get_lcm(const T x, const T y) {
        static_assert(std::is_integral_v<T>, "get_lcm can only be used with integral types.");
        if (x == 0 || y == 0) {
            return 0;
        }
        T a, b;
        if constexpr (std::is_signed_v<T>) {
            a = std::abs(x);
            b = std::abs(y);
        } else {
            a = x;
            b = y;
        }
        return x / get_gcd(x, y) * y;
    };

    class Array {
    protected:
        unsigned long long length;
    public:
    private:
    };

    class Matrix
    {
    protected:
        unsigned long long m, n;
    public:
    private:
    };
};