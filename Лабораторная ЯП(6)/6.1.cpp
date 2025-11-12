// 6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int n, m;
    cout << "Введите кол-во четных чисел для записи (n): " << endl;
    cin >> n;
    cout << "Введите кол-во чисел для чтения (m): " << endl;
    cin >> m;
    if (n <= 0 && m <= 0) {
        cout << "n и m должны быть положительными числами " << endl;
        return 1;
    }

    ofstream out_File("numbers.txt");
    if (!out_File) {
        cerr << "Ошибка при создании файла " << endl;
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        out_File << 2 * i << " ";
    }
    out_File.close();

    ifstream in_File("numbers.txt");
    if (!in_File) {
        cerr << "Ошибка при открытии файла " <<endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    for (int i = 0; i < m && in_File >> num; ++i) {
        numbers.push_back(num);
    }
    in_File.close();
    
    cout << "Прочитанные числа: " << endl;
    for (int val : numbers) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

