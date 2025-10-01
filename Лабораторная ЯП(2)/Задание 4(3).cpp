// Задание 4(3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{

    int a = 1;
    do{
        if (a % 5 == 0) {
            cout << "fuzz" << endl;
        }
        else if (a % 7 == 0) {
            cout << "buzz" << endl;
        }
        else if (a % 5 == 0 && a % 7 == 0) {
            cout << "fuzzbuzz" << endl;
        }
        else {
            cout << a << endl;
        }
        a++;
    } while (a <= 500);

    return 0;
}