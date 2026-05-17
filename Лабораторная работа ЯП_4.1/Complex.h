#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    double re;
    double im;

    Complex();
    Complex(double x, double y);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);

    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;

    Complex& operator++();    // префикс
    Complex& operator--();
    Complex operator++(int);  // постфикс
    Complex operator--(int);

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    bool operator<(const Complex& rhs) const;
    bool operator>(const Complex& rhs) const;

    double abs() const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif // COMPLEX_H

