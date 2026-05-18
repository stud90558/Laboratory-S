#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
class Polynomial {
private:
    std::vector<T> coeffs;

public:
    // Конструкторы
    Polynomial() : coeffs(1, T()) {}

    Polynomial(const std::vector<T>& coefficients) : coeffs(coefficients) {
        // удаляем лишние нули в конце
        while (coeffs.size() > 1 && coeffs.back() == T(0)) {
            coeffs.pop_back();
        }
    }

    Polynomial(const T& constant) : coeffs(1, constant) {}

    // Метод для получения степени
    int degree() const {
        return (int)coeffs.size() - 1;
    }

    // Оператор [] для получения коэффициента
    T operator[](int degree) const {
        if (degree < 0 || degree >= (int)coeffs.size()) {
            return T(0);
        }
        return coeffs[degree];
    }

    // Оператор () для вычисления значения
    T operator()(const T& x) const {
        T result = T(0);
        // схема Горнера
        for (int i = degree(); i >= 0; --i) {
            result = result * x + coeffs[i];
        }
        return result;
    }

    // Операторы сравнения
    bool operator==(const Polynomial<T>& other) const {
        int maxDegree = std::max(degree(), other.degree());
        for (int i = 0; i <= maxDegree; ++i) {
            if ((*this)[i] != other[i]) return false;
        }
        return true;
    }

    bool operator!=(const Polynomial<T>& other) const {
        return !(*this == other);
    }

    bool operator==(const T& scalar) const {
        return degree() == 0 && coeffs[0] == scalar;
    }

    bool operator!=(const T& scalar) const {
        return !(*this == scalar);
    }

    // Арифметические операторы
    Polynomial<T> operator+(const Polynomial<T>& other) const {
        int maxSize = std::max(coeffs.size(), other.coeffs.size());
        std::vector<T> result(maxSize, T(0));

        for (size_t i = 0; i < coeffs.size(); ++i) {
            result[i] = coeffs[i];
        }
        for (size_t i = 0; i < other.coeffs.size(); ++i) {
            result[i] = result[i] + other.coeffs[i];
        }

        return Polynomial<T>(result);
    }

    Polynomial<T> operator+(const T& scalar) const {
        Polynomial<T> result = *this;
        result.coeffs[0] = result.coeffs[0] + scalar;
        return result;
    }

    Polynomial<T> operator-(const Polynomial<T>& other) const {
        int maxSize = std::max(coeffs.size(), other.coeffs.size());
        std::vector<T> result(maxSize, T(0));

        for (size_t i = 0; i < coeffs.size(); ++i) {
            result[i] = coeffs[i];
        }
        for (size_t i = 0; i < other.coeffs.size(); ++i) {
            result[i] = result[i] - other.coeffs[i];
        }

        return Polynomial<T>(result);
    }

    Polynomial<T> operator-(const T& scalar) const {
        Polynomial<T> result = *this;
        result.coeffs[0] = result.coeffs[0] - scalar;
        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        int newDegree = degree() + other.degree();
        std::vector<T> result(newDegree + 1, T(0));

        for (int i = 0; i <= degree(); ++i) {
            for (int j = 0; j <= other.degree(); ++j) {
                result[i + j] = result[i + j] + coeffs[i] * other.coeffs[j];
            }
        }

        return Polynomial<T>(result);
    }

    Polynomial<T> operator*(const T& scalar) const {
        Polynomial<T> result = *this;
        for (size_t i = 0; i < result.coeffs.size(); ++i) {
            result.coeffs[i] = result.coeffs[i] * scalar;
        }
        return result;
    }

    // Составные операторы
    Polynomial<T>& operator+=(const Polynomial<T>& other) {
        *this = *this + other;
        return *this;
    }

    Polynomial<T>& operator+=(const T& scalar) {
        *this = *this + scalar;
        return *this;
    }

    Polynomial<T>& operator-=(const Polynomial<T>& other) {
        *this = *this - other;
        return *this;
    }

    Polynomial<T>& operator-=(const T& scalar) {
        *this = *this - scalar;
        return *this;
    }

    Polynomial<T>& operator*=(const Polynomial<T>& other) {
        *this = *this * other;
        return *this;
    }

    Polynomial<T>& operator*=(const T& scalar) {
        *this = *this * scalar;
        return *this;
    }
};

// Глобальные операторы (ОБЯЗАТЕЛЬНО вне класса!)

// Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& p) {
    if (p.degree() == 0) {
        os << p[0];
        return os;
    }

    for (int i = p.degree(); i >= 0; --i) {
        os << p[i];
        if (i > 0) os << " ";
    }
    return os;
}

// Операторы со скаляром (скаляр слева)
template<typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& poly) {
    return poly + scalar;
}

template<typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& poly) {
    Polynomial<T> temp(scalar);
    return temp - poly;
}

template<typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& poly) {
    return poly * scalar;
}

// Операторы сравнения со скаляром (скаляр слева)
template<typename T>
bool operator==(const T& scalar, const Polynomial<T>& poly) {
    return poly == scalar;
}

template<typename T>
bool operator!=(const T& scalar, const Polynomial<T>& poly) {
    return poly != scalar;
}

#endif