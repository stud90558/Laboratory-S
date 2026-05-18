#pragma once
#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_character.h"
#include "weapon.h"
#include <iostream>
using namespace std;

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    // Конструктор
    BaseEnemy(double pos_x, double pos_y, const Weapon& w, int health = 50)
        : BaseCharacter(pos_x, pos_y, health), weapon(w) {
    }

    // Удар по цели
    void hit(BaseCharacter* target) {
        if (!is_alive()) {
            cout << "Враг мертв и не может атаковать!" << endl;
            return;
        }
        weapon.hit(this, target);
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& os, const BaseEnemy& enemy) {
        os << "Враг на позиции (" << enemy.get_x() << ", " << enemy.get_y()
            << ") с оружием " << enemy.weapon;
        return os;
    }

    // Геттер оружия
    Weapon getWeapon() const { return weapon; }
};

#endif