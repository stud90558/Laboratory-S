#include "Circle.h"
#include <cmath>
#include <iomanip>
constexpr double PI = 3.14159265358979323846;


Circle::Circle(double r) {
    radius = new double(r);
}

Circle::Circle(const Circle& other) {
    radius = new double(*other.radius);
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        delete radius;
        radius = new double(*other.radius);
    }
    return *this;
}

Circle::Circle(Circle&& other) noexcept {
    radius = other.radius;
    other.radius = nullptr;
}

Circle& Circle::operator=(Circle&& other) noexcept {
    if (this != &other) {
        delete radius;
        radius = other.radius;
        other.radius = nullptr;
    }
    return *this;
}

Circle::~Circle() {
    delete radius;
}

double Circle::CalcArea() const {
    return PI * (*radius) * (*radius);
}

void Circle::Show() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Circle: radius = " << *radius
        << ", area = " << CalcArea() << std::endl;
}
