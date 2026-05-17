#pragma once
#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    ~Fish() override = default;
    void breathe() const override;
    void eat() const override;
    void swim() const;
};

#endif // FISH_H
