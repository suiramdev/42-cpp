#pragma once

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack() {}
  ~MutantStack() {}

  MutantStack(const MutantStack<T> &other) { this->c = other.c; }

  MutantStack &operator=(const MutantStack<T> &other) {
    this->c = other.c;
    return *this;
  }

  typedef typename std::stack<T>::container_type::iterator iterator;

  typename std::stack<T>::container_type::iterator begin() {
    return this->c.begin();
  }

  typename std::stack<T>::container_type::iterator end() {
    return this->c.end();
  }
};
