#include <Array.hpp>

template <typename T>
Array<T>::Array() : _Array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _Array = new T[n];
    for (unsigned int i = 0; i < n; i++) {
        _Array[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size) {
    _Array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _Array[i] = other._Array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _Array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        delete[] _Array;
        _size = other._size;
        _Array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _Array[i] = other._Array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _Array[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
    return _size;
}