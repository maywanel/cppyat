#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
        void executeAction() const;
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& original);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);
        void execute(Bureaucrat const & executor) const;
};

#endif