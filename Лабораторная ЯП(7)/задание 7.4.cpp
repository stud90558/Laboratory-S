// задание 7.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double* Max(double& n1, double& n2, double& n3) {
    if (n1 >= n2 && n1 >= n3)
        return &n1;
    else if (n2 >= n1 && n2 >= n3) {
        return &n2;
    }
    else
        return &n3;
}
int main()
{
    setlocale(LC_ALL, "ru");
    double n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    double* max = Max(n1, n2, n3);
    double average = (n1 + n2 + n3) / 3;
    *max = average;
    cout << "После: " << n1<< " " << n2 << " "<< n3 << endl;
}


