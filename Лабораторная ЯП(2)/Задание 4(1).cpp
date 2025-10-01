// Задание 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    for (int i = 1;i <= 500;i += 1) {
        if (i % 5 == 0) {
            cout << "fuzz" << endl;
        }
        else if (i % 7 == 0) {
            cout << "buzz" << endl;
        }
        else if (i % 5 == 0 && i % 7 == 0) {
            cout << "fuzzbuzz" << endl;
        }
        else {
            cout << i << endl;
        }
    }
    return 0;
}

