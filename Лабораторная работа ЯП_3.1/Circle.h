#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double* radius;
public:
    explicit Circle(double r = 0.0);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
    Circle(Circle&& other) noexcept;
    Circle& operator=(Circle&& other) noexcept;
    ~Circle() override;

    double CalcArea() const override;
    void Show() const override;
};

#endif // CIRCLE_H
