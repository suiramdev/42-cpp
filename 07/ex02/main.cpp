#include "Array.hpp"
#include <iostream>

int main() {
  Array<int> arr(10);
  Array<int> arr2(10);

  std::cout << "Create arr" << std::endl;

  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = rand() % 100;
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl << "Create arr2" << std::endl;

  for (unsigned int i = 0; i < arr2.size(); i++) {
    arr2[i] = rand() % 100;
    std::cout << arr2[i] << " ";
  }

  std::cout << std::endl << "Assign arr to arr2" << std::endl;

  arr2 = arr;
  for (unsigned int i = 0; i < arr2.size(); i++)
    std::cout << arr2[i] << " ";
}
