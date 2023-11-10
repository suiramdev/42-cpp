#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), _brain(new Brain(*dog._brain)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &dog) {
    Animal::operator=(dog);
    _brain = dog._brain;
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete _brain;
}

void Dog::makeSound() const { std::cout << "Bark" << std::endl; }
