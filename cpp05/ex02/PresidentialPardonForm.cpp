#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)
    : AForm(original), _target(original._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy) {
    if (this != &toCopy) {
        AForm::operator=(toCopy);
        this->_target = toCopy._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    executeAction();
}

void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}