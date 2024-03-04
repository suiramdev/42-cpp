#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    BitcoinExchange bitcoinExchange("data.csv");
    bitcoinExchange.process(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
