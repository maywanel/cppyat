#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& original) : _name(original._name), _isSigned(original._isSigned), _signGrade(original._signGrade), _execGrade(original._execGrade) {}

AForm& AForm::operator=(const AForm& toCopy) {
    if (this != &toCopy) {
        this->_isSigned = toCopy._isSigned;
    }
    return *this;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    executeAction();
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}
