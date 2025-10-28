// Задание 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void sm(int array[], int size) {
    int h = 0; 

    for (int i = 0; i < size; i++) {
        int mod = abs(array[i]);
        if (mod < 5 || mod > 10) {
            array[h++] = array[i];
        }
    }
    for (;h < size; h++) {
        array[h] = 0;
    }
}


    int main()
    {

        setlocale(LC_ALL, "ru");
        int array[] = { 1, 5, -1, -10, -2, 3, 6.3 };
        int size = sizeof(array) / sizeof(array[0]);
        cout << "Исходный массив: " << endl;

        for (int i = 0; i < size; i++)
            cout << array[i] << " " << endl;

        sm(array, size);
        cout << "Сжатый массив: ";
        for (int i = 0; i < size; i++)
            cout << array[i] << " " << endl;

        return 0;
    }