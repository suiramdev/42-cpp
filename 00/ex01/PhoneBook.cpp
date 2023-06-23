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
    Contact newContact;

    newContact.init();

    _contacts[i % 8] = newContact;
    i++;
    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::searchContact()
{
    char index;

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
    std::cin >> index;
    std::cout << std::endl;
    if (index < '0' || index >= '0' + _contactCount)
        return ;
    _contacts['0' - index].display();
}
