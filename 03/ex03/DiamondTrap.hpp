#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& diamondTrap);
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);
    virtual ~DiamondTrap();
    void attack(const std::string& target);
    void whoAmI();
};
