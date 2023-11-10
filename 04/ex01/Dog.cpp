#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &dog)
    Animal::operator=(dog);
  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "Bark" << std::endl; }
