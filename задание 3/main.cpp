#include <iostream>
#include "Table.hpp"

int main() {
    Table t(3, 4); // 3 строки, 4 столбца (все нули)

    // заполняем таблицу
    int val = 1;
    for (size_t r = 0; r < t.n_rows(); ++r) {
        for (size_t c = 0; c < t.n_cols(); ++c) {
            t.set_value(r, c, val++);
        }
    }

    std::cout << "Table contents:\n";
    t.print();

    std::cout << "Value at (1,2): " << t.get_value(1, 2) << '\n';
    std::cout << "Rows: " << t.n_rows() << ", Cols: " << t.n_cols() << '\n';
    std::cout << "Average: " << t.average() << '\n';

    return 0;
}
