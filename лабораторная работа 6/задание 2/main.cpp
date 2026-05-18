#include "weapon.h"
#include "base_character.h"
#include "base_enemy.h"
#include "main_hero.h"
#include "exceptions.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(0));

    cout << "=== Добро пожаловать в игру! ===" << endl;

    // Создаем оружие
    Weapon sword("Меч", 25, 2.0);
    Weapon bow("Лук", 15, 5.0);
    Weapon axe("Топор", 30, 1.5);
    Weapon dagger("Кинжал", 10, 1.0);

    // Создаем главного героя
    MainHero hero(0, 0, "Артур", 100);
    cout << hero << endl << endl;

    // Добавляем оружие герою
    hero.add_weapon(sword);
    hero.add_weapon(bow);
    cout << endl;

    // Создаем врагов
    vector<BaseEnemy*> enemies;
    enemies.push_back(new BaseEnemy(1, 1, dagger, 40));
    enemies.push_back(new BaseEnemy(3, 2, axe, 60));
    enemies.push_back(new BaseEnemy(4, 5, bow, 50));
    enemies.push_back(new BaseEnemy(6, 3, sword, 45));

    // Выводим информацию о врагах
    cout << "=== Враги ===" << endl;
    for (size_t i = 0; i < enemies.size(); i++) {
        cout << i + 1 << ". " << *enemies[i] << endl;
    }
    cout << endl;

    // Основной игровой цикл
    bool game_running = true;
    int current_enemy = 0;

    while (game_running && hero.is_alive() && current_enemy < (int)enemies.size()) {
        cout << "\n=== Ход героя ===" << endl;
        cout << "1. Атаковать текущего врага" << endl;
        cout << "2. Сменить оружие" << endl;
        cout << "3. Подлечиться" << endl;
        cout << "4. Переместиться" << endl;
        cout << "5. Информация" << endl;
        cout << "0. Выйти из игры" << endl;
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        try {
            switch (choice) {
            case 1: { // Атака
                if (current_enemy >= (int)enemies.size()) {
                    cout << "Все враги побеждены!" << endl;
                    break;
                }

                BaseEnemy* enemy = enemies[current_enemy];

                if (!enemy->is_alive()) {
                    cout << "Этот враг уже мертв! Переход к следующему..." << endl;
                    current_enemy++;
                    break;
                }

                cout << "Атакуем: " << *enemy << endl;
                hero.hit(enemy);

                // Проверяем, умер ли враг
                if (!enemy->is_alive()) {
                    cout << "Враг повержен!" << endl;
                    current_enemy++;
                }
                break;
            }

            case 2: // Смена оружия
                hero.next_weapon();
                break;

            case 3: { // Лечение
                int heal_amount = 20 + rand() % 30;
                hero.heal(heal_amount);
                break;
            }

            case 4: { // Перемещение
                double dx, dy;
                cout << "Введите delta_x: ";
                cin >> dx;
                cout << "Введите delta_y: ";
                cin >> dy;
                hero.move(dx, dy);
                break;
            }

            case 5: // Информация
                cout << hero << endl;
                if (current_enemy < (int)enemies.size() && enemies[current_enemy]->is_alive()) {
                    cout << "Текущий враг: " << *enemies[current_enemy] << endl;
                }
                break;

            case 0: // Выход
                game_running = false;
                cout << "Игра завершена!" << endl;
                break;

            default:
                cout << "Неверный выбор!" << endl;
            }
        }
        catch (NoWeaponException& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        catch (TargetDeadException& e) {
            cout << "Ошибка: " << e.what() << endl;
            current_enemy++;
        }
        catch (...) {
            cout << "Неизвестная ошибка!" << endl;
        }

        // Ход врагов (атакуют только если герой жив и есть живые враги)
        if (hero.is_alive() && game_running) {
            cout << "\n=== Ход врагов ===" << endl;
            for (size_t i = 0; i < enemies.size(); i++) {
                if (enemies[i]->is_alive()) {
                    // Вычисляем расстояние до героя
                    double dx = enemies[i]->get_x() - hero.get_x();
                    double dy = enemies[i]->get_y() - hero.get_y();
                    double dist = sqrt(dx * dx + dy * dy);

                    cout << enemies[i]->getWeapon().getName() << " атакует! ";

                    // Враг атакует, если расстояние позволяет
                    if (dist <= enemies[i]->getWeapon().getRange()) {
                        enemies[i]->hit(&hero);
                    }
                    else {
                        cout << "Слишком далеко для атаки!" << endl;
                    }
                }
            }

            if (!hero.is_alive()) {
                cout << "\n*** ГЕРОЙ ПОГИБ! ИГРА ОКОНЧЕНА ***" << endl;
            }
        }
    }

    // Проверяем победу
    if (hero.is_alive() && current_enemy >= (int)enemies.size()) {
        cout << "\n*** ПОБЕДА! Все враги повержены! ***" << endl;
        cout << hero << endl;
    }

    // Очищаем память
    for (size_t i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }

    return 0;
}