#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "-- ClapTrap --" << std::endl;
    {
        ClapTrap a("ClapTrap A");
        ClapTrap b("ClapTrap B");

        a.attack("ClapTrap B");
        b.takeDamage(a.getAttackDamage());
        b.attack("ClapTrap A");
        a.takeDamage(b.getAttackDamage());
        a.beRepaired(10);
        b.beRepaired(10);
        std::cout << "A has " << a.getHitPoints() << " hit points and " << a.getEnergyPoints() << " energy points" << std::endl;
        std::cout << "B has " << b.getHitPoints() << " hit points and " << b.getEnergyPoints() << " energy points" << std::endl;
    }
    std::cout << "-- ScavTrap --" << std::endl;
    {
        ScavTrap a("ScavTrap A");
        ScavTrap b("ScavTrap B");

        a.attack("ClapTrap B");
        b.takeDamage(a.getAttackDamage());
        b.attack("ClapTrap A");
        a.takeDamage(b.getAttackDamage());
        a.beRepaired(10);
        b.beRepaired(10);
        a.guardGate();
        std::cout << "A has " << a.getHitPoints() << " hit points and " << a.getEnergyPoints() << " energy points" << std::endl;
        std::cout << "B has " << b.getHitPoints() << " hit points and " << b.getEnergyPoints() << " energy points" << std::endl;
    }
}
