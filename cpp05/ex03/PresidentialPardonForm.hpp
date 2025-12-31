#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        void executeAction() const;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& original);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& toCopy);
        void execute(Bureaucrat const & executor) const;
};

#endif