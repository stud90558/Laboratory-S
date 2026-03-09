#include "Film.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string filename;
    cout << "Введите имя файла с данными о фильмах : ";
    getline(cin, filename);
    if (filename.empty()) {
        filename = "films.txt";
    }

    vector<Film> films;

    // Защита от дурака
    if (!readFilmsFromFile(filename, films)) {
       cerr << "Программа завершена." << endl;
        return 1;
    }

    // Контрольный вывод считанных данных
    cout << " Исходный список фильмов ";
    printFilms(films);

    if (films.empty()) {
        cout << "Нет записей для сортировки.";
        return 0;
    }

    // Сортировка по году 
    vector<Film> filmsByYear = films;
    insertionSortByYearDesc(filmsByYear);
    cout << " После сортировки по ГОДУ ";
    printFilms(filmsByYear);

    // Сортировка по названию 
    vector<Film> filmsByTitle = films;
    insertionSortByTitleAsc(filmsByTitle);
    cout << " После сортировки по НАЗВАНИЮ ";
    printFilms(filmsByTitle);

    return 0;
}