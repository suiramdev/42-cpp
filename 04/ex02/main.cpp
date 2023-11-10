#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
  // Animal* test = new Animal(); // ERR: Base class

  for (int i = 0; i < 4; i++)
    delete animals[i];
}
