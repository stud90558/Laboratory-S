// 6.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ifstream F_min("File.txt", ios::binary); 
    int min = 10000;
    int num;

    while (F_min.read((char*)&num, sizeof(num))) {  
        if (num > 0 && num < min) {
            min = num;
        }
    }

    if (min != 10000) {
        cout << "Минимальное положительное число : " << min << endl;
    }
    else {
        cout << "Положительных чисел нет " << endl;
    }
}