#pragma once
#ifndef CONTAINS_H
#define CONTAINS_H

#include <cstddef>  
#include <string>

template <typename T>
bool contains(const T& value, const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}

#endif 
