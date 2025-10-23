// задание 1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

float max(vector <float> array) {
	float max1 = array[0];
	float max2 = array[0];
	for (int b = 1;b < array.size();b++) {
		if (array[b] > max1 ) {
			max2 = max1;
			max1 = array[b];
		}
		else if (array[b] > max2 && array[b] < max1) {
			max2 = array[b];
		}
	}
	return max2;
}


int main()
{
	setlocale(LC_ALL, "ru");
	vector <float>array;
	float n;
	int h;
	cout << "Сколько чисел хотите вывести?" << endl;
	cin >> h;
	cout << "Введите числа: " << endl;
	int a = 0;
	while (a <= h) {
		cin >> n;
		array.push_back(n);
		a++;
		if (a == h)
			break;
	}
	
	float max2 = max(array);
	cout << "2 максимальный элемент: " << max2 << endl;

}


