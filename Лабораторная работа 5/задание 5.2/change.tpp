#ifndef CHANGE_TPP
#define CHANGE_TPP

#include "contains.h"
#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

template<typename T>
bool change(T* a, T* b, T* arr, size_t n) {
    if (!arr || !a || !b) {
        cerr << "Ошибка: null-указатель." << endl;
        return false;
    }

    bool hasA = contains(arr, n, *a);
    bool hasB = contains(arr, n, *b);

    if (!hasA || !hasB) {
        cerr << "Ошибка: один или оба элемента отсутствуют в массиве." << endl;
        return false;
    }

    size_t idxA = n;
    size_t idxB = n;
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] == *a && idxA == n) idxA = i;
        else if (arr[i] == *b && idxB == n) idxB = i;
    }

    if (idxA == n || idxB == n) {
        cerr << "Ошибка: не удалось найти индексы элементов." << endl;
        return false;
    }

    swap(arr[idxA], arr[idxB]);
    cout << "Успех: элементы успешно поменяны местами." << endl;
    return true;
}

#endif // CHANGE_TPP
