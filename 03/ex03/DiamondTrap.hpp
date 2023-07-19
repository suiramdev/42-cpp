#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap(std::string name);
    virtual ~DiamondTrap();
    void attack(const std::string& target);
    void whoAmI();
};
