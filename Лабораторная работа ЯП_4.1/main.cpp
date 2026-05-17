#include <iostream>
#include "Complex.h"

int main() {
    setlocale(LC_ALL, "ru");
    try {
        std::cout << std::boolalpha;

        Complex a;                 // 0 + 0i
        Complex b(3, 4);           // 3 + 4i
        Complex c = b;             // копирование

        std::cout << "a = " << a << "\n";
        std::cout << "b = " << b << "\n";
        std::cout << "c (copy) = " << c << "\n";

        a = Complex(1, -2);
        std::cout << "a after = " << a << "\n";

        Complex x(1, 2), y(3, -1);
        std::cout << "x + y = " << (x + y) << "\n";
        std::cout << "x - y = " << (x - y) << "\n";
        std::cout << "x * y = " << (x * y) << "\n";
        std::cout << "x / y = " << (x / y) << "\n";

        Complex p(0, 0);
        std::cout << "p = " << p << "\n";
        std::cout << "++p = " << ++p << "\n";
        std::cout << "p++ returned = " << p++ << ", now p = " << p << "\n";
        std::cout << "--p = " << --p << "\n";
        std::cout << "p-- returned = " << p-- << ", now p = " << p << "\n";

        Complex u(3, 4), v(-5, 0), w(1, 1);
        std::cout << "u == v? " << (u == v) << "\n";
        std::cout << "u != w? " << (u != w) << "\n";
        std::cout << "w < u? " << (w < u) << "\n";
        std::cout << "v > w? " << (v > w) << "\n";

        std::cout << "\nВведите два числа: re im  ";
        Complex in;
        if (std::cin >> in) {
            std::cout << "Вы ввели: " << in << "\n";
        }
        else {
            std::cerr << "Неверный ввод\n";
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
