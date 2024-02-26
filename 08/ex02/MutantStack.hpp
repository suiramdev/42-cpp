#pragma once

#include <stack>

template <typename T> class MutantStack {
private:
  std::stack<T> _stack;

public:
  MutantStack() {}
  ~MutantStack() {}

  void push(T const &value) { _stack.push(value); }

  void pop() { _stack.pop(); }

  T &top() { return _stack.top(); }

  size_t size() const { return _stack.size(); }

  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin() { return _stack.begin(); }
  iterator end() { return _stack.end(); }
};
