#pragma once
#ifndef CHANGE_H
#define CHANGE_H

#include <cstddef>
#include <iostream>

using namespace std;

template<typename T>
bool change(T* a, T* b, T* arr, size_t n);

#include "change.tpp"
#endif 