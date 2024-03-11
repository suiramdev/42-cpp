#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>

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

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <positive integer sequence>"
              << std::endl;
    return EXIT_FAILURE;
  }

  // Convert the input arguments to a single string
  std::string sequence = concatenate(argv + 1, argc - 1);

  try {
    PmergeMe pmergeMe;
    pmergeMe.process(sequence);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
