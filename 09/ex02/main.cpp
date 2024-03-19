#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

std::string concatenate(char *array[], size_t size) {
  std::string result;
  for (size_t i = 0; i < size; i++) {
    if (i > 0) {
      result += " ";
    }
    result += array[i];
  }

  return result;
}

template<template <typename T, typename = std::allocator<T> > class Container>
void printContainer(const Container<int> &container) {
  for (typename Container<int>::const_iterator it = container.begin();
       it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <positive integer sequence>"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string sequence = concatenate(argv + 1, argc - 1);

  std::vector<int> vec;
  std::deque<int> deq;
  std::istringstream iss(sequence);
  while (iss) {
    int number;
    iss >> number;

    if (number < 0) {
      std::cerr << "The sequence contain(s) negative number(s)" << std::endl;
      return EXIT_FAILURE;
    }

    if (iss) {
      vec.push_back(number);
      deq.push_back(number);
    }
  }

  try {
    clock_t start = clock();
    std::vector<int> sortedVec = PmergeMe<std::vector>::sort(vec);
    double sortVectorTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    start = clock();
    PmergeMe<std::deque>::sort(deq);
    double sortDequeTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << "Before sorting: ";
    printContainer(vec);
    std::cout << "After sorting: ";
    printContainer(sortedVec);
    std::cout << "Vector sort time: " << std::fixed << std::setprecision(5) << sortVectorTime << " seconds" << std::endl;
    std::cout << "Deque sort time: " << std::fixed << std::setprecision(5) << sortDequeTime << " seconds" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
