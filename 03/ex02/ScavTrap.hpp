#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    bool _isGuardMode;
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    virtual ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};
