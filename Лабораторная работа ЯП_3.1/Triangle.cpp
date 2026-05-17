#include "Triangle.h"
#include <iomanip>

Triangle::Triangle(double b, double h) {
    base = new double(b);
    height = new double(h);
}

Triangle::Triangle(const Triangle& other) {
    base = new double(*other.base);
    height = new double(*other.height);
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        delete base;
        delete height;
        base = new double(*other.base);
        height = new double(*other.height);
    }
    return *this;
}

Triangle::Triangle(Triangle&& other) noexcept {
    base = other.base;
    height = other.height;
    other.base = nullptr;
    other.height = nullptr;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        delete base;
        delete height;
        base = other.base;
        height = other.height;
        other.base = nullptr;
        other.height = nullptr;
    }
    return *this;
}

Triangle::~Triangle() {
    delete base;
    delete height;
}

double Triangle::CalcArea() const {
    return 0.5 * (*base) * (*height);
}

void Triangle::Show() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Triangle: base = " << *base << ", height = " << *height
        << ", area = " << CalcArea() << std::endl;
}
