#include <iostream>
#include "Rational.h"

int main() {
    Rational a(1, 2);
    Rational b(3, 4);

    Rational c = a + b; // 5/4
    std::cout << c.Numerator() << "/" << c.Denominator() << "\n";

    Rational d = a - 1; // 1/2 - 1 = -1/2
    std::cout << d.Numerator() << "/" << d.Denominator() << "\n";

    Rational e = 2 * b; // 3/2
    std::cout << e.Numerator() << "/" << e.Denominator() << "\n";

    Rational f = -a; // -1/2
    std::cout << f.Numerator() << "/" << f.Denominator() << "\n";

    a += b; // a = 5/4
    std::cout << a.Numerator() << "/" << a.Denominator() << "\n";

    Rational zero(0, 5); // приведётся к 0/1
    std::cout << zero.Numerator() << "/" << zero.Denominator() << "\n";

    try {
        Rational invalid(1, 0);
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Caught: " << ex.what() << "\n";
    }

    return 0;
}
