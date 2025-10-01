// Задание 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int a = 1;a <= 19;a += 3) {
        double f = (3 + double(a)) /( (a - 4) * (a - 4));
        cout << f <<endl;
    }
    return 0;
}


