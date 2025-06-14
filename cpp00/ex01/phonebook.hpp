#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class contact
{
    public:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        contact();
        ~contact();
};

class phonebook
{
    private:
        std::vector<contact> contacts;
    public:
        phonebook();
        ~phonebook();
        void add_contact(const contact& c);
        void display_contacts() const;
};

#endif
