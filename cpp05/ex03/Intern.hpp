#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern& original);
        Intern& operator=(const Intern& toCopy);
        AForm* makeForm(std::string formName, std::string target);
        static AForm* createPresidentialPardonForm(std::string target);
        static AForm* createRobotomyRequestForm(std::string target);
        static AForm* createShrubberyCreationForm(std::string target);
        class UnknownFormException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif