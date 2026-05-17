#include "Rectangle.h"
#include <iomanip>

Rectangle::Rectangle(double w, double h) {
    width = new double(w);
    height = new double(h);
}

Rectangle::Rectangle(const Rectangle& other) {
    width = new double(*other.width);
    height = new double(*other.height);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        delete width;
        delete height;
        width = new double(*other.width);
        height = new double(*other.height);
    }
    return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept {
    width = other.width;
    height = other.height;
    other.width = nullptr;
    other.height = nullptr;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        delete width;
        delete height;
        width = other.width;
        height = other.height;
        other.width = nullptr;
        other.height = nullptr;
    }
    return *this;
}

Rectangle::~Rectangle() {
    delete width;
    delete height;
}

double Rectangle::CalcArea() const {
    return (*width) * (*height);
}

void Rectangle::Show() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Rectangle: width = " << *width
        << ", height = " << *height
        << ", area = " << CalcArea() << std::endl;
}
