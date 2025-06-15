/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:23:34 by moel-mes          #+#    #+#             */
/*   Updated: 2025/06/15 22:33:16 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
            if (name.empty())
            {
                std::cout << "Name cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the last name: ";
            if (!std::getline(std::cin, last_name)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (last_name.empty())
            {
                std::cout << "Last name cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the nickname: ";
            if (!std::getline(std::cin, nickname)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
            }
            if (nickname.empty())
            {
                std::cout << "Nickname cannot be empty." << std::endl;
                continue;
            }
            std::cout << "Enter the phone number: ";
            if (!std::getline(std::cin, phone_number)) {
                std::cout << "\nInput stream closed. Exiting." << std::endl;
                break;
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
            if (darkest_secret.empty())
            {
                std::cout << "Darkest secret cannot be empty." << std::endl;
                continue;
            }
            Contact c;
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