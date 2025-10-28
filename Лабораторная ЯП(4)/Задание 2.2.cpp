// Задание 2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int suml(vector<int>& array) {
    int lastind = -1;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > 0) {
            lastind = i;
        }
    }

    if (lastind == -1) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < lastind; i++) {
        sum += array[i];
    }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector <int> array(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int result = suml(array);

    if (result == 0) {
        cout << "В массиве нет положительных элементов или сумма равна нулю." << endl;
    }
    else {
        cout << "Сумма элементов до последнего положительного элемента: " << result << endl;
    }

    return 0;
}


