#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& original) {
    (void)original;
}

Intern& Intern::operator=(const Intern& toCopy) {
    (void)toCopy;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    int i = 0;
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    while (i < 3 && formName != formNames[i]) i++;
    std::cout << "Intern creates " << formName << std::endl;
    switch (i) {
        case 0:
        return new ShrubberyCreationForm(target);
        case 1:
        return new RobotomyRequestForm(target);
        case 2:
        return new PresidentialPardonForm(target);
        default:
            throw UnknownFormException();
            return NULL;
    }
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Intern cannot create the requested form because it is unknown!";
}