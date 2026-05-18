#pragma once
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <iostream>
#include <cmath>
using namespace std;

class BaseCharacter {
protected:
    double x, y;  // координаты
    int hp;       // здоровье

public:
    // Конструктор
    BaseCharacter(double pos_x = 0, double pos_y = 0, int health = 100)
        : x(pos_x), y(pos_y), hp(health) {
    }

    // Перемещение
    void move(double delta_x, double delta_y) {
        x += delta_x;
        y += delta_y;
        cout << "Переместился на (" << delta_x << ", " << delta_y
            << "). Теперь позиция: (" << x << ", " << y << ")" << endl;
    }

    // Проверка жив ли
    bool is_alive() const {
        return hp > 0;
    }

    // Получить урон
    void get_damage(int amount) {
        hp -= amount;
        if (hp < 0) hp = 0;
        cout << "Получен урон " << amount << ". Осталось здоровья: " << hp << endl;
    }

    // Геттеры координат
    double get_x() const { return x; }
    double get_y() const { return y; }

    // Геттер здоровья
    int get_hp() const { return hp; }

    // Виртуальный деструктор
    virtual ~BaseCharacter() {}
};

#endif