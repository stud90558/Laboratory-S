#ifndef CONTAINS_TPP
#define CONTAINS_TPP

#include <cstddef>

template<typename T>
bool contains(const T* arr, size_t n, const T& value) {
    if (!arr) return false;
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}

#endif // CONTAINS_TPP
