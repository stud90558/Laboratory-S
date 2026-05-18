#include "get_password.h"
#include "password_errors.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string get_password() {
    string password;

    cout << "Введите пароль: ";
    cin >> password;

    // 1. Проверка длины
    if (password.length() < 9) {
        throw LengthError();
    }

    // 2. Проверка на запрещенные символы
    for (size_t i = 0; i < password.length(); i++) {
        char c = password[i];
        if (c == 'l' || c == 'I' || c == '1' ||
            c == 'o' || c == 'O' || c == '0') {
            throw ForbiddenLetterError();
        }
    }

    // 3. Проверка на регистр букв
    bool hasUpper = false;  // есть большие буквы
    bool hasLower = false;  // есть маленькие буквы

    for (size_t i = 0; i < password.length(); i++) {
        if (isupper(password[i])) {  // если буква большая
            hasUpper = true;
        }
        if (islower(password[i])) {  // если буква маленькая
            hasLower = true;
        }
    }

    // Если нет хотя бы одной большой ИЛИ хотя бы одной маленькой
    if (!hasUpper || !hasLower) {
        throw RegisterError();
    }

    // 4. Проверка на наличие цифр
    bool hasDigit = false;

    for (size_t i = 0; i < password.length(); i++) {
        if (isdigit(password[i])) {  // если символ - цифра
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        throw DigitError();
    }

    // Если все проверки пройдены
    cout << "Пароль принят!" << endl;
    return password;
}