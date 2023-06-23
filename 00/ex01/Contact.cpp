#include <string>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;

        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber)
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->nickName = nickName;
            this->phoneNumber = phoneNumber;
        };
};
