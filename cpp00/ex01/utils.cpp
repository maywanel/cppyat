#include "phonebook.hpp"

Contact::Contact()
{
    name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
}

Contact::~Contact()
{
}

PhoneBook::PhoneBook()
{
    contacts.reserve(8);
}
PhoneBook::~PhoneBook()
{
    contacts.clear();
}
void PhoneBook::add_contact(const Contact& c)
{
    static size_t next_index = 0;
    if (contacts.size() < 8)
        contacts.push_back(c);
    else
        contacts[0] = c;
    next_index = (next_index + 1) % 8;
}

static std::string format_field(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::display_contacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (size_t i = 0; i < contacts.size(); ++i)
    {
        const Contact& c = contacts[i];
        std::cout << std::setw(10) << i << "|"
                  << format_field(c.name) << "|"
                  << format_field(c.last_name) << "|"
                  << format_field(c.nickname) << std::endl;
    }

    std::cout << "Enter the index of the entry to display: ";
    int idx;
    std::cin >> idx;
    if (std::cin.fail() || idx < 0 || idx > 7) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index.\n";
        return;
    }
    if (static_cast<size_t>(idx) >= contacts.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "empty data\n";
        return;
    }
    const Contact& c = contacts[idx];
    std::cout << "First Name: " << c.name << std::endl;
    std::cout << "Last Name: " << c.last_name << std::endl;
    std::cout << "Nickname: " << c.nickname << std::endl;
    std::cout << "Phone Number: " << c.phone_number << std::endl;
}