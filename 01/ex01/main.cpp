#include "Zombie.hpp"


int main()
{
    Zombie* horde;

    horde = zombieHorde(4, "Jack"); 
    delete[] horde;
    horde = zombieHorde(9, "Harry"); 
    delete[] horde;
}
