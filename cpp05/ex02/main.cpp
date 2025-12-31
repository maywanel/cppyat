#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        std::cout << "\n=== Testing Shrubbery Form ===" << std::endl;
        std::cout << shrubbery << std::endl;
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        std::cout << "\n=== Testing Robotomy Form ===" << std::endl;
        std::cout  << robotomy << std::endl;
        bob.signForm(robotomy);
        bob.executeForm(robotomy);
        bob.executeForm(robotomy);

        std::cout << "\n=== Testing Presidential Pardon Form ===" << std::endl;
        std::cout  << pardon << std::endl;
        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n=== Testing with low-grade bureaucrat ===" << std::endl;
        ShrubberyCreationForm shrubbery2("garden");
        charlie.signForm(shrubbery2);
        charlie.executeForm(shrubbery2);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}