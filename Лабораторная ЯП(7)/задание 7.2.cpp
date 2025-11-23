// задание 7.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;

double tr_square(const double* a, const double* b) {
    return *a * *b / 2;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double a, b;
    cout << "Ведите стороны треугольника" << endl;
    cin >> a >> b;
    double* a_link = &a, *b_link = &b;
    cout << "Площадь треугольника:" << tr_square(a_link, b_link) << endl;

    return 0;
}


