#pragma once
#include <vector>

class Span {
private:
  unsigned int _N;
  std::vector<int> _v;

public:
  Span(unsigned int N);
  ~Span();

  void addNumber(int number);

  template <typename T>
  void addNumbers(typename T::iterator begin, typename T::iterator end) {
    for (typename T::iterator it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }

  int shortestSpan();
  int longestSpan();
};
