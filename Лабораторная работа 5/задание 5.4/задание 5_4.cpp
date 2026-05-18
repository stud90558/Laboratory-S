#include "polynomial.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    cout << "=== Тестирование класса Polynomial ===" << endl;

    // Создание многочленов
    vector<double> coeffs1;
    coeffs1.push_back(1);
    coeffs1.push_back(2);
    coeffs1.push_back(1); // 1 + 2x + x^2
    Polynomial<double> p1(coeffs1);

    vector<double> coeffs2;
    coeffs2.push_back(0);
    coeffs2.push_back(1);
    coeffs2.push_back(1); // 0 + x + x^2
    Polynomial<double> p2(coeffs2);

    Polynomial<double> p3(5.0); // константа 5

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;

    // Тест оператора []
    cout << "\n=== Тест оператора [] ===" << endl;
    cout << "Коэффициент p1 при степени 0: " << p1[0] << endl;
    cout << "Коэффициент p1 при степени 1: " << p1[1] << endl;
    cout << "Коэффициент p1 при степени 2: " << p1[2] << endl;
    cout << "Коэффициент p1 при степени 5: " << p1[5] << endl;

    // Тест степени
    cout << "\n=== Тест метода Degree ===" << endl;
    cout << "Степень p1: " << p1.degree() << endl;
    cout << "Степень p2: " << p2.degree() << endl;
    cout << "Степень p3: " << p3.degree() << endl;

    // Тест арифметических операций
    cout << "\n=== Тест арифметических операций ===" << endl;

    Polynomial<double> sum = p1 + p2;
    cout << "p1 + p2 = " << sum << endl;

    Polynomial<double> diff = p1 - p2;
    cout << "p1 - p2 = " << diff << endl;

    Polynomial<double> prod = p1 * p2;
    cout << "p1 * p2 = " << prod << endl;

    Polynomial<double> sum_scalar = p1 + 3.0;
    cout << "p1 + 3 = " << sum_scalar << endl;

    Polynomial<double> sum_scalar_left = 3.0 + p1;
    cout << "3 + p1 = " << sum_scalar_left << endl;

    Polynomial<double> mul_scalar = p1 * 2.0;
    cout << "p1 * 2 = " << mul_scalar << endl;

    Polynomial<double> mul_scalar_left = 2.0 * p1;
    cout << "2 * p1 = " << mul_scalar_left << endl;

    // Тест составных операторов
    cout << "\n=== Тест составных операторов ===" << endl;
    Polynomial<double> p4 = p1;
    p4 += p2;
    cout << "p4 = p1; p4 += p2 => p4 = " << p4 << endl;

    Polynomial<double> p5 = p1;
    p5 *= p2;
    cout << "p5 = p1; p5 *= p2 => p5 = " << p5 << endl;

    // Тест оператора сравнения
    cout << "\n=== Тест операторов сравнения ===" << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << endl;
    cout << "p1 != p2: " << (p1 != p2 ? "true" : "false") << endl;

    cout << "p3 == 5: " << (p3 == 5.0 ? "true" : "false") << endl;
    cout << "5 == p3: " << (5.0 == p3 ? "true" : "false") << endl;
    cout << "p3 != 5: " << (p3 != 5.0 ? "true" : "false") << endl;

    vector<double> coeffs6;
    coeffs6.push_back(1);
    coeffs6.push_back(2);
    coeffs6.push_back(1);
    Polynomial<double> p6(coeffs6);
    cout << "p1 == p6: " << (p1 == p6 ? "true" : "false") << endl;

    // Тест вычисления значения в точке
    cout << "\n=== Тест оператора () ===" << endl;
    double x = 2.0;
    cout << "p1(2) = " << p1(x) << endl;
    cout << "p2(2) = " << p2(x) << endl;
    cout << "p3(2) = " << p3(x) << endl;

    // Тест с целыми числами
    cout << "\n=== Тест с целыми числами ===" << endl;
    vector<int> intCoeffs;
    intCoeffs.push_back(1);
    intCoeffs.push_back(3);
    intCoeffs.push_back(3);
    intCoeffs.push_back(1); // (x+1)^3
    Polynomial<int> pint(intCoeffs);
    cout << "pint = " << pint << endl;
    cout << "pint(2) = " << pint(2) << endl;

    // Тест с нулевыми коэффициентами
    cout << "\n=== Тест с нулевыми коэффициентами ===" << endl;
    vector<double> coeffsWithZeros;
    coeffsWithZeros.push_back(1);
    coeffsWithZeros.push_back(0);
    coeffsWithZeros.push_back(0);
    coeffsWithZeros.push_back(2);
    coeffsWithZeros.push_back(0); // 1 + 0x + 0x^2 + 2x^3 + 0x^4
    Polynomial<double> p7(coeffsWithZeros);
    cout << "p7 = " << p7 << endl;
    cout << "Степень p7: " << p7.degree() << endl;

    cout << "\n=== Все тесты пройдены! ===" << endl;

    return 0;
}