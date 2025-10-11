// Задание 2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;

    for (int i = 1;i <= n;i++)
        result *= i;
    return result;
    
}
int main()
{
    int m, n;
    setlocale(LC_ALL, "ru");
    cout << "Ввкдите переменные m, n " << endl;
    cin >> m >> n;
    unsigned long long sum = 0;
    for (int i = m;i <= n;i++) {
        if (i % 2 == 0) {
            sum += factorial(i);
        }
    }
    
    cout << sum << endl;
    return 0;
}


