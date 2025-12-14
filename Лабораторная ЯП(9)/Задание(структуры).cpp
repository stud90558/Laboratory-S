// Задание(структуры).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;


enum class libSection
{
    SpecialLiterature,
    Hobby,
    HomeEconomics,
    Fiction,
    Other
};

enum class Origin
{
    Purchase,
    Gift,
    Borrowed
};


struct Book
{
    string author;
    string title;
    string publisher;
    libSection section;
    Origin origin;
    bool isAvailable;
};

void displayBookInfo(Book book)
{
    cout << "Автор: " << book.author << endl;
    cout << "Название: " << book.title << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Раздел библиотеки: " << static_cast<int>(book.section) << endl;
    cout << "Происхождение: " << static_cast<int>(book.origin) << endl;
    if (book.isAvailable) {
        cout << "Наличие: в наличии" << endl;
    }
    else {
        cout << "Наличие: нет в наличии" << endl;
    }
}

bool loadBooksFromFile(const string& filename, Book* library, int& n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!\n";
        return false;
    }

    n = 0; // Количество загруженных книг 
    while (file.good() && n < 100) { // Предположим, максимальное количество 100 
        string line;
        if (!getline(file, line) || line.empty()) {
            continue;
        }

        Book book;
        size_t pos = 0;

        // Чтение автора 
        pos = line.find(';');
        book.author = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Чтение названия 
        pos = line.find(';');
        book.title = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Чтение издательства 
        pos = line.find(';');
        book.publisher = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Чтение раздела 
        pos = line.find(';');
        book.section = static_cast<libSection>(line[pos] - '0'); // Если разделы индексированы 
        line.erase(0, pos + 1);

        // Чтение происхождения 
        pos = line.find(';');
        book.origin = static_cast<Origin>(line[pos] - '0');  // Предположим, что они тоже индексированы 
        line.erase(0, pos + 1);

        // Чтение наличия 
        book.isAvailable = (line == "1");

        library[n++] = book;
    }

    file.close();
    return n > 0; // Возвращает true, если книги были загружены 
}

void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Показать все книги\n";
    cout << "2. Показать книги по автору\n";
    cout << "3. Показать книги по разделу\n";
    cout << "4. Выход\n";
}

void displayBooksByAuthor(const Book* library, int n) {
    string author;
    cout << "Введите имя автора: ";
    cin.ignore();
    getline(std::cin, author);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (library[i].author == author) {
            displayBookInfo(library[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Книги автора \"" << author << "\" не найдены.\n";
    }
}

void displayBooksBySection(const Book* library, int n) {
    int sectionInput;
    cout << "Введите номер раздела (0 - Специальная литература, 1 - Хобби, 2 - Домашнее хозяйство, 3 - Беллетристика, 4 - Другое): ";
    cin >> sectionInput;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (static_cast<int>(library[i].section) == sectionInput) {
            displayBookInfo(library[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Книги в разделе " << sectionInput << " не найдены.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int MAX_BOOKS = 100;
    Book library[MAX_BOOKS];
    int n = 0;

    if (!loadBooksFromFile("library.txt", library, n)) {
        return 1; // Прекращаем выполнение в случае ошибки 
    }

    int choice;
    do {
        displayMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) {
                displayBookInfo(library[i]);
            }
            break;
        case 2:
            displayBooksByAuthor(library, n);
            break;
        case 3:
            displayBooksBySection(library, n);
            break;
        case 4:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);


    return 0;
}
