#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
private:
    double* base;
    double* height;
public:
    Triangle(double b = 0.0, double h = 0.0);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(Triangle&& other) noexcept;
    ~Triangle() override;

    double CalcArea() const override;
    void Show() const override;
};

#endif // TRIANGLE_H
