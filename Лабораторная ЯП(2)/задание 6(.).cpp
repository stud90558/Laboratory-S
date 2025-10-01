// задание 6(.).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b, h;
    cin >> a >> b >> h;

    for (double x = 0.1;x <= 1;x += 0.1) {
        double s = 0;
        for (int i = 0;;i++) {
            int fc = 1;
            for (int j = 2;j <= 1;j++) {
                fc *= j;
            }
            double si = ((2 * i + 1) * pow(x, 2 * i)) / fc;
            s += si;
            if (si < 0.0001)
                break;
        }
        double y = (1 + 2 * x / x) * exp(x * x);
        cout << s << "|" << y << endl;
    }
    return 0;
}


