#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

template<typename T>
class Matrix {
public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, const T& val);
    Matrix(const Matrix<T>& other);
    Matrix(Matrix<T>&& other) noexcept;
    ~Matrix();

    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T>& operator=(Matrix<T>&& other) noexcept;

    void Set(size_t i, size_t j, const T& value);
    T Get(size_t i, size_t j) const;
    size_t Rows() const noexcept;
    size_t Cols() const noexcept;

    Matrix<T> operator+(const Matrix<T>& rhs) const;
    Matrix<T> operator*(const Matrix<T>& rhs) const;

    template<typename U>
    friend ostream& operator<<(ostream& os, const Matrix<U>& mat);

    template<typename U>
    friend istream& operator>>(istream& is, Matrix<U>& mat);

private:
    size_t rows_;
    size_t cols_;
    vector<T> data_;

    size_t index(size_t i, size_t j) const;
};

#include "Matrix.tpp"
#endif // MATRIX_H
