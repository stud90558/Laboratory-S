#ifndef ODDEVENSEPARATOR_HPP
#define ODDEVENSEPARATOR_HPP

#include <vector>

class OddEvenSeparator {
public:
    OddEvenSeparator();
    void add_number(int n);
    void even() const; // печатает чёт числа в порядке добавления
    void odd() const;  // печатает нечёт числа в порядке добавления
private:
    std::vector<int> evens;
    std::vector<int> odds;
};

#endif
