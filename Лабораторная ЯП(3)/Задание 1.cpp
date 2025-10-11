// Задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

int simple(int num) {
	if (num <= 1)
		return false;
	for (int i=2;i*i<=num;i++){
		if (num % i == 0)
			return false;
		else
			return true;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите диапазон: " <<endl;
	int a, b;
	cin >> a >> b;
	int c = a;
	int d = b;
	cout << "простые числа в диапозоне от" << a << "до" << b << endl;
	for (a;a <= b;a++) {
		if (simple(a))
			cout << a << endl;
	}
	cout << "дружественные числа:" << endl;
	for (c;c <= d;c++) {
		if (simple(c) && simple(c + 2))
			cout << c << " " << c + 2 << endl;
	}
	return 0;

}

