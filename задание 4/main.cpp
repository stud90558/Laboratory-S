#include <iostream>
#include <cmath>
#include "Complex.hpp"

int main() {
    Complex z1; // 0+0i
    Complex z2(3.0, 4.0); // 3+4i

    std::cout << "z1: "; z1.Print();
    std::cout << "z2: "; z2.Print();

    std::cout << "\nGetters: re=" << z2.GetRe() << ", im=" << z2.GetIm() << std::endl;
    z1.Set(1.0, -2.0);
    std::cout << "After z1.Set(1,-2): "; z1.Print();

    Complex s = z1.Add(z2);
    Complex d = z1.Sub(z2);
    Complex m = z1.Mult(z2);
    Complex q = z1.Div(z2);

    std::cout << "\nAddition (z1+z2): "; s.Print();
    std::cout << "Subtraction (z1-z2): "; d.Print();
    std::cout << "Multiplication (z1*z2): "; m.Print();
    std::cout << "Division (z1/z2): "; q.Print();

   
    std::cout << "\nFor z2:\n";
    std::cout << "Abs: " << z2.Abs() << std::endl;
    std::cout << "Arg (rad): " << z2.Arg() << std::endl;

    std::cout << "Standard form: "; z2.Print();
    std::cout << "Trigonometric form: "; z2.TrigPrint();
    std::cout << "Exponential form: "; z2.ExpPrint();

    return 0;
}
