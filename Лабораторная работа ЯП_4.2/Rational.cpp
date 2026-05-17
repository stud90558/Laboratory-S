#include "Rational.h"

Rational::Rational(int num, int den)
    : num_(num), den_(den)
{
    if (den_ == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    normalize();
}

void Rational::normalize() {
    if (den_ < 0) {
        den_ = -den_;
        num_ = -num_;
    }
    int g = std::gcd(num_ >= 0 ? num_ : -num_, den_);
    if (g != 0) {
        num_ /= g;
        den_ /= g;
    }
    // special-case: if numerator is 0, ensure denominator is 1
    if (num_ == 0) den_ = 1;
}

int Rational::Numerator() const { return num_; }
int Rational::Denominator() const { return den_; }

Rational Rational::operator+() const { return *this; }
Rational Rational::operator-() const { return Rational(-num_, den_); }

Rational& Rational::operator+=(const Rational& other) {
    // a/b + c/d = (ad + bc) / bd
    long long n = static_cast<long long>(num_) * other.den_ + static_cast<long long>(other.num_) * den_;
    long long d = static_cast<long long>(den_) * other.den_;
    num_ = static_cast<int>(n);
    den_ = static_cast<int>(d);
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    long long n = static_cast<long long>(num_) * other.den_ - static_cast<long long>(other.num_) * den_;
    long long d = static_cast<long long>(den_) * other.den_;
    num_ = static_cast<int>(n);
    den_ = static_cast<int>(d);
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    long long n = static_cast<long long>(num_) * other.num_;
    long long d = static_cast<long long>(den_) * other.den_;
    num_ = static_cast<int>(n);
    den_ = static_cast<int>(d);
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    if (other.num_ == 0) throw std::invalid_argument("Division by zero Rational");
    long long n = static_cast<long long>(num_) * other.den_;
    long long d = static_cast<long long>(den_) * other.num_;
    if (d == 0) throw std::invalid_argument("Division leads to zero denominator");
    num_ = static_cast<int>(n);
    den_ = static_cast<int>(d);
    normalize();
    return *this;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.num_ == rhs.num_ && lhs.den_ == rhs.den_;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

// Binary operators
Rational operator+(const Rational& a, const Rational& b) {
    Rational res = a;
    res += b;
    return res;
}

Rational operator-(const Rational& a, const Rational& b) {
    Rational res = a;
    res -= b;
    return res;
}

Rational operator*(const Rational& a, const Rational& b) {
    Rational res = a;
    res *= b;
    return res;
}

Rational operator/(const Rational& a, const Rational& b) {
    Rational res = a;
    res /= b;
    return res;
}

// With int (convert int to Rational(int,1))
Rational operator+(const Rational& a, int b) { return a + Rational(b); }
Rational operator+(int a, const Rational& b) { return Rational(a) + b; }
Rational operator-(const Rational& a, int b) { return a - Rational(b); }
Rational operator-(int a, const Rational& b) { return Rational(a) - b; }
Rational operator*(const Rational& a, int b) { return a * Rational(b); }
Rational operator*(int a, const Rational& b) { return Rational(a) * b; }
Rational operator/(const Rational& a, int b) { return a / Rational(b); }
Rational operator/(int a, const Rational& b) { return Rational(a) / b; }
