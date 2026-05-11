#include "OddEvenSeparator.hpp"
#include <iostream>

OddEvenSeparator::OddEvenSeparator() = default;

void OddEvenSeparator::add_number(int n) {
    if (n % 2 == 0) evens.push_back(n);
    else odds.push_back(n);
}

void OddEvenSeparator::even() const {
    for (size_t i = 0; i < evens.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << evens[i];
    }
    std::cout << std::endl;
}

void OddEvenSeparator::odd() const {
    for (size_t i = 0; i < odds.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << odds[i];
    }
    std::cout << std::endl;
}
