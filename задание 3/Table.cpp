#include "Table.hpp"
#include <iostream>


Table::Table(size_t rows, size_t cols)
    : rows_(rows), cols_(cols), data_(rows* cols, 0) {
}

int Table::get_value(size_t row, size_t col) const {
    return data_[row * cols_ + col];
}

void Table::set_value(size_t row, size_t col, int value) {
    data_[row * cols_ + col] = value;
}

size_t Table::n_rows() const { return rows_; }
size_t Table::n_cols() const { return cols_; }

void Table::print() const {
    for (size_t r = 0; r < rows_; ++r) {
        for (size_t c = 0; c < cols_; ++c) {
            if (c) std::cout << ' ';
            std::cout << get_value(r, c);
        }
        std::cout << '\n';
    }
}

double Table::average() const {
    if (data_.empty()) return 0.0;
    long long sum = 0;
    for (int v : data_) sum += v;
    return static_cast<double>(sum) / static_cast<double>(data_.size());
}
