#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container>
double PmergeMe::sort(Container &sequence, int left, int right) {
  clock_t start = clock();

  if (left < right) {
    int middle = left + (right - left) / 2;
    sort(sequence, left, middle);
    sort(sequence, middle + 1, right);
    merge(sequence, left, middle, right);
  }

  return static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <typename Container>
void PmergeMe::merge(Container &sequence, int left, int middle, int right) {
  int i = left;
  int j = middle + 1;
  int k = left;

  std::vector<int> temp(sequence.size());

  while (i <= middle && j <= right) {
    if (sequence[i] <= sequence[j]) {
      temp[k] = sequence[i];
      i++;
    } else {
      temp[k] = sequence[j];
      j++;
    }
    k++;
  }

  while (i <= middle) {
    temp[k] = sequence[i];
    i++;
    k++;
  }

  while (j <= right) {
    temp[k] = sequence[j];
    j++;
    k++;
  }

  for (int l = left; l <= right; l++) {
    sequence[l] = temp[l];
  }
}

void PmergeMe::process(const std::string &sequence) {
  std::istringstream ss(sequence);

  // Compose the vector from the input sequence
  std::vector<int> _vec;
  std::deque<int> _deque;
  while (ss) {
    int n;
    ss >> n;

    if (n < 0) {
      throw std::runtime_error("Non positive integer in the sequence");
    }

    if (ss) {
      _vec.push_back(n);
      _deque.push_back(n);
    }
  }

  // Sort the vector
  std::cout << "Before: ";
  for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end();
       ++it) {
    std::cout << *it << " ";
  }

  double vectorSortTime = sort(_vec, 0, _vec.size() - 1);
  double dequeSortTime = sort(_deque, 0, _deque.size() - 1);

  std::cout << std::endl << "After: ";
  for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end();
       ++it) {
    std::cout << *it << " ";
  }

  std::cout << std::endl
            << "Time to process a range of " << _vec.size()
            << " elements with std::vector<int> : " << std::fixed
            << std::setprecision(5) << vectorSortTime << " us" << std::endl;

  std::cout << "Time to process a range of " << _vec.size()
            << "elements with std::deque<int> : " << std::fixed
            << std::setprecision(5) << dequeSortTime << " us" << std::endl;
}
