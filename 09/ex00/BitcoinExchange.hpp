#pragma once

#include <ctime>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<time_t, float> _data;

  float getValueAt(const time_t &time) const;

public:
  BitcoinExchange();

  /**
   * @brief Load data from a file
   *
   * @param filename
   */
  BitcoinExchange(const char *filename);

  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  /**
   * @brief Process an input file, based on the following format:
   *        <date> | <price>
   *
   * @param filename
   */
  void process(const char *filename);
};
