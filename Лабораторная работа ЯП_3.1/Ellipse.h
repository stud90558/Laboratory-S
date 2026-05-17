#pragma once
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Figure.h"

class Ellipse : public Figure {
private:
    double* a; // semi-major
    double* b; // semi-minor
public:
    Ellipse(double a_ = 0.0, double b_ = 0.0);
    Ellipse(const Ellipse& other);
    Ellipse& operator=(const Ellipse& other);
    Ellipse(Ellipse&& other) noexcept;
    Ellipse& operator=(Ellipse&& other) noexcept;
    ~Ellipse() override;

    double CalcArea() const override;
    void Show() const override;
};

#endif // ELLIPSE_H
