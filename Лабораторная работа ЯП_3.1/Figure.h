#pragma once
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual double CalcArea() const = 0;
    virtual void Show() const = 0;
};

using FigurePtr = std::unique_ptr<Figure>;

#endif // FIGURE_H
