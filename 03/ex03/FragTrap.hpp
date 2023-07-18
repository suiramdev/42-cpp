#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();
};
