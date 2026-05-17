#include <iostream>
#include <vector>
#include <memory>

#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Animal.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== Раннее связывание (вызовы через конкретные типы) ===\n\n";

    Fish fish;
    fish.breathe();
    fish.eat();
    fish.swim();

    std::cout << "\n";

    Bird bird;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    std::cout << "\n";

    FlyingBird fbird;
    fbird.breathe();
    fbird.eat();
    fbird.lay_eggs();
    fbird.fly();

    std::cout << "\n=== Позднее связывание (через указатель/ссылку на базовый класс) ===\n\n";

    // Вектор уникальных указателей на Animal (полиморфизм)
    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(std::make_unique<Fish>());
    animals.emplace_back(std::make_unique<Bird>());
    animals.emplace_back(std::make_unique<FlyingBird>());

    int idx = 1;
    for (const auto& a : animals) {
        std::cout << "-- Animal #" << idx++ << " (dynamic type: " << typeid(*a).name() << ") --\n";
        a->breathe(); // виртуальные вызовы
        a->eat();

        // динамическое приведение для доступа к специфичным методам
        if (auto pf = dynamic_cast<Fish*>(a.get())) {
            pf->swim();
        }
        if (auto pb = dynamic_cast<Bird*>(a.get())) {
            pb->lay_eggs();
        }
        if (auto pfb = dynamic_cast<FlyingBird*>(a.get())) {
            pfb->fly();
        }
        std::cout << "\n";
    }

    return 0;
}
