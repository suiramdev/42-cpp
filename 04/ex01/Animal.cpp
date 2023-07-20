#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _brain(new Brain), _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _brain(new Brain), _type(type)
{
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : _brain(new Brain(*animal._brain)), _type(animal._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    delete _brain;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}
