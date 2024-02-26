#pragma once

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;

  typename std::stack<T>::container_type::iterator begin() {
    return this->c.begin();
  }

  typename std::stack<T>::container_type::iterator end() {
    return this->c.end();
  }
};
