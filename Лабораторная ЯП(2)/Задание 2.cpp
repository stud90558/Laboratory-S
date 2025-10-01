// Задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    int n;
    cin >> n;

    int first = n % 10;
    int second = (n % 100) / 10;
    int third = (n % 1000) / 100;
    int forth = n / 1000;

    int mirror = first * 1000 + second * 100 + third * 10 + forth;
    if (mirror == n)
        cout << "palindrom" << endl;
    else
        cout << "no" << endl;
   
    return 0;

}

