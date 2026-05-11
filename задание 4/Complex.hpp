#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>
#include <string>

class Complex {
public:
    // constructors
    Complex();
    Complex(double x, double y);

    // getters / setters
    double GetRe() const;
    double GetIm() const;
    void SetRe(double x);
    void SetIm(double y);
    void Set(double x, double y);

    // basic ops
    Complex Add(const Complex& z) const;
    Complex Sub(const Complex& z) const;
    Complex Mult(const Complex& z) const;
    Complex Div(const Complex& z) const; // assume divisor != 0

    // properties / prints
    double Abs() const;
    double Arg() const; // principal value in [-pi, pi]
    void Print() const;     // re+i·im
    void TrigPrint() const; // rho*(cos phi + i sin phi)
    void ExpPrint() const;  // rho*e^{i phi}

private:
    double re;
    double im;
};

#endif 
