// Задание 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (double x = -2.0;x <= 2;x += 0.5) {
		double y = -2.4 * x * x + 5 * x - 3; {
			cout << x << "|" <<y << endl;
		}
	}
	return 0;
}

