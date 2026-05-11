#include <iostream>
#include "OddEvenSeparator.hpp"

int main() {
    OddEvenSeparator s;
    int nums[] = { 5, 2, 7, 8, 4, 3, 10 };
    for (int n : nums) s.add_number(n);

    std::cout << "Even: ";
    s.even(); // чет вывод: 2 8 4 10

    std::cout << "Odd: ";
    s.odd();  //  нечет вывод: 5 7 3

    return 0;
}

