#include "Complex.hpp"
#include <iomanip>

Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double x, double y) : re(x), im(y) {}

double Complex::GetRe() const { return re; }
double Complex::GetIm() const { return im; }
void Complex::SetRe(double x) { re = x; }
void Complex::SetIm(double y) { im = y; }
void Complex::Set(double x, double y) { re = x; im = y; }

Complex Complex::Add(const Complex& z) const {
    return Complex(re + z.re, im + z.im);
}
Complex Complex::Sub(const Complex& z) const {
    return Complex(re - z.re, im - z.im);
}
Complex Complex::Mult(const Complex& z) const {
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}
Complex Complex::Div(const Complex& z) const {
    double denom = z.re * z.re + z.im * z.im;
    double new_re = (re * z.re + im * z.im) / denom;
    double new_im = (im * z.re - re * z.im) / denom;
    return Complex(new_re, new_im);
}

double Complex::Abs() const {
    return std::hypot(re, im);
}

double Complex::Arg() const {
    return std::atan2(im, re);
}

void Complex::Print() const {
    std::cout << re;
    if (im >= 0) std::cout << "+";
    std::cout << "i*" << im << std::endl;
}

void Complex::TrigPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << "*(" << "cos" << phi << " + i sin" << phi << ")" << std::endl;
}

void Complex::ExpPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << "*e^(" << "i" << phi << ")" << std::endl;
}
