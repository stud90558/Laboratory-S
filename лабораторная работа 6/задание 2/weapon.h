#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int damage;
    double range;

public:
    // Конструктор
    Weapon(const string& n = "", int d = 0, double r = 0)
        : name(n), damage(d), range(r) {
    }

    // Геттеры
    string getName() const { return name; }
    int getDamage() const { return damage; }
    double getRange() const { return range; }

    // Метод удара
    void hit(class BaseCharacter* actor, class BaseCharacter* target);

    // Операторы ввода/вывода
    friend ostream& operator<<(ostream& os, const Weapon& w) {
        os << w.name;
        return os;
    }

    friend istream& operator>>(istream& is, Weapon& w) {
        cout << "Введите имя оружия: ";
        is >> w.name;
        cout << "Введите урон: ";
        is >> w.damage;
        cout << "Введите радиус: ";
        is >> w.range;
        return is;
    }
};

#endif