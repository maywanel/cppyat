#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

class Contact
{
    public:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        Contact();
        ~Contact();
};

class PhoneBook
{
    private:
        std::vector<Contact> contacts;
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(const Contact& c);
        void display_contacts() const;
};

#endif
