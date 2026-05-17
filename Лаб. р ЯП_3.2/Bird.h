#pragma once
#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    ~Bird() override = default;
    void breathe() const override;
    void eat() const override;
    void lay_eggs() const;
};

#endif // BIRD_H
