#include <iostream>
#include <memory>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Cylinder.h"

int main() {
    setlocale(LC_ALL, "ru");
    
    std::cout << "Выберите фигуру:\n"
        << "1 - Circle\n"
        << "2 - Rectangle\n"
        << "3 - Ellipse\n"
        << "4 - Triangle\n"
        << "Введите номер: ";
    int choice = 0;
    if (!(std::cin >> choice)) return 1;

    FigurePtr fig;

    if (choice == 1) {
        double r;
        std::cout << "Введите радиус круга: ";
        std::cin >> r;
        fig = std::make_unique<Circle>(r);
    }
    else if (choice == 2) {
        double w, h;
        std::cout << "Введите ширину и высоту прямоугольника: ";
        std::cin >> w >> h;
        fig = std::make_unique<Rectangle>(w, h);
    }
    else if (choice == 3) {
        double a, b;
        std::cout << "Введите полуоси эллипса (a b): ";
        std::cin >> a >> b;
        fig = std::make_unique<Ellipse>(a, b);
    }
    else if (choice == 4) {
        double base, height;
        std::cout << "Введите основание и высоту треугольника: ";
        std::cin >> base >> height;
        fig = std::make_unique<Triangle>(base, height);
    }
    else {
        std::cout << "Неверный выбор." << std::endl;
        return 1;
    }

    double cylHeight;
    std::cout << "Введите высоту обобщенного цилиндра: ";
    std::cin >> cylHeight;

    fig->Show();
    std::cout << "Площадь = " << fig->CalcArea() << std::endl;

    Cylinder cyl(cylHeight);
    cyl.ShowVolume(*fig);

    return 0;
}

