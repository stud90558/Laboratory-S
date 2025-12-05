// задание 8.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int n, a, b;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;
    cout << "Введите границы интервала [a, b]: ";
    cin >> a >> b;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = a + rand() % (b - a + 1);
            cout << matrix[i][j] << endl;
        }
        cout << endl;
    }

    // макс. отриц в зеленой области
    int maxNeg = INT_MIN;
    int negRow = -1, negCol = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1) {
                if (matrix[i][j] < 0 && matrix[i][j] > maxNeg) {
                    maxNeg = matrix[i][j];
                    negRow = i;
                    negCol = j;
                }
            }
        }
    }

    // мин. положит. в красной области
    int minPos = INT_MAX;
    int posRow = -1, posCol = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                if (matrix[i][j] > 0 && matrix[i][j] < minPos) {
                    minPos = matrix[i][j];
                    posRow = i;
                    posCol = j;
                }
            }
        }
    }
    cout << "Максимальный отрицательный элемент в зеленой области: ";
    if (negRow != -1) {
        cout << matrix[negRow][negCol] << " на позиции (" << negRow << ", " << negCol << ")" << endl;
    }
    else {
        cout << "не найден" << endl;
    }

    cout << "Минимальный положительный элемент в красной области: ";
    if (posRow != -1) {
        cout << matrix[posRow][posCol] << " на позиции (" << posRow << ", " << posCol << ")" << endl;
    }
    else {
        cout << "не найден" << endl;
    }

    // Перестановка элементов
    if (negRow != -1 && posRow != -1) {
        swap(matrix[negRow][negCol], matrix[posRow][posCol]);
        cout << "Элементы поменяны местами" << endl;
    }
    else {
        cout << "Невозможно поменять " << endl;
    }

    cout << "Матрица после перестановки:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}

