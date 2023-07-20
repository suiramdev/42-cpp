#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &cat)
        Animal::operator=(cat);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meaow" << std::endl;
}
