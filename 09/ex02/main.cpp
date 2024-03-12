#include "PmergeMe.hpp"
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>

/**
 * @brief Concatenate the elements of an array into a single string
 *
 * @param array the array of strings
 * @param size the size of the array
 * @return the concatenated string
 */
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

/**
 * Print the content of a container
 *
 * @tparam Container the container type
 * @param container the container to print
 */
template<template <typename, typename> class Container>
void printContainer(const Container<int, std::allocator<int> > &container) {
  for (typename Container<int, std::allocator<int> >::const_iterator it = container.begin();
      it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
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
    std::cout << "Before sorting: ";
    printContainer(vec);

    double sortVectorTime = PmergeMe<std::vector>::sort(vec);
    double sortDequeTime = PmergeMe<std::deque>::sort(deq);

    std::cout << "After sorting: ";
    printContainer(vec);

    std::cout << "Time with std::vector : " << std::fixed << std::setprecision(5) << sortVectorTime << " us" << std::endl;
    std::cout << "Time with std::deque : " << std::fixed << std::setprecision(5) << sortDequeTime << " us" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
