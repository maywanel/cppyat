/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:23:34 by moel-mes          #+#    #+#             */
/*   Updated: 2025/11/04 14:58:49 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool is_only_whitespace(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            return false;
        }
    }
    return true;
}

int main(){
    PhoneBook pb;
    std::string command;

    std::cout << "Welcome to the Phonebook" << std::endl;
    while (command != "EXIT")
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nInput stream closed. Exiting." << std::endl;
            break;
        }
        if (command == "ADD")
        {
            std::string name, last_name, nickname, phone_number, darkest_secret;
            std::cout << "Enter the name: ";
            if (!std::getline(std::cin, name)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (name.empty() || is_only_whitespace(name))
            {
                std::cout << "Name cannot be empty or contain only whitespaces." << std::endl;
                continue;
            }
            std::cout << "Enter the last name: ";
            if (!std::getline(std::cin, last_name)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (last_name.empty() || is_only_whitespace(last_name))
            {
                std::cout << "Last name cannot be empty or contain only whitespaces." << std::endl;
                continue;
            }
            std::cout << "Enter the nickname: ";
            if (!std::getline(std::cin, nickname)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (nickname.empty() || is_only_whitespace(nickname))
            {
                std::cout << "Nickname cannot be empty or contain only whitespaces." << std::endl;
                continue;
            }
            std::cout << "Enter the phone number: ";
            if (!std::getline(std::cin, phone_number)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            else {
                bool is_valid = true;
                for (size_t i = 0; i < phone_number.length(); ++i) {
                    if (!isdigit(phone_number[i])) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) {
                    std::cout << "Phone number must contain only digits." << std::endl;
                    continue;
                }
            }
            if (phone_number.empty())
            {
                std::cout << "Phone number cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the darkest secret: ";
            if (!std::getline(std::cin, darkest_secret)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (darkest_secret.empty() || is_only_whitespace(darkest_secret))
            {
                std::cout << "Darkest secret cannot be empty or contain only whitespaces." << std::endl;
                continue;
            }
            Contact c;
            c.set_name(name);
            c.set_last_name(last_name);
            c.set_nickname(nickname);
            c.set_phone_number(phone_number);
            c.set_darkest_secret(darkest_secret);
            pb.add_contact(c);
        }
        else if (command == "SEARCH")
            pb.display_contacts();
        else if (command != "EXIT" && command != "")
            std::cout << "invalid command." << std::endl;
    }
    return 0;
}
