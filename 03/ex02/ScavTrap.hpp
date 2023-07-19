#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    bool _isGuardMode;
public:
    ScavTrap(std::string name);
    virtual ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};
