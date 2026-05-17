#include "Bird.h"
#include <iostream>

void Bird::breathe() const {
    std::cout << "Bird breathes through lungs." << std::endl;
}

void Bird::eat() const {
    std::cout << "Bird pecks at food." << std::endl;
}

void Bird::lay_eggs() const {
    std::cout << "Bird lays eggs." << std::endl;
}
