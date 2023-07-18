#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
    bool _isGuardMode;
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};
