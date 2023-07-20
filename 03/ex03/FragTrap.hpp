#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& fragTrap);
    FragTrap& operator=(const FragTrap& fragTrap);
    virtual ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();
};
