#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook phoneBook;

    std::cout <<
        "-- OPTIONS --"
        "\"ADD\": Save a new contact\n"
        "\"SEARCh\": Display a specific contact\n"
        "\"EXIT\"\n"
        "-------------\n"
        "Choose an option from the above: "
    << std::endl;
}
