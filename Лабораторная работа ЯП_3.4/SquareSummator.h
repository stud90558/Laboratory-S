#pragma once
#ifndef SQUARESUMMATOR_H
#define SQUARESUMMATOR_H

#include "Summator.h"

class SquareSummator : public Summator {
public:
    virtual long long transform(long long i) const override;
};

#endif // SQUARESUMMATOR_H
