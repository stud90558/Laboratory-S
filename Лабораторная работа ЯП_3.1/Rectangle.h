#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double* width;
    double* height;
public:
    Rectangle(double w = 0.0, double h = 0.0);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() override;

    double CalcArea() const override;
    void Show() const override;
};

#endif // RECTANGLE_H
