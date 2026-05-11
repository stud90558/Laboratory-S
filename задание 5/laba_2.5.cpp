#include <iostream>
#include "Stock.hpp"

int main() {
    Stock s;

    s.Add(10, 50); // id 0
    s.Add(5, 20); // id 1
    s.Add(15, 30); // id 2
    s.Add(10, 60); // id 3
    s.Add(20, 40); // id 4

    std::cout << "GetByW(10) -> " << s.GetByW(10) << " (ожидается 4)\n";
    std::cout << "GetByW(10) -> " << s.GetByW(10) << " (ожидается 3)\n";
    std::cout << "GetByV(30) -> " << s.GetByV(30) << " (ожидается 2)\n";
    std::cout << "GetByV(100) -> " << s.GetByV(100) << " (ожидается -1)\n";
    std::cout << "GetByW(1) -> " << s.GetByW(1) << " (ожидается 1 or 0)\n";
    std::cout << "GetByV(10) -> " << s.GetByV(10) << " (ожидается remaining id or -1)\n";

    return 0;
}

