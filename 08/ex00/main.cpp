#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  std::cout << *easyfind(v, 2) << std::endl;
  std::cout << *easyfind(v, 4) << std::endl;
}
