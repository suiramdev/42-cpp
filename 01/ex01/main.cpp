#include "Zombie.hpp"


int main()
{
    Zombie* horde;

    horde = zombieHorde(4, "Jack"); 
    horde->deleteHorde();
    horde = zombieHorde(9, "Harry"); 
    horde->deleteHorde();
}
