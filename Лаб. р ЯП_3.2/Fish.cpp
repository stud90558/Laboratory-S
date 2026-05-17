#include "Fish.h"
#include <iostream>

void Fish::breathe() const {
    std::cout << "Fish breathes through gills." << std::endl;
}

void Fish::eat() const {
    std::cout << "Fish eats small organisms or food in water." << std::endl;
}

void Fish::swim() const {
    std::cout << "Fish is swimming." << std::endl;
}
