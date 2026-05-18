#include "weapon.h"
#include "base_character.h"
#include "exceptions.h"
#include <iostream>
using namespace std;

void Weapon::hit(BaseCharacter* actor, BaseCharacter* target) {
    // Проверяем, жив ли target
    if (!target->is_alive()) {
        cout << "Враг уже повержен" << endl;
        throw TargetDeadException();
        return;
    }

    // Вычисляем расстояние
    double dx = actor->get_x() - target->get_x();
    double dy = actor->get_y() - target->get_y();
    double distance = sqrt(dx * dx + dy * dy);

    // Проверяем радиус
    if (distance > range) {
        cout << "Враг слишком далеко для оружия " << name << endl;
        return;
    }

    // Наносим урон
    cout << "Врагу нанесен урон оружием " << name
        << " в размере " << damage << endl;
    target->get_damage(damage);
}