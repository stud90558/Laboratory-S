#pragma once
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Figure.h"

class Cylinder {
private:
    double* height;
public:
    explicit Cylinder(double h = 0.0);
    Cylinder(const Cylinder& other);
    Cylinder& operator=(const Cylinder& other);
    Cylinder(Cylinder&& other) noexcept;
    Cylinder& operator=(Cylinder&& other) noexcept;
    ~Cylinder();

    double Volume(const Figure& base) const;
    void ShowVolume(const Figure& base) const;
    double GetHeight() const;
};

#endif // CYLINDER_H
