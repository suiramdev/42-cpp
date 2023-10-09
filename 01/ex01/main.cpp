#include "Zombie.hpp"


int main()
{
    Zombie* horde = zombieHorde(9, "Jack"); 
    for (int i = 0; i < 9; i++)
        horde[i].announce();
    delete[] horde;
}
