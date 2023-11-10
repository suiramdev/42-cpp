#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

  for (int i = 0; i < 4; i++)
    delete animals[i];
}
