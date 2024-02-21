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
  int shortestSpan();
  int longestSpan();
};
