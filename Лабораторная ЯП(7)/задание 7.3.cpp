// задание 7.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;

double& max(double& a, double& b, double& c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c) {
        return b;
    }
    else
        return c;
}
void average_max(double& a, double& b, double& c) {
    double average = (a + b + c) / 3;
    max(a, b, c) = average;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double a, b, c;
    cout << "Введите 3 числа " << endl;
    cin >> a >> b >> c;
    average_max(a, b, c);
    cout << "Замена: " << a << " " << b << " " << c << " " << endl;
    return 0;
}

