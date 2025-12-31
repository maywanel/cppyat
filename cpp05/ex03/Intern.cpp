#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

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
    AForm* (*formCreators[3])(std::string) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    while (i < 3 && formName != formNames[i]) i++;
    if (i < 3) {
        std::cout << "Intern creates " << formName << std::endl;
        return formCreators[i](target);
    }
    throw UnknownFormException();
    return NULL;

}

const char* Intern::UnknownFormException::what() const throw() {
    return "Intern cannot create the requested form because it is unknown!";
}