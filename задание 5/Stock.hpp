#ifndef STOCK_HPP
#define STOCK_HPP

#include <vector>

class Stock {
public:
    Stock();

    void Add(int w, int v);    // добавить коробку (w - грузоподъемность, v - объём)
    int GetByW(int min_w);     // вернуть id коробки с w  min_w (или -1), удалить её из склада
    int GetByV(int min_v);     // вернуть id коробки с v  min_v (или -1), удалить её из склада

private:
    struct Box {
        int w;
        int v;
        int id;
        bool alive;
    };

    std::vector<Box> boxes;
};

#endif 
