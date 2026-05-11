#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>

class Table {
public:
    Table(size_t rows, size_t cols);
    int get_value(size_t row, size_t col) const;
    void set_value(size_t row, size_t col, int value);
    size_t n_rows() const;
    size_t n_cols() const;
    void print() const;         // вывод всей таблицы 
    double average() const;     // ср. ариф

private:
    size_t rows_;
    size_t cols_;
    std::vector<int> data_;     // хранение в одномерном векторе (row * cols_ + col)
};
#endif 
