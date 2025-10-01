// Задание 7(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int a = 1;
    do {
        if (a == 4) {
            cout << a << endl;
        }
        else {
            double f = 3 + (double)a / ((a - 4) * (a - 4));
            cout << f << endl;
        }
        a += 3;
    } 
    while (a <= 19);
    return 0;
}


