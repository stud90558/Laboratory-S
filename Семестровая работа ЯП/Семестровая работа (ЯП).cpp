// Семестровая работа (ЯП).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Magazine {
    string title;        // Название журнала 
    int year;           // Год издания
    double price;       // Цена
    int pages;          // Кол-во страниц
    int issue;          // Номер выпуска
};

// Ф-ция для вывода журнала
void printMagazine(const Magazine& mag) {
    cout << "Название: " << mag.title << endl;
    cout << "Год: " << mag.year << endl;
    cout << "Цена: " << mag.price << " руб." << endl;
    cout << "Страниц: " << mag.pages << endl;
    cout << "Выпуск: " << mag.issue << endl;
}

// Ф-ция для ввода данных журнала с клав.
Magazine inputMagazine() {
    Magazine mag;

    cout << "Введите название журнала: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, mag.title);

    cout << "Введите год издания: ";
    cin >> mag.year;

    cout << "Введите цену (руб.): ";
    cin >> mag.price;

    cout << "Введите количество страниц: ";
    cin >> mag.pages;

    cout << "Введите номер выпуска: ";
    cin >> mag.issue;

    return mag;
}

int main() {
    Magazine* magazines = nullptr; // Динамический массив
    int count = 0;                 // Журналов в массиве
    int capacity = 0;              // Вместимость массива

    int choice;
    bool running = true;

    setlocale(LC_ALL, "Russian");

    while (running) {
        cout << "\n=== ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ ===" << endl;
        cout << "1. Вывести текущий список на экран" << endl;
        cout << "2. Добавить в список новый элемент" << endl;
        cout << "3. Удалить из списка существующий элемент" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Сохранить список в файл" << endl;
        cout << "6. Загрузить список из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice) {
        case 1: { 
            if (count == 0) {
                cout << "Список пуст" << endl;
            }
            else {
                cout << "\n=== СПИСОК ЖУРНАЛОВ (" << count << " шт.) ===" << endl;
                for (int i = 0; i < count; i++) {
                    cout << "Журнал #" << i + 1 << ":" << endl;
                    printMagazine(magazines[i]);
                }
            }
            break;
        }

        case 2: { // новый элемент
            if (count >= capacity) {
                // увеличение емкости массива
                int newCapacity;
                if (capacity == 0) {
                    newCapacity = 1;
                }
                else {
                    newCapacity = capacity * 2;
                }
                Magazine* temp = new Magazine[newCapacity];

                for (int i = 0; i < count; i++) {
                    temp[i] = magazines[i];
                }

                // Удаляем старый массив
                delete[] magazines;
                magazines = temp;
                capacity = newCapacity;
            }

            magazines[count] = inputMagazine();
            count++;
            cout << "Новый журнал добавлен" << endl;
            break;
        }

        case 3: { // Удаление журнала
            if (count == 0) {
                cout << "Список пуст (невозможно удалить)" << endl;
                break;
            }

            int index;
            cout << "Введите номер журнала для удаления (1-" << count << "): ";
            cin >> index;

            if (index < 1 || index > count) {
                cout << "Неверный номер!" << endl;
                break;
            }

            // Сдвигаем элементы
            for (int i = index - 1; i < count - 1; i++) {
                magazines[i] = magazines[i + 1];
            }
            count--;

            cout << "Журнал успешно удален!" << endl;

            // если массив сильно большой, то освобожд. память
            if (count > 0 && count <= capacity / 4) {
                int newCapacity = capacity / 2;
                Magazine* temp = new Magazine[newCapacity];

                for (int i = 0; i < count; i++) {
                    temp[i] = magazines[i];
                }

                delete[] magazines;
                magazines = temp;
                capacity = newCapacity;
            }
            break;
        }

        case 4: { // Очистка списка
            if (count == 0) {
                cout << "Список уже пуст" << endl;
            }
            else {
                delete[] magazines;
                magazines = nullptr;
                count = 0;
                capacity = 0;
                cout << "Список очищен полностью" << endl;
            }
            break;
        }

        case 5: { // Сохранение в файл
            if (count == 0) {
                cout << "Список пуст" << endl;
                break;
            }

            string filename;
            cout << "Введите имя файла для сохранения: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);

            ofstream file(filename, ios::binary);
            if (!file) {
                cout << "Ошибка при открытии файла для записи" << endl;
                break;
            }

            // Записываем количество журналов
            file.write(reinterpret_cast<char*>(&count), sizeof(count));

            // Записываем каждый журнал
            for (int i = 0; i < count; i++) {
                // Сохраняем строку с длиной
                size_t titleLength = magazines[i].title.length();
                file.write(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));
                file.write(magazines[i].title.c_str(), titleLength);

                // Сохраняем остальные поля
                file.write(reinterpret_cast<const char*>(&magazines[i].year), sizeof(magazines[i].year));
                file.write(reinterpret_cast<const char*>(&magazines[i].price), sizeof(magazines[i].price));
                file.write(reinterpret_cast<const char*>(&magazines[i].pages), sizeof(magazines[i].pages));
                file.write(reinterpret_cast<const char*>(&magazines[i].issue), sizeof(magazines[i].issue));
            }

            file.close();
            cout << "Список успешно сохранен в файл '" << filename << endl;
            break;
        }

        case 6: { // Загрузка из файла
            string filename;
            cout << "Введите имя файла для загрузки: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, filename);

            ifstream file(filename, ios::binary);
            if (!file) {
                cout << "Ошибка при открытии файла " << endl;
                break;
            }

            // Очищаем текущий список
            if (magazines != nullptr) {
                delete[] magazines;
            }

            // Читаем кол-во журналов
            int fileCount;
            file.
                read(reinterpret_cast<char*>(&fileCount), sizeof(fileCount));

            if (fileCount <= 0) {
                magazines = nullptr;
                count = 0;
                capacity = 0;
                cout << "Ошибка (поврежден или пуст)" << endl;
                break;
            }

            // Создаем новый массив
            magazines = new Magazine[fileCount];
            count = fileCount;
            capacity = fileCount;

            // Читаем каждый журнал
            for (int i = 0; i < count; i++) {
                // Читаем строку
                size_t titleLength;
                file.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength));

                char* buffer = new char[titleLength + 1];
                file.read(buffer, titleLength);
                buffer[titleLength] = '\0';
                magazines[i].title = string(buffer);
                delete[] buffer;

                // Читаем остальные поля
                file.read(reinterpret_cast<char*>(&magazines[i].year), sizeof(magazines[i].year));
                file.read(reinterpret_cast<char*>(&magazines[i].price), sizeof(magazines[i].price));
                file.read(reinterpret_cast<char*>(&magazines[i].pages), sizeof(magazines[i].pages));
                file.read(reinterpret_cast<char*>(&magazines[i].issue), sizeof(magazines[i].issue));
            }

            file.close();
            cout << "Список загружен из файла " << filename  << endl;
            cout << "Загружено " << count << " журналов" << endl;
            break;
        }

        case 0: { // Выход
            running = false;

            // Освобождаем память перед выходом
            if (magazines != nullptr) {
                delete[] magazines;
            }

            cout << "Программа завершена" << endl;
            break;
        }

        default: {
            cout << "Неверный выбор. Выберите действие из меню." << endl;
            break;
        }
        }
    }

    return 0;
}

