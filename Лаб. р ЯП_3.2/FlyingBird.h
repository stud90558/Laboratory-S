#pragma once
#ifndef FLYINGBIRD_H
#define FLYINGBIRD_H

#include "Bird.h"

class FlyingBird : public Bird {
public:
    ~FlyingBird() override = default;
    void breathe() const override;
    void eat() const override;
    void fly() const;
    // lay_eggs() унаследован из Bird
};

#endif // FLYINGBIRD_H
