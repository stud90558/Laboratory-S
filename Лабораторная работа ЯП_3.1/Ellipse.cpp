#include "Ellipse.h"
#include <cmath>
#include <iomanip>

constexpr double PI = 3.14159265358979323846;


Ellipse::Ellipse(double a_, double b_) {
    a = new double(a_);
    b = new double(b_);
}

Ellipse::Ellipse(const Ellipse& other) {
    a = new double(*other.a);
    b = new double(*other.b);
}

Ellipse& Ellipse::operator=(const Ellipse& other) {
    if (this != &other) {
        delete a;
        delete b;
        a = new double(*other.a);
        b = new double(*other.b);
    }
    return *this;
}

Ellipse::Ellipse(Ellipse&& other) noexcept {
    a = other.a;
    b = other.b;
    other.a = nullptr;
    other.b = nullptr;
}

Ellipse& Ellipse::operator=(Ellipse&& other) noexcept {
    if (this != &other) {
        delete a;
        delete b;
        a = other.a;
        b = other.b;
        other.a = nullptr;
        other.b = nullptr;
    }
    return *this;
}

Ellipse::~Ellipse() {
    delete a;
    delete b;
}

double Ellipse::CalcArea() const {
    return PI * (*a) * (*b);
}

void Ellipse::Show() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Ellipse: a = " << *a << ", b = " << *b
        << ", area = " << CalcArea() << std::endl;
}
