#include "Bell.hpp"

Bell::Bell() : nextIsDing(true) {}

std::string Bell::sound() {
    if (nextIsDing) {
        nextIsDing = false;
        return "ding";
    }
    else {
        nextIsDing = true;
        return "dong";
    }
}
