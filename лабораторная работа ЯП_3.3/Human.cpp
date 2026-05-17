#include "Human.h"
#include <sstream>

Human::Human() : name("Неизвестно"), surname("Неизвестно"), patronymic("Неизвестно") {}

Human::Human(const std::string& n, const std::string& s, const std::string& p)
    : name(n), surname(s), patronymic(p) {
}

std::string Human::getSurnameAndInitials() const {
    std::ostringstream oss;
    char in1 = name.empty() ? '\0' : name[0];
    char in2 = patronymic.empty() ? '\0' : patronymic[0];
    if (in1) oss << surname << ' ' << in1 << '.';
    if (in2) oss << in2 << '.';
    return oss.str();
}

std::string Human::getFullName() const {
    return surname + " " + name + " " + patronymic;
}
