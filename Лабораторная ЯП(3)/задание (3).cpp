// задание (3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int Summa(int num) {
    if (num < 0) {
        num = -num;
    }
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cin >> n;
    int maxsum, minsum, numb;
    int maxnumb, minnumb;
    cin >> numb;
    maxsum = minsum = Summa(numb);
    minnumb = maxnumb = numb;
    for (int i = 1; i < n;i++) {
        cin >> numb;
        int f = Summa(numb);
        if (f < minsum) {
            minsum = f;
            minnumb = numb;
        }
        if (f > maxsum) {
            maxsum = f;
            maxnumb = numb;
        }
    }
    cout << "Число с наименьшей суммой цифр: " << minnumb << endl;
    cout << "Число с наибольшей суммой цифр: " << maxnumb << endl;

    return 0;
}

