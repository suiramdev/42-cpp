#pragma once

#include <string>

class PmergeMe {
private:
  template <typename Container>
  double sort(Container &sequence, int left, int right);

  template <typename Container>
  void merge(Container &sequence, int left, int middle, int right);

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void process(const std::string &sequence);
};
