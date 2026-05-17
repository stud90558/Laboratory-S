#include "FlyingBird.h"
#include <iostream>

void FlyingBird::breathe() const {
    std::cout << "FlyingBird breathes deeply to sustain flight." << std::endl;
}

void FlyingBird::eat() const {
    std::cout << "FlyingBird eats to gain energy for flying." << std::endl;
}

void FlyingBird::fly() const {
    std::cout << "FlyingBird is flying." << std::endl;
}
