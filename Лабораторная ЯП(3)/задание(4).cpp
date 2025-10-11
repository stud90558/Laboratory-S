// задание(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;

const double PI= 3.14159265358979323846;

double S_circle(double r) {
	return PI * r * r;
}
double S_rectangle(double a, double b) {
	return a*b;
}
double S_rect_triangle(double h, double n) {
	return h * n * 0.5;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	while (true) {
		cout << "1.круг/2.прямоугольник/3.прямоугольный треугольник" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		double a, b;
		if (choice == 1)
			cout << "радиус: " << endl;
			cin >> a;
			if (a < 0)
				cout << "ошибка" << endl;
			else
				cout << "площадь= " << PI * a * a << endl;
		if (choice == 2)
			cout << "длина и ширина" << endl;
			cin >> a >> b;
			if (a < 0 || b < 0)
				cout << "ошибка" << endl;
			else
				cout << "площадь= " << a * b << endl;
		if (choice == 3)
			cout << "основание и высота" << endl;
			cin >> a >> b;
			if (a < 0 || b < 0)
				cout << "ошибка" << endl;
			else
				cout << "площадь= " << 0.5 * a * b << endl;
	
	}
	cout << "выход" << endl;

	return 0;
}

	

