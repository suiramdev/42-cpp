#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* head = NULL;

    for (int i = 0; i < N; i++)
    {
        Zombie* zombie = new Zombie(name);
        zombie->announce();

        if (!head)
            head = zombie;
        else
        {
            Zombie* tmp = head;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = zombie;
        }
    }
    return (head);
}
