/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:33:22 by moel-mes          #+#    #+#             */
/*   Updated: 2025/11/04 14:55:29 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static size_t g_next_index = 0;
static size_t g_count = 0;

Contact::Contact()
{
    name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
}

Contact::~Contact() {}

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact(const Contact& c)
{
    contacts[g_next_index] = c;
    if (g_count < 8)
        ++g_count;
    g_next_index = (g_next_index + 1) % 8;
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

    for (size_t i = 0; i < g_count; ++i)
    {
        const Contact& c = contacts[i];
        std::cout << std::setw(10) << i << "|"
                  << format_field(c.get_name()) << "|"
                  << format_field(c.get_last_name()) << "|"
                  << format_field(c.get_nickname()) << std::endl;
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
    if ((size_t)idx >= g_count) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "empty data\n";
        return;
    }
    const Contact& c = contacts[idx];
    std::cout << "First Name: " << c.get_name() << std::endl;
    std::cout << "Last Name: " << c.get_last_name() << std::endl;
    std::cout << "Nickname: " << c.get_nickname() << std::endl;
    std::cout << "Phone Number: " << c.get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << c.get_darkest_secret() << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Contact::set_name(const std::string& n) {
    name = n;
}
void Contact::set_last_name(const std::string& ln) {
    last_name = ln;
}
void Contact::set_nickname(const std::string& nn) {
    nickname = nn;
}
void Contact::set_phone_number(const std::string& pn) {
    phone_number = pn;
}

void Contact::set_darkest_secret(const std::string& ds) {
    darkest_secret = ds;
}

std::string Contact::get_name() const {
    return name;
}
std::string Contact::get_last_name() const {
    return last_name;
}
std::string Contact::get_nickname() const {
    return nickname;
}
std::string Contact::get_phone_number() const {
    return phone_number;
}
std::string Contact::get_darkest_secret() const {
    return darkest_secret;
}

