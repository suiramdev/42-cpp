#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

void Span::addNumber(int number) {
  if (_v.size() >= _N)
    throw std::exception();

  _v.push_back(number);
}

int Span::shortestSpan() {
  if (_v.size() < 2)
    throw std::exception();

  std::vector<int> tmp = _v;

  std::sort(tmp.begin(), tmp.end());

  int shortest = tmp[tmp.size() - 1] - tmp[0];

  for (unsigned long i = 0; i < tmp.size(); ++i) {
    if (tmp[i] - tmp[i - 1] < shortest)
      shortest = tmp[i] - tmp[i - 1];
  }

  return shortest;
}

int Span::longestSpan() {
  if (_v.size() < 2)
    throw std::exception();

  std::vector<int> tmp = _v;

  std::sort(tmp.begin(), tmp.end());

  return tmp[tmp.size() - 1] - tmp[0];
}
