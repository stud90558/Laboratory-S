#pragma once
#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "base_character.h"
#include "weapon.h"
#include "base_enemy.h"
#include "exceptions.h"
#include <vector>
#include <iostream>
using namespace std;

class MainHero : public BaseCharacter {
private:
    string name;
    vector<Weapon> inventory;  // инвентарь
    int current_weapon_index;  // индекс текущего оружия
    const int MAX_HP = 200;     // максимальное здоровье

public:
    // Конструктор
    MainHero(double pos_x, double pos_y, const string& n, int health = 100)
        : BaseCharacter(pos_x, pos_y, health), name(n), current_weapon_index(-1) {
    }

    // Удар по врагу
    void hit(BaseEnemy* target) {
        if (!is_alive()) {
            cout << "Герой мертв и не может атаковать!" << endl;
            return;
        }

        if (current_weapon_index == -1 || inventory.empty()) {
            cout << "Я безоружен" << endl;
            throw NoWeaponException();
            return;
        }

        inventory[current_weapon_index].hit(this, target);
    }

    // Добавить оружие
    void add_weapon(const Weapon& w) {
        inventory.push_back(w);
        cout << "Подобрал " << w << endl;

        // Если это первое оружие, экипируем его
        if (current_weapon_index == -1) {
            current_weapon_index = 0;
            cout << "Оружие " << w << " экипировано!" << endl;
        }
    }

    // Сменить оружие
    void next_weapon() {
        if (inventory.empty()) {
            cout << "Я безоружен" << endl;
            return;
        }

        if (inventory.size() == 1) {
            cout << "У меня только одно оружие" << endl;
            return;
        }

        // Переключаем на следующее оружие по кругу
        current_weapon_index = (current_weapon_index + 1) % inventory.size();
        cout << "Сменил оружие на " << inventory[current_weapon_index] << endl;
    }

    // Лечение
    void heal(int amount) {
        if (!is_alive()) {
            cout << "Герой мертв, лечение невозможно!" << endl;
            return;
        }

        hp += amount;
        if (hp > MAX_HP) {
            hp = MAX_HP;
        }
        cout << "Полечился, теперь здоровья " << hp << endl;
    }

    // Геттер имени
    string getName() const { return name; }

    // Оператор вывода
    friend ostream& operator<<(ostream& os, const MainHero& hero) {
        os << "Герой " << hero.name << " на позиции (" << hero.get_x()
            << ", " << hero.get_y() << ") со здоровьем " << hero.get_hp();
        return os;
    }
};

#endif