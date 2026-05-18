#pragma once
#ifndef PASSWORD_ERRORS_H
#define PASSWORD_ERRORS_H

#include <iostream>
#include <string>
using namespace std;

// Базовый класс для всех ошибок пароля
class PasswordError {
protected:
    string message;
public:
    PasswordError(const string& msg) : message(msg) {}

    string what() const {
        return message;
    }
};

// Ошибка: длина меньше 9 символов
class LengthError : public PasswordError {
public:
    LengthError() : PasswordError("Ошибка: длина пароля меньше 9 символов!") {}
};

// Ошибка: все символы одного регистра
class RegisterError : public PasswordError {
public:
    RegisterError() : PasswordError("Ошибка: в пароле все символы одного регистра!") {}
};

// Ошибка: нет ни одной цифры
class DigitError : public PasswordError {
public:
    DigitError() : PasswordError("Ошибка: в пароле нет ни одной цифры!") {}
};

// Ошибка: есть запрещенные символы
class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError() : PasswordError("Ошибка: в пароле есть запрещенные символы (l, I, 1, o, O, 0)!") {}
};

#endif