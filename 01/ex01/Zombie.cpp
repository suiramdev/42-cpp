#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
    std::cout << "deleted " << _name << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}
