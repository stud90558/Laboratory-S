// задание 1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

float min(vector <float> array) {
	float min = array[0];
	for (int a = 1;a < array.size();a++) {
		if (array[a] < min) {
			min = array[a];
		}
	}
	return min;
}
float max(vector <float> array) {
	float max = array[0];
	for (int b = 1;b < array.size();b++) {
		if (array[b] > max) {
			max = array[b];
		}
	}
	return max;
}
vector <float> ch(vector <float> array) {
	int indmax = 0;
	int indmin = 0;
	for (int i = 1;i < array.size();i++) {
		if (array[i] < array[indmin])
			indmin = i;
		if (array[i] > array[indmax])
			indmax = i;
	}
	swap(array[indmin], array[indmax]);
	return array;

}
float different(vector<float> array) {
	int dif = 0;
	for (int a = 0;a < array.size();a++) {
		bool stop = false;
		for (int i = 0;i < array.size();i++) {
			if (array[a] == array[i] && i != a) {
				stop = true;
				break;
			}
		}
		if (!stop)
			dif++;
	}
	for (int i = 0;i < array.size();i++) {
		bool presence = false;
		for (int y = 0;y < array.size();y++) {
			if (array[i] == array[y]) {
				presence = true;
				break;
			}
		}
		if (presence)
			continue;
		int p = 1;
		for (int d = i + 1;d < array.size();d++) {
			if (array[d] == array[i])
				p++;
		}
		cout << array[i] << "встречается " << p << "раз" << endl;
	}
	return dif;
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
	float MIN = min(array);
	cout << "минимальный элемент: " << MIN << endl;
	float MAX = max(array);
	cout << "максимальный элемент: " << MAX << endl;

	vector <float> new_array = ch(array);
	cout << "новый массив" << endl;
	for (float i : new_array) {
		cout << i << " " << endl;
	}
	cout << "Каличество различных эл. в массиве: " << different(array) << endl;
}

