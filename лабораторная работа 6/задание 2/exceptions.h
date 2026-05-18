#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
using namespace std;

// Исключение: нет оружия
class NoWeaponException {
private:
    string message;
public:
    NoWeaponException() : message("У персонажа нет оружия!") {}
    string what() const { return message; }
};

// Исключение: цель мертва
class TargetDeadException {
private:
    string message;
public:
    TargetDeadException() : message("Цель уже мертва!") {}
    string what() const { return message; }
};

#endif