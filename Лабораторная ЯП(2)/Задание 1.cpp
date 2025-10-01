// Laboratornaya_YP(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a > 0 && b % 2 == 0) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;

}
