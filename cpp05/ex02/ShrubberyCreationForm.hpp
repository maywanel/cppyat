#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        void executeAction() const;
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& original);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& toCopy);
        void execute(Bureaucrat const & executor) const;
};

#endif