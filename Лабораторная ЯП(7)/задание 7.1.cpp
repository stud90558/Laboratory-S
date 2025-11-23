// задание 7.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    double num;       
   
    double* ptr = &num;      
    *ptr = 100;             
   
   double* ptr2 = ptr;     
    *ptr2 = 200;            

    cout << "Адрес ptr: " << ptr << " значение: " << *ptr << endl;
    cout << "Адрес ptr2: " << ptr2 << " значение: " << *ptr2 << endl;

    return 0;
}

