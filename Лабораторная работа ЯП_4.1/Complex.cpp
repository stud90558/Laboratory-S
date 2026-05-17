#include "Complex.h"
#include <cmath>
#include <stdexcept>

// Конструкторы
Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double x, double y) : re(x), im(y) {}
Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

// Присваивание
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

// Арифметика
Complex Complex::operator+(const Complex& rhs) const {
    return Complex(re + rhs.re, im + rhs.im);
}
Complex Complex::operator-(const Complex& rhs) const {
    return Complex(re - rhs.re, im - rhs.im);
}
Complex Complex::operator*(const Complex& rhs) const {
    return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
}
Complex Complex::operator/(const Complex& rhs) const {
    double denom = rhs.re * rhs.re + rhs.im * rhs.im;
    if (denom == 0.0) throw std::runtime_error("Division by zero complex number");
    double real = (re * rhs.re + im * rhs.im) / denom;
    double imag = (im * rhs.re - re * rhs.im) / denom;
    return Complex(real, imag);
}

// Инк/декременты
Complex& Complex::operator++() { ++re; ++im; return *this; }
Complex& Complex::operator--() { --re; --im; return *this; }
Complex Complex::operator++(int) { Complex tmp(*this); ++(*this); return tmp; }
Complex Complex::operator--(int) { Complex tmp(*this); --(*this); return tmp; }

// Модуль
double Complex::abs() const { return std::hypot(re, im); }

// Сравнения по модулю
bool Complex::operator==(const Complex& rhs) const {
    return std::abs(this->abs() - rhs.abs()) < 1e-12;
}
bool Complex::operator!=(const Complex& rhs) const { return !(*this == rhs); }
bool Complex::operator<(const Complex& rhs) const { return this->abs() < rhs.abs(); }
bool Complex::operator>(const Complex& rhs) const { return this->abs() > rhs.abs(); }

// Ввод/вывод
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re;
    if (c.im >= 0) os << " + " << c.im << "*i";
    else os << " - " << (-c.im) << "*i";
    return os;
}

// Простой и надёжный ввод: два числа (re im)
std::istream& operator>>(std::istream& is, Complex& c) {
    double a, b;
    if (!(is >> a >> b)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    c.re = a;
    c.im = b;
    return is;
}
