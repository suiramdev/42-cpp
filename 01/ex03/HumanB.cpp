#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (_weapon == NULL)
        return;
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}
