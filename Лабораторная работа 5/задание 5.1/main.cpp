#include <iostream>
#include <string>
#include "contains.h"
using namespace std;

int main() {
    size_t n1 = 5;
    int* a = new int[n1] {1, 2, 3, 4, 5};
    cout << "contains 3 in int array: " << (contains(3, a, n1) ? "true" : "false") << '\n';
    cout << "contains 7 in int array: " << (contains(7, a, n1) ? "true" : "false") << '\n';
    delete[] a;

   
    size_t n2 = 4;
    double* b = new double[n2] {1.1, 2.2, 3.3, 4.4};
    cout << "contains 2.2 in double array: " << (contains(2.2, b, n2) ? "true" : "false") << '\n';
    cout << "contains 5.5 in double array: " << (contains(5.5, b, n2) ? "true" : "false") << '\n';
    delete[] b;

    
    size_t n3 = 3;
    string* s = new string[n3]{ "apple", "banana", "cherry" };
    cout << "contains \"banana\" in string array: " << (contains(std::string("banana"), s, n3) ? "true" : "false") << '\n';
    cout << "contains \"orange\" in string array: " << (contains(std::string("orange"), s, n3) ? "true" : "false") << '\n';
    delete[] s;

    return 0;
}

