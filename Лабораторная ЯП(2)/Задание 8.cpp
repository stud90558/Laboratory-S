// Задание 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a = 1;
    int b = 1;
    int n = 15;
    int i;
    cout << a << "" << b << endl;
    for (int i = 2;i < n;i++) {
        int a1 = (3 * b + 2 * a);
        int b1 = (2 * a + b);
        cout << a1 << "" << b1 << endl;

        a = a1;
        b = b1;
    }
}


