#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <numeric> // std::gcd
#include <stdexcept>

class Rational {
public:
    // Конструктор: числитель по умолчанию 0, знаменатель по умолчанию 1
    Rational(int num = 0, int den = 1);

    // Доступ к несократимому представлению (знаменатель > 0)
    int Numerator() const;
    int Denominator() const;

    // Унарные операторы
    Rational operator+() const;
    Rational operator-() const;

    // Операторы присваивания с операцией
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // Сравнение
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator!=(const Rational& lhs, const Rational& rhs);

    // Бинарные операторы реализованы как дружественные не-члены ниже (в Rational.cpp)
private:
    int num_;
    int den_;

    void normalize(); // привести к несократимому виду с den_ > 0
};

// Бинарные операторы (дружественные не-члены)
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);

// Операторы с int (по обе стороны)
Rational operator+(const Rational& a, int b);
Rational operator+(int a, const Rational& b);
Rational operator-(const Rational& a, int b);
Rational operator-(int a, const Rational& b);
Rational operator*(const Rational& a, int b);
Rational operator*(int a, const Rational& b);
Rational operator/(const Rational& a, int b);
Rational operator/(int a, const Rational& b);

#endif 
