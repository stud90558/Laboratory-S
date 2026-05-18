#pragma once
#ifndef CONTAINS_H
#define CONTAINS_H

#include <cstddef>

using namespace std;

template<typename T>
bool contains(const T* arr, size_t n, const T& value);

#include "contains.tpp"
#endif 
