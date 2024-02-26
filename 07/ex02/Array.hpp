#pragma once
#include <exception>

template <typename T> class Array {
private:
  T *_arr;
  unsigned int _size;

public:
  Array<T>() : _size(0) { _arr = new T[0](); }
  Array<T>(unsigned int n) : _size(n) { _arr = new T[n](); }
  Array(const Array &other) : _size(other._size) {
    _arr = new T[other._size]();
    for (unsigned int i = 0; i < _size; i++)
      _arr[i] = other._arr[i];
  }
  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _arr;
      _size = other._size;
      _arr = new T[other._size]();
      for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
    }
    return *this;
  }
  virtual ~Array<T>() { delete[] _arr; }

  T &operator[](unsigned int i) {
    if (i >= _size)
      throw std::exception();
    return _arr[i];
  }

  unsigned int size() const { return _size; }
};
