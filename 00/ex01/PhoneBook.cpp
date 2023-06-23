#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int oldestContact = 0;

    public:
        void addContact(Contact contact)
        {
            contacts[oldestContact] = contact;
            oldestContact++;
            if (oldestContact > 8)
                oldestContact = 0;
        };
};
