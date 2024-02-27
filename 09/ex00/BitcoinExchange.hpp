#pragma once

#include <ctime>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<time_t, double> _data;

  double getValueAt(const time_t &time) const;

public:
  BitcoinExchange();

  /**
   * @brief Load data from a file
   *
   * @param filename
   */
  BitcoinExchange(const std::string &filename);

  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  /**
   * @brief Process an input file, based on the following format:
   *        <date> | <price>
   *
   * @param filename
   */
  void process(const std::string &filename);
};
