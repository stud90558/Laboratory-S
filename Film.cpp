#include "Film.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;


// Чтение фильмов из файла. Формат строки: название|режиссёр|год|рейтинг|длительность
bool readFilmsFromFile(const string& filename, vector<Film>& films) {
   ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename <<endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Film film;

        try {
            getline(ss, film.title, '|');
            getline(ss, film.director, '|');

            getline(ss, token, '|');
            film.year = stoi(token);

            getline(ss, token, '|');
            film.rating = stod(token);

            getline(ss, token, '|');
            film.duration = stoi(token);
        }
        catch (...) {
            cerr << "Ошибка парсинга строки: " << line << endl;
            continue;
        }

        films.push_back(film);
    }

    file.close();
    return true;
}

// Вывод таблицы фильмов на экран
void printFilms(const vector<Film>& films) {
    if (films.empty()) {
        cout << "Нет данных для отображения.";
        return;
    }

    printf("%-30s %-20s %-6s %-8s %-10s",
        "Название", "Режиссёр", "Год", "Рейтинг", "Длит.");
    cout << string(80, '-') << endl;

    for (const auto& f : films) {
        printf("%-30s %-20s %-6d %-8.1f %-10d\n",
            f.title.c_str(), f.director.c_str(), f.year, f.rating, f.duration);
    }
    cout << endl;
}

// Сортировка вставками по году выпуска (по убыванию)
void insertionSortByYearDesc(vector<Film>& films) {
    int n = films.size();
    for (int i = 1; i < n; ++i) {
        Film key = films[i];
        int j = i - 1;
        // Сортировка по убыванию (более поздние годы — выше)
        while (j >= 0 && films[j].year < key.year) {
            films[j + 1] = films[j];
            --j;
        }
        films[j + 1] = key;
    }
}

// Вспомогательная функция для сравнения строк без учёта регистра
bool compareTitlesIgnoreCase(const string& a, const string& b) {
    size_t len =min(a.size(), b.size());
    for (size_t i = 0; i < len; ++i) {
        char ca = tolower(static_cast<unsigned char>(a[i]));
        char cb = tolower(static_cast<unsigned char>(b[i]));
        if (ca != cb) return ca < cb;
    }
    return a.size() < b.size();
}

// Сортировка вставками по названию 
void insertionSortByTitleAsc(vector<Film>& films) {
    int n = films.size();
    for (int i = 1; i < n; ++i) {
        Film key = films[i];
        int j = i - 1;
        while (j >= 0 && compareTitlesIgnoreCase(films[j].title, key.title)) {
            films[j + 1] = films[j];
            --j;
        }
        films[j + 1] = key;
    }
}