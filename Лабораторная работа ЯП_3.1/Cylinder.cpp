#include "Cylinder.h"
#include <iostream>
#include <iomanip>

Cylinder::Cylinder(double h) {
    height = new double(h);
}

Cylinder::Cylinder(const Cylinder& other) {
    height = new double(*other.height);
}

Cylinder& Cylinder::operator=(const Cylinder& other) {
    if (this != &other) {
        delete height;
        height = new double(*other.height);
    }
    return *this;
}

Cylinder::Cylinder(Cylinder&& other) noexcept {
    height = other.height;
    other.height = nullptr;
}

Cylinder& Cylinder::operator=(Cylinder&& other) noexcept {
    if (this != &other) {
        delete height;
        height = other.height;
        other.height = nullptr;
    }
    return *this;
}

Cylinder::~Cylinder() {
    delete height;
}

double Cylinder::GetHeight() const {
    return *height;
}

double Cylinder::Volume(const Figure& base) const {
    return base.CalcArea() * (*height);
}

void Cylinder::ShowVolume(const Figure& base) const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Cylinder height = " << *height
        << ", base area = " << base.CalcArea()
        << ", volume = " << Volume(base) << std::endl;
}
