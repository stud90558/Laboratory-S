#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
using namespace std;

struct Film {
    string title; // название фильма (строковое поле)
    string director; // режиссёр
    int year; // год выпуска (числовое поле)
    double rating; // рейтинг (числовое поле)
    int duration; // продолжительность (в мин.)
};

// Функции для работы с массивом фильмов
bool readFilmsFromFile(const string& filename,vector<Film>& films);
void printFilms(const vector<Film>& films);
void insertionSortByYearDesc(vector<Film>& films); // по году (убывание)
void insertionSortByTitleAsc(vector<Film>& films); // по названию (возрастание)

#endif
