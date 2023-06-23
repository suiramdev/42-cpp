#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int     _contactCount;

public:
    PhoneBook();
    void addContact();
    void searchContact();
};
