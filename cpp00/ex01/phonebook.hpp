/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:33:31 by moel-mes          #+#    #+#             */
/*   Updated: 2025/08/26 10:16:54 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    private:
        std::string name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();
        void set_name(const std::string& n);
        void set_last_name(const std::string& ln);
        void set_nickname(const std::string& nn);
        void set_phone_number(const std::string& pn);
        void set_darkest_secret(const std::string& ds);
        std::string get_name() const;
        std::string get_last_name() const;
        std::string get_nickname() const;
        std::string get_phone_number() const;
        std::string get_darkest_secret() const;
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
