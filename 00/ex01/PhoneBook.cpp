#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    _contactCount = 0;
};


void PhoneBook::addContact()
{
    static int  i = 0;

    _contacts[i % 8].init();
    i++;
    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::searchContact()
{
    std::string index;

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _contacts[i].firstName << "|";
        std::cout << std::setw(10) << _contacts[i].lastName << "|";
        std::cout << std::setw(10) << _contacts[i].nickname;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Enter an index: ";
    std::getline(std::cin, index);
    std::cout << std::endl;
    if (index[1] || index[0] < '0' || index[0] >= '0' + _contactCount)
        return ;
    _contacts[index[0] - '0'].display();
}
