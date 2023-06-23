#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name)
{
    this->name = name;
    this->next = NULL;
}

Zombie::~Zombie()
{
    std::cout << "deleted " << name << std::endl;
}

void Zombie::deleteHorde()
{
    Zombie* zombie = this;

    while (zombie)
    {
        Zombie* tmp = zombie;
        zombie = zombie->next;
        delete tmp;
    }
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
