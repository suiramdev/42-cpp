#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
    std::string option;
    PhoneBook phoneBook; 

    while (option != "EXIT")
    {
        std::cout << "\"ADD\": Save a new contact" << std::endl;
        std::cout << "\"SEARCH\": Display a specific contact" << std::endl;
        std::cout << "\"EXIT\"" << std::endl;
        std::cout << std::endl;
        std::cout << "Choose an option from above: ";
        std::cin >> option;
        std::cout << std::endl;

        if (option == "ADD")
            phoneBook.addContact();
        else if (option == "SEARCH")
            phoneBook.searchContact();
    }
}
