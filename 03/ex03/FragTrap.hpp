#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    virtual ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();
};
