#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <algorithm>

using namespace std;

template<typename T>
Matrix<T>::Matrix() : rows_(0), cols_(0), data_() {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& val)
    : rows_(rows), cols_(cols), data_(rows * cols, val) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
    : rows_(other.rows_), cols_(other.cols_), data_(other.data_) {}

template<typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), data_(move(other.data_)) {
    other.rows_ = 0;
    other.cols_ = 0;
}

template<typename T>
Matrix<T>::~Matrix() {}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = other.data_;
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
    if (this != &other) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = move(other.data_);
        other.rows_ = 0;
        other.cols_ = 0;
    }
    return *this;
}

template<typename T>
size_t Matrix<T>::index(size_t i, size_t j) const {
    if (i >= rows_ || j >= cols_) {
        ostringstream oss;
        oss << "Index out of range: (" << i << "," << j << ") for matrix "
            << rows_ << "x" << cols_;
        throw out_of_range(oss.str());
    }
    return i * cols_ + j;
}

template<typename T>
void Matrix<T>::Set(size_t i, size_t j, const T& value) {
    data_[index(i, j)] = value;
}

template<typename T>
T Matrix<T>::Get(size_t i, size_t j) const {
    return data_[index(i, j)];
}

template<typename T>
size_t Matrix<T>::Rows() const noexcept { return rows_; }

template<typename T>
size_t Matrix<T>::Cols() const noexcept { return cols_; }

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
    if (rows_ != rhs.rows_ || cols_ != rhs.cols_) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix<T> res(rows_, cols_);
    size_t n = rows_ * cols_;
    for (size_t k = 0; k < n; ++k) res.data_[k] = data_[k] + rhs.data_[k];
    return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const {
    if (cols_ != rhs.rows_) {
        throw invalid_argument("Matrix inner dimensions must match for multiplication");
    }
    Matrix<T> res(rows_, rhs.cols_, T{});
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < rhs.cols_; ++j) {
            T sum = T{};
            for (size_t k = 0; k < cols_; ++k) {
                sum = sum + this->Get(i, k) * rhs.Get(k, j);
            }
            res.Set(i, j, sum);
        }
    }
    return res;
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& mat) {
    os << mat.rows_ << ' ' << mat.cols_ << '\n';
    for (size_t i = 0; i < mat.rows_; ++i) {
        for (size_t j = 0; j < mat.cols_; ++j) {
            os << mat.data_[i * mat.cols_ + j];
            if (j + 1 < mat.cols_) os << ' ';
        }
        os << '\n';
    }
    return os;
}

template<typename T>
istream& operator>>(istream& is, Matrix<T>& mat) {
    size_t r, c;
    if (!(is >> r >> c)) {
        is.setstate(ios::failbit);
        return is;
    }
    Matrix<T> tmp(r, c);
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            T val;
            if (!(is >> val)) {
                is.setstate(ios::failbit);
                return is;
            }
            tmp.Set(i, j, val);
        }
    }
    mat = move(tmp);
    return is;
}

#endif // MATRIX_TPP
