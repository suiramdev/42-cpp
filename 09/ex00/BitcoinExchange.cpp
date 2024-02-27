#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>

// We use a map, because otherwise we will not be able to use vector in the
// other exercices
std::map<int, std::string> split(const std::string &line, char delim) {
  std::map<int, std::string> elems;
  std::istringstream ss(line);
  std::string elem;

  size_t i = 0;
  while (getline(ss, elem, delim)) {
    elems[i] = elem;
    i++;
  }

  return elems;
}

time_t parseDate(const std::string &date) {
  tm tm;
  if (strptime(date.c_str(), "%Y-%m-%d", &tm) == nullptr) {
    throw std::runtime_error("Invalid date format");
  }

  return mktime(&tm);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open the data file");
  }

  std::string line;

  getline(file, line); // Skip the first line (header)
  while (getline(file, line)) {
    std::map<int, std::string> elems = split(line, ',');
    if (elems.size() < 2) {
      throw std::runtime_error("The data file is invalid");
    }

    std::string date;
    std::istringstream(elems[0]) >> date;

    double value;
    std::istringstream(elems[1]) >> value;

    _data[parseDate(date)] = value;
  }

  file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    _data = other._data;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getValueAt(const time_t &date) const {
  double value = 0;
  for (std::map<time_t, double>::const_iterator it = _data.begin();
       it != _data.end(); ++it) {
    if (it->first <= date) {
      value = it->second;
    }
  }

  return value;
}

void BitcoinExchange::process(const std::string &filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::runtime_error("Could not open the input file");
  }

  std::string line;

  getline(file, line); // Sip the first line (header)
  while (getline(file, line)) {
    std::map<int, std::string> elems = split(line, '|');
    if (elems.size() <= 0) {
      throw std::runtime_error("The input file is invalid");
    }

    std::string date;
    std::istringstream(elems[0]) >> date;

    try {
      double value = getValueAt(parseDate(date));

      if (elems.size() > 1) { // A value is provided
        double amount;
        std::istringstream(elems[1]) >> amount;

        value *= amount;

        if (value > 1000) {
          std::cout << "Error: too large number." << std::endl;
        } else if (value < 0) {
          std::cout << "Error: too small number." << std::endl;
        } else {
          std::cout << date << " => " << amount << " = " << value << std::endl;
        }
      } else {
        std::cout << date << " = " << value << std::endl;
      }
    } catch (const std::runtime_error &e) {
      std::cout << "Error: bad input => " << date << std::endl;
    }
  }

  file.close();
}
