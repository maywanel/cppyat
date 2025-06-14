#include "phonebook.hpp"

int main(){
    phonebook pb;
    std::string command;

    std::cout << "Welcome to the Phonebook" << std::endl;
    while (command != "EXIT")
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            std::string name, last_name, nickname, phone_number, darkest_secret;
            std::cout << "Enter the name: ";
            std::getline(std::cin, name);
            if (name.empty())
            {
                std::cout << "Name cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the last name: ";
            std::getline(std::cin, last_name);
            if (last_name.empty())
            {
                std::cout << "Last name cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the nickname: ";
            std::getline(std::cin, nickname);
            if (nickname.empty())
            {
                std::cout << "Nickname cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the phone number: ";
            std::getline(std::cin, phone_number);
            if (phone_number.empty())
            {
                std::cout << "Phone number cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the darkest secret: ";
            std::getline(std::cin, darkest_secret);
            if (darkest_secret.empty())
            {
                std::cout << "Darkest secret cannot be empty." << std::endl;
                continue;
            }
            contact c;
            c.name = name;
            c.last_name = last_name;
            c.nickname = nickname;
            c.phone_number = phone_number;
            c.darkest_secret = darkest_secret;
            pb.add_contact(c);
        }
        else if (command == "SEARCH")
            pb.display_contacts();
    }
    return 0;
}