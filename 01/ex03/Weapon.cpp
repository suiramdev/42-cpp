#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
    _type = type;
}

std::string const &Weapon::getType()
{
    return _type;
}
