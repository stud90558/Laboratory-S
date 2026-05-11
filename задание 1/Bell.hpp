#pragma once
#ifndef BELL_HPP
#define BELL_HPP

#include <string>

class Bell {
public:
    Bell();
    std::string sound(); // возвращает "ding" или "dong" попеременно, начиная с "ding"
private:
    bool nextIsDing;
};

#endif // BELL_HPP
