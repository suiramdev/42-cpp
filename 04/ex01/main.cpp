#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  {
    std::cout << "----- Test 1 -----" << std::endl;
    Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

    for (int i = 0; i < 4; i++)
      delete animals[i];
  }
  {
    std::cout << "----- Test 2 -----" << std::endl;
    Cat cat;

    Cat tmp = cat;
  }
}
