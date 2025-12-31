#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
    : AForm(original), _target(original._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy) {
    if (this != &toCopy) {
        AForm::operator=(toCopy);
        this->_target = toCopy._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    executeAction();
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}
