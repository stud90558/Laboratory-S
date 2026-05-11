#include "Stock.hpp"

Stock::Stock() = default;

void Stock::Add(int w, int v) {
    Box b;
    b.w = w;
    b.v = v;
    b.id = static_cast<int>(boxes.size());
    b.alive = true;
    boxes.push_back(b);
}

int Stock::GetByW(int min_w) {
    int best_idx = -1;
    for (int i = 0; i < static_cast<int>(boxes.size()); ++i) {
        if (!boxes[i].alive) continue;
        if (boxes[i].w >= min_w) {
            if (best_idx == -1 || boxes[i].id > boxes[best_idx].id) best_idx = i;
        }
    }
    if (best_idx == -1) return -1;
    boxes[best_idx].alive = false;
    return boxes[best_idx].id;
}

int Stock::GetByV(int min_v) {
    int best_idx = -1;
    for (int i = 0; i < static_cast<int>(boxes.size()); ++i) {
        if (!boxes[i].alive) continue;
        if (boxes[i].v >= min_v) {
            if (best_idx == -1 || boxes[i].id > boxes[best_idx].id) best_idx = i;
        }
    }
    if (best_idx == -1) return -1;
    boxes[best_idx].alive = false;
    return boxes[best_idx].id;
}
