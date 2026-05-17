#pragma once
#ifndef SUMMATOR_H
#define SUMMATOR_H

class Summator {
public:
    virtual ~Summator() = default;
    // виртуальное преобразование одного элемента последовательности
    virtual long long transform(long long i) const;
    // суммирует transform(i) для i = 1..N
    long long sum(long long N) const;
};

#endif // SUMMATOR_H
