// 6.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ifstream File("numbers.txt", ios::binary);
    if (!File.is_open()) {
        cerr << "Не удалось открыть файл " << endl;
        return 1;
    }

    int num;
    int sum = 0;

    while (File.read((char*)&num, sizeof(num))) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    File.close();

    cout << "Сумма четных чисел: " << sum << endl;

    return 0;
}

