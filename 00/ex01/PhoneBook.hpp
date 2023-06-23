#pragma once

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact(Contact contact);
};
