#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
  std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : _type(animal._type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &animal) {
    _type = animal._type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }

std::string Animal::getType() const { return _type; }
