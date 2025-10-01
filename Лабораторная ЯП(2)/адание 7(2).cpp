// адание 7(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    while (a <= 19) {
        double f = 3 + double(a) / ((a - 4)*(a - 4));
        cout << f << endl;
        a += 3;
    }
    return 0;
}

