#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
    Weapon* _weapon;
    std::string _name;

public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& weapon);
};
