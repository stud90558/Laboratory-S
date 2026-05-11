#include <iostream>
#include "Bell.hpp"

int main() {
    Bell b;
    for (int i = 0; i < 6; ++i) {
        std::cout << b.sound();
        if (i < 5) std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}

