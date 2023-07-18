#include "ClapTrap.hpp"
#include <iostream>

int main()
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
