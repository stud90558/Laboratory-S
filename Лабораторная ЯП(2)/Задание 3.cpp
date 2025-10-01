// Задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a < 0 || b < 0 || c < 0 || a >= 30000 || b >= 30000 || c  >= 30000) {
        cout << "UNDEFINED" << endl;
        return -1;
    }

    if (a + b > c || b + c > a || c + a > b) {
        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    if (a + b < c || c + b < a || a + c < b) {
        cout << "UNDEFINED" << endl;
    }
}

