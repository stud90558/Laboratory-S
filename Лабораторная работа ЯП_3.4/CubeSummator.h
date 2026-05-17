#pragma once
#ifndef CUBESUMMATOR_H
#define CUBESUMMATOR_H

#include "Summator.h"

class CubeSummator : public Summator {
public:
    virtual long long transform(long long i) const override;
};

#endif // CUBESUMMATOR_H
