#include <cmath> // For std::abs
#include <type_traits> // For std::is_integral

class Fraction {
private:
    bool is_negative; // Changed from 'sign' to be clearer
    unsigned long long num, den;

public:
    // Template constructor to accept any integral type
    template<typename N_Type, typename D_Type, typename = std::enable_if_t<std::is_integral_v<N_Type> && std::is_integral_v<D_Type>>>
    Fraction(N_Type n = 0, D_Type d = 1) {
        // Handle sign
        is_negative = ((n < 0) != (d < 0)); // XOR logic for sign. 0 is not negative.

        // Convert to absolute unsigned long long
        // Use static_cast to handle potential large integer types
        // Note: For D_Type, if d is 0, this will be handled by normalize()
        num = static_cast<unsigned long long>(std::abs(static_cast<long long>(n))); // Cast to long long first to handle large negative
        den = static_cast<unsigned long long>(std::abs(static_cast<long long>(d)));

        // Handle the 0/0 and N/0 cases immediately in the constructor by throwing
        if (den == 0) {
            if (num == 0) {
                throw Number::FractionException(Number::FractionException::ErrorType::INDEFINITE_FORM, "Fraction: 0/0 encountered.");
            } else {
                // For N/0, the sign of N determines the sign of infinity.
                // We throw a generic DIVIDE_BY_ZERO, and the Number class will decide the sign.
                // Or you could pass the sign information in the exception, e.g., DIVIDE_BY_ZERO_POSITIVE.
                throw Number::FractionException(Number::FractionException::ErrorType::DIVIDE_BY_ZERO, "Fraction: Division by zero (non-zero numerator).");
            }
        }

        normalize(); // Normalize after initialization
    }

    // You might still want a direct unsigned long long constructor for internal use
    // or very specific cases where you already have absolute unsigned values.
    // This could be private or public depending on your design.
    // Fraction(unsigned long long n_abs, unsigned long long d_abs, bool negative_sign) {
    //     is_negative = negative_sign;
    //     num = n_abs;
    //     den = d_abs;
    //     // No need to handle 0/0 or N/0 here if this is used internally after such checks
    //     // or if normalize() handles it.
    //     normalize();
    // }
};