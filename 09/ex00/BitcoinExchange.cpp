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
  time_t now = time(0);
  struct tm *tm = localtime(&now);
  if (strptime(date.c_str(), "%Y-%m-%d", tm) == NULL) {
    throw std::runtime_error("Invalid date format");
  }

  return mktime(tm);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *filename) {
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

    std::istringstream dateSS(elems[0]);
    std::string date;
    dateSS >> date;

    std::istringstream valueSS(elems[1]);
    float value;
    valueSS >> value;

    _data[parseDate(date)] = value;
  }
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

float BitcoinExchange::getValueAt(const time_t &date) const {
  std::map<time_t, float>::const_iterator closest = _data.end();
  for (std::map<time_t, float>::const_iterator it = _data.begin();
       it != _data.end(); ++it) {
    if (it->first <= date) {
      closest = it;
    }
  }

  if (closest == _data.end()) {
    throw std::runtime_error("No data available");
  }

  return closest->second;
}

bool isNumber(const std::string &s) {
  size_t i = 0;
  if (s[0] == '-' || s[0] == '+') {
    i = 1;
  }

  for (; i < s.size(); i++) {
    if (!isspace(s[i]) && !isdigit(s[i]) && s[i] != '.') {
      return false;
    }
  }

  return true;
}

void BitcoinExchange::process(const char *filename) {
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

    std::istringstream dateSS(elems[0]);
    std::string date;
    dateSS >> date;

    try {
      float value = getValueAt(parseDate(date));

      if (elems.size() > 1) { // A value is provided
        std::istringstream amountSS(elems[1]);
        if (!isNumber(elems[1])) {
          std::cout << "Error: not a number." << std::endl;
          continue;
        }
        float amount;
        amountSS >> amount;

        if (amount > 1000) {
          std::cout << "Error: too large number." << std::endl;
          continue;
        } else if (amount < 0) {
          std::cout << "Error: not a positive number." << std::endl;
          continue;
        }

        std::cout << date << " => " << amount << " = " << value * amount
                  << std::endl;
      } else {
        std::cout << date << " = " << value << std::endl;
      }
    } catch (const std::runtime_error &e) {
      std::cout << "Error: bad input => " << date << std::endl;
    }
  }
}
