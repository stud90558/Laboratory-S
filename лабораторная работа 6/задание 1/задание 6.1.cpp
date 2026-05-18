#include "get_password.h"
#include "password_errors.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    cout << "=== Программа проверки пароля ===" << endl;
    cout << "Требования к паролю:" << endl;
    cout << "1. Длина не менее 9 символов" << endl;
    cout << "2. Должны быть буквы ВЕРХНЕГО и НИЖНЕГО регистра" << endl;
    cout << "3. Должна быть хотя бы одна цифра" << endl;
    cout << "4. Нельзя использовать: l, I, 1, o, O, 0" << endl;
    cout << "===================================" << endl << endl;

    string user_password;

    // Пробуем получить пароль, обрабатывая возможные ошибки
    try {
        user_password = get_password();
        cout << "Ваш пароль: " << user_password << endl;
        cout << "Пароль успешно сохранен!" << endl;
    }
    catch (LengthError& e) {
        cout << e.what() << endl;
        cout << "Попробуйте снова!" << endl;
    }
    catch (RegisterError& e) {
        cout << e.what() << endl;
        cout << "Попробуйте снова!" << endl;
    }
    catch (DigitError& e) {
        cout << e.what() << endl;
        cout << "Попробуйте снова!" << endl;
    }
    catch (ForbiddenLetterError& e) {
        cout << e.what() << endl;
        cout << "Попробуйте снова!" << endl;
    }
    catch (...) {  // на всякий случай, если какая-то другая ошибка
        cout << "Неизвестная ошибка!" << endl;
    }

    return 0;
}