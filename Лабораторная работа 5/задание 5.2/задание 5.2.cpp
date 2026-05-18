#include <iostream>
#include <string>
#include "change.h"
#include "contains.h"

using namespace std;

template<typename T>
void printArray(const T* arr, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i];
        if (i + 1 < n) cout << ", ";
    }
    cout << '\n';
}

int main() {
    setlocale(LC_ALL, "ru");
    int iarr[] = { 1, 2, 3, 4, 5 };
    size_t in = sizeof(iarr) / sizeof(iarr[0]);
    int a1 = 2, b1 = 4;
    cout << "Int до: ";
    printArray(iarr, in);
    change(&a1, &b1, iarr, in);
    cout << "Int после: ";
    printArray(iarr, in);
    cout << '\n';

    double darr[] = { 1.1, 2.2, 3.3, 4.4 };
    size_t dn = sizeof(darr) / sizeof(darr[0]);
    double a2 = 1.1, b2 = 4.4;
    cout << "Double до: ";
    printArray(darr, dn);
    change(&a2, &b2, darr, dn);
    cout << "Double после: ";
    printArray(darr, dn);
    cout << '\n';

    string sarr[] = { "apple", "banana", "cherry", "date" };
    size_t sn = sizeof(sarr) / sizeof(sarr[0]);
    string a3 = "banana", b3 = "date";
    cout << "String до: ";
    printArray(sarr, sn);
    change(&a3, &b3, sarr, sn);
    cout << "String после: ";
    printArray(sarr, sn);
    cout << '\n';

    int x = 100, y = 2;
    change(&x, &y, iarr, in);

    return 0;
}

